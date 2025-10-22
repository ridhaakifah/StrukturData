#include "Singlylist.h"

void CreateList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
}

void insertFirst (List &L, address P) {
    P->next = L.First;
    L.First = P;
}

void insertLast(List &L, address P ) {
    if (L.First == Nil) {
        // Jika list kosong, insertLast sama dengan insertFirst
        insertFirst(L,P);
    } else {
        // Jika list tidak kosong, cari elemen terakhir
        address Last = L.First;
        while (Last->next != Nil) {
            Last = Last->next;
        }
        // Sambungkan elemen terakhir ke elemen baru (P)
        Last->next = P;
    }
}

void printInfo(List L) {
    address P = L.First;
    if (P == Nil) {
    std::cout << "List Kosong!" << std::endl;
} else {
    while (P != Nil) {
        std :: cout << P->info << " ";
        P = P->next;
    }
    std :: cout << std :: endl;
}
}