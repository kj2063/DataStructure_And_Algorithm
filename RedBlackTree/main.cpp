#include "MyRedBlackTree.hpp"

int main(){

    MyRedBlackTree<char> RedBlackTree;
    RedBlackTree.insertNode(new Node<char>(5,'A'));
    RedBlackTree.insertNode(new Node<char>(4,'B'));
    RedBlackTree.insertNode(new Node<char>(3,'C'));
    RedBlackTree.insertNode(new Node<char>(2,'D'));
    RedBlackTree.insertNode(new Node<char>(1,'E'));
    RedBlackTree.insertNode(new Node<char>(7,'F'));
    RedBlackTree.insertNode(new Node<char>(6,'G'));
    RedBlackTree.insertNode(new Node<char>(10,'H'));
    RedBlackTree.insertNode(new Node<char>(12,'I'));
    RedBlackTree.insertNode(new Node<char>(11,'J'));
    RedBlackTree.insertNode(new Node<char>(8,'K'));

    RedBlackTree.deleteNode(5);

    RedBlackTree.showAll();

    return 0;
}