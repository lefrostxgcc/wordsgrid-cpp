#include <gtkmm.h>
#include "frame.h"

Frame::Frame(const Glib::ustring &caption)
{
  set_title("Words in Boxes");
  set_default_size(600, 400);
  set_resizable(false);
  set_position(Gtk::WIN_POS_CENTER);
  show_all_children();
}
