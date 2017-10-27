#ifndef __EE604A_ALGOS_SLIC_GRAPH_CLUSTER__
#define __EE604A_ALGOS_SLIC_GRAPH_CLUSTER__

#include "slic.h"

#include <opencv2/core/core.hpp>
#include <vector>
#include <set>
#include <array>
#include <iostream>

namespace EE604A {
namespace algos  {

class SlicGC : public Slic
{
public:
    void create_graph (void);
    void colour_graph (cv::Mat& image);
    
    template<typename container>
    void create_connections (const container& connected)
    {
        if (!connected.size()) {
            
            std::cerr << "No point was selected" << std::endl;
            return;
        }
        else if (connected.size() == 1)
            return;
        
        auto it1 = connected.cbegin();
        auto it2 = it1;
        ++it2;
        
        adjList.clear();
        adjList.resize (centers.size());
        
        while (it2 != connected.cend()) {
            
            if (it1->x >= 0 && it1->x < cols && it1->y >= 0 && it1->y < rows &&
                it2->x >= 0 && it2->x < cols && it2->y >= 0 && it2->y < rows) {
                
                const int c1 = clusters[it1->x][it1->y];
                const int c2 = clusters[it2->x][it2->y];
                
                adjList[c1].insert (c2);
                adjList[c2].insert (c1);
            }
            
            ++it1;
            ++it2;
        }
    }
    
private:
    void dfs (int c);
    
protected:
    std::vector<std::set<int>> adjList;
    std::vector<int> segments;
    std::vector<std::array<double, 3>> segmentColour;
    
    std::vector<std::vector<int>> segmentClusters;
};

}} //namespace EE604A, ALGOS

#endif