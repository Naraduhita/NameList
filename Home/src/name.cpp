#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>

int main()
{
    int gm, x, y, gd = DETECT, i;

    char data[] = "C:\\MinGW\\lib\\libbgi.a"; // static file

    initgraph(&gd, &gm, data);
    x = getmaxx(); // to get the co-ordinates i.e. x & y
    y = getmaxy();
    cleardevice();

    // x1,y1,x2,y2
    // Membuat titik dengan circle (x,y, radius)
    // N
    setcolor(4);
    circle(100, 100, 5);
    circle(50, 50, 5);
    circle(50, 100, 5);
    circle(100, 50, 5);
    circle(125, 100, 5);
    line(50, 100, 50, 50);
    line(50, 50, 100, 100);
    line(100, 100, 100, 50);
    line(100, 100, 125, 100);

    // A
    setcolor(3);
    circle(150, 50, 5);
    circle(175, 100, 5);
    circle(138, 75, 5);
    circle(163, 75, 5);
    circle(200, 100, 5);
    line(125, 100, 138, 75);
    line(138, 75, 150, 50);
    line(138, 75, 163, 75);
    line(150, 50, 163, 75);
    line(163, 75, 175, 100);
    line(175, 100, 200, 100);

    //R
    setcolor(6);
    circle(200, 75, 5);
    circle(200, 50, 5);
    circle(225, 50, 5);
    circle(225, 75, 5);
    circle(250, 100, 5);
    circle(275, 100, 5);
    line(200,100, 200,75);
    line(200,75, 200,50);
    line(200,50, 225,50);
    line(225,50, 225,75);
    line(225,75, 250,100);
    line(200,75, 225,75);
    line(250,100, 275,100);

    //A
    setcolor(5);
    circle(288,75,5);
    circle(300,50,5);
    circle(313,75,5);
    circle(325,100,5);
    line(275,100,288,75);
    line(288,75,300,50);
    line(300,50,313,75);
    line(313,75,325,100);
    line(288,75,313,75);
    
    //smile
    setcolor(YELLOW);
    circle(364,85,30);
    // setfillstyle (SOLID_FILL, YELLOW);
    // floodfill(364, 100, YELLOW);
    
 

    setcolor(2);
    fillellipse(350,75, 2, 6);
    fillellipse(375,75, 2, 6);
    ellipse(364,90,205,335,20,9);
    ellipse(364,90,205,335,20,10);
    ellipse(364,90,205,335,20,11);
    
    

    setcolor(7);
    // line(5, 330, 600, 330);
    for (i = 0; i < 650; i = i + 10)
    {
        setcolor(4);
        settextstyle(7, 0, 5);

        char stringData1[] = "My Name is Naraduhita";

        outtextxy(0 + i, 390, stringData1);
        delay(100);
        setcolor(0);
        settextstyle(7, 0, 5);

        outtextxy(0 + i, 390, stringData1);
    }
    getch();
    closegraph();

    return 0;
}