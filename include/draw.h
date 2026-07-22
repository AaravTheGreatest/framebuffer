#pragma once

#include <fb.h>
#include <math/typedefs.h>

#include <vector>

int drawLine(Framebuffer& fb, int x1, int y1, int x2, int y2, Color color);
int drawLine(Framebuffer& fb, raster::Vec2f a, raster::Vec2f b, Color c);
int drawTriangle(Framebuffer& fb, const int* verts, int startIndex, int numIndices);
int drawTriangle(Framebuffer& fb, int x1, int y1, int x2, int y2, int x3, int y3, bool filled, Color color);
int drawTriangle(Framebuffer& fb, std::vector<int>& verts, int startIndex, int numIndices);


