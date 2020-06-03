#define STB_IMAGE_IMPLEMENTATION

#include <iostream>
#include <time.h>

#include "ray.h"
#include "vec3.h"
#include "shape/hittable_list.h"
#include "shape/sphere.h"
#include "color.h"
#include "camera/camera.h"

#include "material/lambertian.h"
#include "material/metal.h"
#include "material/dielectric.h"
#include "material/diffuse_light.h"

#include "texture/image_texture.h"

#include "bvh/bvh_node.h"

hittable_list random_scene() {
    hittable_list world;

    auto checker = std::make_shared<checker_texture>(
        std::make_shared<solid_color>(0.0, 0.0, 0.0),
        std::make_shared<solid_color>(1.0, 1.0, 1.0)
    );

    auto ground_material = std::make_shared<lambertian>(checker);
    world.add(std::make_shared<sphere>(point3(0, -1000, 0), 1000, ground_material));

    auto difflight = std::make_shared<diffuse_light>(std::make_shared<solid_color>(4, 4, 4));
    world.add(std::make_shared<sphere>(point3(4, 3, 0), 1, difflight));

    for (int a = -3; a < 15; a++) {
        for (int b = -3; b < 15; b++) {
            auto choose_mat = random_double();
            point3 center(a + 0.9 * random_double(), 0.2, b + 0.9 * random_double());

            if ((center - vec3(4, 0.2, 0)).length() > 0.9) {
                std::shared_ptr<material> sphere_material;

                if (choose_mat < 0.4) {
                    auto albedo = color::random() * color::random();
                    auto solid_texture = std::make_shared<solid_color>(albedo);
                    sphere_material = std::make_shared<lambertian>(solid_texture);
                    world.add(std::make_shared<sphere>(center, 0.2, sphere_material));
                } else if (choose_mat < 0.8) {
                    auto albedo = color::random(0.5, 1);
                    auto fuzz = random_double(0, 0.5);
                    sphere_material = std::make_shared<metal>(albedo, fuzz);
                    world.add(std::make_shared<sphere>(center, 0.2, sphere_material));
                } else {
                    sphere_material = std::make_shared<dielectric>(1.5);
                    world.add(std::make_shared<sphere>(center, 0.2, sphere_material));
                }
            }
        }
    }

    auto earth_texture = std::make_shared<image_texture>("assets/earthmap.jpg");
    auto earth_surface = std::make_shared<lambertian>(earth_texture);
    auto globe = std::make_shared<sphere>(point3(5, 1, 4), 1.0, earth_surface);
    world.add(globe);

    auto material1 = std::make_shared<dielectric>(1.5);
    world.add(std::make_shared<sphere>(point3(0, 1, 0), 1.0, material1));

    auto material2 = std::make_shared<lambertian>(std::make_shared<solid_color>(color(0.4, 0.2, 0.1)));
    world.add(std::make_shared<sphere>(point3(-4, 1, 0), 1.0, material2));

    auto material3 = std::make_shared<metal>(color(0.7, 0.6, 0.5), 0.0);
    world.add(std::make_shared<sphere>(point3(4, 1, 0), 1.0, material3));

    std::shared_ptr<hittable> bvh_world = std::make_shared<bvh_node>(world, 0.0, 1.0);

    return hittable_list(bvh_world);
}

color ray_color(const ray& r, const color& background, const hittable& world, int depth) {
    hit_record rec;

    if (depth <= 0)
        return color(0, 0, 0);

    if (!world.hit(r, 0.001, infinity, rec)) {
        return background;
    }

    ray scattered;
    color attenuation;
    color emitted = rec.mat_ptr->emitted(rec.u, rec.v, rec.p);

    if (!rec.mat_ptr->scatter(r, rec, attenuation, scattered))
        return emitted;
    
    return emitted + attenuation * ray_color(scattered, background, world, depth - 1);
}

int main() {
    srand(time(NULL));
    const auto aspect_ratio = 16.0 / 9.0;
    const int image_width = 1920;
    const int image_height = static_cast<int>(image_width / aspect_ratio);
    const int samples_per_pixel = 2000;
    const int max_depth = 50;

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    hittable_list world = random_scene();

    point3 lookfrom(13, 2, 3);
    point3 lookat(0, 0, 0);
    vec3 vup(0, 1, 0);

    camera cam(lookfrom, lookat, vup, 40, aspect_ratio);

    const color background(0, 0, 0);

    for (int j = image_height-1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            color pixel_color(0, 0, 0);
            for (int s = 0; s < samples_per_pixel; s++) {
                auto u = (i + random_double()) / (image_width - 1);
                auto v = (j + random_double()) / (image_height - 1);
                ray r = cam.get_ray(u, v);
                pixel_color += ray_color(r, background, world, max_depth);
            }
            write_color(std::cout, pixel_color, samples_per_pixel);
        }
    }
}