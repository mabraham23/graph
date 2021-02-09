#include "graph.h"

std::string num_direction;


Graph::Graph(int num_v)
{ 
    V vect;
    for (int i=0; i<num_v; i++ ){
        verts.push_back(vect);
    }
}

bool Graph::add_Edge(int v1, int v2)
{
    if (num_direction == "one")
    {
        for (int i = 0; i < verts[v1].mNeighbors.size(); i++)
        {
            if (v2 == verts[v1].mNeighbors[i])
            {
                return false;
            }
        }
        verts[v1].mNeighbors.push_back(v2);
        return true;
    }
    else if (num_direction == "two")
    {
        for (int i = 0; i < verts[v1].mNeighbors.size(); i++)
        {
            if (v2 == verts[v1].mNeighbors[i])
            {
                return false;
            }
        }
        for (int i = 0; i < verts[v2].mNeighbors.size(); i++)
        {
            if (v1 == verts[v2].mNeighbors[i])
            {
                return false;
            }
        }
        verts[v1].mNeighbors.push_back(v2);
        verts[v2].mNeighbors.push_back(v1);
        return true;
    }
    return false;
}

V Graph::get_Neighbors(int v)
{
    return verts[v];
}

void Graph::explore( V &v, int &start) {
    v.visited_vert();
    v.previsit(start);
    for( int i=0; i<v.mNeighbors.size(); i++){
        if ( verts[v.mNeighbors[i]].visited == false ) {
            explore(verts[v.mNeighbors[i]], start+=1 );
        }
    }
    v.postvisit(start+=1);
}

void Graph::dfs() {
    for( int i=0; i<verts.size(); i++) {
        if ( verts[i].visited == false ) {
            int start = 1;
            explore(verts[i], start); 
        }
    }
}