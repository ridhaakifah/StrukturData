#include <iostream>
using namespace std;
void tampil(int a[3][3])
{
    for (int i = 0; i < 3; i++, cout << endl)
        for (int j = 0; j < 3; j++)
            cout << a[i][j] << " ";
}
void tukarArray(int a[3][3], int b[3][3], int i, int j)
{
    int t = a[i][j];
    a[i][j] = b[i][j];
    b[i][j] = t;
}
void tukarPtr(int *p1, int *p2)
{
    int t = *p1;
    *p1 = *p2;
    *p2 = t;
}
int main()
{
    int A[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int B[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int x = 10, y = 20, *p1 = &x, *p2 = &y;
    cout << "A sebelum tukar:\n";
    tampil(A);
    cout << "\nB sebelum tukar:\n";
    tampil(B);
    tukarArray(A, B, 1, 2);
    cout << "\n\nSetelah tukar [1][2]:\nA:\n";
    tampil(A);
    cout << "\nB:\n";
    tampil(B);
    cout << "\n\nSebelum tukar pointer: x=" << x << ", y=" << y;
    tukarPtr(p1, p2);
    cout << "\nSetelah tukar pointer: x=" << x << ", y=" << y << endl;
}