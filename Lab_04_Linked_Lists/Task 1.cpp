```cpp
#include <iostream>
using namespace std;

struct Node
{
    int rollNo;
    Node* next;
};

void addStudent(Node*& head, int rollNo)
{
    Node* newNode = new Node;

    newNode->rollNo = rollNo;
    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void display(Node* head)
{
    Node* temp = head;

    cout << "Registered Students: ";

    while(temp != NULL)
    {
        cout << temp->rollNo << " ";
        temp = temp->next;
    }

    cout << endl;
}

void search(Node* head, int rollNo)
{
    Node* temp = head;

    while(temp != NULL)
    {
        if(temp->rollNo == rollNo)
        {
            cout << "Student Found" << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Student Not Found" << endl;
}

int main()
{
    Node* head = NULL;

    addStudent(head, 101);
    addStudent(head, 105);
    addStudent(head, 108);
    addStudent(head, 112);

    display(head);

    int rollNo;

    cout << "Enter Roll Number to Search: ";
    cin >> rollNo;

    search(head, rollNo);

    return 0;
}
```

