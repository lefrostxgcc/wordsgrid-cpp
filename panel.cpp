#include "panel.h"

Panel::Panel()
{
  set_size_request(600, 400);
}

bool Panel::on_draw(const Cairo::RefPtr<Cairo::Context> &cr)
{
  cr->move_to(200, 150);
  cr->show_text("ABC");
  return true;
}
