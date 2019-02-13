#include "frame.h"

Frame::Frame(const Glib::ustring &caption)
{
  set_title(caption);
  add(panel);
  set_resizable(false);
  set_position(Gtk::WIN_POS_CENTER);
  show_all_children();
}
