#include "MyGraph.hpp"

int main(){
    MyGraph<char> myGraph;
    vertex<char> *v1 = myGraph.createVertex('A');
    vertex<char> *v2 = myGraph.createVertex('B');
    vertex<char> *v3 = myGraph.createVertex('C');
    vertex<char> *v4 = myGraph.createVertex('D');
    vertex<char> *v5 = myGraph.createVertex('E');
    vertex<char> *v6 = myGraph.createVertex('F');
    vertex<char> *v7 = myGraph.createVertex('G');

    myGraph.addVertex(v1);
    myGraph.addVertex(v2);
    myGraph.addVertex(v3);
    myGraph.addVertex(v4);
    myGraph.addVertex(v5);
    myGraph.addVertex(v6);
    myGraph.addVertex(v7);


    myGraph.addEdge(v1,v2);
    myGraph.addEdge(v1,v4);
    myGraph.addEdge(v2,v3);
    myGraph.addEdge(v2,v5);
    myGraph.addEdge(v4,v5);
    myGraph.addEdge(v4,v7);
    myGraph.addEdge(v7,v6);
    myGraph.addEdge(v7,v5);
    myGraph.addEdge(v5,v1);
    myGraph.addEdge(v5,v3);
    myGraph.addEdge(v3,v6);
    myGraph.addEdge(v6,v5);
    
    myGraph.showAll();
    // myGraph.DFS(myGraph.vertices);
    myGraph.BFS();

    return 0;
}