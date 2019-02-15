#include "picture.h"

Picture::Picture() :
  surface(Cairo::ImageSurface::create(Cairo::FORMAT_ARGB32, 600, 400)),
  g(Cairo::Context::create(surface)),
  box(g)
{
  clear();
  draw();
}

Cairo::RefPtr<Cairo::Surface> Picture::get_surface()
{
  return surface;
}

void Picture::clear()
{
  g->save();
  g->set_source_rgba(1.0, 1.0, 1.0, 1.0);
  g->paint();
  g->restore();
}

void Picture::draw()
{
  box.draw("Q", 50, 80, 40, 40);
  box.draw("I", 50, 120, 40, 40);
}

int Picture::get_width()
{
  return surface->get_width();
}

int Picture::get_height()
{
  return surface->get_height();
}
