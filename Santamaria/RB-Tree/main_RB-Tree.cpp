#include "RB-Tree.cpp"

int main() 
{
    RBTree<int> tree;
    tree.insertKey(4);
    tree.insertKey(6);
    tree.insertKey(8);
    tree.insertKey(5);
    tree.insertKey(7);
    tree.insertKey(11);
    tree.insertKey(10);
    tree.insertKey(9);
    tree.insertKey(12);
    tree.insertKey(13);

    
    cout << "\nVisita in order: " << endl;
    tree.inOrder();

    cout << "\nVisita pre order: " << endl;
    tree.preOrder();

    cout << "\nVisita post order: " << endl;
    tree.postOrder();
}