#include <fb.h>

Framebuffer::Framebuffer(uint32_t w, uint32_t h): width(w), height(h), pixels(w * h) {}
Framebuffer::~Framebuffer() {}

// getters because I can't just Framebuffer.height :(
uint32_t Framebuffer::getWidth() const { return width; }
uint32_t Framebuffer::getHeight() const { return height; }
uint32_t* Framebuffer::data() { return pixels.data(); }

// changing dimensions (setters, because, once again, you can't just Framebuffer.height = x)
void Framebuffer::setWidth(uint32_t w) { width = w; pixels.resize(width * height); }
void Framebuffer::setHeight(uint32_t h) {height = h; pixels.resize(width * height); }

// coloring stuff
void Framebuffer::clear(uint32_t colour) { 
  for (size_t i = 0; i < pixels.size(); i++) pixels[i] = colour; 
} 
void Framebuffer::setPixel(uint32_t x, uint32_t y, uint32_t colour) { 
  if (x >= width || y >= height) return; 
  pixels[y * getWidth() + x] = colour; 
}
