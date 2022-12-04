#include <stdio.h>
#include <iostream>

using namespace std;

template <typename T>
struct Node{
    int key;
    T data;
    Node<T> *rightNode = nullptr;
    Node<T> *leftNode = nullptr;
};

template <typename T> 
class MyBinarySearchTree {
private:
    Node<T> *root;

public:
    MyBinarySearchTree():root{nullptr}{};
    ~ MyBinarySearchTree(){};

    void AddNode(int Key,T data);
    void removeNode(int Key);
    void searchData(int key);
    void preOrder(Node<T> *cursor);
    void inOrder(Node<T> *cursor);
    void postOrder(Node<T> *cursor);
    void showAll();
}; 

template <typename T>
void MyBinarySearchTree<T>::AddNode(int keyParam,T dataParam){
    Node<T> *newNode = new Node<T>;
    newNode->key = keyParam;
    newNode->data = dataParam;

    Node<T> *cursor = root;
    Node<T> *preCursor = nullptr;

    if(this->root == nullptr){
        this->root = newNode;
    }
    else{
        while(cursor){
            if(cursor->key == keyParam){
                throw invalid_argument(to_string(keyParam) + " is the key that exist");
            }
            else{
                preCursor = cursor;
                if(cursor->key > keyParam){
                    cursor = cursor->leftNode;
                }
                else{
                    cursor = cursor->rightNode;
                }
            }
        }

        if(preCursor->key > keyParam){
            preCursor->leftNode = newNode;
        }
        else{
            preCursor->rightNode = newNode;
        }
    }
}

template <typename T>
void MyBinarySearchTree<T>::searchData(int keyParam){
    Node<T> *cursor = this->root;
    
    while(cursor != nullptr){
        if(cursor->key == keyParam){
            cout << "search Data => " << cursor->data << endl;
            cout << "left : " << cursor->leftNode->data; 
            cout <<  " / " << "right : " << cursor->rightNode->data << endl;
            return;
        }
        else if(cursor->key > keyParam){
                cursor = cursor->leftNode;
        }
        else{
                cursor = cursor->rightNode;
        }
    }

    if(cursor == nullptr){
        cout << "key does not exist" << endl;
    }
}

template <typename T>
void MyBinarySearchTree<T>::removeNode(int keyParam){
    Node<T> *cursor = this->root;
    Node<T> *preCursor = nullptr;
    
    while(cursor != nullptr){
        if(cursor->key == keyParam){
            break;
        }
        else if(cursor->key > keyParam){
            preCursor = cursor;
            cursor = cursor->leftNode;
        }
        else{
            preCursor = cursor;
            cursor = cursor->rightNode;
        }
    }

    if(cursor == nullptr){
        cout << "key does not exist" << endl;
        return;
    }

    if(cursor->leftNode != nullptr && cursor->rightNode != nullptr){
        Node<T> *childCursor = cursor->rightNode;
        Node<T> *childPreCursor = cursor;
        
        while(childCursor->leftNode){
            childPreCursor = childCursor;
            childCursor = childCursor->leftNode;
        }

        childPreCursor->leftNode = childCursor->rightNode;

        cursor->key = childCursor->key;
        cursor->data = childCursor->data;

        delete childCursor;
    }
    else if(cursor->leftNode != nullptr || cursor->rightNode != nullptr){

        Node<T> *childCursor = cursor->leftNode ? cursor->leftNode : cursor->rightNode;

        if(preCursor->leftNode == cursor){
            preCursor->leftNode = childCursor;
        }
        else{
            preCursor->rightNode = childCursor;
        }

        delete cursor;
    }
    else{
        if(preCursor->leftNode == cursor){
            preCursor->leftNode = nullptr;
        }
        else{
            preCursor->rightNode = nullptr;
        }

        delete cursor;
    }
}

template <typename T>
void MyBinarySearchTree<T>::showAll(){
    cout << "inOrder => ";
    inOrder(this->root);
    cout << endl;

    cout << "preOrder => ";
    preOrder(this->root);
    cout << endl;

    cout << "postOrder => ";
    postOrder(this->root);
    cout << endl;
}

template <typename T>
void MyBinarySearchTree<T>::inOrder(Node<T> *cursorParam){
    if(cursorParam != nullptr){
        inOrder(cursorParam->leftNode);
        cout << " " << cursorParam->data;
        inOrder(cursorParam->rightNode);
    }
}

template <typename T>
void MyBinarySearchTree<T>::preOrder(Node<T> *cursorParam){
    if(cursorParam != nullptr){
        cout << " " << cursorParam->data;
        preOrder(cursorParam->leftNode);
        preOrder(cursorParam->rightNode);
    }
}

template <typename T>
void MyBinarySearchTree<T>::postOrder(Node<T> *cursorParam){
    if(cursorParam != nullptr){
        postOrder(cursorParam->leftNode);
        postOrder(cursorParam->rightNode);
        cout << " " << cursorParam->data;
    }
}