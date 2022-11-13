#include <iostream>
#include <list>
#include <graphics.h>

using namespace std;

class titik {
    private : 
    int urut;
    int x, y;

    public : 
    // ini adalah constractor 
    titik(int _urut) {
        urut = _urut;
    }

    // ini adalah constractor kedua yang parameternya adalah urut x dan y
    titik(int _urut, int _x, int _y) {
        x = _x;
        y = _y;
        urut = _urut;
    }

    // ini adalah function getter -> untuk mendapatkan nilai variable urut 
    int get_urut() {
        return urut;
    }

    int get_x() {
        return x;
    }

    int get_y() {
        return y;
    }
};

// Function to print list elements
// specified at the index, "index"
void print(list<titik>& mylist, int index)
{
    cout << "The list elements stored at the index " << 
             index << ": \n";
  
    // Each element of the list is a pair on 
    // its own
    for (list<titik>::iterator i=mylist.begin(); i!=mylist.end(); i++) 
    {
        // Each element of the list is a pair 
        // on its own
        cout << (*i).get_urut() << " -> ";
    }
    cout << '\n';
}
  
// Function to iterate over all the array
void print(list<titik>* myContainer, int n)
{
    cout << "myContainer elements:\n\n";
  
    // Iterating over myContainer elements
    // Each element is a list on its own
    for (int i = 0; i < n; i++) 
    {
        print(myContainer[i], i);
    }
}

void tampilRumah(list <titik> *info, int N) {
    int urut, x, y;

    int gm, gd = DETECT, i;
    // int midx, midy;
    int stangle = 45, endangle = 50;
    int radius = 50;
    
    char data[] = "C:\\MinGW\\lib\\libbgi.a"; //static file

    initgraph(&gd, &gm, data);
    x = getmaxx(); // to get the co-ordinates i.e. x & y
    y = getmaxy();
    cleardevice();

    for (list<titik>::iterator i=info->begin(); i!=info->end(); i++) 
    {
        // Each element of the list is a pair 
        // on its own
        // cout << (*i).get_urut() << " -> ";
        urut = (*i).get_urut();
        x = (*i).get_x();
        y = (*i).get_y();
        circle(x, y, 15);

        // cout << "(" << urut << "," << x << "," << y << ") ";

    }
    getch();
    closegraph();
}

int main() {
    int N = 5;
    // membuat pointer yang menunjuk ke list bertipe titik 
    list <titik> *infoTitik;

    // membuat list 
    infoTitik = new list <titik>;
    infoTitik->push_back(titik(0, 100, 100));
    infoTitik->push_back(titik(1, 300, 100));
    infoTitik->push_back(titik(2, 100, 300));
    infoTitik->push_back(titik(3, 300, 300));
    infoTitik->push_back(titik(4, 400, 200));
    
    // line(200,300,200,300);

    list <titik> rumah [N];
    // membuat adjacendy list 
    // [awal].push_back(tujuan)
    rumah[0].push_back(1);
    rumah[0].push_back(2);
    rumah[1].push_back(0);
    rumah[1].push_back(3);
    rumah[1].push_back(4);
    rumah[2].push_back(0);
    rumah[2].push_back(3);
    rumah[3].push_back(2);
    rumah[3].push_back(1);
    rumah[3].push_back(4);
    rumah[4].push_back(1);
    rumah[4].push_back(3);

    print(rumah,N); 

    tampilRumah(infoTitik, N);


    cout << "selesai" << endl;



}

