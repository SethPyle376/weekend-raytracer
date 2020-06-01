#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include "material/material.h"

class lambertian : public material {
public:
  lambertian(const color& albedo);

  color albedo;

  virtual bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const;
};

#endif