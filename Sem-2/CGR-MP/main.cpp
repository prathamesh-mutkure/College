#include <iostream>
#include <graphics.h>
#include <stdio.h>
#include <strings.h>
#include <stdbool.h>
#include <windows.h>

#define MAX_Y 480
#define MAX_X 640

void enemyCar(int x, int y, int moveFactor, colors body, colors head);
void reposition(int *es, int *en, int *ef, int *c_x, int *s_val);
void restart(int* lives, long* score, int* score_val);

using namespace std;

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, " ");

    // Background Music
    PlaySound("car_music.wav", NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);

    // To track Points
    char pts[100] = "0";
    long score = 0;
    int score_val = 5;

    // To track positions
    int page = 0, track_y = -300;
    int car_pos_x1 = 0, car_pos_y1;
    int Car_x = 0, Car_y = 0, Car_speed_x = 5;
    int enemySlow = 0, enemyNormal = 0, enemyFast = 0;

    // Flags and game flow
    int lives  = 3;
    bool flag = true;

    restart:
    while (flag)
    {
        // Maintaining constant picture
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

        // Tracks in the middle of the Roads
        for(int i=0; i<400; i+=65)
        {
            rectangle(290, 10+i+track_y, 310, 50+i+track_y);
            setfillstyle(SOLID_FILL, WHITE);
            floodfill(291, 11+i+track_y, WHITE);
        }

        // Moving the track by Translation
        track_y += 15;
        if (track_y > 450)
            track_y = -500;

        // Player stats
        settextstyle(BOLD_FONT, HORIZ_DIR, SMALL_FONT);
        outtextxy(10, 10, "LIFE:");
        outtextxy(10, 40, "POINTS:");

        // Displaying user's Points
        sprintf(pts, "%ld", score);
        outtextxy(100, 40, pts);

        // Circles representing number of life:
        for (int i=0, n = lives; i<=40 && n>0; i+=20, n--)
        {
            setfillstyle(SOLID_FILL, WHITE);
            circle(90+i, 20, 8);
            floodfill(91+i, 21, WHITE);
        }

        // Spawning three Enemy cars
        enemyCar(235, -50, enemyFast, RED, GREEN);
        enemyCar(290, -100, enemyNormal, BLUE, BROWN);
        enemyCar(345, -30, enemySlow, YELLOW, CYAN);

        // Moving the Enemy with help of Translation
        enemySlow += 3;
        enemyNormal += 5;
        enemyFast += 8;

        // Enemy Cars Positions
        int e1_x = 235;
        int e1_y = enemyFast - 50;

        int e2_x = 290;
        int e2_y = enemyNormal - 95;

        int e3_x = 345;
        int e3_y = enemySlow - 25;

        // Re-spawning the enemy cars after they cross the window
        if (enemyFast > MAX_Y + 50)
            enemyFast = -50;
        if (enemyNormal > MAX_Y + 100)
            enemyNormal = -100;
        if (enemySlow > MAX_Y + 50)
            enemySlow = -30;

        // Main part of the Car
        setcolor(BLACK);
        setfillstyle(SOLID_FILL, RED);
        rectangle(300+Car_x, 400-Car_y, 340+Car_x, 460-Car_y);
        floodfill(301+Car_x, 401, BLACK);

        // Front Part of the Car
        setfillstyle(SOLID_FILL, BROWN);
        rectangle(305+Car_x, 385-Car_y, 335+Car_x, 400-Car_y);
        floodfill(306+Car_x, 386, BLACK);

        // Hood of the Car
        setfillstyle(SOLID_FILL, BLACK);
        rectangle(305+Car_x, 405-Car_y, 335+Car_x, 455-Car_y);
        floodfill(306+Car_x, 406, BLACK);

        // Wheels of the car
        setfillstyle(SOLID_FILL, BLACK);
        pieslice(305+Car_x, 392-Car_y, 90, 270, 6);
        pieslice(337+Car_x, 392-Car_y, 270, 90, 5);

        // Position of Car
        car_pos_x1 = 300+Car_x;
        car_pos_y1 = 400+Car_y-15;

        // Controls to move car
        if (GetAsyncKeyState(VK_LEFT) && car_pos_x1 >= 210)
            Car_x -= Car_speed_x;
        else if (GetAsyncKeyState(VK_RIGHT) && car_pos_x1 <= 350)
            Car_x += Car_speed_x;

        // Winning Logic
        // For X-axis collision
        for (int i=0; i<=40; i+=10)
        {
            // For Y-axis collision
            for (int j=0; j<=75; j+=25)
            {
                if (car_pos_x1+i > e1_x && car_pos_x1+i < e1_x+20 && car_pos_y1+j < e1_y && car_pos_y1+j > e1_y-40)
                {
                    strcpy(pts, "loose");
                    --lives;
                    reposition(&enemySlow, &enemyNormal, &enemyFast, &Car_x, &score_val);
                    //delay(250);
                }
                else if (car_pos_x1+i > e2_x && car_pos_x1+i < e2_x+20 && car_pos_y1+j < e2_y && car_pos_y1+j > e2_y-40)
                {
                    strcpy(pts, "loose");
                    --lives;
                    reposition(&enemySlow, &enemyNormal, &enemyFast, &Car_x, &score_val);
                    //delay(250);
                }
                else if (car_pos_x1+i > e3_x && car_pos_x1+i < e3_x+20 && car_pos_y1+j < e3_y && car_pos_y1+j > e3_y-40)
                {
                    strcpy(pts, "loose");
                    --lives;
                    reposition(&enemySlow, &enemyNormal, &enemyFast, &Car_x, &score_val);
                    //delay(250);
                }
            }
        }

        // Game Over
        if (lives <= 0)
        {
            score_val = 0;
            setcolor(BLUE);
            setfillstyle(SOLID_FILL, BLUE);
            rectangle(90, 100, 560, 400);
            floodfill(101, 101, BLUE);

            // Game Over Prompt
            setcolor(WHITE);
            outtextxy(100, 120, "GAME OVER! PRESS SPACE KEY TO RESTART");
            outtextxy(100, 160, "PRESS ESC TO EXIT!");

            char msg[100];
            sprintf(msg, "YOUR SCORE WAS %ld", score);
            outtextxy(100, 200, msg);

            if (GetAsyncKeyState(VK_SPACE))
            {
                reposition(&enemySlow, &enemyNormal, &enemyFast, &Car_x, &score_val);
                restart(&lives, &score, &score_val);
                goto out;
            }
            if (GetAsyncKeyState(VK_ESCAPE))
                return 0;

            getch();
        }

        out:
        score += score_val;
        page = 1-page;
        delay(30);
    }

    getch();
    closegraph();

    cout << "YOU LOOSE!!";

    getch();
    return 0;
}

void restart(int* lives, long* score, int* score_val)
{
    *lives = 3;
    *score = 0;
    *score_val = 5;
}

void reposition(int *es, int *en, int *ef, int *c_x, int *s_val)
{
    *es = 0;
    *en = 0;
    *ef = 0;
    *c_x = 0;
}

void enemyCar(int x, int y, int moveFactor, colors body, colors head)
{
    setcolor(BLACK);
    rectangle(x, y + moveFactor, x+20,  -30+y+moveFactor);
    setfillstyle(SOLID_FILL, body);
    floodfill(x+1, -20+y+moveFactor-1, BLACK);

    setcolor(BLACK);
    rectangle(x+5, y+moveFactor, x+15, 5+y+moveFactor);
    setfillstyle(SOLID_FILL, head);
    floodfill(x+6, -20+y+moveFactor-1, BLACK);
}
