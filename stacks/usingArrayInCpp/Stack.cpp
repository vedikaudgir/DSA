#include <iostream>
using namespace std;

#define MAX 10

class Stack
{
private:
    int stack[MAX];
    int top = -1;

public:
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
    int search(int data)
    {
        
    }

    Stack(){}
    ~Stack(){}
};
