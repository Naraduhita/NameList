#include <iostream>
#include <list>
#include <graphics.h>

using namespace std;

// BFS harus jalan
// list<int>*adj
// tampilan dihapus, BFS jalan baru tampilan
// lalu data posisi -> list<titik> posisi

class point
{
private:
    int urut;
    int x, y;

public:
    // ini adalah constractor
    point(int _urut)
    {
        urut = _urut;
    }

    // ini adalah constractor kedua yang parameternya adalah urut x dan y
    point(int _urut, int _x, int _y)
    {
        x = _x;
        y = _y;
        urut = _urut;
    }

    // ini adalah function getter -> untuk mendapatkan nilai variable urut
    int get_urut()
    {
        return urut;
    }

    int get_x()
    {
        return x;
    }

    int get_y()
    {
        return y;
    }
};

// Function to print list elements
// specified at the index, "index"
void print(list<point> &mylist, int index)
{
    cout << "The list elements stored at the index " << index << ": \n";

    // Each element of the list is a pair on
    // its own
    for (list<point>::iterator i = mylist.begin(); i != mylist.end(); i++)
    {
        // Each element of the list is a pair
        // on its own
        cout << (*i).get_urut() << " -> ";
    }
    cout << '\n';
}

// Function to iterate over all the array
void print(list<point> *nama, int n)
{
    cout << "nama elements:\n\n";

    // Iterating over nama elements
    // Each element is a list on its own
    for (int i = 0; i < n; i++)
    {
        print(nama[i], i);
    }
}

void tampilNama(list<point> *info, int N)
{
    int urut, x, y;

    int gm, gd = DETECT, i;
    initgraph(&gd, &gm, "");
    // int midx, midy;
    int stangle = 45, endangle = 50;
    int radius = 30;

    char data[] = "C:\\MinGW\\lib\\libbgi.a"; // static file

    initgraph(&gd, &gm, data);
    x = getmaxx(); // to get the co-ordinates i.e. x & y
    y = getmaxy();
    cleardevice();

    for (list<point>::iterator i = info->begin(); i != info->end(); i++)
    {
        // Each element of the list is a pair
        // on its own
        // cout << (*i).get_urut() << " -> ";
        urut = (*i).get_urut();
        x = (*i).get_x();
        y = (*i).get_y();
        circle(x, y, 5);

        // cout << "(" << urut << "," << x << "," << y << ") ";
    }
    getch();
    closegraph();
}

int main()
{
    int N = 24;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // membuat pointer yang menunjuk ke list bertipe point
    list<point> *infoPoint;
    // membuat list
    infoPoint = new list<point>;

    // N
    infoPoint->push_back(point(1, 50, 50));
    infoPoint->push_back(point(2, 50, 100));
    infoPoint->push_back(point(3, 100, 50));
    infoPoint->push_back(point(4, 100, 100));
    infoPoint->push_back(point(5, 125, 100));
    //x1,y1,x2,y2
    line(50, 100, 50, 50);
    line(50, 50, 100, 100);
    line(100, 100, 100, 50);
    line(100, 100, 125, 100);

    // A
    infoPoint->push_back(point(6, 138, 75));
    infoPoint->push_back(point(7, 150, 50));
    infoPoint->push_back(point(8, 163, 75));
    infoPoint->push_back(point(9, 175, 100));
    infoPoint->push_back(point(10, 200, 100));
    line(125, 100, 138, 75);
    line(138, 75, 150, 50);
    line(138, 75, 163, 75);
    line(150, 50, 163, 75);
    line(163, 75, 175, 100);
    line(175, 100, 200, 100);

    // R
    infoPoint->push_back(point(11, 200, 75));
    infoPoint->push_back(point(12, 200, 50));
    infoPoint->push_back(point(13, 225, 50));
    infoPoint->push_back(point(14, 225, 75));
    infoPoint->push_back(point(15, 250, 100));
    infoPoint->push_back(point(16, 275, 100));
    line(200, 100, 200, 75);
    line(200, 75, 200, 50);
    line(200, 50, 225, 50);
    line(225, 50, 225, 75);
    line(225, 75, 250, 100);
    line(200, 75, 225, 75);
    line(250, 100, 275, 100);

    // A
    infoPoint->push_back(point(17, 288, 75));
    infoPoint->push_back(point(18, 300, 50));
    infoPoint->push_back(point(19, 313, 75));
    infoPoint->push_back(point(20, 325, 100));
    line(275, 100, 288, 75);
    line(288, 75, 300, 50);
    line(300, 50, 313, 75);
    line(313, 75, 325, 100);
    line(288, 75, 313, 75);

    // smile
    setcolor(YELLOW);
    circle(364, 85, 30);
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(364, 100, YELLOW);

    setcolor(2);
    fillellipse(350, 75, 2, 6);
    fillellipse(375, 75, 2, 6);
    ellipse(364, 90, 205, 335, 20, 9);
    ellipse(364, 90, 205, 335, 20, 10);
    ellipse(364, 90, 205, 335, 20, 11);

    list<point> nama[N];
    // membuat adjacendy list
    // [awal].push_back(tujuan)
    // nama[1].push_back(2);

    // N
    nama[1].push_back(2);
    nama[1].push_back(4);
    nama[2].push_back(1);
    nama[3].push_back(4);
    nama[4].push_back(1);
    nama[4].push_back(3);
    nama[4].push_back(5);
    // A
    nama[5].push_back(4);
    nama[5].push_back(6);
    nama[6].push_back(5);
    nama[6].push_back(8);
    nama[6].push_back(7);
    nama[7].push_back(6);
    nama[7].push_back(8);
    nama[8].push_back(7);
    nama[8].push_back(6);
    nama[8].push_back(9);
    nama[9].push_back(8);
    nama[9].push_back(10);
    // R
    nama[10].push_back(9);
    nama[10].push_back(11);
    nama[11].push_back(10);
    nama[11].push_back(12);
    nama[11].push_back(14);
    nama[12].push_back(11);
    nama[12].push_back(13);
    nama[13].push_back(12);
    nama[13].push_back(14);
    nama[14].push_back(11);
    nama[14].push_back(13);
    nama[14].push_back(15);
    nama[15].push_back(14);
    nama[15].push_back(16);
    // A
    nama[16].push_back(15);
    nama[16].push_back(17);
    nama[17].push_back(16);
    nama[17].push_back(18);
    nama[17].push_back(19);
    nama[18].push_back(17);
    nama[18].push_back(19);
    nama[19].push_back(17);
    nama[19].push_back(18);
    nama[19].push_back(20);

    // cetak list
    print(nama, N);
    getch();
    closegraph();

    // menampilkan grpah
    tampilNama(infoPoint, N);
    cout << "selesai" << endl;
}