#include <iostream>

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
    private:
        vertex<T> *vertices;
        int vertexCount;

    public:
        MyGraph():vertices{NULL},vertexCount{0}{};
        ~MyGraph(){};

        vertex<T>* createVertex(T dataParam);
        void addVertex(vertex<T> *vertexParam);
        void addEdge(vertex<T> *fromVertex, vertex<T> *toVertex);
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
};


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
}
