#include <draw.h>
#include <X11/Xlib.h>
#include <fb.h>
#include <unistd.h>
#include <stdio.h>

int main() {
  Display* display = XOpenDisplay(nullptr);
  int screen = DefaultScreen(display);
  Window window = XCreateSimpleWindow(display, RootWindow(display, screen), 50, 50, 600, 800, 2, BlackPixel(display, screen),WhitePixel(display, screen));
  Framebuffer framebuffer(600, 800);
  framebuffer.clear(0xFF0000FF);
  XImage* image = XCreateImage(
    display,
    DefaultVisual(display, screen),
    24,
    ZPixmap,
    0,
    reinterpret_cast<char*>(framebuffer.data()),
    framebuffer.getWidth(),
    framebuffer.getHeight(),
    32,
    framebuffer.getWidth() * sizeof(uint32_t)
  );
  while (1) {
    XMapWindow(display, window);
    XPutImage(
      display,
      window,
      DefaultGC(display, screen),
      image,
      0, 0,
      0, 0,
      framebuffer.getWidth(),
      framebuffer.getHeight()
    );
    XFlush(display);
    framebuffer.clear(0xFF0000FF);
    printf("depth: %d\n", image->depth);
    printf("bpp: %d\n", image->bits_per_pixel);
    printf("byte order: %d\n", image->byte_order);

    printf("red mask:   %08lx\n", image->red_mask);
    printf("green mask: %08lx\n", image->green_mask);
    printf("blue mask:  %08lx\n", image->blue_mask);
    sleep(1);
    framebuffer.clear(0xFF00FF00);
    printf("depth: %d\n", image->depth);
    printf("bpp: %d\n", image->bits_per_pixel);
    printf("byte order: %d\n", image->byte_order);

    printf("red mask:   %08lx\n", image->red_mask);
    printf("green mask: %08lx\n", image->green_mask);
    printf("blue mask:  %08lx\n", image->blue_mask);
    sleep(1);
    framebuffer.clear(0xFFFF0000);
    printf("depth: %d\n", image->depth);
    printf("bpp: %d\n", image->bits_per_pixel);
    printf("byte order: %d\n", image->byte_order);

    printf("red mask:   %08lx\n", image->red_mask);
    printf("green mask: %08lx\n", image->green_mask);
    printf("blue mask:  %08lx\n", image->blue_mask);
    sleep(1);
    
  }
}
