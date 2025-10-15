#include <iostream>
#include "pelajaran.h"
using namespace std;
Pelajaran create_pelajaran(string namaMapel, string kodeMapel)
{
    Pelajaran p;
    p.namaMapel = namaMapel;
    p.kodeMapel = kodeMapel;
    return p;
}
void tampil_pelajaran(Pelajaran pel)
{
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}