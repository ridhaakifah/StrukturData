#include "Doublylist.h"
#include "Doublylist.cpp"
int main()
{
    List L;
    CreateList(L);
    infotype x;
    string cari, hapus;
    address P, found;
  
    for (int i = 0; i < 3; i++)
    {
        cout << "Masukkan nomor polisi: ";
        cin >> x.nopol;
        cout << "Masukkan warna kendaraan: ";
        cin >> x.warna;
        cout << "Masukkan tahun kendaraan: ";
        cin >> x.thnBuat;
 
        if (findElm(L, x.nopol) != NULL)
        {
            cout << "Nomor polisi sudah terdaftar!\n";
        }
        else
        {
            P = alokasi(x);
            insertLast(L, P);
        }
        cout << endl;
    }
    printInfo(L);
   
    cout << "Masukkan Nomor Polisi yang dicari : ";
    cin >> cari;
    found = findElm(L, cari);
    if (found != NULL)
    {
        cout << "\nData ditemukan:\n";
        cout << "Nomor Polisi : " << found->info.nopol << endl;
        cout << "Warna : " << found->info.warna << endl;
        cout << "Tahun : " << found->info.thnBuat << endl;
    }
    else
    {
        cout << "Data tidak ditemukan.\n";
    }
   
    cout << "\nMasukkan Nomor Polisi yang akan dihapus : ";
    cin >> hapus;
    found = findElm(L, hapus);
    if (found != NULL)
    {
        if (found == L.First)
        {
            deleteFirst(L, P);
        }
        else if (found == L.Last)
        {
            deleteLast(L, P);
        }
        else
        {
            deleteAfter(found->prev, P);
        }
        dealokasi(P);
        cout << "Data dengan nomor polisi " << hapus << " berhasil dihapus.\n";
    }
    else
    {
        cout << "Data tidak ditemukan.\n";
    }
    printInfo(L);
    return 0;
}