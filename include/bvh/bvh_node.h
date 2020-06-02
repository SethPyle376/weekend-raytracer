#ifndef BVH_H
#define BVH_H

#include <vector>
#include <memory>
#include <algorithm>

#include "shape/hittable.h"
#include "shape/hittable_list.h"

class bvh_node : public hittable {
public:
  bvh_node() {};
  bvh_node(hittable_list& list, double time0, double time1);
  bvh_node(std::vector<std::shared_ptr<hittable>>& objects, size_t start, size_t end, double time0, double time1);

  std::shared_ptr<hittable> left;
  std::shared_ptr<hittable> right;
  aabb box;

  virtual bool hit(const ray& r, double tmin, double tmax, hit_record& rec) const;
  virtual bool bounding_box(double t0, double t1, aabb& output_box) const;

};

#endif