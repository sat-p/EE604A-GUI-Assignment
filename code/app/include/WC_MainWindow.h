// generated by Fast Light User Interface Designer (fluid) version 1.0303

#ifndef WC_MainWindow_h
#define WC_MainWindow_h
#include <FL/Fl.H>
#undef WC_MainWindow_h
#include "UI_ImageBox.h"
namespace EE604A {namespace GUI {class WC_MainWindow;}}; 
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Menu_Bar.H>

class EE604A::GUI::WC_MainWindow : public Fl_Double_Window {
  void _WC_MainWindow();
public:
  WC_MainWindow(int X, int Y, int W, int H, const char *L = 0);
  WC_MainWindow(int W, int H, const char *L = 0);
  WC_MainWindow();
  static Fl_Menu_Item menu_[];
private:
  inline void cb_Open_i(Fl_Menu_*, void*);
  static void cb_Open(Fl_Menu_*, void*);
  inline void cb_Quit_i(Fl_Menu_*, void*);
  static void cb_Quit(Fl_Menu_*, void*);
  inline void cb_Option_i(Fl_Menu_*, void*);
  static void cb_Option(Fl_Menu_*, void*);
  inline void cb_Option1_i(Fl_Menu_*, void*);
  static void cb_Option1(Fl_Menu_*, void*);
public:
  UI_ImageBox *wImageBox1;
  UI_ImageBox *wImageBox2;
private:
  virtual void WOpen_cb (void) {}; 
  virtual void WQuit_cb (void) {}; 
  virtual void WAutoenhance_cb (void) {}; 
  virtual void WRemoval_cb (void) {}; 
};
#endif
