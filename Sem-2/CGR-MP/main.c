#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <graphics.h>

int main() {

    int gd = DETECT, gm;
    detectgraph(&gd, &gm);
    initgraph(&gd, &gm, NULL);

    line(10, 10, 50, 50);

    closegraph();

    return 0;
}