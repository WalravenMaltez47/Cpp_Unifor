#include <iostream>
#include <memory>

template <typename T>
struct Node 
{
    T data;
    std::unique_ptr<Node> right;
    std::unique_ptr<Node> left;

    Node(T data) : data(data), right(nullptr), left(nullptr) {}
};


template <typename T>
void insert(std::unique_ptr<Node<T>> &root, T data) 
{
    if(!root) 
    {
        root = std::make_unique<Node<T>>(data);
    }

    else if (data < root->data)
    {
       insert(root->left, data);
    }

    else if(data > root->data)
    {
        insert(root->right, data);
    }
}

template <typename T>
void order(std::unique_ptr<Node<T>> &root) 
{
    if (root)
    {
        order(root->left);
        std::cout << root->data << std::endl;
        order(root->right);
    }
    
}

int main() 
{
    std::unique_ptr<Node<int>> root;

    insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 7);

    std::cout << "Árvore percorrida em ordem:" << std::endl;
    order(root);
    std::cout << std::endl;
    return 0;
}