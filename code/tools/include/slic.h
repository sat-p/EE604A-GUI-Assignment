#ifndef __EE604A_TOOLS_SLIC_H__
#define __EE604A_TOOLS_SLIC_H__

#include "../../algos/include/slicGC.h"

#include <cmath>
#include <iostream>
#include <string>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

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
    
    if (!connected.size()) {
    
        std::cerr << "No point on input image has been selected" << std::endl;
        return img;
    }
    
    cv::Mat lab_img;
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
        
    const cv::Mat& mask = slic.fetch_mask (connected);
    
    cv::Mat res;
    cv::blur (img, res, cv::Size (100, 100));
    
    img.copyTo (res, mask);
    slic.display_contours (res, cv::Vec3b (0,0,255));
    
    return res;
}

/*****************************************************************************/
    
}} // namespaces EE604A, tools

#endif