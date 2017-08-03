// generated by Fast Light User Interface Designer (fluid) version 1.0303

#include "../include/WC_MainWindow.h"

void EE604A::GUI::WC_MainWindow::cb_Open_i(Fl_Menu_*, void*) {
  WOpen_cb();
}
void EE604A::GUI::WC_MainWindow::cb_Open(Fl_Menu_* o, void* v) {
  ((EE604A::GUI::WC_MainWindow*)(o->parent()))->cb_Open_i(o,v);
}

void EE604A::GUI::WC_MainWindow::cb_Quit_i(Fl_Menu_*, void*) {
  WQuit_cb();
}
void EE604A::GUI::WC_MainWindow::cb_Quit(Fl_Menu_* o, void* v) {
  ((EE604A::GUI::WC_MainWindow*)(o->parent()))->cb_Quit_i(o,v);
}

Fl_Menu_Item EE604A::GUI::WC_MainWindow::menu_[] = {
 {"&File", 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 0},
 {"&Open", 0,  (Fl_Callback*)EE604A::GUI::WC_MainWindow::cb_Open, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {"&Quit", 0,  (Fl_Callback*)EE604A::GUI::WC_MainWindow::cb_Quit, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},
 {"&Tools", 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0}
};
EE604A::GUI::WC_MainWindow::WC_MainWindow(int X, int Y, int W, int H, const char *L)
  : Fl_Double_Window(X, Y, W, H, L) {
  _WC_MainWindow();
}

EE604A::GUI::WC_MainWindow::WC_MainWindow(int W, int H, const char *L)
  : Fl_Double_Window(0, 0, W, H, L) {
  clear_flag(16);
  _WC_MainWindow();
}

EE604A::GUI::WC_MainWindow::WC_MainWindow()
  : Fl_Double_Window(0, 0, 800, 600, "EE604A : Assignment [14610]") {
  clear_flag(16);
  _WC_MainWindow();
}

void EE604A::GUI::WC_MainWindow::_WC_MainWindow() {
this->box(FL_FLAT_BOX);
this->color(FL_BACKGROUND_COLOR);
this->selection_color(FL_BACKGROUND_COLOR);
this->labeltype(FL_NO_LABEL);
this->labelfont(0);
this->labelsize(14);
this->labelcolor(FL_FOREGROUND_COLOR);
this->align(Fl_Align(FL_ALIGN_TOP));
this->when(FL_WHEN_RELEASE);
{ Fl_Menu_Bar* o = new Fl_Menu_Bar(0, 0, 800, 25);
  o->menu(menu_);
} // Fl_Menu_Bar* o
{ wImageBox1 = new Fl_Box(25, 50, 360, 270);
} // Fl_Box* wImageBox1
{ wImageBox2 = new Fl_Box(415, 50, 360, 270);
} // Fl_Box* wImageBox2
end();
resizable(this);
}
