#include "picture.h"

Picture::Picture() :
  surface(Cairo::ImageSurface::create(Cairo::FORMAT_ARGB32, 600, 400)),
  g(Cairo::Context::create(surface))
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
  g->set_source_rgba(0.0, 1.0, 1.0, 1.0);
  g->paint();
  g->restore();
}

void Picture::draw()
{
  g->save();
  g->move_to(200, 100);
  g->set_source_rgba(1.0, 0.0, 0.0, 1.0);
  g->show_text("VIDEOJAVA.INFO");
  g->restore();
}

int Picture::get_width()
{
  return surface->get_width();
}

int Picture::get_height()
{
  return surface->get_height();
}
