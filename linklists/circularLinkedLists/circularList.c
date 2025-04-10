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
    newNode->next = head;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertNode(node **headRef, int d, int position)
{
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
    while (i < position - 2 && temp->next != head)
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
        node *last = head;
        while (last->next != head)
            last = last->next;
        node *temp = head;
        head = head->next;
        last->next = head;
        free(temp);
        return;
    }
    if (position == 0)
    {
        head = head->next;
        free(temp);
        return;
    }
    int i = 0;
    while (i < position - 2 && temp != head)
    {
        i++;
        temp = temp->next;
    }
    if (temp == head || temp->next == head)
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
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("\nList: ");
    printf("\nHead -> ");

    do
    {
        printf("[ %d | %p ] -> ", temp->data, temp->next);
        temp = temp->next;
    } while (temp != head);

    printf("HEAD (again)\n");
}

int countNodes()
{
    int c = 0;
    node *temp = head;
    do
    {
        c++;
        temp = temp->next;
    } while (temp != head);
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
