#ifndef SPHERE_H
#define SPHERE_H

#include <cmath>

#include "shape/hittable.h"

class sphere : public hittable {
public:
  sphere() {}
  sphere(point3 cen, double r) : center(cen), radius(r){};

  point3 center;
  double radius;

  virtual bool hit(const ray &r, double t_min, double t_max,
                   hit_record &rec) const;
};

#endif