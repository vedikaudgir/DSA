#include <stdio.h>
#include <stdlib.h>

typedef struct StackUsingLinkedList
{
    int data;
    struct StackUsingLinkedList *next;
} Node;

Node *head = NULL;

void push()
{
    int value = 0;
    printf("\nEnter the data: ");
    scanf("%d", &value);
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = value;
    if (head == NULL)
    {
        p->next = NULL;
        head = p;
    }
    else
    {
        p->next = head;
        head = p;
    }
    printf("\nPushed successfully.");
}

void pop()
{
    int temp;
    Node *p;
    if (head == NULL)
    {
        printf("\nStack Underflow.");
    }
    else
    {
        temp = head->data;
        p = head;
        head = head->next;
        free(p);
        printf("\nPopped successfully.");
    }
}

void display()
{
    Node *p;
    p = head;
    if (p == NULL)
    {
        printf("\nStack is empty.");
        return;
    }
    else
    {
        printf("\nThe stack is - \n");
        printf("head -> ");
        while (p != NULL)
        {
            printf("[ %d | * ]  ->  ", p->data);
            p = p->next;
        }
        printf("NULL");
    }
}

void main()
{
    int choice = 0, value = 0;

    while (1)
    {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("\nWrong selection!!! Try again!!!");
        }
    }
}