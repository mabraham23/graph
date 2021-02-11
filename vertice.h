#include <vector>

class V
{
public:
    std::vector <int> mNeighbors;
    bool visited;
    int pre;
    int post;
    int cc;
    V();
    void visited_vert();
    void previsit( int num );
    void postvisit( int num );
    void setcc( int num );
};