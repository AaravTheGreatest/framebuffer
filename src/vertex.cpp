#include <vertex.h>

Vertex::Vertex(const raster::Vec4f& pos, const Color& color, const raster::Vec2f& uv, const raster::Vec3f& normal): pos(pos), color(color), uv(uv), normal(normal) {}
Vertex::Vertex(const raster::Vec4f& pos, const Color& color, float uv1, float uv2, float n1, float n2, float n3): Vertex(pos, color, raster::Vec2f(uv1, uv2), raster::Vec3f(n1, n2, n3)) {}
Vertex::Vertex(const raster::Vec4f& pos, const Color& color, const raster::Vec2f& uv, float n1, float n2, float n3): Vertex(pos, color, uv, raster::Vec3f(n1, n2, n3)) {}
Vertex::Vertex(const raster::Vec4f& pos, const Color& color, float uv1, float uv2, const raster::Vec3f& normal): Vertex(pos, color, raster::Vec2f(uv1, uv2), normal) {}
Vertex::Vertex(float x, float y, float z, float w, const Color& color, const raster::Vec2f& uv, float n1, float n2, float n3):  Vertex(raster::Vec4f(x, y, z, w), color, uv, raster::Vec3f(n1, n2, n3)) {}
Vertex::Vertex(float x, float y, float z, float w, const Color& color, const raster::Vec2f& uv, const raster::Vec3f& normal): Vertex(raster::Vec4f(x, y, z, w), color, uv, normal) {}
Vertex::Vertex(float x, float y, float z, float w, const Color& color, float uv1, float uv2, const raster::Vec3f& normal): Vertex(raster::Vec4f(x, y, z, w), color, raster::Vec2f(uv1, uv2), normal) {}
Vertex::Vertex(float x, float y, float z, float w, const Color& color, float uv1, float uv2, float n1, float n2, float n3): Vertex(raster::Vec4f(x, y, z, w), color, raster::Vec2f(uv1, uv2), raster::Vec3f(n1, n2, n3)) {}
