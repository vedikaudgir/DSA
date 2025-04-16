#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char data;
    struct Node* leftChild;
    struct Node* rightChild;
}node;

node* createNode(char d)
{
    node* newNode = (node*)malloc(sizeof(node));

    newNode->data = d;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;

    return newNode;
}

void printPreorder(node* root)
{
    if (root == NULL)
    {
        return;
    }
    
    printf("%4c", root->data);
    printPreorder(root->leftChild);
    printPreorder(root->rightChild);
}

void main()
{
    node* head = createNode('A');
    head->leftChild = createNode('B');
    head->rightChild = createNode('C');
    head->leftChild->leftChild = createNode('D');
    head->leftChild->rightChild = createNode('E');
    head->rightChild->leftChild = createNode('F');
    head->rightChild->leftChild->rightChild = createNode('G');
    printPreorder(head);
}