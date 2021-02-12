#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "graph.h"

int main(int argc, char **argv)
{
    std::ifstream file("graph-1000-4.txt");
    std::string line;
    int num_v;
    // int num_e;

    // std::getline(file, line);
    // num_direction = line;

    // get the number of vertices
    std::getline(file, line);
    num_v = atoi(line.c_str());
    // std::cout << "\nthis is the number of vertices: " << num_v << std::endl;

    // create a graph object
    Graph graph(num_v);

    // get the number of edges
    // std::getline(file, line);
    // num_e = atoi(line.c_str());
    // std::cout << "this is the number of edges: " << num_e << std::endl;

    // get the edge pairs
    while (std::getline(file, line))
    {
        std::stringstream linestream(line);
        std::string data;
        bool result;
        int v1;
        int v2;
        int v3;

        linestream >> v1 >> v2 >> v3;

        result = graph.add_Edge(v1, v2);
        assert(result == true);
        // std::cout << "this is val1: " << val1 << std::endl;
        // std::cout << "this is val2: " << val2 << std::endl;
    }
    // for (int i = 1; i <=num_v; i++)
    // {
    //     V vect;
    //     vect = graph.get_Neighbors(i);
    //     std::cout << "Vertice " << i << " Neighbors: ";
    //     for (int j = 0; j < vect.mNeighbors.size(); j++)
    //     {
    //         int z = vect.mNeighbors[j];
    //         std::cout << z << " ";
    //     }
    //     std::cout << "\n";
    // }
    // std::cout << "\n";
    // int start = 1;
    // graph.explore(graph.verts[0], start);
    // graph.dfs();
    // for ( int i=1; i <= graph.verts.size(); i++ ) {
    //     std::cout << "Vertex: " << i << " Pre: " << graph.verts[i-1].pre << " Post: " << graph.verts[i-1].post << " CC: " << graph.verts[i-1].cc << std::endl; 
    // }
    graph.dfs();
    for ( int i=1; i <= graph.verts.size(); i++ ) {
        std::cout << i << " " << graph.verts[i-1].pre << " " << graph.verts[i-1].post << " " << graph.verts[i-1].cc << std::endl; 
    }
}