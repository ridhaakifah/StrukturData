#include "queue.h"
#include <iostream>
#include <iomanip>
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(const Queue &Q) {
    return (Q.tail == -1);
}

bool isFullQueue(const Queue &Q) {
    return (Q.tail == 4);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) return;
    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail++;
    }
    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) return -1;
    infotype val = Q.info[Q.head];
    if (Q.head == Q.tail) {
        // menjadi kosong
        Q.head = -1;
        Q.tail = -1;
    } else {
        // geser semua ke kiri (head tetap index 0)
        for (int i = Q.head; i < Q.tail; ++i) {
            Q.info[i] = Q.info[i+1];
        }
        Q.tail--;
    }
    return val;
}

void printInfo(const Queue &Q) {
    // Format yang persis: head (2 chars) " - " tail (2 chars) "   | " lalu isi
    // gunakan setw untuk penjajaran
    cout << setw(0); // reset
    // Print head dan tail dengan lebar 2 (so -1 -> "-1", 0 -> " 0")
    cout << setw(0); // no-op
    // Kita cetak manual agar persis
    // head
    if (Q.head == -1) cout << "-1";
    else cout << " " << Q.head;
    cout << " - ";
    // tail
    if (Q.tail == -1) cout << "-1";
    else cout << " " << Q.tail;
    // tiga spasi lalu pipe sesuai modul
    cout << "   | ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        for (int i = Q.head; i <= Q.tail; ++i) {
            cout << Q.info[i];
            if (i < Q.tail) cout << " ";
        }
    }
    cout << endl;
}
