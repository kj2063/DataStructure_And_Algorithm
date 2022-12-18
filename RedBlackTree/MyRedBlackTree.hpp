#include <iostream>

using namespace std;

enum Color
{
    RED,
    BLACK
};

template <typename T>
struct Node {
    int key;
    T data;

    Node<T> *parent = nullptr;
    Node<T> *right = nullptr;
    Node<T> *left = nullptr;

    Color color = BLACK;
    
    Node(){};
    Node(int keyParam, T dataParam):key{keyParam}, data{dataParam}{};
};

template <typename T>
class MyRedBlackTree {
    private:
        Node<T> *root;
        Node<T> *nil;

    public:
        string enumToString(Color color){
            switch(color){
                case 0 : return "RED";
                case 1 : return "BLACK";
            }
        }

        MyRedBlackTree(){
            nil = new Node<T>;
            root = nil;
        };
        ~MyRedBlackTree(){};

        void insertNode(Node<T> *nodeParam);
        void rotateRight(Node<T> *centerNode);
        void rotateLeft(Node<T> *centerNode);
        void arrangeInsertedNode(Node<T> *insertedNode);

        void deleteNode(int key);
        Node<T>* getNode(int key);
        Node<T>* getReplacementNode(Node<T> *willReplacedNode);
        void arrangeAfterDeleteNode(Node<T> *replacedNode, Node<T> *replacedParentNode);

        void showAll();
        void preOrder(Node<T> *cursorParam);

        
};

template <typename T>
void MyRedBlackTree<T>::insertNode(Node<T> *newNode){
    newNode->left = nil;
    newNode->right = nil;

    if(root == nil){
        newNode->color = BLACK;

        this->root = newNode;
    }
    else{
        newNode->color = RED;

        Node<T> *ptr = root;
        Node<T> *prePtr = nullptr; 

        while(ptr != nil){
            prePtr = ptr;

            if(ptr->key > newNode->key)
                ptr = prePtr->left;
            else
                ptr = prePtr->right;    
        }
        
        newNode->parent = prePtr;
        
        if(prePtr->key > newNode->key){
            prePtr->left = newNode;
        }
        else{
            prePtr->right = newNode;
        }

        arrangeInsertedNode(newNode);
    }
};

template <typename T>
void MyRedBlackTree<T>::rotateRight(Node<T> *centerNode){
    if(centerNode == nil || centerNode->left == nil)
        throw invalid_argument("error : target Node == nil || targetNode->left == nil");
    
    //temp = will be centerNode
    Node<T> *temp = centerNode->left;

    centerNode->left = centerNode->left->right;

    if(centerNode->left != nil)
        centerNode->left->parent = centerNode;

    temp->right = centerNode;
    temp->parent = centerNode->parent;

    if(temp->parent != nullptr){
        if(temp->parent->left == centerNode)
            temp->parent->left = temp;
        else
            temp->parent->right = temp;
    }

    centerNode->parent = temp;

    if(root == centerNode){
        root = temp;   
    }
};

template <typename T>
void MyRedBlackTree<T>::rotateLeft(Node<T> *centerNode){
    if(centerNode == nil || centerNode->right == nil)
        throw invalid_argument("error : target Node == nil || targetNode->right == nil");
    
    //temp = will be centerNode
    Node<T> *temp = centerNode->right;

    centerNode->right = centerNode->right->left;

    if(centerNode->right != nil)
        centerNode->right->parent = centerNode;

    temp->left = centerNode;
    temp->parent = centerNode->parent;

    if(temp->parent != nullptr){
        if(temp->parent->left == centerNode)
            temp->parent->left = temp;
        else
            temp->parent->right = temp;
    }

    centerNode->parent = temp;

    if(root == centerNode){
        root = temp;   
    }
};

template <typename T>
void MyRedBlackTree<T>::arrangeInsertedNode(Node<T> *insertedNode){
    Node<T> *parentNode = insertedNode->parent;
    while(parentNode != nullptr && parentNode->color == RED){
        Node<T> *grandParentNode = parentNode->parent;
        bool isParentLeftChild = grandParentNode->left == parentNode ? true : false;
        Node<T> *uncleNode = isParentLeftChild ? grandParentNode->right : grandParentNode->left;

        if(uncleNode->color == RED){
            parentNode->color = BLACK;
            uncleNode->color = BLACK;
            grandParentNode->color = RED;

            insertedNode = grandParentNode;
            parentNode = grandParentNode->parent;
        }
        else{
            // to align grandParentNode - parentNode - insertedNode
            if(insertedNode == (isParentLeftChild ? parentNode->right : parentNode->left)){
                isParentLeftChild ? rotateLeft(parentNode) : rotateRight(parentNode);
                // if rotation occurs, parentNode becomes child of insertedNode, so change parentNode to insertedNode
                parentNode = insertedNode;
            }

            parentNode->color = BLACK;
            grandParentNode->color = RED;
            isParentLeftChild ? rotateRight(grandParentNode) : rotateLeft(grandParentNode);
        }
    }
    root->color = BLACK;
};

template <typename T>
Node<T>* MyRedBlackTree<T>::getNode(int keyParam){
    
    Node<T> *ptr = root;

    while(ptr != nil){
        if(ptr->key == keyParam){
            return ptr;
        }
        else{
            if(ptr->key > keyParam)
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }
    }
    
    throw invalid_argument("invalid key");
}


template <typename T>
Node<T>* MyRedBlackTree<T>::getReplacementNode(Node<T> *targetNodeParam){
    Node<T> *ptr = targetNodeParam->right;

    while(ptr->left != nil){
        ptr = ptr->left;
    }

    return ptr;
}

template <typename T>
void MyRedBlackTree<T>::deleteNode(int keyParam){
    Node<T> *targetNode = getNode(keyParam);

    Node<T> *afterReplacedTargetNode;
    Node<T> *afterReplacedParentNode;
    bool needArrange = false;

    if(targetNode->right != nil && targetNode->left != nil){
        Node<T> *selectedChildNode = getReplacementNode(targetNode);

        if(selectedChildNode->color == BLACK && selectedChildNode->right->color == RED){
            selectedChildNode->right->color = BLACK;
        }
        else if(selectedChildNode->color == BLACK && selectedChildNode->right->color == BLACK){
            needArrange = true;
        }

        if(targetNode->right != selectedChildNode){

            selectedChildNode->parent->left = selectedChildNode->right;
            if(selectedChildNode != nil){
                selectedChildNode->right->parent = selectedChildNode->parent;
            }
        }
        else{
            targetNode->right = selectedChildNode->right;
            selectedChildNode->right->parent = targetNode;
        }

        targetNode->key = selectedChildNode->key;
        targetNode->data = selectedChildNode->data;

        afterReplacedTargetNode = selectedChildNode->right;
        afterReplacedParentNode = selectedChildNode->parent;

        delete selectedChildNode;
    }
    else {
        Node<T> *selectedChildNode = targetNode->left != nil ? targetNode->left : targetNode->right;

        if(targetNode->color == BLACK && selectedChildNode->color == RED){
            selectedChildNode->color = BLACK;
        }
        else if(targetNode->color == BLACK && selectedChildNode->color == BLACK){
            needArrange = true;
        }

        if(targetNode == root){
            root = selectedChildNode;
        }
        
        if(targetNode != root){
            if(targetNode->parent->right == targetNode)
                targetNode->parent->right = selectedChildNode;
            else
                targetNode->parent->left = selectedChildNode;
        }

        if(selectedChildNode != nil){
            selectedChildNode->parent = targetNode->parent;
        }

        afterReplacedTargetNode = selectedChildNode;
        afterReplacedParentNode = targetNode->parent;

        delete targetNode;
    }

    if(needArrange){
        arrangeAfterDeleteNode(afterReplacedTargetNode,afterReplacedParentNode);
    }
}

template <typename T>
void MyRedBlackTree<T>::arrangeAfterDeleteNode(Node<T> *targetNode, Node<T> *parentNode){

    string isNil = targetNode == nil ? "is nil" : "is not nil";
    cout<< "targetNode " << isNil << endl;
    // cout << "here" << targetNode->key << endl;
    // cout << "here" << targetNode->parent->data << endl;

    while (nullptr != parentNode)
	{
		bool left = parentNode->left == targetNode;
		Node<T> *siblingNode = left ? parentNode->right : parentNode->left;
		if (RED == parentNode->color && BLACK == siblingNode->left->color && BLACK == siblingNode->right->color)
		{
            // case 1
            // parent : red, sibling : black, sibling left : black, sibling right : black
            siblingNode->color = RED;
            parentNode->color = BLACK;
            break; 
		}
		else if(BLACK == siblingNode->left->color && BLACK == siblingNode->right->color)
		{
			if (BLACK == siblingNode->color)
			{
				// case 4
				// parent : black, sibling : black, sibling left : black, sibling right : black
				siblingNode->color = RED;
				targetNode = parentNode;
				parentNode = parentNode->parent;
				continue; 
			}
			else // RED == sibling->color
			{
				// case 5
				// parent : black, sibling : red, sibling left : black, sibling right : black
				parentNode->color = RED;
				siblingNode->color = BLACK;
				if (left)
				{
					rotateLeft(parentNode);
					siblingNode = parentNode->right;
				}
				else
				{
					rotateRight(parentNode);
					siblingNode = parentNode->left;
				}
				continue;
			}
		}

		if (BLACK == siblingNode->color &&
			((left && RED == siblingNode->left->color && BLACK == siblingNode->right->color)
				|| (!left && BLACK == siblingNode->left->color && RED == siblingNode->right->color)))
		{
			// case 3
			// parent : all, sibling : black, sibling left : red, sibling right : black
			if (left)
			{
				rotateRight(siblingNode);
				parentNode->right->color = BLACK;
				parentNode->right->right->color = RED;
				siblingNode = parentNode->right;
			}
			else
			{
				rotateLeft(siblingNode);
				parentNode->left->color = BLACK;
				parentNode->left->left->color = RED;
				siblingNode = parentNode->left;
			}
		}
		
		if (BLACK == siblingNode->color && ((left && RED == siblingNode->right->color) || (!left && RED == siblingNode->left->color)))
		{
			// case 2
			// parent : all, sibling : black, sibling left : all, sibling right : red
			left ? rotateLeft(parentNode) : rotateRight(parentNode);
			Color temp = parentNode->color;
			parentNode->color = siblingNode->color;
			siblingNode->color = temp;
			left ? siblingNode->right->color = BLACK : siblingNode->left->color = BLACK;
			break; 
		}
	}
}

template <typename T>
void MyRedBlackTree<T>::showAll(){
    cout << "======Show All======" << endl;
    
    preOrder(root);
    
    cout << "====================" << endl;
};

template <typename T>
void MyRedBlackTree<T>::preOrder(Node<T> *ptr){
    if(ptr != nil){
        string direction = "root";
        if(ptr->parent != nullptr)
            direction = ptr->parent->right == ptr ? "R" : "L";

        int parentKey = 0;
        if(ptr->parent != nullptr) 
            parentKey = ptr->parent->key;

        cout << ptr->key << "[" << ptr->data << "] " << "(" << enumToString(ptr->color) << "," << parentKey << "," << direction << ")" << endl;
        preOrder(ptr->left);
        preOrder(ptr->right);
    }
};