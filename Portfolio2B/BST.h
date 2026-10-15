
#ifndef BST_H
#define BST_H

#include <algorithm>
#include <iostream>

template <typename T>
class BST {
private:
    struct Node {
        T value;
        Node* left;
        Node* right;

        Node(const T& val)
            : value(val), left(nullptr), right(nullptr) {}
    };

    Node* root;
    int nodeCount;

    Node* copyTree(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        Node* newNode = new Node(node->value);
        newNode->left = copyTree(node->left);
        newNode->right = copyTree(node->right);
        return newNode;
    }

    void deleteTree(Node* node) {
        if (node == nullptr) {
            return;
        }

        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

    bool insertHelper(Node*& node, const T& value) {
        if (node == nullptr) {
            node = new Node(value);
            return true;
        }

        if (value < node->value) {
            return insertHelper(node->left, value);
        }

        if (node->value < value) {
            return insertHelper(node->right, value);
        }

        return false;
    }

    bool searchHelper(Node* node, const T& value) const {
        if (node == nullptr) {
            return false;
        }

        if (value == node->value) {
            return true;
        }

        if (value < node->value) {
            return searchHelper(node->left, value);
        }

        return searchHelper(node->right, value);
    }

    Node* findMin(Node* node) const {
        while (node != nullptr && node->left != nullptr) {
            node = node->left;
        }

        return node;
    }

    bool removeHelper(Node*& node, const T& value) {
        if (node == nullptr) {
            return false;
        }

        if (value < node->value) {
            return removeHelper(node->left, value);
        }

        if (node->value < value) {
            return removeHelper(node->right, value);
        }

        if (node->left == nullptr) {
            Node* temp = node;
            node = node->right;
            delete temp;
            return true;
        }

        if (node->right == nullptr) {
            Node* temp = node;
            node = node->left;
            delete temp;
            return true;
        }

        Node* successor = findMin(node->right);
        node->value = successor->value;
        return removeHelper(node->right, successor->value);
    }

    void inorderHelper(Node* node) const {
        if (node == nullptr) {
            return;
        }

        inorderHelper(node->left);
        std::cout << node->value << '\n';
        inorderHelper(node->right);
    }

    template <typename Func>
    void forEachInorderHelper(Node* node, Func& visit) const {
        if (node == nullptr) {
            return;
        }

        forEachInorderHelper(node->left, visit);
        visit(node->value);
        forEachInorderHelper(node->right, visit);
    }

    int heightHelper(Node* node) const {
        if (node == nullptr) {
            return -1;
        }

        return 1 + std::max(heightHelper(node->left),
                            heightHelper(node->right));
    }

    int sizeHelper(Node* node) const {
        if (node == nullptr) {
            return 0;
        }

        return 1 + sizeHelper(node->left) + sizeHelper(node->right);
    }

public:
    BST() : root(nullptr), nodeCount(0) {}

    BST(const BST& other) : root(nullptr), nodeCount(other.nodeCount) {
        root = copyTree(other.root);
    }

    BST& operator=(const BST& other) {
        if (this != &other) {
            Node* newRoot = copyTree(other.root);
            deleteTree(root);
            root = newRoot;
            nodeCount = other.nodeCount;
        }

        return *this;
    }

    ~BST() {
        deleteTree(root);
    }

    void insert(const T& value) {
        if (insertHelper(root, value)) {
            ++nodeCount;
        }
    }

    bool search(const T& value) const {
        return searchHelper(root, value);
    }

    bool remove(const T& value) {
        if (removeHelper(root, value)) {
            --nodeCount;
            return true;
        }

        return false;
    }

    void inorder() const {
        inorderHelper(root);
    }

    template <typename Func>
    void forEachInorder(Func visit) const {
        forEachInorderHelper(root, visit);
    }

    int size() const {
        return nodeCount;
    }

    int height() const {
        return heightHelper(root);
    }

    bool isEmpty() const {
        return root == nullptr;
    }
};

#endif
