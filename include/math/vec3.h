#pragma once

#include <math/vec2.h>

namespace raster {
  template<typename T>
  struct Vec3 {
    T x, y, z;
    Vec3();
    Vec3(T x, T y, T z);
    Vec3(const Vec2<T>& xy, T z);
  };
  template<typename T>
  Vec3<T>::Vec3(): x(0), y(0), z(0) {}
  template<typename T>
  Vec3<T>::Vec3(T x, T y, T z): x(x), y(y), z(z) {}
  template<typename T>
  Vec3<T>::Vec3(const Vec2<T>& xy, T z): x(xy.x), y(xy.y), z(z) {}
}
