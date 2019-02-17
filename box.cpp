#include "box.h"

Box::Box(const Cairo::RefPtr<Cairo::Context> &graphics, int D_arg) :
  g(graphics),
  font(Cairo::ToyFontFace::create("Liberation Serif",
                                  Cairo::FONT_SLANT_NORMAL,
                                  Cairo::FONT_WEIGHT_NORMAL)),
  D{D_arg}
{
}

void Box::draw(const Glib::ustring &letter, int x, int y)
{
  g->save();
  g->set_source_rgba(0.0, 0.0, 0.0, 1.0);
  g->set_line_width(0.5);
  g->rectangle(x, y, D, D);
  g->stroke();
  g->set_font_face(font);
  g->set_font_size(D / 2);
  Cairo::TextExtents ex;
  g->get_text_extents(letter, ex);
  double letter_x = x + 1 + (D - 2 - ex.width) / 2 - ex.x_bearing;
  double letter_y = y + 1 + (D - 2 - ex.height) / 2 - ex.y_bearing;
  g->set_source_rgba(1.0, 0.0, 0.0, 1.0);
  g->move_to(letter_x, letter_y);
  g->show_text(letter);
  g->stroke();
  g->restore();
}
