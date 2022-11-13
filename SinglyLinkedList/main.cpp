#include <stdio.h>
#include "MySinglyLinkedList.h"

int main(){

    MySinglyLinkedList<int> myList;
    myList.add(1);
    myList.add(2);
    myList.add(3);
    myList.add(4);

    
    myList.addFirst(5);
    myList.show();
    return 0;
}
