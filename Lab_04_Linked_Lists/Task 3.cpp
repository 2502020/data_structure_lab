#include <iostream>
using namespace std;
struct Node
{
    int productID;
    Node* next;
};
void addProduct(Node*& head, int id)
{
    Node* newNode = new Node;
    newNode->productID = id;
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
        cout << "P" << temp->productID;
        if(temp->next != NULL)
        {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << endl;
}
void removeProduct(Node*& head, int id)
{
    if(head == NULL)
    {
        cout << "Cart is empty." << endl;
        return;
    }
    if(head->productID == id)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL)
    {
        if(temp->next->productID == id)
        {
            Node* deleteNode = temp->next;
            temp->next = temp->next->next;
            delete deleteNode;
            return;
        }
        temp = temp->next;
    }
    cout << "Product not found." << endl;
}
int main()
{
    Node* head = NULL;
    addProduct(head, 101);
    addProduct(head, 205);
    addProduct(head, 310);
    addProduct(head, 415);
    cout << "Shopping Cart:" << endl;
    display(head);
    cout << "Remove Product: P310" << endl;
    removeProduct(head, 310);
    cout << "Updated Cart:" << endl;
    display(head);
    return 0;
}


