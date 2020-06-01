#include "material/lambertian.h"

lambertian::lambertian(const color& albedo) {
  this->albedo = albedo;
}

bool lambertian::scatter(const ray& ray_in, const hit_record& hit_record, color& attenuation, ray& scattered) const {
  vec3 scatter_direction = hit_record.normal + vec3::random_unit_vector();
  scattered = ray(hit_record.p, scatter_direction);
  attenuation = this->albedo;
  return true;
}