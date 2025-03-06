#include <iostream>

template <typename T>
struct Node
{
    T data;
    Node *next;

    Node(T data) : data(data), next(nullptr) {}
};

template <typename T>
class LinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~LinkedList()
    {
        Node<T> *current = head;
        while (current != nullptr)
        {
            Node<T> *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    T insert_At_Beginning(T data)
    {
        Node<T> *newNode = new Node<T>(data);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }

        else
        {
            newNode->next = head;
            head = newNode;
        }

        size++;
        return head->data;
    }

    T insert_At_End(T data)
    {
        if (head == nullptr)
        {
            return insert_At_Beginning(data);
        }

        else
        {
            Node<T> *newNode = new Node<T>(data);

            tail->next = newNode;
            tail = newNode;
        }

        size++;
        return tail->data;
    }

    void insert_At_Position(T data, int position)
    {
        if (position < 1 || position > size + 1)
        {
            std::cerr << "Invalid position!" << std::endl;
            return;
        }

        Node<T> *newNode = new Node<T>(data);

        if (position == 1)
        {
            newNode->next = head;
            head = newNode;
            if (tail == nullptr)
            {
                tail = newNode;
            }
        }

        else if (position == size + 1)
        {
            tail->next = newNode;
            tail = newNode;
        }
        else
        {
            Node<T> *current = head;
            for (int i = 1; i < position - 1; ++i)
            {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }

        size++;
    }

    int getSize() const
    {
        return size;
    }

    void print()
    {
        Node<T> *current = head;

        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};
    int main()
    {
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
