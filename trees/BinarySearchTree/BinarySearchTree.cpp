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

        Node(int value)
        {
            data = value;
            leftChild = NULL;
            rightChild = NULL;
        }
    } node;

    node *root = NULL;
    node *insertNode(node *root, int value)
    {
        if (root == NULL)
        {
            return new Node(value);
        }
        
        if (value < root->data)
        {
            root->leftChild = insertNode(root->leftChild, value);
        }
        else if (value > root->data)
        {
            root->rightChild = insertNode(root->rightChild, value);
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
    
    public:

    void insertNode(int value)
    {
        root = insertNode(root, value);
    }
    void printTree()
    {
        cout << "\nThe tree is: \n";
        printInorder(root);
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
    myTree.insertNode(10);
    myTree.insertNode(100);
    myTree.insertNode(107);
    myTree.insertNode(170);
    myTree.insertNode(710);
    myTree.insertNode(120);
    myTree.insertNode(210);

    myTree.printTree();

}
