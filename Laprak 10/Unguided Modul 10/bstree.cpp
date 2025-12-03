#include <iostream>
#include "bstree.h"
using namespace std;

address alokasi(infotype x) {
    address P = new Node;
    P->info = x;
    P->left = Nil;
    P->right = Nil;
    return P;
}

void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } 
    else if (x < root->info) {
        insertNode(root->left, x);
    }
    else if (x > root->info) {
        insertNode(root->right, x);
    }
}

address findNode(infotype x, address root) {
    if (root == Nil) return Nil;
    if (x == root->info) return root;
    else if (x < root->info) return findNode(x, root->left);
    else return findNode(x, root->right);
}

void inorder(address root) {
    if (root != Nil) {
        inorder(root->left);
        cout << root->info << " - "; // penambahan min untuk soal no 2
        inorder(root->right);
    }
}

// ditambahkan untuk soal no 2
int hitungNode(address root) {
    if (root == Nil) {
        return 0;
    } else {
        return 1 + hitungNode(root->left) + hitungNode(root->right);
    }
}

int hitungTotal(address root, int start) {
    if (root == Nil) {
        return start;
    } else {
        start += root->info;
        start = hitungTotal(root->left, start);
        start = hitungTotal(root->right, start);
        return start;
    }
}

int hitungKedalaman(address root, int start) {
    if (root == Nil) {
        return start;
    } else {
        int leftDepth = hitungKedalaman(root->left, start + 1);
        int rightDepth = hitungKedalaman(root->right, start + 1);
        return (leftDepth > rightDepth) ? leftDepth : rightDepth;
    }
}

// ditambahkan untuk soal no 3
void printPreOrder(address root) {
    if (root != Nil) {
        cout << root->info << " - ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

void printPostOrder(address root) {
    if (root != Nil) {
        printPostOrder(root->left);
        printPostOrder(root->right);
        cout << root->info << " - ";
    }
}