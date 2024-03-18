#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>

int hour, minute, second, milli;

void main() {
    struct tm *timeinfo;
    time_t rawtime;
    char timeStr[256];
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    timeinfo->tm_hour = 0;
    timeinfo->tm_min = 0;
    timeinfo->tm_sec = 0;
    while (!kbhit()) {
	cleardevice();
	setcolor(WHITE);
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 8);
	strftime(timeStr, 256, "%I:%M:%S %p", timeinfo);
	outtextxy(70, 170, timeStr);
	timeinfo->tm_sec++;
	mktime(timeinfo);
	delay(1000);
    }
    getch();
    closegraph();
}
