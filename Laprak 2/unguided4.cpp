#include <iostream>
#include <string>
using namespace std;

string buatSegitiga(int n) {
    string hasil = "";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            hasil += to_string(j) + " ";
        }
        hasil += "\n";
    }
    return hasil;
}

int main() {
    int n;

    cout << "Masukkan nilai n: ";
    cin >> n;

    cout << buatSegitiga(n);

    return 0;
}
