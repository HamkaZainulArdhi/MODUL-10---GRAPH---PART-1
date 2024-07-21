#include <iostream>
#include <string>

using namespace std;

int jumlahSimpul = 5;
string *dataSimpul;
int **dataBusur;
bool cekMatrik = false;

struct graph{
    graph *kanan;
    string data;
    graph *kiri;
};

graph *simpul;
graph *busur;
graph *awal;
graph *akhir;
graph **alamat;
graph *helperA;
graph *helperB;

void inisiasi(){
    awal = NULL;
    akhir = NULL;
}

bool graphKosong(){
    if(awal == NULL && akhir == NULL){
        return true;
    }else{
        return false;
    }
}

void buatMatriks(){
    dataSimpul = new string[jumlahSimpul];
    dataBusur = new int*[jumlahSimpul];
    dataBusur[0] = new int[jumlahSimpul * jumlahSimpul];

    for(int i = 1; i < jumlahSimpul; i++){
        dataBusur[i] = dataBusur[i-1] + jumlahSimpul;
    }

    cout<<"Silahkan masukkan nama simpul "<<endl;
    for(int i = 0; i < jumlahSimpul; i++){
        cout<<"Kota "<<i+1<<" : ";
        cin>>dataSimpul[i];
    }

    cout<<"Silahkan masukkan bobot antar simpul "<<endl;
    for(int baris = 0; baris < jumlahSimpul; baris++){
        for(int kolom = 0; kolom < jumlahSimpul; kolom++){
            cout<<dataSimpul[baris]<<" --> "<<dataSimpul[kolom]<<" : ";
            cin>> dataBusur[baris][kolom];
        }
    }
    cekMatrik = true;

}

void buatSimpulGraph(){
alamat = new graph*[jumlahSimpul];
buatMatriks();
    for(int i = 0; i < jumlahSimpul; i++){
        if(graphKosong()){
            simpul = new graph;
            simpul->data = dataSimpul[i];
            simpul->kanan = NULL;
            simpul->kiri = NULL;
            awal = simpul;
            akhir = simpul;
            alamat[i] = awal; 
        }else{
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
    for(int baris = 0; baris < jumlahSimpul; baris++){
        helperB = helperA;
        for(int kolom = 0; kolom < jumlahSimpul; kolom++){
            if(dataBusur[baris][kolom] != 0){
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

void tampilGraph(){
    if(!graphKosong()){
        helperA = awal;
        while(helperA != NULL){
            cout<<helperA->data<<" : ";
            helperB = helperA->kanan;
            while(helperB != NULL){
                cout<<helperB->kiri->data<<" : "<<helperB->data<<" ";
                helperB = helperB->kanan;
            }
            cout<<endl;
            helperA = helperA->kiri;
        }
    }else{
        cout<<"Graph kosong...!!!"<<endl;
    }
}

int main(){
    inisiasi();
    cout<<"Silahkan masukkan jumlah kota : ";
    cin>>jumlahSimpul;
    buatSimpulGraph();
    tampilGraph();
    return 0;
}