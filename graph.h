#ifndef GRAPH
#define GRAPH

#include "stdlib.h"
#include "vertice.h"
#include <string>
#include <vector>

extern std::string num_direction;

class Graph
{
public:
    Graph(int num_v);
    bool add_Edge(int v1, int v2);
    bool is_Edge(int v1, int v2);
    V get_Neighbors(int v);
    void explore( V &v, int &start, int &cc);
    void dfs();
    bool inNeighbors( V vertice_object, int vertice);
    std::vector <V> verts;
    void insert( std::vector<int> &arr, int value);
};

#endif // GRAPH