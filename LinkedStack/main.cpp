#include "MyLinkedStack.hpp"

int main(){
    MyLinkedStack<int> linkedStack;

    linkedStack.show();
    linkedStack.pop();

    linkedStack.push(1);
    linkedStack.push(2);
    linkedStack.push(3);
    linkedStack.push(4);
    linkedStack.push(5);
    linkedStack.push(6);

    linkedStack.show();

    linkedStack.getTop();
    linkedStack.pop();
    linkedStack.show();


    return 0;
}