
#include <graphics.h>
#include <iostream>

void drawHouse();
void emoji ();
void drawBangladeshFlag();
void drawWalkingMan(int i);
void  drawRain(int x, int y);
int main()
{
    int choice;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    while (true)
    {
        std::cout << "Choose an option:\n";
        std::cout << "1. House\n";
        std::cout << "2. Emoji \n";
        std::cout << "3. National Flag of Bangladesh\n";
        std::cout << "4. Man In The Rain\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice : ";
        std::cin >> choice;
        if (choice == 5)
        {
            std::cout << "Exiting...\n";
            break;
        }

        switch (choice)
        {
        case 1:
            initwindow(500,500,"House");
            drawHouse();
            break;
        case 2:
            initwindow(500,500,"EMOJI");
            emoji();
            break;

        case 3:
            initwindow(500,500,"Flag");
            drawBangladeshFlag();
            break;
        case 4:
            initwindow(580, 385, "Man In The Rain");
            int x, y, i;
            for (i = 0; i < 500; i++)
            {
                drawWalkingMan(i); // Draw walking animation
                x = getmaxx();
                y = getmaxy();
                drawRain(x, y); // Draw raindrops
                delay(50);
                cleardevice(); // Clear graphics window
            }
            break;

        default:
            std::cout << "Invalid choice. Please select 1 or 2.\n";
            break;
        }
    }


    getch();
    closegraph();
    return 0;
}

void drawHouse()
{
    // Draw house body with filling color
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    setcolor(WHITE);
    rectangle(150, 200, 450, 400);
    floodfill(300, 250, WHITE);

    // Draw reverse V-shaped roof
    setfillstyle(SOLID_FILL, DARKGRAY);
    setcolor(WHITE);
    line(150, 200, 300, 100);
    line(300, 100, 450, 200);
    line(150, 200, 450, 200);
    floodfill(300, 150, WHITE);

    // Draw door with a different color
    setfillstyle(SOLID_FILL, BROWN);
    setcolor(WHITE);
    rectangle(200, 300, 300, 400);
    floodfill(250, 350, WHITE);

    // Draw window with a different color
    setfillstyle(HATCH_FILL, LIGHTBLUE);
    setcolor(WHITE);
    rectangle(350, 250, 450, 325);
    floodfill(375, 275, WHITE);

    outtextxy(230, 410, "The House Of King !");
}


void emoji()
{


// Draw face circle
    int centerX = getmaxx() / 2;
    int centerY = getmaxy() / 2;
    int faceRadius = 100;
    setcolor(WHITE);
    circle(centerX, centerY, faceRadius);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(centerX,centerY,WHITE);
    // Draw eyes


    int eyeRadius = 20;
    setcolor(BLACK);
    circle(centerX - 40, centerY - 30, eyeRadius);
    setfillstyle(SOLID_FILL,BLACK);
    floodfill(centerX-40,centerY-30,BLACK);
     circle(centerX + 40, centerY - 30, eyeRadius);
    floodfill(centerX+40,centerY-30,BLACK);
    // Draw nose (triangle)
    int noseLength = 20;
    line(centerX, centerY - 10, centerX - noseLength, centerY + 10);
    line(centerX - noseLength, centerY + 10, centerX + noseLength, centerY + 10);
    line(centerX + noseLength, centerY + 10, centerX, centerY - 10);

    // Draw mouth (ellipse)
    ellipse(centerX, centerY + 40, 0, 180, 40, 20);
    setcolor(WHITE);
    outtextxy(centerX-20, centerY+faceRadius+20, " Angry Emoji !");

}


void drawBangladeshFlag()
{
    int flagWidth = 300;
    int flagHeight = 200;
    int stickWidth = 10; // Stick width
    int stickHeight = 300; // Stick height
    int centerX = getmaxx() / 2;
    int centerY = getmaxy() / 2;
    int circleRadius = flagWidth / 10;

    // Draw the rectangular flag in bottle green color
    setfillstyle(SOLID_FILL, COLOR(0, 102, 71)); // Bottle green color

    // Calculate coordinates for the flag
    int leftX = centerX - flagWidth / 2;
    int rightX = centerX + flagWidth / 2;
    int topY = centerY - flagHeight / 2;
    int bottomY = centerY + flagHeight / 2;

    bar(leftX, topY, rightX, bottomY);

    // Draw the flag stick to the left of the flag
    setcolor(WHITE);
    rectangle(leftX - stickWidth, topY, leftX, topY + stickHeight);
    floodfill(leftX - 5, topY + stickHeight / 2, WHITE);

    // Calculate circle's center for the flag
    int circleCenterX = leftX + static_cast<int>(flagWidth * 0.48);
    int circleCenterY = centerY;

    // Draw the red circle in the middle
    setfillstyle(SOLID_FILL, RED);
    fillellipse(circleCenterX, circleCenterY, circleRadius, circleRadius);

    // Text at the bottom
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    outtextxy(centerX - 120, centerY + flagHeight / 2 + 30, "National Flag of Bangladesh");


}


void drawWalkingMan(int i)
{
    // Draw the ground line
    line(20, 380, 580, 380);

    // Draw legs and arms based on the animation step
    if (i % 2)
    {
        line(25 + i, 380, 35 + i, 340); // Left leg
        line(45 + i, 380, 35 + i, 340); // Right leg
        line(35 + i, 310, 25 + i, 330); // Left arm
        delay(20);
    }
    else
    {
        line(35 + i, 340, 35 + i, 310); // Body
        line(35 + i, 310, 40 + i, 330); // Right arm
        delay(20);
    }

    // Draw body and head
    line(35 + i, 340, 35 + i, 310); // Body
    circle(35 + i, 300, 10); // Head

    // Draw umbrella
    line(35 + i, 310, 50 + i, 330); // Umbrella handle
    line(50 + i, 330, 50 + i, 280); // Umbrella stick
    setcolor(RED);
    line(15 + i, 280, 85 + i, 280); // Umbrella arc
    arc(50 + i, 280, 0, 180, 35);
    setfillstyle(SOLID_FILL, RED);
    floodfill(50 + i, 279, RED); // Fill the umbrella with red color

    // Draw umbrella handle
    setcolor(YELLOW);
    arc(55 + i, 330, 180, 360, 5);
}



void drawRain(int x, int y)
{
    for (int j = 0; j < 100; j++)
    {
        // Draw raindrops randomly
        setcolor(WHITE);
        outtextxy(rand() % x, rand() % (y - 50), "|");

    }
}


