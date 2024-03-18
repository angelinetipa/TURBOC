#include <stdio.h>
#include <conio.h>
#include <dos.h>

int hour, minute, second, milli;

void main() {
    for (hour = 0; hour < 24; hour++) {
        for (minute = 0; minute < 60; minute++) {
            for (second = 0; second < 60; second++) {
                for (milli = 0; milli < 100; milli++) {
                    clrscr();
		    printf("[%02d : %02d : %02d : %02d]", hour, minute, second, milli);
		    delay(10);
		    if(kbhit()) {
                        exit(0);
                    }
                }
            }
        }
    }
    getch();
}
