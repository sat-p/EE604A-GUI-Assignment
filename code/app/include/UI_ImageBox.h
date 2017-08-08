#ifndef __EE604A_GUI_UI_IMAGE_BOX_H__
#define __EE604A_GUI_UI_IMAGE_BOX_H__

#include "WC_ImageBox.h"

#include <memory>

#include <opencv2/core/core.hpp>

#include <Fl/Fl_Image.H>

/*****************************************************************************/

namespace EE604A {
namespace GUI {

class UI_ImageBox : public WC_ImageBox
{
public:
    UI_ImageBox(int X, int Y, int W, int H, const char *L = 0) :
        WC_ImageBox (X, Y, W, H, L)
    {}

public:
    void image (const cv::Mat& mat);
    void image (cv::Mat&& mat);    

private:
    void scale (void);
    
private:
    std::unique_ptr<Fl_RGB_Image> _image;
    cv::Mat _orig;
    cv::Mat _resize;
};

}} // namespaces EE604A, GUI

/*****************************************************************************/
/*****************************************************************************/

#endif