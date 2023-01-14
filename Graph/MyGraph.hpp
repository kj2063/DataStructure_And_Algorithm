#include <iostream>
#include "MyLinkedQueue.hpp"

using namespace std;

enum visitedState {
    noVisited = 0,
    visited = 1
};

template <typename T>
struct edge;

template <typename T>
struct vertex {
    T data;
    visitedState visit = noVisited;
    int index = -1;

    vertex<T> *next = NULL;
    edge<T> *adjacencyList = NULL;
    vertex(T dataParam):data{dataParam}{};
    ~vertex(){};
};

template <typename T>
struct edge {
    int weight = 0;
    edge<T> *next = NULL;
    vertex<T> *from;
    vertex<T> *target;
    edge(vertex<T> *fromVertex, vertex<T> *toVertex):from{fromVertex},target{toVertex}{};
    ~edge(){};
};

template <typename T>
class MyGraph {
    
    public:
        vertex<T> *vertices;
        int vertexCount;

        MyGraph():vertices{NULL},vertexCount{0}{};
        ~MyGraph(){};

        vertex<T>* createVertex(T dataParam);
        void addVertex(vertex<T> *vertexParam);
        void addEdge(vertex<T> *fromVertex, vertex<T> *toVertex);
        void DFS(vertex<T> * vertexParam);//depth first search
        void BFS();//breadth first search
        void showAll();
};

template <typename T>
vertex<T>* MyGraph<T>::createVertex(T dataParam){
    return new vertex(dataParam);
};

template <typename T>
void MyGraph<T>::addVertex(vertex<T> *newVertexParam){
    newVertexParam->index = this->vertexCount++;

    vertex<T> *vertexList = this->vertices;
    if(vertexList == NULL){
        this->vertices = newVertexParam;
    }
    else{
        while(vertexList->next != NULL){
            vertexList = vertexList->next;
        }

        vertexList->next = newVertexParam;
    }
};


template <typename T>
void MyGraph<T>::addEdge(vertex<T> *fromVertexParam, vertex<T> *toVertexParam){
    edge<T> *newEdge = new edge(fromVertexParam, toVertexParam);

    if(fromVertexParam->adjacencyList == NULL){
        fromVertexParam->adjacencyList = newEdge;
    }
    else{
        edge<T> *adjacencyList = fromVertexParam->adjacencyList;
        while(adjacencyList->next != NULL){
            adjacencyList = adjacencyList->next;
        }

        adjacencyList->next = newEdge;
    }

    // //In the case of undirected graph, add following code. If not, remove it.
    // edge<T> *newReverseEdge = new edge(toVertexParam, fromVertexParam);

    // if(toVertexParam->adjacencyList == NULL){
    //     toVertexParam->adjacencyList = newReverseEdge;
    // }
    // else{
    //     edge<T> *adjacencyList = toVertexParam->adjacencyList;
    //     while(adjacencyList->next != NULL){
    //         adjacencyList = adjacencyList->next;
    //     }

    //     adjacencyList->next = newReverseEdge;
    // }

};

template <typename T>
void MyGraph<T>::DFS(vertex<T> *targetVertex){

    printf("%c ",targetVertex->data);

    vertex<T> *vertexPtr = targetVertex;

    vertexPtr->visit = visited;

    edge<T> *edgePtr = vertexPtr->adjacencyList;

    while(edgePtr != NULL){
        if(edgePtr->target != NULL && edgePtr->target->visit != visited){
            DFS(edgePtr->target);
        }

        edgePtr = edgePtr->next;
    }
}

template <typename T>
void MyGraph<T>::BFS(){
    MyLinkedQueue<vertex<T>> linkedQueue;

    vertex<T> *vertexPtr = this->vertices;
    
    linkedQueue.enQueue(vertexPtr);
    vertexPtr->visit = visited;

    printf("%c ", vertexPtr->data);

    while(!linkedQueue.isEmpty()){
        vertex<T> *targetVertex = linkedQueue.deQueue();

        edge<T> *edgePtr = targetVertex->adjacencyList;
        
        int cnt = 0;
        while(edgePtr != NULL){
            if(edgePtr->target->visit != visited){
                linkedQueue.enQueue(edgePtr->target);
                edgePtr->target->visit=visited;

                printf("%c ", edgePtr->target->data);
            }

                edgePtr = edgePtr->next;
        }
    }
}

template <typename T>
void MyGraph<T>::showAll(){
    vertex<T> *V = this->vertices;
    edge<T> *E = NULL;

    while(V != NULL){
        printf("%c : ",V->data);

        if((E = V->adjacencyList) == NULL){
            V = V->next;
            printf("\n");
            continue;
        }

        while (E != NULL){
            printf("%c[%d] ", E->target->data, E->weight);
            E = E->next;
        }

        printf("\n");

        V = V->next;
    }

    printf("\n");
};
