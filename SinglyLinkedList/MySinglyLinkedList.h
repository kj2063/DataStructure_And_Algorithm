#include <iostream>

using namespace std;

template <typename T>
struct Node{
    T data;
    Node<T> *nextNode;
};

template <typename T>
class MySinglyLinkedList{
    private:
        Node<T> *head;
        Node<T> *tail;
        int size = 0; 

        void deleteNode(Node<T> *targetNode){
            delete(targetNode);
        }

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
            else if(index > size){
                throw invalid_argument("list size is " + to_string(size) + ", but provided arguement of index is " + to_string(index));
            }
            else{
                for(int i=0; i<index-1; i++){
                    preNode = preNode->nextNode;
                    postNode = preNode->nextNode;
                }

                preNode->nextNode = newNode;
                newNode->nextNode = postNode;
            }
        };

        void addFirst(T newData){
            Node<T> *newNode = new Node<T>;

            newNode->data = newData;
            size++;
            
            newNode->nextNode = head;
            head = newNode;
        }

        void removeFirst(){
            Node<T> *targetNode = head;
            
            head = head->nextNode;
            size--;
            
            deleteNode(targetNode);
        }

        void removeLast(){
            Node<T> *preNode = head;
            Node<T> *postNode = head->nextNode;

            while(postNode->nextNode != nullptr){
                preNode = preNode->nextNode;
                postNode = preNode->nextNode;
            }
            
            size--;
            preNode->nextNode = nullptr;
            tail = preNode;
            deleteNode(postNode);
        }

        void removeByIndex(int index){
            if(index == 0){
                removeFirst();
            }
            else if(index == size-1){
                removeLast();
            }
            else if(index > size-1){
                throw invalid_argument("list size is " + to_string(size) + ", but provided arguement of index is " + to_string(index));
            }
            else{
                int indexCnt = 1;
                Node<T> *preNode = head;
                Node<T> *targetNode = head->nextNode;
                Node<T> *postNode = targetNode->nextNode;

                while(indexCnt != index){
                    preNode = preNode->nextNode;
                    targetNode = preNode->nextNode;
                    postNode = targetNode->nextNode;
                    indexCnt++;
                }

                size--;
                preNode->nextNode = postNode;
                deleteNode(targetNode);
            }
        }

        void removeByValue(T deleteData){
            int indexCnt = 1;
            Node<T> *preNode = head;
            Node<T> *targetNode = head->nextNode;
            Node<T> *postNode = targetNode->nextNode;
            if(head->data == deleteData){
                removeFirst();
            }
            
            while(targetNode->nextNode != nullptr){
                if(targetNode->data == deleteData){
                    Node<T> *willDeleteNode = targetNode;

                    deleteNode(willDeleteNode);
                    
                    size--;
                    preNode->nextNode = postNode;
                    targetNode = postNode;
                    postNode = postNode->nextNode;
                }
                else{
                    preNode = targetNode;
                    targetNode = postNode;
                    postNode = postNode->nextNode;
                }
            }

            if(tail->data == deleteData){
                removeLast();
            }
        }

        T get(int index){
            if(index > size-1){
                throw invalid_argument("list size is " + to_string(size) + ", but provided arguement of index is " + to_string(index));
            }

            int indexCnt = 0;
            Node<T> *targetNode = head;
            
            while(true){
                if(indexCnt == index){
                    return targetNode->data;
                }
                else{
                    targetNode = targetNode->nextNode;
                    indexCnt++;
                }
            }
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
            cout << "size => " << size << endl;
        }


};