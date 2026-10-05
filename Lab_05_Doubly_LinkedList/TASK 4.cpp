
#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string songName;
    Node* next;

    Node(string name)
    {
        songName = name;
        next = NULL;
    }
};

int main()
{
    Node* first = new Node("Perfect");
    Node* second = new Node("Believer");
    Node* third = new Node("Shape of You");
    Node* fourth = new Node("Faded");
    Node* fifth = new Node("Let Me Down Slowly");

    // Connect the songs
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Last song connects back to first song
    fifth->next = first;

    // Display all songs once
    cout << "Music Playlist:" << endl;

    Node* current = first;

    for (int i = 1; i <= 5; i++)
    {
        cout << current->songName << endl;
        current = current->next;
    }

    // Play playlist for 2 complete rounds
    cout << "\nPlaying Playlist for 2 Complete Rounds:" << endl;

    current = first;

    for (int i = 1; i <= 10; i++)
    {
        cout << "Playing: " << current->songName << endl;
        current = current->next;
    }

    return 0;
}

