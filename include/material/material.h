#ifndef MATERIAL_H
#define MATERIAL_H

#include "shape/hittable.h"

class material {
public:
  virtual bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const = 0;

  virtual color emitted(double u, double v, const point3& p) const {
    return color(0, 0, 0);
  }

  static double schlick(double cosine, double ref_idx) {
    auto r0 = (1 - ref_idx) / (1 + ref_idx);
    r0 = r0 * r0;
    return r0 + (1 - r0) * pow((1 - cosine), 5);
  }

};
#endif