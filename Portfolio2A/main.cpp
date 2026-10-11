#include <iostream>
#include "BST.h"

int main() {
    BST<int> tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    std::cout << "Inorder: ";
    tree.inorder();

    std::cout << "Preorder: ";
    tree.preorder();

    std::cout << "Postorder: ";
    tree.postorder();

    std::cout << "Levelorder: ";
    tree.levelorder();

    std::cout << "Search 40: " << tree.search(40) << '\n';
    std::cout << "Search 90: " << tree.search(90) << '\n';
    std::cout << "Size: " << tree.size() << '\n';
    std::cout << "Height: " << tree.height() << '\n';

    tree.remove(20);
    tree.remove(30);
    tree.remove(50);

    std::cout << "After removals: ";
    tree.inorder();

    BST<int> copy = tree;
    copy.insert(100);

    std::cout << "Original: ";
    tree.inorder();

    std::cout << "Copy: ";
    copy.inorder();

    return 0;
}
