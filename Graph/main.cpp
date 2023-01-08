#include "MyGraph.hpp"

int main(){
    MyGraph<char> myGraph;
    vertex<char> *v1 = myGraph.createVertex('A');
    vertex<char> *v2 = myGraph.createVertex('B');
    vertex<char> *v3 = myGraph.createVertex('C');
    vertex<char> *v4 = myGraph.createVertex('D');
    myGraph.addVertex(v1);
    myGraph.addVertex(v2);
    myGraph.addVertex(v3);
    myGraph.addVertex(v4);

    myGraph.addEdge(v1,v2);
    myGraph.addEdge(v2,v3);
    myGraph.addEdge(v3,v4);
    myGraph.addEdge(v4,v1);
    myGraph.addEdge(v1,v3);
    
    myGraph.showAll();

    return 0;
}