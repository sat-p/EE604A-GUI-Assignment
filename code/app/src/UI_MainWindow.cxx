#include "../include/UI_MainWindow.h"
#include "../../tools/include/slic.h"

#include <opencv2/highgui/highgui.hpp>

#include <FL/Fl_File_Chooser.H>

#include <iostream>

/*****************************************************************************/

typedef EE604A::GUI::UI_MainWindow UI_MainWindow;

/*****************************************************************************/

void UI_MainWindow::WOpen_cb (void)
{
    const char* filename = fl_file_chooser ("Choose an Image file",
                                            "JPEG Files (*.jpg)\t"
                                            "BMP Files (*.bmp)\t"
                                            "PNG Files (*.png)",
                                            "", // default
                                            0); // absolute path
    
    wImageBox1->image (cv::imread (filename, cv::IMREAD_COLOR));
}

void UI_MainWindow::WQuit_cb (void)
{ exit(0); }

/*****************************************************************************/

void UI_MainWindow::WRemoval_cb (void)
{
    auto result = EE604A::tools::slic (wImageBox1->image());
    wImageBox2->image (result);
}


/*****************************************************************************/
/*****************************************************************************/