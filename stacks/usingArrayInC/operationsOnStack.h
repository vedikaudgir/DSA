//Header File to store all the functions for operations on a stack.
//Author - Vedika Udgir

#include <stdio.h>
#define MAX 10

int top = -1;
int stack[MAX];

void push(int data)
{
    if (top == MAX)
    {
        printf("\nStack Overflow! Cannot push.");
    }
    else
    {
        top++;
        stack[top] = data;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("\nStack Underflow! Cannot pop.");
    }
    else
    {
        top--;
    }
}

int peek()
{
    if (top == -1)
    {
        printf("\nStack Underflow! Cannot peek.");
    }
    else
    {
        return stack[top];
    }
}

void display()
{
    printf("\nThe stack is - \n");
    for (int i = 0; i < top; i++)
    {
        printf("%4d", stack[i]);
    }
}

bool isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull()
{
    if (top == MAX)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int size()
{
    return top;
}

