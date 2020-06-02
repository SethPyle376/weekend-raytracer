#ifndef AABB_H
#define AABB_H

#include "vec3.h"
#include "ray.h"

class aabb {
public:
  aabb() {}
  aabb(const point3& a, const point3& b);

  point3 _min;
  point3 _max;

  point3 min() const;
  point3 max() const;

  bool hit(const ray& r, double tmin, double tmax) const;

  static aabb surrounding_box(aabb box0, aabb box1) {
    point3 small(fmin(box0.min().x(), box1.min().x()),
                  fmin(box0.min().y(), box1.min().y()),
                  fmin(box0.min().z(), box1.min().z()));

    point3 big(fmax(box0.max().x(), box1.max().x()),
              fmax(box0.max().y(), box1.max().y()),
              fmax(box0.max().z(), box1.max().z()));
    
    return aabb(small, big);
  }
};

#endif