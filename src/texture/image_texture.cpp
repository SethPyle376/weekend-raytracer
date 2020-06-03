#include "texture/image_texture.h"

image_texture::image_texture(const char* filename) {
  auto components_per_pixel = bytes_per_pixel;

  data = stbi_load(filename, &width, &height, &components_per_pixel, components_per_pixel);

  if (!data) {
    std::cerr << "ERROR: COULD NOT LOAD TEXTURE IMAGE FILE " << filename << "\n";
    width = height = 0;
  }

  bytes_per_scanline = bytes_per_pixel * width;
}

image_texture::~image_texture() {
  delete data;
}

color image_texture::value(double u, double v, const vec3& p) const {
  if (data == nullptr)
    return color(0, 1, 1);
  
  u = clamp(u, 0.0, 1.0);
  v = 1.0 - clamp(v, 0.0, 1.0);

  auto i = static_cast<int>(u * width);
  auto j = static_cast<int>(v * height);

  if (i >= width) i = width - 1;
  if (j >= height) j = height - 1;

  const auto color_scale = 1.0 / 255.0;
  auto pixel = data + j * bytes_per_scanline + i * bytes_per_pixel;

  return color(color_scale * pixel[0], color_scale * pixel[1], color_scale * pixel[2]);
}