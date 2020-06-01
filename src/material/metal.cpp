#include "material/metal.h"

metal::metal(const color& a, double f) : albedo(a), fuzz(f) {}

bool metal::scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const {
  vec3 reflected = reflect(unit_vector(r_in.direction()), rec.normal);
  scattered = ray(rec.p, reflected + fuzz * vec3::random_in_unit_sphere());
  attenuation = albedo;
  return (dot(scattered.direction(), rec.normal) > 0);
}