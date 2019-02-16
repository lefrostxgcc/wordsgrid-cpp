#include "picture.h"

Glib::Rand Picture::random;
const Glib::ustring Picture::abc{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

Picture::Picture(int N_arg, int D_arg) :
  surface(Cairo::ImageSurface::create(Cairo::FORMAT_ARGB32,
                                      N_arg * D_arg + 1, N_arg * D_arg + 1)),
  g(Cairo::Context::create(surface)),
  N{N_arg},
  D{D_arg}
{
  clear();
  init();
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

void Picture::init()
{
  box.clear();
  for (int row = 0; row < N; row++)
    {
      box.push_back({});
      for (int col = 0; col < N; col++)
        box.back().push_back(Box{g});
    }
}

void Picture::draw()
{
  for (int row = 0; row < N; row++)
    for (int col = 0; col < N; col++)
      box[row][col].draw(get_random_letter(), row * D, col * D, D + 1, D + 1);
}

Glib::ustring Picture::get_random_letter()
{
  auto index = random.get_int_range(0, abc.length());
  return abc.substr(index, 1);
}

int Picture::get_width()
{
  return surface->get_width();
}

int Picture::get_height()
{
  return surface->get_height();
}
