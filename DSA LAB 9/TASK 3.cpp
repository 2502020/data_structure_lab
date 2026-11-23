
#include <iostream>
#include <string>
using namespace std;

class Order {
public:
    int orderID;
    string customerName;
    float amount;

    Order* left;
    Order* right;

    Order(int id, string name, float a) {
        orderID = id;
        customerName = name;
        amount = a;

        left = NULL;
        right = NULL;
    }
};

class MaxHeap {
private:
    Order* heap[100];
    int size;


    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;

            if (heap[index]->amount > heap[parent]->amount) {
                swap(heap[index], heap[parent]);
                index = parent;
            }
            else {
                break;
            }
        }
    }

    
    void heapifyDown(int index) {
        while (true) {
            int largest = index;

            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < size &&
                heap[left]->amount > heap[largest]->amount) {
                largest = left;
            }

            if (right < size &&
                heap[right]->amount > heap[largest]->amount) {
                largest = right;
            }

            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            }
            else {
                break;
            }
        }
    }

    
    void updatePointers() {
        for (int i = 0; i < size; i++) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < size)
                heap[i]->left = heap[left];
            else
                heap[i]->left = NULL;

            if (right < size)
                heap[i]->right = heap[right];
            else
                heap[i]->right = NULL;
        }
    }

public:
    MaxHeap() {
        size = 0;
    }

    
    void insert(int id, string name, float amount) {
        Order* newOrder = new Order(id, name, amount);

        heap[size] = newOrder;
        size++;

        heapifyUp(size - 1);
        updatePointers();
    }

    
    void display() {
        for (int i = 0; i < size; i++) {
            cout << "Order ID: " << heap[i]->orderID
                 << " | Customer: " << heap[i]->customerName
                 << " | Amount: " << heap[i]->amount << endl;
        }
    }

    
    void heapSort() {
        float sortedAmounts[100];
        int count = 0;

        while (size > 0) {
            sortedAmounts[count] = heap[0]->amount;
            count++;

            delete heap[0];

            heap[0] = heap[size - 1];
            size--;

            if (size > 0) {
                heapifyDown(0);
            }

            updatePointers();
        }

        cout << "\nOrder amounts in ascending order:\n";

        for (int i = count - 1; i >= 0; i--) {
            cout << sortedAmounts[i] << " ";
        }

        cout << endl;
    }
    
    ~MaxHeap() {
        for (int i = 0; i < size; i++) {
            delete heap[i];
        }
    }
};

int main() {
    MaxHeap h;

    
    h.insert(101, "Ali", 500);
    h.insert(102, "Ahmed", 200);
    h.insert(103, "Sara", 800);
    h.insert(104, "Usman", 300);
    h.insert(105, "Ayesha", 100);
    h.insert(106, "Bilal", 600);

    cout << "Original Max Heap:\n";
    h.display();


    h.heapSort();

    return 0;
}

