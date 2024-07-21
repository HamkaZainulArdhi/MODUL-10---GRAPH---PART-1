#include <iostream>
#include <string>

using namespace std;

const int MAX_SIMPUL = 10; 
const int INF = 999999; 

int jumlahSimpul = 5;
string *dataSimpul;
int **dataBusur;
bool cekMatrik = false;

struct graph {
    graph *kanan;
    string data;
    graph *kiri;
};

graph *simpul;
graph *awal;
graph *akhir;
graph **alamat;
graph *helperA;
graph *helperB;

void inisiasi() {
    awal = NULL;
    akhir = NULL;
}

bool graphKosong() {
    if (awal == NULL && akhir == NULL) {
        return true;
    } else {
        return false;
    }
}

void buatMatriks() {
    dataSimpul = new string[MAX_SIMPUL];
    dataBusur = new int*[MAX_SIMPUL];
    dataBusur[0] = new int[MAX_SIMPUL * MAX_SIMPUL];

    for (int i = 1; i < MAX_SIMPUL; i++) {
        dataBusur[i] = dataBusur[i-1] + MAX_SIMPUL;
    }

    cout << "Silahkan masukkan nama simpul " << endl;
    for (int i = 0; i < jumlahSimpul; i++) {
        cout << "Kota " << i + 1 << " : ";
        cin >> dataSimpul[i];
    }

    cout << "Silahkan masukkan bobot antar simpul " << endl;
    for (int baris = 0; baris < jumlahSimpul; baris++) {
        for (int kolom = 0; kolom < jumlahSimpul; kolom++) {
            cout << dataSimpul[baris] << " --> " << dataSimpul[kolom] << " : ";
            cin >> dataBusur[baris][kolom];
        }
    }
    cekMatrik = true;
}

void buatSimpulGraph() {
    alamat = new graph*[MAX_SIMPUL];
    buatMatriks();
    for (int i = 0; i < jumlahSimpul; i++) {
        if (graphKosong()) {
            simpul = new graph;
            simpul->data = dataSimpul[i];
            simpul->kanan = NULL;
            simpul->kiri = NULL;
            awal = simpul;
            akhir = simpul;
            alamat[i] = awal;
        } else {
            simpul = new graph;
            simpul->data = dataSimpul[i];
            akhir->kiri = simpul;
            akhir = simpul;
            simpul->kiri = NULL;
            simpul->kanan = NULL;
            alamat[i] = akhir;
        }
    }

    helperA = awal;
    for (int baris = 0; baris < jumlahSimpul; baris++) {
        helperB = helperA;
        for (int kolom = 0; kolom < jumlahSimpul; kolom++) {
            if (dataBusur[baris][kolom] != 0) {
                simpul = new graph;
                simpul->data = to_string(dataBusur[baris][kolom]);
                helperB->kanan = simpul;
                simpul->kiri = alamat[kolom];
                simpul->kanan = NULL;
                helperB = simpul;
            }
        }
        helperA = helperA->kiri;
    }
}

void tampilGraph() {
    if (!graphKosong()) {
        helperA = awal;
        while (helperA != NULL) {
            cout << helperA->data << " : ";
            helperB = helperA->kanan;
            while (helperB != NULL) {
                cout << helperB->kiri->data << " : " << helperB->data << " ";
                helperB = helperB->kanan;
            }
            cout << endl;
            helperA = helperA->kiri;
        }
    } else {
        cout << "Graph kosong...!!!" << endl;
    }
}

void dijkstra(int src, int dest) {
    int dist[MAX_SIMPUL];
    bool sptSet[MAX_SIMPUL];
    int parent[MAX_SIMPUL];

    for (int i = 0; i < jumlahSimpul; i++) {
        dist[i] = INF;
        sptSet[i] = false;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < jumlahSimpul - 1; count++) {
        int u = -1;

        for (int i = 0; i < jumlahSimpul; i++) {
            if (!sptSet[i] && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }

        sptSet[u] = true;

        for (int v = 0; v < jumlahSimpul; v++) {
            if (!sptSet[v] && dataBusur[u][v] && dist[u] != INF && dist[u] + dataBusur[u][v] < dist[v]) {
                dist[v] = dist[u] + dataBusur[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Jarak terpendek dari " << dataSimpul[src] << " ke " << dataSimpul[dest] << " adalah: " << dist[dest] << endl;
    cout << "Jalur: ";
    int crawl = dest;
    while (parent[crawl] != -1) {
        cout << dataSimpul[crawl];
        crawl = parent[crawl];
        if (crawl != -1) {
            cout << " <- ";
        }
    }
    cout << endl;
}

int main() {
    inisiasi();
    cout << "Silahkan masukkan jumlah kota: ";
    cin >> jumlahSimpul;
    buatSimpulGraph();
    tampilGraph();

    int src, dest;
    cout << "Masukkan nomor kota awal (0 - " << jumlahSimpul - 1 << "): ";
    cin >> src;
    cout << "Masukkan nomor kota tujuan (0 - " << jumlahSimpul - 1 << "): ";
    cin >> dest;

    dijkstra(src, dest);

    return 0;
}
