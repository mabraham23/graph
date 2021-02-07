#include "graph.h"

std::string num_direction;

Graph::Graph(int num_v)
{
    std::vector<int> vect;
    for (int i = 0; i < num_v; i++)
    {
        mNeighbors.push_back(vect);
    }
}

bool Graph::add_Edge(int v1, int v2)
{
    if (num_direction == "one")
    {
        for (int i = 0; i < mNeighbors[v1].size(); i++)
        {
            if (v2 == mNeighbors[v1][i])
            {
                return false;
            }
        }
        mNeighbors[v1].push_back(v2);
        return true;
    }
    else if (num_direction == "two")
    {
        for (int i = 0; i < mNeighbors[v1].size(); i++)
        {
            if (v2 == mNeighbors[v1][i])
            {
                return false;
            }
        }
        for (int i = 0; i < mNeighbors[v2].size(); i++)
        {
            if (v1 == mNeighbors[v2][i])
            {
                return false;
            }
        }
        mNeighbors[v1].push_back(v2);
        mNeighbors[v2].push_back(v1);
        return true;
    }
    return false;
}

std::vector<int> Graph::get_Neighbors(int v)
{
    return mNeighbors[v];
}