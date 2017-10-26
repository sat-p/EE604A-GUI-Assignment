#include "../include/slic.h"
#include "../../algos/include/slic.h"

#include <cmath>
#include <opencv2/imgproc/imgproc.hpp>

/*****************************************************************************/

constexpr int NR_SUPERPIXELS = 40;
constexpr int NC = 100;

/*****************************************************************************/

/*
 * Written by using
 * https://github.com/sat-p/SLIC-Superpixels/blob/master/test_slic.cpp as a
 * reference
 */

cv::Mat EE604A::tools::slic (const cv::Mat& img)
{
    auto lab_img = img.clone();
    
    cv::cvtColor (img, lab_img, CV_BGR2Lab);
    
    const int w = img.cols;
    const int h = img.rows; 
    
    const double step = std::sqrt (w * h) / NR_SUPERPIXELS;
    
    Slic slic;
    slic.generate_superpixels (lab_img, step, NC);
    slic.create_connectivity (lab_img);
    
    auto res = img.clone();
    slic.display_contours (res, cv::Vec3b (0, 0, 255)); // color in BGR format
    
    return res;
}

/*****************************************************************************/
/*****************************************************************************/