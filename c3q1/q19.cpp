
#include "q19.h"

BinaryTree::BinaryTree(int maxSize) {
    size = maxSize;
    tree = new int[size];
    for (int i = 0; i < size; ++i) {
        tree[i] = -1; 
    }
}

BinaryTree::~BinaryTree() {
    delete[] tree;
}

void BinaryTree::insert(int value) {
  
    for (int i = 0; i < size; ++i) {
        if (tree[i] == -1) {
            tree[i] = value;
            break;
        }
    }
}

void BinaryTree::preOrderTraversal(int index) {
    if (index >= size || tree[index] == -1) {
        return;
    }
    std::cout << tree[index] << " "; 
    preOrderTraversal(2 * index + 1); 
    preOrderTraversal(2 * index + 2);
}

void BinaryTree::inOrderTraversal(int index) {
    if (index >= size || tree[index] == -1) {
        return;
    }
    inOrderTraversal(2 * index + 1); 
    std::cout << tree[index] << " "; 
    inOrderTraversal(2 * index + 2);
}

void BinaryTree::postOrderTraversal(int index) {
    if (index >= size || tree[index] == -1) {
        return;
    }
    postOrderTraversal(2 * index + 1); 
    postOrderTraversal(2 * index + 2); 
    std::cout << tree[index] << " ";  
}

void BinaryTree::preOrder() {
    preOrderTraversal(0); 
}

void BinaryTree::inOrder() {
    inOrderTraversal(0); 
}

void BinaryTree::postOrder() {
    postOrderTraversal(0); 
}
