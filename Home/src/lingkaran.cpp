#include <graphics.h>

using namespace std;

void * __gxx_personality_v0=0;
void * _Unwind_Resume =0;

int main( )
{
    int gd=DETECT, gm;
    initgraph(&gd, &gm, NULL);

    circle(100, 100, 40);

    getch();
    closegraph();

return 0;
}