#ifndef CHIP_FRAME_H
#define CHIP_FRAME_H

#include <gtkmm/window.h>
#include "panel.h"

class Frame : public Gtk::Window
{
 public:
  explicit Frame(const Glib::ustring &caption);
private:
  Panel panel;
};

#endif
