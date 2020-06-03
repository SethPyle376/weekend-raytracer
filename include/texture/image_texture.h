#ifndef IMAGE_TEXTURE_H
#define IMAGE_TEXTURE_H

#include "stb_image.h"

#include "texture/texture.h"

class image_texture : public texture {
private:
  unsigned char *data;
  int width, height;
  int bytes_per_scanline;
public:
  const static int bytes_per_pixel = 3;

  image_texture() : data(nullptr), width(0), height(0), bytes_per_scanline(0) {}
  image_texture(const char* filename);
  ~image_texture();

  virtual color value(double u, double v, const vec3& p) const;
};

#endif