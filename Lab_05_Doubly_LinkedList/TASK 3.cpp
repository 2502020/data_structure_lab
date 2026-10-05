
#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string imageName;
    Node* prev;
    Node* next;

    Node(string name)
    {
        imageName = name;
        prev = NULL;
        next = NULL;
    }
};

int main()
{
    Node* first = new Node("Nature.jpg");
    Node* second = new Node("Beach.jpg");
    Node* third = new Node("Mountain.jpg");
    Node* fourth = new Node("City.jpg");
    Node* fifth = new Node("Sunset.jpg");

    // Connecting nodes
    first->next = second;

    second->prev = first;
    second->next = third;

    third->prev = second;
    third->next = fourth;

    fourth->prev = third;
    fourth->next = fifth;

    fifth->prev = fourth;

    // Display images from first to last
    cout << "Image Gallery (First to Last):" << endl;

    Node* current = first;

    while (current != NULL)
    {
        cout << current->imageName << endl;
        current = current->next;
    }

    // Display images from last to first
    cout << "\nImage Gallery (Last to First):" << endl;

    current = fifth;

    while (current != NULL)
    {
        cout << current->imageName << endl;
        current = current->prev;
    }

    return 0;
}

