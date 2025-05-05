//Implementaion of queue Data Structure using LinkedLists in C.
///Author - Vedika Udgir.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    node *next;
} node;

node *head, rear;
head = NULL;

void enQueue(int d)
{
    node *temp = (node *)malloc((sizeof(node)));

    if (head == NULL)
    {
        head = temp;
        rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
    temp->data = d;
    temp->next = NULL;
    printf("\nInserted Successfully");
}

void deQueue()
{
    int item;
    if (head == NULL)
    {
        printf("\nQueue Underflow");
    }
    else
    {
        item = head->data;
        ptr = head;
        head = head->next;        
        free(ptr);
        printf("\nItem deleted successfully !!");
    }  
}
void display()
{
    if (temp == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Printing Queue elements….\n");
        while (ptr != NULL)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
    }
}

