#ifndef DIELECTRIC_H
#define DIELECTRIC_H

#include "material/material.h"

class dielectric : public material {
public:
  dielectric(double ri);

  double ref_idx;

  virtual bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const;
};

#endif