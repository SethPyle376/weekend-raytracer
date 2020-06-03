#ifndef DIFFUSE_LIGHT_H
#define DIFFUSE_LIGHT_H

#include "material/material.h"
#include "texture/texture.h"

class diffuse_light : public material {
public:
  diffuse_light(std::shared_ptr<texture> a) : emit(a) {}

  std::shared_ptr<texture> emit;

  virtual bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const;
  virtual color emitted(double u, double v, const point3& p) const;
};

#endif