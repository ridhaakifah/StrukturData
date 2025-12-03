#ifndef BSTREE_H
#define BSTREE_H

#define Nil NULL

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void inorder(address root);

// ditambahkan untuk soal no 2
int hitungNode(address root);
int hitungTotal(address root, int start);
int hitungKedalaman(address root, int start);

// ditambahkan untuk soal no 3
void printPreOrder(address root);
void printPostOrder(address root);
#endif