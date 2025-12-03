#include <iostream>
#include "bstree.h"
#include "bstree.cpp"

using namespace std;

int main() {
   cout << "hello World" << endl;
   address root = Nil;
   insertNode(root, 1);
   insertNode(root, 2);
   insertNode(root, 6);
   insertNode(root, 4);
   insertNode(root, 5);
   insertNode(root, 3);
   insertNode(root, 6);
   insertNode(root, 7);
   inorder(root);

   // tambahan untuk soal no 2
   cout<<"\n";
   cout<<"kedalaman : "<< hitungKedalaman(root,0) << endl;
   cout<<"jumlah Node : "<< hitungNode(root) << endl;
   cout<<"total : "<< hitungTotal(root, 0) << endl;

   // tambahan untuk soal no 3
   cout << "\nPreOrder : ";
   printPreOrder(root);

   cout << "\nPostOrder: ";
   printPostOrder(root);
   return 0;
}