#include <iostream>
#include <memory>

template <typename T>
struct Node 
{
    T data;
    std::unique_ptr<Node> rightSon;
    std::unique_ptr<Node> leftSon;

    Node(T data) : data(data), rightSon(nullptr), leftSon(nullptr) {}
};


template <typename T>
void insert(std::unique_ptr<Node<T>> &dad, T data) 
{
    if(!dad) 
    {
        dad = std::make_unique<Node<T>>(data);
    }

    else if (data < dad->data)
    {
       insert(dad->leftSon, data);
    }

    else if(data > dad->data)
    {
        insert(dad->rightSon, data);
    }
}

template <typename T>
void sort(std::unique_ptr<Node<T>> &dad) 
{
    if (dad)
    {
        sort(dad->leftSon);
        std::cout << dad->data << std::endl;
        sort(dad->rightSon);
    }
    
}

int main() 
{
    std::unique_ptr<Node<int>> dad;

    insert(dad, 10);
    insert(dad, 5);
    insert(dad, 15);
    insert(dad, 3);
    insert(dad, 7);

    std::cout << "Árvore percorrida em ordem:" << std::endl;
    sort(dad);
    std::cout << std::endl;
    return 0;
}