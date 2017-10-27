#ifndef __EE604A_TOOLS_SLIC_H__
#define __EE604A_TOOLS_SLIC_H__

#include "../../algos/include/slicGC.h"

#include <cmath>

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

namespace EE604A {
namespace tools  {
    
/*****************************************************************************/

/*
 * Written by using
 * https://github.com/sat-p/SLIC-Superpixels/blob/master/test_slic.cpp as a
 * reference
 */

template<typename container>
cv::Mat slic (const cv::Mat& img, const container& connected)
{
    constexpr int NR_SUPERPIXELS = 40;
    constexpr int NC = 100;
    
    auto lab_img = img.clone();
    
    cv::cvtColor (img, lab_img, CV_BGR2Lab);
    
    const int w = img.cols;
    const int h = img.rows; 
    
    const double step = std::sqrt (w * h) / NR_SUPERPIXELS;
    
    EE604A::algos::SlicGC slic;
    slic.generate_superpixels (lab_img, step, NC);
    slic.generate_contours();
    slic.generate_cluster_means (lab_img);
    
    slic.create_connections (connected);
    
    slic.create_graph();
    slic.colour_graph (lab_img);
    
    cv::Mat res;
    cv::cvtColor (lab_img, res, CV_Lab2BGR);
    slic.display_contours (res, cv::Vec3b (0, 0, 255));
    
    return res;
}

/*****************************************************************************/
    
}} // namespaces EE604A, tools

#endif