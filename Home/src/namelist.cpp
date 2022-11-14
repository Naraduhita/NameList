#include <iostream>
#include <list>
#include <graphics.h>
#include <sstream>
#include <string>
#define TOTAL 100

using namespace std;

class point
{
private:
    int urut;
    int x, y;

public:
    // constractor pertama
    point(int _urut)
    {
        urut = _urut;
    }

    // costractor kedua dgn param urut x dan y
    point(int _urut, int _x, int _y)
    {
        x = _x;
        y = _y;
        urut = _urut;
    }

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

// cetak list
void print(list<point> &mylist, int index)
{
    cout << "The list elements stored at the index " << index << ": \n";
    for (list<point>::iterator i = mylist.begin(); i != mylist.end(); i++)
    {
        cout << (*i).get_urut() << " " << (*i).get_x() << " -> ";
    }
    cout << '\n';
}
void print(list<point> *myContainer, int n)
{
    cout << "myContainer elements:\n\n";
    for (int i = 0; i < n; i++)
    {
        print(myContainer[i], i);
    }
}
void printLine(list<point> &mylist, int index)
{
    cout << "The list elements stored at the index " << index << ": \n";
    for (list<point>::iterator i = mylist.begin(); i != mylist.end(); i++)
    {
        cout << (*i).get_urut() << ""
             << " -> ";
    }
    cout << '\n';
}

void tampilname(list<point> *info, int N, list<point> *myContainer)
{
    int urut, x, y;
    int x2, y2;
    int gm, gd = DETECT, i;
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    initwindow(getmaxwidth(), getmaxheight());
    x = getmaxx();
    y = getmaxy();
    cleardevice();
    cout << x << " " << y << endl;
    for (list<point>::iterator i = info->begin(); i != info->end(); i++)
    {
        cout << (*i).get_urut() << " -> ";
        urut = (*i).get_urut();
        x = (*i).get_x();
        y = (*i).get_y();
        cout << "(" << urut << "," << x << "," << y << ") ";
    }
    cout << endl;
    for (int i = 0; i < TOTAL; i++)
    {
        for (list<point>::iterator i2 = myContainer[i].begin(); i2 != myContainer[i].end(); i2++)
        {
            list<point>::iterator info2 = next(info->begin(), (*i2).get_urut());
            list<point>::iterator info3 = next(info->begin(), i);
            cout << "line from (u, x, y) => (" << (*info3).get_urut() << ", " << (*info3).get_x() << ", " << (*info3).get_y() << ")"
                 << " to (" << (*info2).get_urut() << ", " << (*info2).get_x() << ", " << (*info2).get_y() << ")" << endl;
            line((*info3).get_x(), (*info3).get_y(), (*info2).get_x(), (*info2).get_y());
        }
    }
    getch();
    closegraph();
}

int main()
{
    // membuat pointer yang menunjuk ke list bertipe point
    list<point> *infoPoint;

    // membuat list
    infoPoint = new list<point>;

    // N
    infoPoint->push_back(point(0, 50, 50));
    infoPoint->push_back(point(1, 50, 100));
    infoPoint->push_back(point(2, 100, 50));
    infoPoint->push_back(point(3, 100, 100));
    infoPoint->push_back(point(4, 125, 100));

    // A
    infoPoint->push_back(point(6, 138, 75));
    infoPoint->push_back(point(7, 150, 50));
    infoPoint->push_back(point(8, 163, 75));
    infoPoint->push_back(point(9, 175, 100));
    infoPoint->push_back(point(10, 200, 100));

    // R
    infoPoint->push_back(point(11, 200, 75));
    infoPoint->push_back(point(12, 200, 50));
    infoPoint->push_back(point(13, 225, 50));
    infoPoint->push_back(point(14, 225, 75));
    infoPoint->push_back(point(15, 250, 100));
    infoPoint->push_back(point(16, 275, 100));

    // A
    infoPoint->push_back(point(17, 288, 75));
    infoPoint->push_back(point(18, 300, 50));
    infoPoint->push_back(point(19, 313, 75));
    infoPoint->push_back(point(20, 325, 100));

    // membuat adjencendy list
    //[awal].push_back(tujuan)
    list<point> name[TOTAL];
    // N
    name[0].push_back(1);
    name[0].push_back(3);
    name[2].push_back(3);
    name[3].push_back(4);

    // A
    name[5].push_back(4);
    name[5].push_back(6);
    name[6].push_back(8);
    name[6].push_back(7);
    name[5].push_back(7);
    name[8].push_back(9);

    // R
    name[10].push_back(9);
    name[10].push_back(11);
    name[11].push_back(12);
    name[10].push_back(13);
    name[12].push_back(13);
    name[13].push_back(14);
    name[14].push_back(15);

    // A
    name[16].push_back(15);
    name[16].push_back(17);
    name[17].push_back(18);
    name[16].push_back(18);
    name[18].push_back(19);

    // cetak list
    // print(name, TOTAL);

    // menampilkan graphics
    tampilname(infoPoint, TOTAL, name);

    return 0;
}