#include <iostream>

class Node {
    public:
    int data;
    Node *next;

    Node(int data) : data(data), next(nullptr) {}
};

class List {
    public:
    Node *head;
    Node *tail;
    int size;

    List() : head(nullptr), tail(nullptr), size(0) {}

    ~List() {
        Node *current = head;
        while (current != nullptr) {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    int insertAtBeginning(int data) {
        Node *newNode = new Node(data);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }

        size++;
        return 0;
    }

    int insertAtEnd(int data) {
        Node *newNode = new Node(data);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        size++;
        return 0;
    }
};

void printList(List *list) {
    Node *current = list->head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    List *list = new List();
    list->insertAtBeginning(1);
    list->insertAtBeginning(2);
    list->insertAtEnd(3);

    printList(list);

    delete list; 
    return 0;
}