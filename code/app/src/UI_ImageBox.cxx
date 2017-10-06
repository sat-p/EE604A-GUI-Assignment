#include "../include/UI_ImageBox.h"

#include "../../tools/include/convert.h"

#include <opencv2/imgproc/imgproc.hpp>

/*****************************************************************************/

typedef EE604A::GUI::UI_ImageBox UI_ImageBox;

/*****************************************************************************/

void UI_ImageBox::image (const cv::Mat& mat)
{
    _orig = mat;
    scale();
}

void UI_ImageBox::image (cv::Mat&& mat)
{
    _orig = mat;
    scale();
}

/*****************************************************************************/
/*****************************************************************************/

void UI_ImageBox::scale (void)
{
    if (_orig.empty())
        return;
    
    const float box_x = wBox->w() - 10;
    const float box_y = wBox->h() - 10;
    
    const float x_scale = box_x / _orig.cols;
    const float y_scale = box_y / _orig.rows;
    
    int x_size, y_size;
    if (x_scale > y_scale) {
    
        y_size = box_y;
        x_size = _orig.cols * y_scale;
    }
    else {
    
        x_size = box_x;
        y_size = _orig.rows * x_scale;
    }
    
    cv::resize (_orig, _resize,
                cv::Size (x_size, y_size));
    
    _image.reset (EE604A::tools::Mat_to_Fl_Image (_resize));
    
    wBox->image (_image.get());
    wBox->redraw();
}

/*****************************************************************************/
/*****************************************************************************/