#include <iostream>
using namespace std;

class BinarySearchTree
{
private:
    typedef struct Node
    {
        int data;
        struct Node *leftChild;
        struct Node *rightChild;
    } node;

    public:
    
    node *root = NULL;
    node *insertNode(node *root, char d)
    {
        if (root == NULL)
        {
            node *newNode = (node *)malloc(sizeof(node));
            newNode->data = d;
            newNode->leftChild = NULL;
            newNode->rightChild = NULL;
            return newNode;
        }

        if (d < root->data)
        {
            root->leftChild = insertNode(root->leftChild, d);
        }
        else if (d > root->data)
        {
            root->rightChild = insertNode(root->rightChild, d);
        }
        return root;
    }

    void printInorder(node* root)
    {
        if (root == NULL)
        {
            return;
        }
        printInorder(root->leftChild);
        printf("%4d", root->data);
        printInorder(root->rightChild);
    }

    BinarySearchTree() 
    {
        root = NULL;
    }
    ~BinarySearchTree() {}
};

int main()
{
    BinarySearchTree myTree;
    myTree.root = myTree.insertNode(myTree.root, 1);
    myTree.root = myTree.insertNode(myTree.root, 20);
    myTree.root = myTree.insertNode(myTree.root, 30);
    myTree.root = myTree.insertNode(myTree.root, 15);
    myTree.root = myTree.insertNode(myTree.root, 7);
    myTree.root = myTree.insertNode(myTree.root, 2);
    myTree.root = myTree.insertNode(myTree.root, 100);
    myTree.printInorder(myTree.root);
}