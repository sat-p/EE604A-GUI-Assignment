#include "../include/UI_MainWindow.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "FL/Fl_File_Chooser.H"

/*****************************************************************************/

typedef EE604A::GUI::UI_MainWindow UI_MainWindow;

/*****************************************************************************/

void UI_MainWindow::WOpen_cb (void)
{
    const char* filename = fl_file_chooser ("Choose an Image file",
                                            "Image Files (*.{jpg, bmp, png})",
                                            "", // default
                                            0); // absolute path
    
    cv::Mat image = cv::imread (filename, cv::IMREAD_COLOR);
    
//     cv::namedWindow ("Display window",
//                      cv::WINDOW_AUTOSIZE);// Create a window for display.
//     cv::imshow ("Display window", image);
//     
//     cv::waitKey(0);
}

void UI_MainWindow::WQuit_cb (void)
{}

/*****************************************************************************/
/*****************************************************************************/