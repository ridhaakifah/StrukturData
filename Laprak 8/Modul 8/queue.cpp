//kode itu mengimplementasikan antrian (queue) berbasis array dengan teknik circular buffer (penyimpanan melingkar)
#include "queue.h" 
#include <iostream>

using namespace std; //Menggunakan namespace standar agar tidak perlu menulis std::

// Definisi prosedur untuk membuat queue kosong
void createQueue(Queue &Q) {
    Q.head = 0;  // Set kepala ke indeks 0
    Q.tail = 0;  // Set ekor ke indeks 0
    Q.count = 0;  // Set jumlah elemen ke 0
}

// Definisi fungsi untuk mengecek apakah queue kosong
bool isEmpty(Queue Q) {
    return Q.count == 0; //Kembalikan true jika jumlah elemen adalah 0
}

// Definisi fungsi untuk mengecek apakah queue penuh
bool isFull(Queue Q) {
    return Q.count == MAX_QUEUE; // Kembalikan true jika jumlah elemen sama dengan maks
}

// Definisi prosedur untuk menambahkan elemen (enqueue)
void enqueue(Queue &Q, int x) {
    if (!isFull(Q)) { // Jika queue tidak penuh
        Q.info[Q.tail] = x; // Masukkan data (x) ke posisi ekor (tail)
        // Pindahkan ekor secara circular (memutar)
        Q.tail = (Q.tail + 1) % MAX_QUEUE; 
        Q.count++; //Tambah jumlah elemen
    } else { // Jika queue penuh
        cout << "Antrean Penuh!" << endl; //Tampilkan pesan error
    }
}

//Definisi fungsi untuk menghapus elemen (dequeue)
int dequeue(Queue &Q) {
    if (!isEmpty(Q)) { // Jika queue tidak kosong
        int x = Q.info[Q.head]; // Ambil data di posisi kepala (head)
        //Pindahkan kepala secara circular (memutar)
        Q.head = (Q.head + 1) % MAX_QUEUE;
        Q.count--; // Kurangi jumlah elemen
        return x; // Kembalikan data yang diambil
    } else { // Jika queue kosong
        cout << "Antrean Kosong!" << endl; //Tampilkan pesan error
        return -1; // Kembalikan nilai -1 sebagai tanda error
    }
}

// Definisi prosedur untuk menampilkan isi queue 
void printInfo(Queue Q) {
    cout << "Isi Queue: [ "; // Tampilkan awalan
    if (!isEmpty(Q)) { // ika tidak kosong
        int i = Q.head; // Mulai dari kepala
        int n = 0; //Penghitung elemen yang sudah dicetak
        while (n < Q.count) { // Ulangi sebanyak jumlah elemen
            cout << Q.info[i] << " "; // Cetak info
            i = (i + 1) % MAX_QUEUE; // Geser 'i' secara circular
            n++; // Tambah penghitung
        }
    }
    cout << "]" << endl; // Tampilkan akhiran
}