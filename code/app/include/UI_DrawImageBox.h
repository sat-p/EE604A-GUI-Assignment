#ifndef __EE604A_GUI_UI_DRAW_IMAGE_BOX_H__
#define __EE604A_GUI_UI_DRAW_IMAGE_BOX_H__

#include "UI_ImageBox.h"

#include <set>
#include <utility>

/*****************************************************************************/

namespace EE604A {
namespace GUI {

class UI_DrawImageBox : public UI_ImageBox
{
public:
    UI_DrawImageBox(int X, int Y, int W, int H, const char *L = 0) :
        UI_ImageBox (X, Y, W, H, L)
    {}

private:
    int handle (int event) override;
    
private:
    std::set<std::pair<int, int>> _coordinates;
};

}} // namespaces EE604A, GUI

/*****************************************************************************/
/*****************************************************************************/

#endif