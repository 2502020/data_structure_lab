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
void insertBeginning(Node*& head, int rollNo)
{
    Node* newNode = new Node;
    newNode->rollNo = rollNo;
    newNode->next = head;
    head = newNode;
}
void searchStudent(Node* head, int rollNo)
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
void display(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->rollNo;
        if(temp->next != NULL)
        {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Node* head = NULL;
    addStudent(head, 22);
    addStudent(head, 35);
    addStudent(head, 41);
    addStudent(head, 56);
    cout << "Initially:" << endl;
    display(head);
    insertBeginning(head, 18);
    cout << "After insertion:" << endl;
    display(head);
    int rollNo;
    cout << "Enter Roll Number to Search: ";
    cin >> rollNo;
    searchStudent(head, rollNo);
    return 0;
}


