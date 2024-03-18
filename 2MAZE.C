#include <stdio.h>
#include <conio.h>

#define p printf  // Define printf as p for shorthand
#define g gotoxy   // Define gotoxy as g for shorthand

void main() {
    int x, y;
    clrscr();  // Clear the console screen

    // 1st loop
    for (x = 1; x < 80; x++){
	if ( x == 5) {
	     p("\033[1;31m PUP \033[0m");
	     x += 5;
	}
	g(x, 3); delay(25); p("\033[1;31m%c\033[0m", 219);  // Draw top border
    }

    for (y = 3; y < 24; y++){
	g(80, y); delay(25); p("\033[1;31m%c\033[0m", 219);  // Draw right border
    }

    for (x = 79; x > 1; x--){
	g(x, 23); delay(25); p("\033[1;31m%c\033[0m", 219);  // Draw bottom border
    }

    for (y = 23; y > 6; y--){
	g(1, y); delay(25); p("\033[1;31m%c\033[0m", 219);  // Draw left border
    }

    // 2nd loop
    for (x = 1; x < 75; x++){
	if ( x == 15) {
	     p("\033[1;31m PUP \033[0m");
	     x += 5;
	}
	g(x, 6); delay(25); p("\033[1;31m%c\033[0m", 219);
    }

    for (y = 6; y < 21; y++){
	g(75, y); delay(25); p("\033[1;31m%c\033[0m", 219);
    }

    for (x = 75; x > 6; x--){
	g(x, 20); delay(25); p("\033[1;31m%c\033[0m", 219);
    }

    for (y = 20; y > 8; y--){
	g(6, y); delay(25); p("\033[1;31m%c\033[0m", 219);
    }

    // 3rd loop
    for (x = 6; x < 70; x++){
	if ( x == 25) {
	     p("\033[1;31m PUP \033[0m");
	     x += 5;
	}
	g(x, 9); delay(25); p("\033[1;31m%c\033[0m", 219);
    }

    for (y = 9; y < 18; y++){
	g(70, y); delay(25); p("\033[1;31m%c\033[0m", 219);
    }

    for (x = 70; x > 10; x--){
	g(x, 17); delay(25); p("\033[1;31m%c\033[0m", 219);
    }

    for (y = 17; y > 11; y--){
	g(11, y); delay(25); p("\033[1;31m%c\033[0m", 219);
    }

    // 4th loop
    for (x = 11; x < 65; x++){
	if ( x == 35) {
	     p("\033[1;31m PUP \033[0m");
	     x += 5;
	}
	g(x, 12); delay(25); p("\033[1;31m%c\033[0m", 219);
    }

    for (y = 12; y < 15; y++){
        g(65, y); delay(25); p("\033[1;31m%c\033[0m", 219);
    }

    for (x = 65; x > 15; x--){
        g(x, 15); delay(25); p("\033[1;31m%c\033[0m", 219);
    }

    getch();  // Wait for a key press before exiting
}
