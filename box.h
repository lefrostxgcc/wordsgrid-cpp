#ifndef CHIP_BOX_H
#define CHIP_BOX_H

#include <glibmm/ustring.h>
#include <cairomm/context.h>
#include <cairomm/surface.h>

class Box {
 public:
  explicit Box(const Cairo::RefPtr<Cairo::Context> &graphics, int D);
  ~Box() = default;
  void draw(const Glib::ustring &letter, bool hint, int x, int y);
 private:
  Cairo::RefPtr<Cairo::Context> g;
  Cairo::RefPtr<Cairo::ToyFontFace> font;
  int D;
};

#endif
