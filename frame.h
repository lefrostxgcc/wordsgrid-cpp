#ifndef CHIP_FRAME_H
#define CHIP_FRAME_H

#include <gtkmm.h>

class Frame : public Gtk::Window
{
 public:
  explicit Frame(const Glib::ustring &caption);
};

#endif
