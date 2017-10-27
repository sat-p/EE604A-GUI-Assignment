#include "../include/slicGC.h"

#include <cmath>
#include <vector>
#include <iostream>

/*****************************************************************************/

typedef EE604A::algos::SlicGC SlicGC;
constexpr int thresh = 40;

/*****************************************************************************/

void SlicGC::create_graph (void)
{
    if (!contours.size())
        std::cerr << "generate_contours() needs to be called" << std::endl;
    if (!colours.size())
        std::cerr << "generate_cluster_means() needs to be called" << std::endl;
    
    constexpr int N_SIZE = 8;
    
    const int dx[N_SIZE] = {-1, -1,  0,  1, 1, 1, 0, -1};
	const int dy[N_SIZE] = { 0, -1, -1, -1, 0, 1, 1,  1};
    
    if (adjList.size() != centers.size()) {
        
        adjList.clear();
        adjList.resize (centers.size());
    }
    
    for (const cv::Point& p : contours) {
        for (int k = 0; k < N_SIZE; ++k) {
        
            const int x = p.x + dx[k]; const int y = p.y + dy[k];
            if (x >= 0 && x < cols && y >= 0 && y < rows &&
                clusters[p.x][p.y] != clusters[x][y]) {
                    
                const int c1 = clusters[p.x][p.y];
                const int c2 = clusters[x][y];
                
                if (!adjList[c1].count (c2) &&
                    std::sqrt (std::pow (centers[c1][0] - centers[c2][0], 2) +
                               std::pow (centers[c1][1] - centers[c2][1], 2) +
                               std::pow (centers[c1][2] - centers[c2][2], 2))
                    < thresh) {
                    
                    adjList[c1].insert (c2);
                    adjList[c2].insert (c1);
                }
            }
        }
    }
    
    segments.resize (centers.size());
    std::fill (segments.begin(), segments.end(), -1);
    segmentClusters.clear();
    
    for (int i = 0; i < (int) segments.size(); ++i)
        if (segments[i] == -1) {
            segmentClusters.emplace_back();
            dfs (i);
        }
    
    std::cout << "The number of segments is : " << segmentClusters.size() << std::endl;
    
    segmentColour.resize (segmentClusters.size());
    for (auto& cc : segmentColour)
        cc.fill (0);
    
    for (int i = 0; i < (int) segmentClusters.size(); ++i) {
        for (const auto& c : segmentClusters[i]) {
        
            segmentColour[i][0] += colours[c][0];
            segmentColour[i][1] += colours[c][1];
            segmentColour[i][2] += colours[c][2];
        }
        
        segmentColour[i][0] /= segmentClusters[i].size();
        segmentColour[i][1] /= segmentClusters[i].size();
        segmentColour[i][2] /= segmentClusters[i].size();
    }
}

/*****************************************************************************/

void SlicGC::colour_graph (cv::Mat& image)
{
    for (int j = 0; j < image.cols; ++j) {
        for (int k = 0; k < image.rows; ++k) {
            
            const int s_id = segments[clusters[j][k]];
            
            auto& pix = image.at<cv::Vec3b> (k, j);
            
            pix[0] = segmentColour[s_id][0];
            pix[1] = segmentColour[s_id][1];
            pix[2] = segmentColour[s_id][2];
        }
    }
}

/*****************************************************************************/
/*****************************************************************************/

void SlicGC::dfs (int c)
{
    segmentClusters.back().push_back (c);
    segments[c] = segmentClusters.size() - 1;

    for (int d : adjList[c])
        if (segments[d] == -1)
            dfs (d);
}

/*****************************************************************************/
/*****************************************************************************/