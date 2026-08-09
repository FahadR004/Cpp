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

void insert_end(Node*& head, int value) {
    Node* new_node = new Node(value);
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = new_node;
    temp->next->prev = temp;
}

void insert_middle(Node*& head, int value, int index) {
    Node* new_node = new Node(value);
    int count = 0;
    Node* curr = head;
    Node* prev = nullptr;
    while (curr != nullptr && count != index) {
        prev = curr;
        curr = curr->next; 
        count++;
    }

    if (prev == nullptr) {
        insert_start(head, value);
    } else if (curr->next == nullptr) {
        insert_end(head, value);
    } else {
        prev->next = new_node;
        new_node->prev = prev;

        curr->prev = new_node;
        new_node->next = curr;
    }

}

int main() {
    Node* head = new Node(10); // head is not a node, it is a ptr to the first node
    head->next = new Node(30); // Node with 10 points to node with 20 value
    head->next->prev = head; 
    // Access where head->next is pointing and then point it's prev to where head is pointing

    head->next->next = new Node(40);
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

    insert_middle(head, 20, 1);
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