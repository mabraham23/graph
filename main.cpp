#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "graph.h"

int main()
{
    std::ifstream file("three_two_b.txt");
    std::string line;
    int num_v;
    int num_e;

    std::getline(file, line);
    num_direction = line;

    // get the number of vertices
    std::getline(file, line);
    num_v = atoi(line.c_str());
    // std::cout << "\nthis is the number of vertices: " << num_v << std::endl;

    // create a graph object
    Graph graph(num_v);

    // get the number of edges
    std::getline(file, line);
    num_e = atoi(line.c_str());
    // std::cout << "this is the number of edges: " << num_e << std::endl;

    // get the edge pairs
    while (std::getline(file, line))
    {
        std::stringstream linestream(line);
        std::string data;
        bool result;
        int v1;
        int v2;

        linestream >> v1 >> v2;

        result = graph.add_Edge(v1, v2);
        // assert(result == true);
        // std::cout << "this is val1: " << val1 << std::endl;
        // std::cout << "this is val2: " << val2 << std::endl;
    }
    std::string a[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i"};
    for (int i = 0; i < num_v; i++)
    {
        std::vector<int> vect;
        vect = graph.get_Neighbors(i);
        std::cout << "The neighbors for vertice " << a[i] << " are: ";
        for (int j = 0; j < vect.size(); j++)
        {
            int z = vect[j];
            std::cout << a[z] << " ";
        }
        std::cout << "\n";
    }
}