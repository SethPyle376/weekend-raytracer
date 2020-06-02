#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include "texture/texture.h"
#include "material/material.h"

class lambertian : public material {
public:
  lambertian(std::shared_ptr<texture> albedo);

  std::shared_ptr<texture> albedo;

  virtual bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const;
};

#endif