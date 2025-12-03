#include<iostream>
#include "tree.h"
#include "tree.cpp"

using namespace std;

int main() {
    BinaryTree tree;

    cout << "===INSERT DATA ===" << endl;
    tree.insert(10);
    tree.insert(15);
    tree.insert(20);
    tree.insert(30);
    tree.insert(35);
    tree.insert(40);
    tree.insert(50);

    cout << "Data yang diinsert: 10, 15, 20, 30, 35, 40, 50" << endl;
    cout << "\nTreversal setelah insert" << endl;
    cout << "Inorder     : "; tree.inorder();
    cout << "Preeorder   : "; tree.inorder();
    cout << "Postorder   : "; tree.inorder();

    cout << "\n=== UPDATE DATA===" << endl;
    cout << "Sebelum update (20-25): " << endl;
    cout << "Inorder : "; tree.inorder();

    tree.update(20, 25);

    cout << "stelah upd  dte (20->25):" <<endl;
    cout << "Inorder : "; tree.inorder();

    cout << "\n=== Delete DATA===" << endl;
    cout << "Sebelum delete (haps subtree dengan root = 30) : " << endl;
    cout << "Inorder : "; tree.inorder();

    tree.deleteValue(30);

    cout << "Stlh delete (subtree dengan root = 30) : " << endl;
    cout << "Inorder : "; tree.inorder();

    return 0;
}