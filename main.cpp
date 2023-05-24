#include "binarySeachTree.h"
#include <iostream>

using namespace std;

int main(){
    binarySeachTree<int> tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    cout << "In-order traversal: ";
    tree.inOrder();

    cout << "Pre-order traversal: ";
    tree.preOrder();

    cout << "Post-order traversal: ";
    tree.postOrder();

    cout << "Tree size: " << tree.getSize() << endl;
    cout << "Is 7 in tree? " << tree.lookup(7) << endl;
    cout << "Is 10 in tree? " << tree.lookup(10) << endl;
    cout << "Height: " << tree.height() << endl;

}