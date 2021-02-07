#ifndef GRAPH
#define GRAPH

#include "stdlib.h"
#include <string>
#include <vector>

extern std::string num_direction;
class Graph
{
public:
    Graph(int num_v);
    bool add_Edge(int v1, int v2);
    bool is_Edge(int v1, int v2);
    std::vector<int> get_Neighbors(int v);

private:
    std::vector<std::vector<int> > mNeighbors;
};

#endif // GRAPH