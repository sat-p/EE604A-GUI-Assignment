#include "../include/UI_DrawImageBox.h"

// #include "../../tools/include/convert.h"
// 
// #include <opencv2/imgproc/imgproc.hpp>

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
            
            int x = Fl::event_x();
            int y = Fl::event_y();
            
            if (x >= wBox->x() && x <= wBox->x() + wBox->w() &&
                y >= wBox->y() && y <= wBox->y() + wBox->h()) {
                
                _coordinates.emplace (x, y);
            
                std::cerr << "The coordinates are : " << x << ' ' << y
                          << std::endl;
            }
            
            return 1;
        }
    }
    
    return ret;
}

/*****************************************************************************/
/*****************************************************************************/