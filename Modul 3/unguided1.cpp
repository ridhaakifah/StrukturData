#include <iostream>
#include <string>
using namespace std;

float HitungNilaiAkhir(float uts, float uas, float tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

int main() {
    struct mahasiswa {
        string nama, nim;
        float uts, uas, tugas, nilaiAkhir;
    } mhs[10];

    int n;
    cout << "Jumlah mahasiswa (max 10): ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "Nama: "; getline(cin, mhs[i].nama);
        cout << "NIM : "; getline(cin, mhs[i].nim);
        cout << "UTS : "; cin >> mhs[i].uts;
        cout << "UAS : "; cin >> mhs[i].uas;
        cout << "Tugas: "; cin >> mhs[i].tugas;
        mhs[i].nilaiAkhir = HitungNilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
        cin.ignore();
    }

    cout << "\n== Data Mahasiswa ===\n";
    for (int i = 0; i < n; i++) 
        cout << mhs[i].nama << "(" << mhs [i].nim << ") - Nilai Akhir : "
             << mhs[i].nilaiAkhir << endl;

    return 0;
    

}