#ifndef CHIP_BOX_H
#define CHIP_BOX_H

#include <glibmm/ustring.h>
#include <cairomm/context.h>
#include <cairomm/surface.h>

class Box {
 public:
  explicit Box(const Cairo::RefPtr<Cairo::Context> &graphics);
  ~Box() = default;
  void draw(const Glib::ustring &letter, int x, int y, int sx, int sy);
 private:
  Cairo::RefPtr<Cairo::Context> g;
  Cairo::RefPtr<Cairo::ToyFontFace> font;
};

#endif
