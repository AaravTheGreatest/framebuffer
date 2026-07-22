#pragma once

#include <colors.h>

#include <vector>
#include <cstdint>

class Framebuffer {
public:
  Framebuffer(uint32_t w, uint32_t h);
  void clear(Color color);
  void setPixel(uint32_t x, uint32_t y, Color color);
  uint32_t* data();
  uint32_t getWidth() const;
  uint32_t getHeight() const;
  void setWidth(uint32_t w);
  void setHeight(uint32_t h);
  Framebuffer(Framebuffer &&) = default;
  Framebuffer(const Framebuffer &) = default;
  Framebuffer &operator=(Framebuffer &&) = default;
  Framebuffer &operator=(const Framebuffer &) = default;
  ~Framebuffer();

private:
  uint32_t width, height;
  std::vector<uint32_t> pixels;
};



