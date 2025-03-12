#include <iostream>
#include <memory>

template <typename T>
struct Node 
{
    T data;
    std::shared_ptr<Node<T>> next;
    std::shared_ptr<Node<T>> prev;
    
    Node(const T& data) : data(data), next(nullptr), prev(nullptr) {}
};

template <typename T>
class List 
{
    private:
    std::shared_ptr<Node<T>> head;
    std::shared_ptr<Node<T>> tail;
    size_t size;

    public:
    List() : head(nullptr), tail(nullptr), size(0) {}

    void push_front(T data) 
    {
        auto newNode = std::make_shared<Node<T>>(data);

        if(head == nullptr) 
        {
            tail = newNode;
        }
        
        else
        {
            newNode->next = head;
            head->prev = newNode;
        }
        
        head = newNode;
        size++;
    }

    void push_back(T data) 
    {
        auto newNode = std::make_shared<Node<T>>(data);

        if (head == nullptr)
        {
            push_front(data);
        }

        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
            size++;
        }
    }

    void insert(T data, int pos) 
    {
        if(pos < 0 || pos > size) 
        {
            std::cout << "erro" << std::endl;
        }

        else if (pos == 0)
        {
            push_front(data);
        }

        else if (pos == size)
        {
            push_back(data);
        }
        
        else
        {
            auto newNode = std::make_shared<Node<T>>(data);
            auto current = head;

            for (size_t i = 0; i < pos - 1; i++)
            {
                current = current->next;
            }
            
            // current == A
            // A <-> C   
            // A <-> newNode <-> C
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next != nullptr) {
                current->next->prev = newNode;
            }
    
            current->next = newNode;
            size++; 
        }
    }

    void print() 
    {
        auto current = head;

        while (current != nullptr) 
        {
            std::cout << current->data << " ";
            current = current->next;
        }
    }
};

int main() 
{
    List<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_back(4);
    list.push_back(5);
    list.insert(10, 3);

    list.print();
    return 0;
}

