//Program to implement BST in c.
//Author - Vedika Udgir 

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* leftChild;
    struct Node* rightChild;
}node;

node* insertNode(node* root, int d)
{
    if (root == NULL)
    {
        node* newNode = (node*)malloc(sizeof(node));
        newNode->data = d;
        newNode->leftChild = NULL;
        newNode->rightChild = NULL;
        return newNode;
    }
    if (d < root->data)
    {
        root->leftChild = insertNode(root->leftChild, d);
    }
    else if(d > root->data)
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
    printf("%4d",root->data);
    printInorder(root->rightChild);
}

void main()
{
    node* head = NULL;
    head = insertNode(head,30);
    head = insertNode(head,10);
    head = insertNode(head,20);
    head = insertNode(head,45);
    head = insertNode(head,90);
    head = insertNode(head,80);
    head = insertNode(head,65);
    head = insertNode(head,0);
    printInorder(head);
}