#include <iostream>

// Doubly Linked List Node
class Node {
    public:
        int data;
        Node* prev;
        Node* next;
        Node (int value) {
            data = value;
            prev = nullptr;
            next = nullptr;
        }
};

bool searchData(Node*& head, int data) {
    Node* temp = head;
    bool found = false;
    while (temp != nullptr) {
        if (temp->data == data) {
           found = true;
           break;
        }
        temp = temp->next;
    }
    return found;
}

int main() {
    Node* head = new Node(10); // head is not a node, it is a ptr to the first node
    head->next = new Node(20); // Node with 10 points to node with 20 value
    head->next->prev = head; 
    // Access where head->next is pointing and then point it's prev to where head is pointing

    head->next->next = new Node(30);
    head->next->next->prev = head->next;
    
    bool res = searchData(head, 200);

    if (res) {
        std::cout << "Data Found" << std::endl;
    } else {
        std::cout << "Data Not Found" << std::endl;
    }

    return 0;
}