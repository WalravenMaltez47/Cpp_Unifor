#include <iostream>
#include <memory>

template <typename T>
struct Node {
    T data;
    std::unique_ptr<Node<T>> next;

    Node(T data) : data(data), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    std::unique_ptr<Node<T>> head;
    Node<T>* tail;
    size_t size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}
    ~LinkedList() = default;

    void insert_At_Beginning(T data) {
        auto newNode = std::make_unique<Node<T>>(data);

        if (head == nullptr) 
        {
            tail = newNode.get();
        }
         
        else
        {
            newNode->next = std::move(head);
        }

        head = std::move(newNode);
        size++;
    }

    void insert_At_End(T data) {
        if (head == nullptr) {
            insert_At_Beginning(data);
        } else {
            auto newNode = std::make_unique<Node<T>>(data);
            tail->next = std::move(newNode);
            tail = tail->next.get();
            size++;
        }
    }

    void insert_At_Position(T data, int position) {
        if (position < 1 || position > size + 1) {
            std::cerr << "Invalid position!" << std::endl;
            return;
        }

        auto newNode = std::make_unique<Node<T>>(data);

        if (position == 1) {
            newNode->next = std::move(head);
            head = std::move(newNode);
            if (tail == nullptr) {
                tail = head.get();
            }
        } else {
            Node<T>* current = head.get();
            for (int i = 1; i < position - 1; ++i) {
                current = current->next.get();
            }
            newNode->next = std::move(current->next);
            current->next = std::move(newNode);
            if (current->next->next == nullptr) {
                tail = current->next.get();
            }
        }

        size++;
    }

    size_t getSize() const {
        return size;
    }

    void print() const {
        Node<T>* current = head.get();

        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next.get();
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList<double> list;
    list.insert_At_Beginning(10);
    list.insert_At_Beginning(20);
    list.insert_At_End(30);
    list.insert_At_End(40);
    list.insert_At_Position(25, 3);

    std::cout << list.getSize() << std::endl;

    list.print();

    return 0;
}
