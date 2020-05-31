#ifndef MATH_COMMON_H
#define MATH_COMMON_H

#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

inline double degrees_to_radians(double degrees) {
  return degrees * pi / 180;
}

#include "ray.h"
#include "vec3.h"

#endif