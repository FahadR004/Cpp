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

int main() {
    Node* head = new Node(10); // head is not a node, it is a ptr to the first node
    head->next = new Node(20); // Node with 10 points to node with 20 value
    head->next->prev = head; 
    // Access where head->next is pointing and then point it's prev to where head is pointing

    head->next->next = new Node(30);
    head->next->next->prev = head->next;
    
    std::cout << "Forward Traversal" << std::endl;
   
    Node* curr = head;
    Node* prev = nullptr;
    while (curr != nullptr) {
        std::cout << curr->data;
        if (curr->next != nullptr) {
           std::cout << " <-> ";
        }
        prev = curr;
        curr = curr->next;
    }
    
    std::cout << "\n";

    std::cout << "Backwards Traversal" << std::endl;

    curr = prev; // Points to same place as prev (last node)

    while (curr != nullptr) {
        std::cout << curr->data;
        if (curr->prev != nullptr) {
           std::cout << " <-> ";
        }
        curr = curr->prev;
    }

    return 0;
}