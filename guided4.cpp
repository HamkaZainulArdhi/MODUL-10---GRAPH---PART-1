#include <iostream>
#include <string>
using namespace std;

string simpul[7] = {"Bandung", "Bekasi", "Jakarta", "Purwokerto", "Semarang", "Tasikmalaya", "Yogyakarta"};

int busur[7][7] = {
    {0, 5, 0, 15, 0, 0, 0},
    {6, 0, 0, 0, 5, 0, 0},
    {7, 8, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 23, 0, 0, 10, 8},
    {5, 0, 0, 4, 0, 0, 0},
    {0, 0, 0, 4, 9, 0, 0}
};

void tampilGraph() {
    if (simpul && busur) {
        for (int baris = 0; baris < 7; baris++) {
            cout << simpul[baris] << " : ";
            for (int kolom = 0; kolom < 7; kolom++) {
                if (busur[baris][kolom] != 0) {
                    cout << simpul[kolom] << "(" << busur[baris][kolom] << ") ";
                }
            }
            cout << endl;
        }
    }
}

int main() {
    tampilGraph();
    return 0;
}
