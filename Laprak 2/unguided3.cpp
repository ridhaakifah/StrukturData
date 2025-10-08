#include <iostream>
#define MAX 100
using namespace std;

float hitungRata(int nilai[], int N) {
    int jumlah = 0;
    for (int i = 0; i < N; i++) {
        jumlah = jumlah + nilai[i];
    }
    return (float) jumlah / N;
}

int cariMaks(int nilai[], int N) {
    int maks = nilai[0];
    for (int i = 1; i < N; i++) {
        if (nilai[i] > maks) {
            maks = nilai[i];
        }
    }
    return maks;
}

int cariMin(int nilai[], int N) {
    int min = nilai[0];
    for (int i = 1; i < N; i++) {
        if (nilai[i] < min) {
            min = nilai[i];
        }
    }
    return min;
}

int main() {
    int N;
    int nilai[MAX];

    cout << "Masukkan jumlah siswa: ";
    cin >> N;

    for (int i = 0; i < N; i++) {
        cout << "Nilai siswa ke-" << i+1 << " : ";
        cin >> nilai[i];
    }

    float rata = hitungRata(nilai, N);
    int maks = cariMaks(nilai, N);
    int min  = cariMin(nilai, N);

    cout << "\nHasil Perhitungan:\n";
    cout << "Rata-rata kelas = " << rata << endl;
    cout << "Nilai tertinggi = " << maks << endl;
    cout << "Nilai terendah  = " << min << endl;

    return 0;
}
