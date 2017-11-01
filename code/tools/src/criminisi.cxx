#include "../include/criminisi.h"

#include <opencv2/imgproc/imgproc.hpp>

/*****************************************************************************/

/*
 * Written by using
 * https://github.com/sat-p/Exempler-Inpainting/blob/master/test.cxx as a
 * reference
 */

cv::Mat EE604A::tools::criminisi (const cv::Mat& img, const cv::Mat& mask)
{
    cv::Mat lab_img;
    cv::cvtColor (img, lab_img, CV_BGR2Lab);
    
    Criminisi criminisi (lab_img, 5);
    
    criminisi.mask (mask);
    const auto& res_lab = criminisi.generate();
    cv::Mat res;
    
    cv::cvtColor (res_lab, res, CV_Lab2BGR);
    return res;
}

/*****************************************************************************/
/*****************************************************************************/