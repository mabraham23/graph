#include "vertice.h"

V::V(){
    visited = false;
}

void V::visited_vert(){
    visited = true;
}

void V::previsit( int num ){
    pre = num;
}

void V::postvisit( int num ){
    post = num;
}

void V::setcc( int num ){
    cc = num;
}