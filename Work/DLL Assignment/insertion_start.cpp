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

void insert_start(Node*& head, int value) {
    Node* new_node = new Node(value);
    new_node->next = head;
    new_node->next->prev = new_node;

    head = new_node;

}

int main() {
    Node* head = new Node(10); // head is not a node, it is a ptr to the first node
    head->next = new Node(20); // Node with 10 points to node with 20 value
    head->next->prev = head; 
    // Access where head->next is pointing and then point it's prev to where head is pointing

    head->next->next = new Node(30);
    head->next->next->prev = head->next;
    
    std::cout << "Before Insertion" << std::endl;
   
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data;
        if (temp->next != nullptr) {
           std::cout << "<->";
        }
        temp = temp->next;
    }

    std::cout << "\n";

    insert_start(head, 40);
    std::cout << "After Insertion" << std::endl;
    temp = head;
    while (temp != nullptr) {
        std::cout << temp->data;
        if (temp->next != nullptr) {
           std::cout << "<->";
        }
        temp = temp->next;
    }

    return 0;
}