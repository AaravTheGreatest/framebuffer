#pragma once

#include <math/typedefs.h>
#include <color.h>

struct Vertex {
  raster::Vec4f pos; // x, y, z, w
  Color color; // argb
  raster::Vec2f uv; // for textures
  raster::Vec3f normal;

  Vertex(const raster::Vec4f& pos, const Color& color, const raster::Vec2f& uv, const raster::Vec3f& normal);
  Vertex(const raster::Vec4f& pos, const Color& color, float uv1, float uv2, float n1, float n2, float n3);
  Vertex(const raster::Vec4f& pos, const Color& color, const raster::Vec2f& uv, float n1, float n2, float n3);
  Vertex(const raster::Vec4f& pos, const Color& color, float uv1, float uv2, const raster::Vec3f& normal);
  Vertex(float x, float y, float z, float w, const Color& color, const raster::Vec2f& uv, float n1, float n2, float n3);  
  Vertex(float x, float y, float z, float w, const Color& color, const raster::Vec2f& uv, const raster::Vec3f& normal);
  Vertex(float x, float y, float z, float w, const Color& color, float uv1, float uv2, const raster::Vec3f& normal);
  Vertex(float x, float y, float z, float w, const Color& color, float uv1, float uv2, float n1, float n2, float n3);
};
