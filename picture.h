#ifndef CHIP_PICTURE_H
#define CHIP_PICTURE_H

#include <cairomm/context.h>
#include <cairomm/surface.h>
#include <glibmm/random.h>
#include <vector>
#include "box.h"

class Picture {
public:
  Picture(int N, int D);
  ~Picture() = default;
  Cairo::RefPtr<Cairo::Surface> get_surface();
  int get_width();
  int get_height();
  void clear();
  void init();
  void draw();
private:
  Glib::ustring get_random_letter();
  Cairo::RefPtr<Cairo::ImageSurface> surface;
  Cairo::RefPtr<Cairo::Context> g;
  std::vector<std::vector<Box>> box;
  static const Glib::ustring abc;
  static Glib::Rand random;
  int N;
  int D;
};

#endif
