#include "q19.cpp"

int main() {
    BinaryTree tree(10); 

    
    tree.insert(9);
    tree.insert(7);
    tree.insert(8);
    tree.insert(6);
    tree.insert(5);
    tree.insert(3);
    tree.insert(4);

    cout << "Pre-order traversal: ";
    tree.preOrder();
    cout << endl;

    cout << "In-order traversal: ";
    tree.inOrder();
    cout << endl;

    cout << "Post-order traversal: ";
    tree.postOrder();
    cout << endl;

    return 0;
}