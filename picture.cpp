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
        box.back().push_back(Box{g, D});
    }
}

void Picture::draw()
{
  std::vector<std::vector<int>> map(N);
  for (auto &x : map)
    for (int i = 0; i < N; i++)
      x.push_back({});
  while (true)
    {
      for (int row = 0; row < N; row++)
        for (int col = 0; col < N; col++)
          map[row][col] = -1;
      int row = random.get_int_range(0, N);
      int col = random.get_int_range(0, N);
      int index;
      for (index = 0; index < word.length(); index++)
        {
          if (row < 0 || row >= N || col < 0 || col >= N)
            break;
          if (map[row][col] >= 0)
            break;
          map[row][col] = index;
          switch (random.get_int_range(0, 4))
            {
            case 0: row++; break;
            case 1: row--; break;
            case 2: col++; break;
            case 3: col--; break;
            }
        }
      if (index >= word.length())
        break;
    }
  for (int row = 0; row < N; row++)
    for (int col = 0; col < N; col++)
      {
        Glib::ustring letter;
        bool hint = false;
        if (map[row][col] >= 0)
          {
            letter = word.substr(map[row][col], 1);
            hint = true;
          }
        else
          letter = get_random_letter();
        box[row][col].draw(letter, hint, row * D, col * D);
      }
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
