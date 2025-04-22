//Program to implement search in Binary Search Tree in C.
//Author - Vedika Udgir

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *leftChild;
    struct node *rightChild;
} node;

node *insertNode(node *root, int d)
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

node *searchNode(node *root, int key)
{
    if (root == NULL || root->data == key)
    {
        return root;
    }
    if (root->data > key)
    {
        return searchNode(root->leftChild, key);
    }
    else if (root->data < key)
    {
        return searchNode(root->rightChild, key);
    }
}

void printInorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    printInorder(root->leftChild);
    printf("%4d", root->data);
    printInorder(root->rightChild);
}

void main()
{
    node *head = NULL;

    head = insertNode(head, 30);
    head = insertNode(head, 10);
    head = insertNode(head, 20);
    head = insertNode(head, 45);
    head = insertNode(head, 90);
    head = insertNode(head, 80);
    head = insertNode(head, 65);
    head = insertNode(head, 20);
    head = insertNode(head, 10);
    head = insertNode(head, 0);

    printf("Inorder traversal: ");
    printInorder(head);
    printf("\n");

    int key = 65;
    node *result = searchNode(head, key);
    if (result != NULL)
    {
        printf("Element %d found!\n", key);
    }
    else
    {
        printf("Element %d not found\n", key);
    }
}