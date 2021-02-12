#include "graph.h"

// std::string num_direction;


Graph::Graph(int num_v)
{ 
    V vect;
    for (int i=0; i<num_v; i++ ){
        verts.push_back(vect);
    }
}

bool Graph::inNeighbors(V vertice_obj, int vertice){
    for( int i=0; i <vertice_obj.mNeighbors.size(); i++){
        if( vertice == vertice_obj.mNeighbors[i] ) {
            return true;
        }
    }
    return false;
}

void Graph::insert( std::vector<int> &arr, int value)
{
    int low = 0;
    int high = (int)(arr.size() - 1);
    int mid = low+(high - low)/2;
    int indexToInsert = -1;
    while(low<=high)
    {
        if(mid < 0 || mid > arr.size()-1)
            break;
        if(value < arr[mid])
        {
            //check if previous index is valid and lesser than value
            if(mid-1 >= 0)
            {
                if(arr[mid-1]<value)
                {
                    indexToInsert = mid;
                    break;
                }
            }
            high = mid - 1;
        }
        else if(value > arr[mid])
        {
            //check if next index is valid and greater than value
            if(mid+1 < arr.size())
            {
                if(arr[mid+1]>value)
                {
                    indexToInsert = mid+1;
                    break;
                }
            }
            low = mid + 1;
        }
        mid = low+(high - low)/2;
    }
    if(indexToInsert == -1)
    {
        if(mid<=0)
            indexToInsert = 0;
        else if (mid>=arr.size())
            indexToInsert = (int)(arr.size());
    }

    arr.insert(arr.begin() + indexToInsert, value);
}

bool Graph::add_Edge(int v1, int v2)
{
    if ( inNeighbors(verts[v1-1], v2) == false) {
        insert(verts[v1-1].mNeighbors, v2);
        // verts[v1].mNeighbors.push_back(v2);
    }
    else {
        return false;
    }
    if ( inNeighbors(verts[v2-1], v1) == false) {
        // verts[v2].mNeighbors.push_back(v1);
        insert(verts[v2-1].mNeighbors, v1);
    }
    else {
        return false;
    }
    return true;
}

V Graph::get_Neighbors(int v)
{
    return verts[v-1];
}

void Graph::explore( V &v, int &start, int &cc) {
    v.visited_vert();
    v.previsit(start);
    v.setcc(cc);
    for( int i=0; i<v.mNeighbors.size(); i++){
        if ( verts[v.mNeighbors[i]-1].visited == false ) {
            explore(verts[v.mNeighbors[i]-1], start+=1, cc);
        }
    }
    v.postvisit(start+=1);
}

void Graph::dfs() {
    int start = 0;
    int cc = 0;
    for( int i=0; i<verts.size(); i++) {
        if ( verts[i].visited == false ) {
            explore(verts[i], start+=1, cc+=1); 
        }
    }
}