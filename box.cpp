#include "box.h"

Box::Box(const Cairo::RefPtr<Cairo::Context> &graphics) :
  g(graphics),
  font(Cairo::ToyFontFace::create("Liberation Serif",
				  Cairo::FONT_SLANT_NORMAL,
				  Cairo::FONT_WEIGHT_NORMAL))
{
}

void Box::draw(const Glib::ustring &letter, int x, int y, int sx, int sy)
{
  g->save();
  g->set_source_rgba(0.0, 0.0, 0.0, 1.0);
  sx--;
  sy--;
  g->set_line_width(0.5);
  g->rectangle(x, y, sx, sy);
  g->stroke();
  g->set_font_face(font);
  g->set_font_size(20);
  Cairo::TextExtents ex;
  g->get_text_extents(letter, ex);
  double letter_x = x + 1 + (sx - 2 - ex.width) / 2 - ex.x_bearing;
  double letter_y = y + 1 + (sy - 2 - ex.height) / 2 - ex.y_bearing;
  g->set_source_rgba(1.0, 0.0, 0.0, 1.0);
  g->move_to(letter_x, letter_y);
  g->show_text(letter);
  g->stroke();
  g->restore();
}
