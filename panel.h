#ifndef CHIP_PANEL_H
#define CHIP_PANEL_H

#include <gtkmm/drawingarea.h>

class Panel : public Gtk::DrawingArea {
 public:
  Panel();
  virtual ~Panel() = default;
 protected:
  bool on_draw(const Cairo::RefPtr<Cairo::Context> &cr) override;
};

#endif
