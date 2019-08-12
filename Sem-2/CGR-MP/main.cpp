#include <iostream>
#include <graphics.h>

using namespace std;

int main()
{

    int gd = DETECT, gm;
    initgraph(&gd, &gm, " ");
    int page = 0, t_y = -300;

    while (1)
    {

        setactivepage(page);
        setvisualpage(1-page);
        cleardevice();

        // Background
        setcolor(CYAN);
        rectangle(0, 0, 1000, 1000);
        setfillstyle(SOLID_FILL, CYAN);
        floodfill(1, 1, CYAN);

        // Road
        setcolor(WHITE);
        rectangle(200, -1, 400, 500);
        setfillstyle(SOLID_FILL, DARKGRAY);
        floodfill(201, 0, WHITE);

        // Track
        for(int i=0; i<500; i+=65)
        {
            rectangle(290, 10+i, 310, 50+i);
            setfillstyle(SOLID_FILL, WHITE);
            floodfill(291, 11+i, WHITE);
        }

        // Info
        settextstyle(BOLD_FONT, HORIZ_DIR, SMALL_FONT);
        outtextxy(10, 10, "LIFE:");
        outtextxy(10, 40, "POINTS:");

        // Circles for Life:
        setfillstyle(SOLID_FILL, WHITE);
        circle(90, 20, 8);
        floodfill(91, 21, WHITE);
        circle(110, 20, 8);
        floodfill(111, 21, WHITE);
        circle(130, 20, 8);
        floodfill(131, 21, WHITE);

        // Points
        outtextxy(100, 40, "0");

        delay(200);
        --page;
    }

    getch();
    closegraph();

    return 0;
}
