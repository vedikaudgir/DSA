//Program to implement a doubly Linked List in C.
//Author - Vedika Udgir.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *previous;
    struct node *next;
} node;

node *head = NULL;

void insertAtEnd(int d)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = d;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        newNode->previous = NULL;
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->previous = temp;
    }
}
void insertNode(node **headRef, int d, int position)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = d;

    if (*headRef == NULL)
    {
        newNode->next = NULL;
        newNode->previous = NULL;
        return;
    }

    if (position == 1 && *headRef != NULL)
    {
        newNode->next = *headRef;
        (*headRef)->previous = newNode;
        *headRef = newNode;
        newNode->previous = NULL;
        return;
    }

    else
    {
        int i = 1;
        node *temp = *headRef;
        while (i < position - 1 && temp->next != NULL)
        {
            temp = temp->next;
            i++;
        }

        newNode->next = temp->next;
        newNode->previous = temp;
        if (temp->next != NULL)
            temp->next->previous = newNode;
        temp->next = newNode;
    }
}

void deleteNode(node **headRef, int position)
{
    if (*headRef == NULL)
    {
        printf("\nAlready Empty");
        return;
    }
    node *temp = *headRef;
    if (position == 1 && *headRef != NULL)
    {
        node *temp = *headRef;
        *headRef = temp->next;
        if (*headRef != NULL)
            (*headRef)->previous = NULL;
        free(temp);
        return;
    }
    int i = 0;
    while (i < position - 1 && temp != NULL)
    {
        i++;
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL)
    {
        printf("\nInvalid position!");
        return;
    }
    node *nodeToDelete = temp->next;
    if (nodeToDelete->next != NULL)
    {
        nodeToDelete->next->previous = temp;
    }
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}

void displayList()
{
    node *temp = head;
    printf("\nList: ");
    printf("\nHead -> ");
    while (temp != NULL)
    {
        printf("[ %p | %d | %p ] <-> ", temp->previous, temp->data, temp->next);
        temp = temp->next;
    }
}

int countNodes()
{
    int c = 0;
    node *temp = head;
    while (temp != NULL)
    {
        c++;
        temp = temp->next;
    }
    return c;
}
int main()
{
    int choice;
    while (1)
    {
        printf("\n\n\n1. Insert at end.");
        printf("\n2. Insert at a given index.");
        printf("\n3. Delete at given index.");
        printf("\n4. Display the list.");
        printf("\n5. Check number of nodes.");
        printf("\n6. Exit.");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int data;
            printf("\nEnter data to insert: ");
            scanf("%d", &data);
            insertAtEnd(data);
            break;
        }
        case 2:
        {
            int data, index;
            printf("\nEnter data to insert: ");
            scanf("%d", &data);
            printf("\nEnter index to insert at: ");
            scanf("%d", &index);
            insertNode(&head, data, index);
            break;
        }
        case 3:
        {
            int index;
            printf("\nEnter index to delete: ");
            scanf("%d", &index);
            deleteNode(&head, index);
            break;
        }
        case 4:
        {
            displayList();
            break;
        }
        case 5:
        {
            printf("\nThere are %d nodes.", countNodes());
            break;
        }
        case 6:
        {
            printf("\nExitted");
            exit(0);
        }
        default:
        {
            printf("\nInvalid Input try again!");
        }
        }
    }
}
