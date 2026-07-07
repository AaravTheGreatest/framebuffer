#include <fb.h>

Framebuffer::Framebuffer(uint32_t w, uint32_t h): width(w), height(h), pixels(w * h) {}
Framebuffer::~Framebuffer() {}
uint32_t Framebuffer::getWidth() const { return width; }

void Framebuffer::clear(uint32_t colour) { 
  for (size_t i = 0; i < pixels.size(); i++) pixels[i] = colour; 
} 
void Framebuffer::setPixel(uint32_t x, uint32_t y, uint32_t colour) { 
  if (x >= width || y >= height) return; 
  pixels[y * getWidth() + x] = colour; 
}
