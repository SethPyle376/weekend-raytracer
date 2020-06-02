#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include <memory>
#include <vector>

#include "shape/hittable.h"

class hittable_list : public hittable {
public:
  hittable_list() {}
  hittable_list(std::shared_ptr<hittable> object);

  std::vector<std::shared_ptr<hittable>> objects;

  void clear();
  void add(std::shared_ptr<hittable> object);

  virtual bool hit(const ray &r, double t_min, double t_max, hit_record &rec) const;
  virtual bool bounding_box(double t0, double t1, aabb& output_box) const;
};

#endif