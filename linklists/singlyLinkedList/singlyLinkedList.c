#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
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
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int countNodes()
{
    int c = 0;
    node* temp = head;
    while (temp != NULL)
    {
        c++;
        temp = temp->next;
    }
    return c;
}

void insertNode(node **headRef, int d, int position)
{
    if (position > countNodes() + 1 || position <= 0)
    {
        printf("Invalid Position");
        return;
    }
    
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = d;
    if (*headRef == NULL || position == 1)
    {
        newNode->next = *headRef;
        *headRef = newNode;
        return;
    }
    int i = 0;
    node *temp = *headRef;
    while (i < position - 2 && temp->next != NULL)
    {
        i++;
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNode(int position)
{
    if (head == NULL)
    {
        return;
    }

    node *temp = head;

    if (position == 1)
    {
        head = head->next;
        free(temp);
        return;
    }
    int i = 0;
    while (i < position - 2 && temp != NULL)
    {
        i++;
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL)
    {
        return;
    }

    node *nodeToDelete = temp->next;
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
        printf("[ %d | %p ] -> ", temp->data, temp->next);
        temp = temp->next;
    }
    printf("NULL");
}

void reverseList(node** headRef)
{
    node* past = NULL;
    node* present = *headRef;
    node* future = NULL;
    
    past = NULL;

    while (present != NULL)
    {
        future = present->next;
        present->next = past;
        past = present;
        present = future;
    }
    *headRef = past;
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
        printf("\n6. Reverse Lists.");
        printf("\n7. Exit.");

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
            deleteNode(index);
            break;
        }
        case 4:
        {
            displayList();
            break;
        }
        case 5:
        {
            printf("\nThere are %d nodes.",countNodes());
            break;
        }
        case 6:
        {
            reverseList(&head);
            break;
        }
        case 7:
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
