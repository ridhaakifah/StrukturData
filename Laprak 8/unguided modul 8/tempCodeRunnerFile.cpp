#include <iostream>
#include "queue.h"
#include "queue.cpp"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << " H - T    : Queue Info" << endl;
    cout << "----------------------" << endl;

    printInfo(Q);        // awal: empty
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q);   printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q);   printInfo(Q);
    dequeue(Q);   printInfo(Q);

    // sesuai modul, tampilkan sekali lagi untuk menunjukkan antrean kosong akhir
    // (di modul ada baris -1 - -1 lagi)
    printInfo(Q);

    return 0;
}
