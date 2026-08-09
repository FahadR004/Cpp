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

void delete_node(Node*& head, int index) {
    int count = 0;
    Node* curr = head;
    Node* prev = nullptr;
    while (curr != nullptr && count != index) {
        prev = curr;
        curr = curr->next; 
        count++;
    }

    if (prev == nullptr) {
        // Deleting first node
        head = head->next;
        head->next->prev = nullptr;
    } else if (curr->next == nullptr) {
        // Deleting last node
        prev->next = nullptr;
    } else {
        prev->next = curr->next;
        curr->next->prev = prev; 
    }

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

    delete_node(head, 2);
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