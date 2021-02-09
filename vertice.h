#include <vector>

class V
{
public:
    std::vector <int> mNeighbors;
    bool visited;
    int pre;
    int post;
    V();
    void visited_vert();
    void previsit( int num );
    void postvisit( int num );
};