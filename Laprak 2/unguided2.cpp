#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Masukkan jumlah elemen array: ";
    cin >> N;

    int *arr = new int[N];   

    for (int i = 0; i < N; i++) {
        cout << "Elemen ke-" << i+1 << " : ";
        cin >> *(arr + i);   
    }

    int jumlah = 0;
    int maks = *arr;
    int min = *arr;

    for (int i = 0; i < N; i++) {
        int nilai = *(arr + i);   
        jumlah += nilai;
        if (nilai > maks) maks = nilai;
        if (nilai < min) min = nilai;
    }

    cout << "\nHasil Perhitungan:\n";
    cout << "Jumlah seluruh elemen = " << jumlah << endl;
    cout << "Nilai maksimum        = " << maks << endl;
    cout << "Nilai minimum         = " << min << endl;

    delete[] arr; 
    return 0;
}
