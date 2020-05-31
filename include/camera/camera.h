#ifndef CAMERA_H
#define CAMERA_H

#include "math/math_common.h"

class camera {
private:
  point3 origin;
  point3 lower_left_corner;
  vec3 horizontal;
  vec3 vertical;
public:
  camera();
  ray get_ray(double u, double v);
};

#endif