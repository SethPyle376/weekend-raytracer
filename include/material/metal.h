#ifndef METAL_H
#define METAL_H

#include "material/material.h"
#include "math/math_common.h"

class metal : public material {
public:
  metal(const color& a, double f);

  color albedo;
  double fuzz;

  virtual bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const;
};

#endif