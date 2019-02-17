#include <gtkmm/application.h>
#include "frame.h"

namespace {

  void save_picture(const Frame &frame)
  {
    frame.panel.picture.surface->write_to_png("words.png");
  }
  
}

int main(int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv,
				      "info.videosharp.chip.wordsgridpp");
  Frame frame{"Words in Boxes"};
  save_picture(frame);
  return app->run(frame);
}
