#include <gtkmm.h>

int main(int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv,
				      "info.videosharp.chip.wordsgridpp");
  Gtk::Window jframe;
  jframe.set_title("Words in Boxes");
  jframe.set_default_size(600, 400);
  jframe.set_resizable(false);
  jframe.set_position(Gtk::WIN_POS_CENTER);
  jframe.show_all_children();
  return app->run(jframe);
}
