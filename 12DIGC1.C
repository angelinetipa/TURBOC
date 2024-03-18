#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>

int hour, minute, second, milli;

void main() {
    char timeStr[256];
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    while (!kbhit()) {
	time_t currentTime = time(NULL);
	cleardevice();
	setcolor(WHITE);
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 8);
	strftime(timeStr, 256, "%I:%M:%S %p", localtime(&currentTime));
	outtextxy(80, 180, timeStr);
	delay(1000);
    }
    printf("\nPress any key to exit...");
    getch();
    closegraph();
}
