#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int queue[MAX];
int front = 0;
int rear = 0;

void enQueue(int data)
{
    if (front == 0 && rear == 0)
    {
        queue[rear] = data;
        rear++;
        printf("\nEnQueued successfully");
    }
    else if (rear == MAX)
    {
        printf("\nQueue is full!");
    }
    else
    {
        queue[rear] = data;
        rear++;
        printf("\nEnQueued successfully");
    }
}

int deQueue()
{
    if (front == 0 && rear == 0)
    {
        printf("\nQueue is empty!");
    }
    else
    {
        int t = queue[front];
        for (int i = front; i < rear; i++)
        {
            queue[i] = queue[i + 1];
        }
        rear--;
        printf("\nDeQueued successfully");
        return t;
    }
}
void display()
{
    if (front == 0 && rear == 0)
    {
        printf("\nQueue is empty!");
    }
    else
    {
        printf("\nQueue is - ");
        for (int i = front; i < rear; i++)
        {
            printf("%8d", queue[i]);
        }
    }
}
int isEmpty()
{
    if (rear == 0 && front == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull()
{
    if (rear == MAX)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void printMenu()
{
    printf("\n\n\nMENU");
    printf("\nEnter 1 to enQueue");
    printf("\nEnter 2 to deQueue");
    printf("\nEnter 3 to display queue");
    printf("\nEnter 4 to check is queue is empty");
    printf("\nEnter 5 to check is queue is full");
    printf("\nEnter 6 to EXIT\n");
}

void main()
{
    int choice = 0;

    while (choice != 6)
    {
        printMenu();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            int data;
            printf("\nEnter data to enQueue - ");
            scanf("%d", &data);
            enQueue(data);
            display();
            break;
        }
        case 2:
        {
            int a = deQueue();
            display();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            isEmpty() ? printf("\nQueue is empty") : printf("\nQueue is not empty");
            break;
        }
        case 5:
        {
            isFull() ? printf("\nQueue is full") : printf("\nQueue is not full");
            break;
        }
        case 6:
        {
            exit(0);
        }
        default:
        {
            printf("\nInvalid Input try again!");
            break;
        }
        }
    }
}