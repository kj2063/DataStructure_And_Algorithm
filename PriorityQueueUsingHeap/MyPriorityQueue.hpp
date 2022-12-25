#include <iostream>

using namespace std;

template <typename T>
struct Node{
    int priorityKey;
    T data;

    Node():priorityKey{},data{}{};
    Node(int priorityKeyParam, T dataParam):priorityKey{priorityKeyParam},data{dataParam}{};
    ~Node(){};
};

template <typename T>
class MyPriorityQueue{
    private:
        int usedHeapLength;
        int maxHeapLength;
        Node<T>* heapArr;
        
        int getParentIdx(int index){return (index - 1)/2;};
        int getLeftChildIdx(int index){return (index * 2) + 1;};
        int getRightChildIdx(int index){return (index * 2) + 2;};
        int getHightPriorityChildIdx(int index);
        void swapNode(int index1, int index2);

    public:
        MyPriorityQueue(int arraySize = 10){
            maxHeapLength = arraySize;
            usedHeapLength = 0;
            heapArr = new Node<T>[arraySize]; 
        };

        ~MyPriorityQueue(){delete[] heapArr;};

        void enqueue(int priority, T data);
        T dequeue();
        void showAll();
};

template <typename T>
int MyPriorityQueue<T>::getHightPriorityChildIdx(int indexParam){
    
    int leftChildIdx = getLeftChildIdx(indexParam);
    int rightChildIdx = getRightChildIdx(indexParam);

    T leftData = heapArr[leftChildIdx].data;
    T rightData = heapArr[rightChildIdx].data;

    if( leftData && rightData ){
        if(heapArr[leftChildIdx].priorityKey < heapArr[rightChildIdx].priorityKey)
            return leftChildIdx;
        else
            return rightChildIdx;     
    }
    else if(leftData){
        return leftChildIdx;
    }
    else{
        return -1;
    }
};

template <typename T>
void MyPriorityQueue<T>::swapNode(int indexParam1, int indexParam2){
    Node<T> tempNode = heapArr[indexParam1];

    heapArr[indexParam1] = heapArr[indexParam2];
    heapArr[indexParam2] = tempNode;
};

template <typename T>
void MyPriorityQueue<T>::enqueue(int priorityParam, T dataParam){
    heapArr[usedHeapLength] = Node<T>(priorityParam,dataParam);
    
    int currentIdx = usedHeapLength;

    while(currentIdx != 0){
        int parentIdx = getParentIdx(currentIdx);

        if(heapArr[parentIdx].priorityKey > heapArr[currentIdx].priorityKey){
            swapNode(parentIdx, currentIdx);
            currentIdx = parentIdx;
        }
        else{
            break;
        }
    }

    usedHeapLength++;
};

template <typename T>
T MyPriorityQueue<T>::dequeue(){
    T result = heapArr[0].data;

    heapArr[0] = Node<T>(heapArr[usedHeapLength-1].priorityKey, heapArr[usedHeapLength-1].data);
    
    Node<T> tempNode = Node<T>();
    heapArr[usedHeapLength-1] = tempNode;

    int currentIdx = 0;

    while(heapArr[currentIdx].priorityKey > heapArr[getLeftChildIdx(currentIdx)].priorityKey || 
    heapArr[currentIdx].priorityKey > heapArr[getRightChildIdx(currentIdx)].priorityKey ){
        
        int targetChildIdx = getHightPriorityChildIdx(currentIdx);

        if(targetChildIdx != -1){
            swapNode(currentIdx,targetChildIdx);
            currentIdx = targetChildIdx;
        }
        else{
            break;
        }
    }

    usedHeapLength--;

    cout << result << " is removed" << endl;
    return result;
};

template <typename T>
void MyPriorityQueue<T>::showAll(){
    for(int i = 0; i<maxHeapLength ; i++){
        cout << heapArr[i].data << "(" << heapArr[i].priorityKey << ")->" << heapArr[getLeftChildIdx(i)].data << "/" << heapArr[getRightChildIdx(i)].data << endl;
    }
};