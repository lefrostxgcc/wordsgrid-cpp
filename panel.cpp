#include "panel.h"

Panel::Panel() :
  picture(12, 40)
{
  set_size_request(picture.get_width(), picture.get_height());
}

bool Panel::on_draw(const Cairo::RefPtr<Cairo::Context> &cr)
{
  cr->set_source(picture.get_surface(), 0, 0);
  cr->paint();
  return true;
}
