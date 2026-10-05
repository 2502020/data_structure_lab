#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string playerName;
    Node* next;

    Node(string name)
    {
        playerName = name;
        next = NULL;
    }
};

int main()
{
    Node* first = new Node("Ali");
    Node* second = new Node("Hassan");
    Node* third = new Node("Ahmed");
    Node* fourth = new Node("Bilal");
    Node* fifth = new Node("Usman");

    // Connecting the players
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Last player points back to first player
    fifth->next = first;

    cout << "Game Player Turns:" << endl;

    Node* current = first;

    // Display each player's turn once
    for (int i = 1; i <= 5; i++)
    {
        cout << current->playerName << "'s turn" << endl;
        current = current->next;
    }

    cout << "\nAfter the last player, turn returns to: ";
    cout << current->playerName << endl;

    return 0;
}

