#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Linkedlist {
    private:
    Node* head;
    Node* tail;

    public:
    Linkedlist() {
        head = nullptr;
        tail = nullptr;
    }

    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << endl;
            current = current->next;
        }
    }
};

int main() {
    Linkedlist list;
    list.append(10);
    list.append(20);
    list.append(30);
    list.display();
    return 0;
}