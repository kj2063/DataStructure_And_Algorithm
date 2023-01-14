#include <iostream>

using namespace std;

template <typename T>
struct Node{
    T *data;
    Node<T> *nextNode;
    Node(T *dataParam):data{dataParam},nextNode{nullptr}{};
    ~Node(){};
};

template <typename T>
class MyLinkedQueue{
    private:
        Node<T> *front;
        Node<T> *rear; 
        int size;

    public:
        MyLinkedQueue():front{nullptr}, rear{nullptr}, size{0}{};
        ~MyLinkedQueue(){};
        
        bool isEmpty();
        void enQueue(T *data);
        T* deQueue();
        T* getFront();
        int getSize();
        void show();
};

template <typename T>
bool MyLinkedQueue<T>::isEmpty(){
    if(front == nullptr){
        return true;
    }
    else{
        return false;
    }
};

template <typename T>
void MyLinkedQueue<T>::enQueue(T *data){
    Node<T> *newNode = new Node<T>(data);
    size++;
    
    if(isEmpty()){
        front = newNode;
        rear = newNode;
    }
    else{
        rear->nextNode = newNode;
        rear = newNode;
    }
};

template <typename T>
T* MyLinkedQueue<T>::deQueue(){
    if(isEmpty()){
        cout << "Empty Queue" << endl;
        return nullptr;
    }
    else{
        T *resData = front->data;
        Node<T> *preFrontNode = front;

        front = front->nextNode;
        size--;

        delete preFrontNode;

        return resData;
    }
};

template <typename T>
T* MyLinkedQueue<T>::getFront(){
    if(isEmpty()){
        cout << "Empty Queue" << endl;
        return nullptr;
    }
    else{
        cout << "getFront -> " << front->data << endl;
        return front->data;
    }
};

template <typename T>
int MyLinkedQueue<T>::getSize(){
    return size;
};

template <typename T>
void MyLinkedQueue<T>::show(){
    Node<T> *targetNode = front;

    cout << "front -> [";
    while(targetNode != nullptr){
        cout << targetNode->data << ",";
        targetNode = targetNode->nextNode;
    }
    cout << "] <- rear  /  size = " << size << endl;
};