#include "Doublylist.h"
void CreateList(List &L) { L.First = L.Last = NULL; }
address alokasi(infotype x)
{
    address P = new ElmList;
    P->info = x;
    P->next = P->prev = NULL;
    return P;
}
void dealokasi(address &P)
{
    delete P;
    P = NULL;
}
void printInfo(List L)
{
    if (!L.First)
    {
        cout << "List kosong\n";
        return;
    }
    address P = L.First;
    int i = 1;
    cout << "\nDATA LIST:\n";
    while (P)
    {
        cout << "Data ke-" << i++ << endl;
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna : " << P->info.warna << endl;
        cout << "Tahun : " << P->info.thnBuat << "\n\n";
        P = P->next;
    }
}
void insertLast(List &L, address P)
{
    if (!L.First)
        L.First = L.Last = P;
    else
    {
        L.Last->next = P;
        P->prev = L.Last;
        L.Last = P;
    }
}
address findElm(List L, string nopol)
{
    for (address P = L.First; P; P = P->next)
        if (P->info.nopol == nopol)
            return P;
    return NULL;
}
void deleteFirst(List &L, address &P)
{
    if (!L.First)
        return;
    P = L.First;
    if (L.First == L.Last)
        L.First = L.Last = NULL;
    else
    {
        L.First = L.First->next;
        L.First->prev = NULL;
    }
    P->next = NULL;
}
void deleteLast(List &L, address &P)
{
    if (!L.Last)
        return;
    P = L.Last;
    if (L.First == L.Last)
        L.First = L.Last = NULL;
    else
    {
        L.Last = L.Last->prev;
        L.Last->next = NULL;
    }
    P->prev = NULL;
}
void deleteAfter(address Prec, address &P)
{
    if (!Prec || !Prec->next)
        return;
    P = Prec->next;
    Prec->next = P->next;
    if (P->next)
        P->next->prev = Prec;
    P->next = P->prev = NULL;
}