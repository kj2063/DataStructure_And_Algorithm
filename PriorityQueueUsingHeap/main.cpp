#include "MyPriorityQueue.hpp"

int main(){
    MyPriorityQueue<char> myPriorityQueue;
    myPriorityQueue.enqueue(10, 'A');
    myPriorityQueue.enqueue(20, 'B');
    myPriorityQueue.enqueue(1, 'C');
    myPriorityQueue.enqueue(9, 'D');
    myPriorityQueue.enqueue(17, 'E');
    myPriorityQueue.enqueue(11, 'F');
    myPriorityQueue.enqueue(12, 'G');
    myPriorityQueue.enqueue(3, 'H');
    myPriorityQueue.enqueue(5, 'I');
    myPriorityQueue.enqueue(19, 'J');

    myPriorityQueue.dequeue();
    myPriorityQueue.dequeue();

    myPriorityQueue.showAll();

    return 0;
}