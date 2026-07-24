#include <draw.h>

#include <algorithm>
#include <cmath>

float edge(const Vertex& a, const Vertex& b, float x, float y) {
  int x1 = a.pos.x, x2 = b.pos.x, x3 = x, y1 = a.pos.y, y2 = b.pos.y, y3 = y;
  return (x3 - x1) * (y2 - y1) - (y3 - y1) * (x2 - x1);
}
int drawLine(Framebuffer& fb, const Vertex& a, const Vertex& b) {
  int x1 = a.pos.x, x2 = b.pos.x, y1 = a.pos.y, y2 = b.pos.y;
  int dx = (x2 - x1), dy = (y2 - y1);
  if (dx == 0 && dy == 0) {
    fb.setPixel(x1, y1, a.color);
  }
  else {
    int steps = std::max(std::abs(dx), std::abs(dy));
    float xInc = (float)dx / steps, yInc = (float)dy / steps;
    float x = (float)x1, y = (float)y1;
    for (int i = 0; i <= steps; i++) {
      float t = i / (float)steps;
      Color color = a.color.lerp(b.color, t);
      fb.setPixel(std::round(x), std::round(y), color);
      x += xInc;
      y += yInc;
    }
  }
  return 0;
}

int drawTriangle(Framebuffer& fb, const Vertex& a, const Vertex& b, const Vertex& c, bool filled) {
  drawLine(fb, a, b); drawLine(fb, b, c); drawLine(fb, c, a);
  if (filled) {
    float area = edge(a, b, c.pos.x, c.pos.y);
    int xMin = std::min(a.pos.x, std::min(b.pos.x, c.pos.x)), xMax = std::max(a.pos.x, std::max(b.pos.x, c.pos.x)),
        yMin = std::min(a.pos.y, std::min(b.pos.y, c.pos.y)), yMax = std::max(a.pos.y, std::max(b.pos.y, c.pos.y));
    for (int y = yMin; y <= yMax; y++) {
      for (int x = xMin; x <= xMax; x++){
        int p1 = edge(a, b,x + .5, y + .5), p2 = edge(b, c,x + .5, y + .5), p3 = edge(c, a,x + .5, y + .5);
        float wa = edge(b, c, x + .5, y + .5) / area, wb = edge(c, a,x + .5, y + .5) / area, wc = edge(a, b,x + .5, y + .5) / area;
        Color color = a.color * wa + b.color * wb + c.color * wc;
        if ((p1 >= 0 && p2 >= 0 && p3 >= 0) || (p1 <= 0 && p2 <= 0 && p3 <= 0)) fb.setPixel(x, y, color);
      }
    }
  }
  return 0;
}

