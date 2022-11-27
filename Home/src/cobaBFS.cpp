#include <iostream>
#include <list>
#include <graphics.h>

using namespace std;

// mendefiniskan class vertex
class Vertex
{
private:
    int nomor;
    int x;
    int y;
    string nama;

public:
    // membuat constructor vertex
    // constructor ini akan dijalankan secara otomatis saat objek dibuat
    Vertex(int _nomor, int _x, int _y, string _nama)
    {
        nomor = _nomor;
        x = _x;
        y = _y;
        nama = _nama;
    }

    string getNama()
    {
        return nama;
    }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }
};

// mendefiniskan class myGraph
class myGraph
{
private:
    int JV;                   // jumlah vertex
    list<Vertex> *infoVertex; // mendefiniskan pointer ke list vertex
                              //  yang menunjuk list dari vertex
    list<int> *adj;           // membuat pointer ke list
    // membuat konstraktor
public:
    myGraph(int jumlahvertex)
    {
        JV = jumlahvertex;
        // membuat list vertex
        infoVertex = new list<Vertex>;
        adj = new list<int>[jumlahvertex];
    }

    // membuat function sambung
    void sambung(int dari, int ke)
    {
        adj[dari].push_back(ke);
    }

    // membuat function simpan vertex
    void simpanVertex(int _nomor, int _x, int _y, string _nama)
    {
        // membuat vertex x yang akan ditambahkan ke list
        Vertex x = Vertex(_nomor, _x, _y, _nama);
        // menambhakn x ke list infoVertex
        infoVertex[0].push_back(x);
    }

    // mendapatkan vertex
    list<Vertex>::iterator getVertex(int v)
    {

        list<Vertex>::iterator vx;
        vx = infoVertex->begin();

        if (v < 0 || v >= JV)
            v = 0;

        for (int i = v; i > 0; i--)
            vx++;

        return vx;
    }

    // menampilkan edge
    void tampilEdge()
    {
        list<int> la;
        list<int>::iterator i;
        list<Vertex>::iterator asal;
        list<Vertex>::iterator tujuan;
        int x1, x2, y1, y2;
        // Vertex asal = Vertex(0, 0, 0, "");
        // Vertex tujuan = Vertex(0, 0, 0, "");

        for (int v = 0; v < JV; v++)
        {
            cout << v; // titik awal
            // mendapatkan titik awal
            asal = getVertex(v);
            x1 = asal->getX();
            y1 = asal->getY();
            for (i = adj[v].begin(); i != adj[v].end(); ++i)
            {
                cout << "-> " << (*i); // titik tujuan
                tujuan = getVertex(*i);
                x2 = tujuan->getX();
                y2 = tujuan->getY();
                line(x1, y1, x2, y2);
            }
            cout << ("\n");
        }
    }

    // menampilkan vertex
    void tampilVertex()
    {
        list<int> la;
        list<Vertex>::iterator i;
        Vertex myV = Vertex(0, 0, 0, "");
        int x, y;
        string nama;

        initwindow(900, 700, "My Graph");

        // menampilkan vertex V
        for (i = infoVertex[0].begin(); i != infoVertex[0].end(); ++i)
        {
            char snama[80];
            nama = i->getNama();
            // sprintf(snama, "%s", nama);
            strcpy(snama, nama.c_str());
            x = i->getX();
            y = i->getY();
            circle(x , y, 20);
            outtextxy(x, y, snama);
        }

        // lakukan modifikasi di bagian setelah ini untuk menambahkan instruksi yang
        // digunakan untuk menampilkan Edge E
        // gunakan LOOP yang sama dengan yang ada di function tampilList()
        // a. untuk setiap Edge E, dapatkan titik awal (x1,y1)
        // b. dapatkan titik akhir (x2,y2)
        // c. untuk Edge E, tampilkan garisnya dengan instruksi line(x1,y1,x2,y2)
        // d. idem untuk menampilkan tulisan atau info lainnya
        tampilEdge();

        while (!kbhit())
        {
            delay(200);
        }
    }
};

int main()
{

    // membuat graph dengan jumlah 6
    myGraph g(6); // ini membuat objek dengan nmaa g berjenis graf

    // mendefinisikan vertex
    g.simpanVertex(0, 100, 400, "bandara"); // anggap aja bandara its
    g.simpanVertex(1, 300, 100, "perumdos");
    g.simpanVertex(2, 600, 100, "pedalaman");
    g.simpanVertex(3, 300, 600, "KTT 3");
    g.simpanVertex(4, 600, 600, "Keputih");
    g.simpanVertex(5, 800, 400, "Gebang");

    // membuat edge ke x
    g.sambung(0, 1);
    g.sambung(0, 3);
    g.sambung(1, 0);
    g.sambung(1, 4);
    g.sambung(1, 2);
    g.sambung(2, 1);
    g.sambung(2, 4);
    g.sambung(2, 5);
    g.sambung(5, 2);
    g.sambung(5, 4);
    g.sambung(4, 5);
    g.sambung(4, 2);
    g.sambung(4, 1);
    g.sambung(4, 3);
    g.sambung(3, 4);
    g.sambung(3, 0);

    // menampilkakn vertex
    g.tampilVertex();

    // menampilkan edge
    // g.tampilEdge();
}