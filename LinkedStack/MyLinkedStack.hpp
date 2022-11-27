#include <iostream>

using namespace std;

template <typename T>
struct Node{
    T data;
    Node<T> *nextNode;
};

template <typename T>
class MyLinkedStack{
    private:
        Node<T> *topNode;
        int size;

    public:
        MyLinkedStack():topNode{nullptr}, size{0}{};
        ~MyLinkedStack(){};

        bool isEmpty();
        void push(T data);
        T pop();
        T getTop();
        int getSize();
        void show();
};

template <typename T>
bool MyLinkedStack<T>::isEmpty(){
    if(topNode == nullptr){
        return true;
    }
    else{
        return false;
    }
};

template <typename T>
void MyLinkedStack<T>::push(T data){
    Node<T> *newNode = new Node<T>;
    newNode->data = data;
    size++;

    if(isEmpty()){
        newNode->nextNode = nullptr;
        topNode = newNode;
    }
    else{
        newNode->nextNode = topNode;
        topNode = newNode;
    }

};

template <typename T>
T MyLinkedStack<T>::pop(){
    if(isEmpty()){
        cout << "Empty Stack" << endl;
    }
    else{
        T targetData = topNode->data;
        Node<T> *targetNode = topNode;

        topNode = topNode->nextNode;

        size--;

        delete targetNode;

        return targetData;
    }
};

template <typename T>
T MyLinkedStack<T>::getTop(){
    if(isEmpty()){
        cout << "Empty Stack" << endl;
    }
    else{
        cout << "getTop -> " << topNode->data << endl;
        return topNode->data;
    }
};

template <typename T>
int MyLinkedStack<T>::getSize(){
    return size;
};

template <typename T>
void MyLinkedStack<T>::show(){
    Node<T> *targetNode = topNode;

    cout << "top -> [";
    while(targetNode != nullptr){
        cout << targetNode->data << ",";
        targetNode = targetNode->nextNode;
    }
    cout << "] <- bottom  /  size = " << size << endl;
};

