#include <iostream>

using namespace std;

template <typename T>
struct Node{
    T data;
    Node<T> *nextNode;
};

template <typename T>
class MySinglyLinkedList{
    Node<T> *head;
    Node<T> *tail;
    int size = 0; 

public:
    MySinglyLinkedList(): head{nullptr}, tail{nullptr}{};

    ~MySinglyLinkedList(){};

    void add(T addData){

        Node<T> *newNode = new Node<T>;
        
        newNode->data = addData;
        newNode->nextNode = nullptr;
        size++;

        if(head == nullptr){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->nextNode = newNode;
            tail = tail->nextNode;
        }
    }

    void add(T addData, int index){
        Node<T> *preNode = head;
        Node<T> *postNode = head->nextNode;

        Node<T> *newNode = new Node<T>;
        
        newNode->data = addData;
        size++;

        if(index == 0){
            newNode->nextNode = head;
            head = newNode;
        }
        else if(index == size){
            newNode->nextNode = nullptr;
            tail->nextNode = newNode;
            tail = tail->nextNode;
        }
        else{
            for(int i=0; i<index-1; i++){
                preNode = preNode->nextNode;
                postNode = preNode->nextNode;
            }

            preNode->nextNode = newNode;
            newNode->nextNode = postNode;
        }

        cout<< "preData : " << preNode->data << endl;
        cout<< "postData : " << postNode->data << endl;

    };

    void addFirst(T newData){
        Node<T> *newNode = new Node<T>;

        newNode->data = newData;
        size++;
        
        newNode->nextNode = head;
        head = newNode;
    }

    void show(){
        Node<T> *node = head;

        cout << "[";
        while(node != nullptr){
            cout << node->data << ",";
            node = node->nextNode;
        } 
        cout << "]" << endl;
        cout << "headData => " << head->data << endl;
        cout << "tailData => " << tail->data << endl;
    }


};