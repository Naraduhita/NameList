#include <iostream>
#include <list>
#include <graphics.h>

using namespace std;

class point
{
private:
    int urut;
    int x, y,x1,x2,y1,y2;

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
    point(int _x1, int _x2, int _y1, int _y2){
        x1 = _x1;
        x2 = _x2;
        y1 = _y1;
        y2 = _y2;
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

    int get_x1()
    {
        return x1;
    }

    int get_x2()
    {
        return x2;
    }

    int get_y1()
    {
        return y1;
    }

    int get_y2()
    {
        return y2;
    }
};

// cetak list
void print(list<int> &mylist, int index)
{
    cout << "The list elements stored at the index " << index << ": \n";

    // Each element of the list is a pair on
    // its own
    for (list<int>::iterator i = mylist.begin(); i != mylist.end(); i++)
    {
        // Each element of the list is a pair
        // on its own
        cout << *i << " -> ";
    }
    cout << '\n';
}

// Function to iterate over all the array
void print(list<int> *myContainer, int n)
{
    cout << "myContainer elements:\n\n";

    // looping hingga kurang dari n
    for (int i = 0; i < n; i++)
    {
        print(myContainer[i], i);
    }
}

void tampilname(list<point> *info, int N)
{
    int urut, x, y;

    int gm, gd = DETECT, i;
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
        urut = (*i).get_urut();
        x = (*i).get_x();
        y = (*i).get_y();
        circle(x, y, 8);
    }
    getch();
    closegraph();
}

int main()
{
    int N = 20;
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

    // A
    infoPoint->push_back(point(6, 138, 75));
    infoPoint->push_back(point(7, 150, 50));
    infoPoint->push_back(point(8, 163, 75));
    infoPoint->push_back(point(9, 175, 100));
    infoPoint->push_back(point(10, 200, 100));
    // line(125, 100, 138, 75);
    // line(138, 75, 150, 50);
    // line(138, 75, 163, 75);
    // line(150, 50, 163, 75);
    // line(163, 75, 175, 100);
    // line(175, 100, 200, 100);

    // R
    infoPoint->push_back(point(11, 200, 75));
    infoPoint->push_back(point(12, 200, 50));
    infoPoint->push_back(point(13, 225, 50));
    infoPoint->push_back(point(14, 225, 75));
    infoPoint->push_back(point(15, 250, 100));
    infoPoint->push_back(point(16, 275, 100));
    // line(200,100, 200,75);
    // line(200,75, 200,50);
    // line(200,50, 225,50);
    // line(225,50, 225,75);
    // line(225,75, 250,100);
    // line(200,75, 225,75);
    // line(250,100, 275,100);

    // A
    infoPoint->push_back(point(17, 288, 75));
    infoPoint->push_back(point(18, 300, 50));
    infoPoint->push_back(point(19, 313, 75));
    infoPoint->push_back(point(20, 325, 100));
    // line(275,100,288,75);
    // line(288,75,300,50);
    // line(300,50,313,75);
    // line(313,75,325,100);
    // line(288,75,313,75);

    // smile
    //  setcolor(YELLOW);
    //  circle(364,85,30);
    //  setfillstyle (SOLID_FILL, YELLOW);
    //  floodfill(364, 100, YELLOW);

    // setcolor(2);
    // fillellipse(350,75, 2, 6);
    // fillellipse(375,75, 2, 6);
    // ellipse(364,90,205,335,20,9);
    // ellipse(364,90,205,335,20,10);
    // ellipse(364,90,205,335,20,11);

    // membuat adjencendy list
    //[awal].push_back(tujuan)
    list<int> myContainer[N];
    // N
    myContainer[1].push_back(2);
    myContainer[1].push_back(4);
    myContainer[2].push_back(1);
    myContainer[3].push_back(4);
    myContainer[4].push_back(1);
    myContainer[4].push_back(3);
    myContainer[4].push_back(5);
    // A
    myContainer[5].push_back(4);
    myContainer[5].push_back(6);
    myContainer[6].push_back(5);
    myContainer[6].push_back(8);
    myContainer[6].push_back(7);
    myContainer[7].push_back(6);
    myContainer[7].push_back(8);
    myContainer[8].push_back(7);
    myContainer[8].push_back(6);
    myContainer[8].push_back(9);
    myContainer[9].push_back(8);
    myContainer[9].push_back(10);
    // R
    myContainer[10].push_back(9);
    myContainer[10].push_back(11);
    myContainer[11].push_back(10);
    myContainer[11].push_back(12);
    myContainer[11].push_back(14);
    myContainer[12].push_back(11);
    myContainer[12].push_back(13);
    myContainer[13].push_back(12);
    myContainer[13].push_back(14);
    myContainer[14].push_back(11);
    myContainer[14].push_back(13);
    myContainer[14].push_back(15);
    myContainer[15].push_back(14);
    myContainer[15].push_back(16);
    // A
    myContainer[16].push_back(15);
    myContainer[16].push_back(17);
    myContainer[17].push_back(16);
    myContainer[17].push_back(18);
    myContainer[17].push_back(19);
    myContainer[18].push_back(17);
    myContainer[18].push_back(19);
    myContainer[19].push_back(17);
    myContainer[19].push_back(18);
    myContainer[19].push_back(20);

    // cetak list
    print(myContainer, N);

    // menampilkan graphics
    tampilname(infoPoint, N);

    // line(50, 100, 50, 50);
    // line(50, 50, 100, 100);
    // line(100, 100, 100, 50);
    // line(100, 100, 125, 100);

    return 0;
}