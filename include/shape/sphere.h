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
  virtual bool bounding_box(double t0, double t1, aabb& output_box) const;

  static void get_sphere_uv(const vec3& p, double& u, double& v) {
    auto phi = atan2(p.z(), p.x());
    auto theta = asin(p.y());
    u = 1 - (phi + pi) / (2 * pi);
    v = (theta + pi / 2) / pi;
  }
};

#endif