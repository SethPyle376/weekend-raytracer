#ifndef SPHERE_H
#define SPHERE_H

#include <memory>
#include <cmath>

#include "shape/hittable.h"

class sphere : public hittable {
public:
  sphere() {}
  sphere(point3 cen, double r, std::shared_ptr<material> m) : center(cen), radius(r), mat_ptr(m) {};

  point3 center;
  double radius;
  std::shared_ptr<material> mat_ptr;

  virtual bool hit(const ray &r, double t_min, double t_max,
                   hit_record &rec) const;
};

#endif