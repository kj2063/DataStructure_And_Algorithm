#include "MyBinarySearchTree.hpp"

int main(){
    MyBinarySearchTree<char> myBinarySearchTree;

    myBinarySearchTree.AddNode(5,'A');
    myBinarySearchTree.AddNode(4,'B');
    myBinarySearchTree.AddNode(2,'C');
    myBinarySearchTree.AddNode(8,'D');
    myBinarySearchTree.AddNode(10,'E');
    myBinarySearchTree.AddNode(1,'F');
    myBinarySearchTree.AddNode(7,'G');
    myBinarySearchTree.AddNode(9,'H');
    myBinarySearchTree.AddNode(11,'I');


    // showAll:inOrder => F C B A G D E
    // showAll:preOrder => A B C F D G E
    // showAll:postOrder => F C B G E D A

    myBinarySearchTree.showAll();

    myBinarySearchTree.searchData(8);

    cout << endl;

    myBinarySearchTree.removeNode(11);

    // myBinarySearchTree.searchData(5);
    myBinarySearchTree.showAll();

    // myBinarySearchTree.searchData(9);

    return 0;
}