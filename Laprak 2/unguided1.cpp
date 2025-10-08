#include <iostream>
#define MHS 5
#define MATKUL 3

using namespace std;

int main() {
    string nama[MHS];
    float nilai[MHS][MATKUL];
    float rata[MHS];
    int i, j;
    int idxTerbaik = 0;

    for (i = 0; i < MHS; i++) {
        cout << "Masukkan nama mahasiswa ke-" << i+1 << " : ";
        cin >> nama[i];
        float total = 0;
        for (j = 0; j < MATKUL; j++) {
            cout << "  Nilai mata kuliah " << j+1 << " : ";
            cin >> nilai[i][j];
            total = total + nilai[i][j];
        }
        rata[i] = total / MATKUL;
        cout << endl;
    }

    for (i = 1; i < MHS; i++) {
        if (rata[i] > rata[idxTerbaik]) {
            idxTerbaik = i;
        }
    }

    cout << "\nNama\tM1\tM2\tM3\tRata-rata\tKeterangan\n";
    cout << "-------------------------------------------------------\n";
    for (i = 0; i < MHS; i++) {
        cout << nama[i] << "\t";
        for (j = 0; j < MATKUL; j++) {
            cout << nilai[i][j] << "\t";
        }
        cout << rata[i] << "\t";
        if (i == idxTerbaik) {
            cout << "Terbaik";
        }
        cout << endl;
    }

    cout << "-------------------------------------------------------\n";
    cout << "Mahasiswa terbaik: " << nama[idxTerbaik]
         << " dengan rata-rata " << rata[idxTerbaik] << endl;

    return 0;
}
