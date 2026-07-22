#pragma once

#include <fb.h>
#include <math/typedefs.h>
#include <vertex.h>

#include <vector>

int drawLine(Framebuffer& fb, const Vertex& a, const Vertex& b);
int drawTriangle(Framebuffer& fb, const Vertex& a, const Vertex& b, const Vertex c, bool filled, Color color);


