#ifndef __EE604A_ALGOS_SLIC_GRAPH_CLUSTER__
#define __EE604A_ALGOS_SLIC_GRAPH_CLUSTER__

#include "slic.h"

#include <opencv2/core/core.hpp>
#include <vector>
#include <set>
#include <array>

namespace EE604A {
namespace algos  {

class SlicGC : public Slic
{
public:
    void create_graph (void);
    void colour_graph (cv::Mat& image);

private:
    void dfs (int c);
    
protected:
    std::vector<std::set<int>> adjList;
    std::vector<int> segments;
    std::vector<std::array<double, 3>> segmentColour;
    
private:
    int label;
};

}} //namespace EE604A, ALGOS

#endif