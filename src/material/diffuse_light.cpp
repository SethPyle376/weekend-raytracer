#include "material/diffuse_light.h"

bool diffuse_light::scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const {
  return false;
}

color diffuse_light::emitted(double u, double v, const point3& p) const {
  return emit->value(u, v, p);
}