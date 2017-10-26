#include "../include/slic.h"
#include "../../algos/include/slicGC.h"

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
    
    EE604A::algos::SlicGC slic;
    slic.generate_superpixels (lab_img, step, NC);
//     slic.create_connectivity (lab_img);
    
    slic.display_contours (lab_img, cv::Vec3b (0, 0, 255)); // color in BGR format
    slic.create_graph();
    slic.colour_graph (lab_img);
    
    cv::Mat res;
    cv::cvtColor (lab_img, res, CV_Lab2BGR);
    
    return res;
}

/*****************************************************************************/
/*****************************************************************************/