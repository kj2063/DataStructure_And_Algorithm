#include "MyLinkedQueue.hpp"

int main(){
    MyLinkedQueue<int> linkedQueue;
    linkedQueue.enQueue(1);
    linkedQueue.enQueue(2);
    linkedQueue.enQueue(3);
    linkedQueue.enQueue(4);
    linkedQueue.enQueue(5);
    linkedQueue.enQueue(6);

    linkedQueue.show();

    linkedQueue.getFront();
    linkedQueue.deQueue();
    linkedQueue.show();

    return 0;
}