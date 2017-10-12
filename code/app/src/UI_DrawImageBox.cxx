#include "../include/UI_DrawImageBox.h"
#include "../../tools/include/convert.h"

#include <iostream>

/*****************************************************************************/

typedef EE604A::GUI::UI_DrawImageBox UI_DrawImageBox;

/*****************************************************************************/

/*
 * Developed with help from http://seriss.com/people/erco/fltk/
 */
int UI_DrawImageBox::handle (int event)
{
    int ret = UI_ImageBox::handle (event);
    switch (event) {
        case FL_PUSH: 
        case FL_DRAG: if (Fl::event_button() ==  1) {
            
            int x = Fl::event_x() - wBox->x();
            int y = Fl::event_y() - wBox->y();
            
            if (x >= 0 && x <= wBox->w() &&
                y >= 0 && y <= wBox->h()) {
                
                _coordinates.emplace (x, y);
                
                _shown.at<cv::Vec3b> (cv::Point (x, y)) = cv::Vec3b (0, 0, 0);                    
                _image.reset (EE604A::tools::Mat_to_Fl_Image (_shown));
    
                wBox->image (_image.get());
                wBox->redraw();
            }
            
            return 1;
        }
    }
    
    return ret;
}

/*****************************************************************************/
/*****************************************************************************/