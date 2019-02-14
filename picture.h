#ifndef CHIP_PICTURE_H
#define CHIP_PICTURE_H

#include <cairomm/context.h>
#include <cairomm/surface.h>

class Picture {
 public:
  Picture();
  ~Picture() = default;
  Cairo::RefPtr<Cairo::Surface> get_surface();
  int get_width();
  int get_height();
  void clear();
  void draw();
 private:
  Cairo::RefPtr<Cairo::ImageSurface> surface;
  Cairo::RefPtr<Cairo::Context> g;
};

#endif
