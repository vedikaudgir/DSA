#include <iostream>
#include <stdlib.h>
using namespace std;

class singlyLinkedList
{
private:
    typedef struct node
    {
        int data;
        struct node *next;
    } node;

    node *head = NULL;

    void insertAtEnd(int d)
    {
        node *newNode = (node *)malloc(sizeof(node));
        newNode->data = d;
        if (head == NULL)
        {
            head = newNode;
            newNode->next = NULL;
            return;
        }
        else
        {
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = NULL;
            return;
        }
        cout << "\nInserted Succesfully.";
    }

    void insertNode(int d, int position)
    {
        if (position > countNodes() || position < 1)
        {
            cout << "\nIncorrect Position.";
            return;
        }
        
        node *newNode = (node *)malloc(sizeof(node));
        newNode->data = d;

        if (head == NULL)
        {
            head = newNode;
            newNode->next = NULL;
            return;
        }
        if (position == 1)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            node *temp = head;
            int i = 1;
            while (i < position - 1)
            {
                i++;
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        cout << "\nInserted Succesfully.";
    }

    void deleteNode(int position)
    {
        if (position > countNodes() || position < 1)
        {
            cout << "\nIncorrect Position.";
            return;
        }

        if (head == NULL)
        {
            printf("\nList is already empty!");
            return;
        }
        node *nodeToDelete = head;
        if (position == 1)
        {
            head = nodeToDelete->next;
        }
        else
        {
            node *temp = head;
            int i = 1;
            while (i < position - 1)
            {
                i++;
                temp = temp->next;
            }
            nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;
        }
        free(nodeToDelete);
        cout << "\nNode deleted succesfully.";
    }

    void displayList()
    {
        node *temp = head;
        if (head == NULL)
        {
            cout << "\nList is Empty!";
        }

        cout << "\nList: head -> ";
        while (temp != NULL)
        {
            cout << "[ " << temp->data << " | " << temp->next << " ] -> ";
            temp = temp->next;
        }
        cout << "NULL";
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
    void printMenu()
    {
        cout << "\nMenu: ";
        cout << "\n1. Insert at end.";
        cout << "\n2. Insert at any position.";
        cout << "\n3. Delete a node.";
        cout << "\n4. Display List.";
        cout << "\n5. check number of nodes.";
        cout << "\n6. Exit.";
    }

public:
    void operationsOnList()
    {
        int choice;
        while (true)
        {
            printMenu();
            cout << "\nEnter your choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                int data;
                cout << "\nEnter the data to insert: ";
                cin >> data;
                insertAtEnd(data);
                break;
            }
            case 2:
            {
                int data, position;
                cout << "\nEnter the data to insert: ";
                cin >> data;
                cout << "\nEnter the position to insert at: ";
                cin >> position;
                insertNode(data, position);
                break;
            }
            case 3:
            {
                int position;
                cout << "\nEnter the position of the node to delete: ";
                cin >> position;
                deleteNode(position);
                break;
            }
            case 4:
            {
                displayList();
                break;
            }
            case 5:
            {
                int numberOfNodes = countNodes();
                cout << "\nThere are " << numberOfNodes << "nodes.";
                break;
            }
            case 6:
            {
                exit(0);
            }
            default:
            {
                cout << "\nIncorrect Input try again.";
                break;
            }
            }
        }
    }

    singlyLinkedList()
    {
        head = NULL;
    }
    ~singlyLinkedList() {}
};

int main()
{
    singlyLinkedList List1;
    List1.operationsOnList();
}