#include <color.h>

uint32_t Color::pack() const {
  return ((int)(a * 255) << 24) | ((int)(r * 255) << 16) | ((int)(g * 255) << 8) | (int)(b * 255);
}
Color Color::operator*(float t) const {
  return Color(r * t, g * t, b * t, a * t);
}
Color Color::operator+(const Color& other) const {
  return Color(r + other.r, g + other.g, b + other.b, a + other.a);
}
Color Color::lerp(const Color& other, float t) const {
  return (*this) * (1.0f - t) + other * t;
}
