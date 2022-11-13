#include <graphics.h>
#include <iostream>
#include <cstdlib>

using namespace std;

int randomx(int max)
{
  return (rand() % max) + 1;
}

int main( )
{
    char ch;
    cout << "Hello \nHello";

    initwindow(800,800);
    /* ---- */	
   setbkcolor(BLACK);
  outtextxy(0, 0, "Drawing 1000 lines...");

  for (int i = 0; i < 1000; i++) {
    setcolor(1 + randomx(15));
    line(randomx(getmaxx()), randomx(getmaxy()), 
         randomx(getmaxx()), randomx(getmaxy()));
  }
    /* ---- */
    getch();
    closegraph();

    return 0;
}
