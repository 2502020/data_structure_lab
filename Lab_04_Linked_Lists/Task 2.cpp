
#include <iostream>
using namespace std;

struct Node
{
    int patientID;
    Node* next;
};

void addPatient(Node*& head, int id)
{
    Node* newNode = new Node;

    newNode->patientID = id;
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

    while(temp != NULL)
    {
        cout << "P" << temp->patientID;

        if(temp->next != NULL)
        {
            cout << " -> ";
        }

        temp = temp->next;
    }

    cout << endl;
}

void removePatient(Node*& head)
{
    if(head == NULL)
    {
        cout << "No patients waiting." << endl;
        return;
    }

    Node* temp = head;

    cout << "Patient P" << temp->patientID << " is being served." << endl;

    head = head->next;

    delete temp;
}

int main()
{
    Node* head = NULL;

    addPatient(head, 101);
    addPatient(head, 102);
    addPatient(head, 103);
    addPatient(head, 104);

    cout << "Waiting Patients:" << endl;
    display(head);

    removePatient(head);

    cout << "Updated Queue:" << endl;
    display(head);

    return 0;
}


