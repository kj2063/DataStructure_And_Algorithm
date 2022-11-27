#include <stdio.h>
#include "MySinglyLinkedList.hpp"

int main(){

    MySinglyLinkedList<int> myList;
    myList.add(1);
    myList.add(2);
    myList.add(3);
    myList.add(4);
    myList.add(3);

    
    cout << myList.get(0) << endl;
    // myList.show();
    return 0;
}
