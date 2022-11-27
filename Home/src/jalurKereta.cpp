#include <graphics.h>
#include <iostream>
#include <list>
#include <conio.h>

using namespace std;

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

// mendefiniskan class jalur
class jalur
{
private:
    int JV;                   // jumlah vertex
    list<Vertex> *infoVertex; // mendefiniskan pointer ke list vertex
                              //  yang menunjuk list dari vertex
    list<int> *adj;           // membuat pointer ke list
    // membuat konstraktor
public:
    jalur(int jumlahvertex)
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

        /*Initwindow untuk membuat */
        initwindow(1000, 1000, "My Graph");
        setbkcolor(BLACK);
        cleardevice();
        /*readimagefile untuk menampilkan gambar dengan format
            "alamat/nama file", x1, y1, x2, y2*/
        readimagefile("Home/src/BusSurabaya.jpg", 650, 50, 990, 650);

        // menampilkan vertex V
        for (i = infoVertex[0].begin(); i != infoVertex[0].end(); ++i)
        {
            char snama[80];
            nama = i->getNama();
            // sprintf(snama, "%s", nama);
            strcpy(snama, nama.c_str());
            x = i->getX();
            y = i->getY();
            circle(x, y, 5);
            outtextxy(x - 170, y - 8, snama);

            outtextxy(285, 80, "Rajawali");
            outtextxy(285, 65, "Halte");
            outtextxy(355, 80, "Jembatan Merah");
            outtextxy(355, 65, "Halte");
            outtextxy(350, 720, "Terminal Purabaya");
            outtextxy(400, 107, "Halte Veteran");
            outtextxy(4000, 132, "Halte Tugu Pahlawan");
            outtextxy(400, 162, "Halte Alun-alun Contong");
            outtextxy(400, 192, "Halte Siola");
            outtextxy(400, 162, "Halte Alun-alun Contong");
            outtextxy(400, 222, "Halte Tunjungan");
            outtextxy(400, 252, "Halte Simpang Dukuh");
            outtextxy(430, 292, "Halte Gubernur Suryo");
            outtextxy(420, 312, "Halte Panglima Sudirman");
            outtextxy(400, 332, "Halte Sono Kembang");
            outtextxy(400, 362, "Halte Urip Sumoaharjo");
            outtextxy(400, 392, "Halte Santa Maria");
            outtextxy(400, 422, "Halte Marmoyo");
            outtextxy(400, 452, "Halte Joyoboyo");
            outtextxy(400, 482, "Halte RSAL");
            outtextxy(400, 512, "Halte Margorejo");
            outtextxy(400, 542, "Halte Wonocolo");
            outtextxy(400, 572, "Halte UIN");
            outtextxy(400, 602, "Halte Jemur Ngawinan");
            outtextxy(400, 632, "Halte Siwalankerto");
            outtextxy(400, 662, "Halte Kerto Menanggal");
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
    jalur g(50); // ini membuat objek dengan nmaa g berjenis graf

    // mendefinisikan vertex
    g.simpanVertex(0, 300, 670, "Halte Dukuh Menanggal"); // anggap aja bandara its
    g.simpanVertex(1, 300, 640, "Halte Siwalankerto");
    g.simpanVertex(2, 300, 610, "Halte Taman Pelangi");
    g.simpanVertex(3, 300, 580, "Halte RS Bhayangkara");
    g.simpanVertex(4, 300, 550, "Halte UBHARA");
    g.simpanVertex(5, 300, 520, "Halte PUSVETMA");
    g.simpanVertex(6, 300, 490, "Halte Ketintang");
    g.simpanVertex(7, 300, 460, "Halte Joyoboyo");
    g.simpanVertex(8, 300, 430, "Halte Museum BI");
    g.simpanVertex(9, 300, 400, "Halte Pandigilng");
    g.simpanVertex(10, 300, 370, "Halte Basra");
    g.simpanVertex(11, 300, 340, "Halte Kaliasin");
    g.simpanVertex(12, 300, 310, "");

    g.simpanVertex(13, 280, 290, "Halte Embong Malang");
    g.simpanVertex(14, 260, 270, "");
    g.simpanVertex(15, 260, 240, "Halte Blauran");
    g.simpanVertex(16, 260, 210, "Halte Pimgadi");
    g.simpanVertex(17, 260, 180, "Halte Pasar Turi");
    g.simpanVertex(18, 260, 160, " ");

    g.simpanVertex(19, 240, 140, "Halte Masjid Kemayoran");
    g.simpanVertex(20, 210, 120, "Halte Indrapura");
    g.simpanVertex(21, 210, 100, " ");
    g.simpanVertex(22, 280, 100, "");
    g.simpanVertex(23, 350, 100, "");
    g.simpanVertex(24, 390, 100, "");

    g.simpanVertex(25, 390, 115, "");
    g.simpanVertex(26, 390, 140, "");
    g.simpanVertex(27, 390, 170, "");
    g.simpanVertex(28, 390, 200, "");
    g.simpanVertex(29, 390, 230, "");
    g.simpanVertex(30, 390, 260, "");
    g.simpanVertex(31, 390, 290, "");
    g.simpanVertex(32, 410, 300, "");
    g.simpanVertex(32, 450, 310, "");

    g.simpanVertex(33, 410, 320, "");
    g.simpanVertex(34, 390, 340, "");
    g.simpanVertex(35, 390, 370, "");
    g.simpanVertex(36, 390, 400, "");
    g.simpanVertex(37, 390, 430, "");
    g.simpanVertex(38, 390, 460, "");
    g.simpanVertex(39, 390, 490, "");
    g.simpanVertex(40, 390, 520, "");
    g.simpanVertex(41, 390, 550, "");
    g.simpanVertex(42, 390, 580, "");
    g.simpanVertex(43, 390, 610, "");
    g.simpanVertex(44, 390, 640, "");
    g.simpanVertex(45, 390, 670, "");
    g.simpanVertex(46, 350, 700, "");

    // membuat edge ke x
    g.sambung(0, 1);
    g.sambung(1, 2);
    g.sambung(2, 3);
    g.sambung(3, 4);
    g.sambung(4, 5);
    g.sambung(5, 6);
    g.sambung(6, 7);
    g.sambung(7, 8);
    g.sambung(8, 9);
    g.sambung(9, 10);
    g.sambung(10, 11);
    g.sambung(11, 12);
    g.sambung(12, 13);
    g.sambung(13, 14);
    g.sambung(14, 15);
    g.sambung(15, 16);
    g.sambung(16, 17);
    g.sambung(17, 18);
    g.sambung(18, 19);
    g.sambung(19, 20);
    g.sambung(20, 21);
    g.sambung(21, 22);
    g.sambung(22, 23);
    g.sambung(23, 24);
    g.sambung(24, 25);
    g.sambung(25, 26);
    g.sambung(26, 27);
    g.sambung(27, 28);
    g.sambung(28, 29);
    g.sambung(29, 30);
    g.sambung(30, 31);
    g.sambung(31, 32);
    g.sambung(32, 33);
    g.sambung(33, 34);
    g.sambung(34, 35);
    g.sambung(35, 36);
    g.sambung(36, 37);
    g.sambung(37, 38);
    g.sambung(38, 39);
    g.sambung(39, 40);
    g.sambung(40, 41);
    g.sambung(41, 42);
    g.sambung(42, 43);
    g.sambung(43, 44);
    g.sambung(44, 45);
    g.sambung(45, 46);
    g.sambung(46, 47);
    g.sambung(47, 0);

    // menampilkakn vertex
    g.tampilVertex();

    // menampilkan edge
    // g.tampilEdge();

    getch();
    closegraph();

    return 0;
}