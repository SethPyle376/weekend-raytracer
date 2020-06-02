#include "material/lambertian.h"

lambertian::lambertian(std::shared_ptr<texture> albedo) {
  this->albedo = albedo;
}

bool lambertian::scatter(const ray& ray_in, const hit_record& hit_record, color& attenuation, ray& scattered) const {
  vec3 scatter_direction = hit_record.normal + vec3::random_unit_vector();
  scattered = ray(hit_record.p, scatter_direction);
  attenuation = this->albedo->value(hit_record.u, hit_record.v, hit_record.p);
  return true;
}