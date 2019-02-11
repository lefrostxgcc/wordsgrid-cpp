#include <gtkmm.h>
#include "frame.h"

int main(int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv,
				      "info.videosharp.chip.wordsgridpp");
  Frame frame{"Words in Boxes"};
  return app->run(frame);
}
