#include <stdio.h>
#include <conio.h>

#define p printf  // Define printf as p for shorthand
#define s scanf    // Define scanf as s for shorthand
#define g gotoxy   // Define gotoxy as g for shorthand

void main(){
    int x, y, cpe, ce, ece, ee, me, ie, rem, cped, ced, eced, eed, med, ied, remd;

    clrscr();  // Clear the console screen

    // Draw the screen border
    for (x = 1; x <= 40; x++) {
        g(x, 1); p("%c", 205); g(x, 25); p("%c", 205);
    }

    for (y = 1; y <= 25; y++) {
        g(1, y); p("%c", 186); g(40, y); p("%c", 186);
    }

    g(1, 1); p("%c", 201); g(40, 1); p("%c", 187);
    g(1, 25); p("%c", 200); g(40, 25); p("%c", 188);

    for (x = 41; x <= 79; x++) {
        g(x, 1); p("%c", 205); g(x, 25); p("%c", 205);
    }

    for (y = 1; y <= 25; y++) {
        g(41, y); p("%c", 186); g(79, y); p("%c", 186);
    }

    g(41, 1); p("%c", 201); g(79, 1); p("%c", 187);
    g(41, 25); p("%c", 200); g(79, 25); p("%c", 188);

    // Display header and course names
    g(9, 3); p("College of Engineering");
    g(14, 4); p("SY 2022-2023");
    g(7, 6); p("Course         No. of Students");
    g(24, 7); p("1SEM  2SEM");
    g(8, 9); p("BSECE");
    g(8, 10); p("BSEE");
    g(8, 11); p("BSCE");
    g(8, 12); p("BSREM");
    g(8, 13); p("BSME");
    g(8, 14); p("BSIE");
    g(8, 15); p("BSCPE");

    // Input the number of students for each course and semester
    g(26, 9); s("%d", &ece); g(31, 9); s("%d", &eced);
    g(26, 10); s("%d", &ee); g(31, 10); s("%d", &eed);
    g(26, 11); s("%d", &ce); g(31, 11); s("%d", &ced);
    g(26, 12); s("%d", &rem); g(31, 12); s("%d", &remd);
    g(26, 13); s("%d", &me); g(31, 13); s("%d", &med);
    g(26, 14); s("%d", &ie); g(31, 14); s("%d", &ied);
    g(26, 15); s("%d", &cpe); g(31, 15); s("%d", &cped);

    // Display the graph for each course
    g(58, 3); p("TOTAL");
    g(43, 5); p("ECE");
    for (x = 47; x <= ece + eced + 46; x++) {
        g(x, 5); delay(25); p("%c", 219);
    }

    g(43, 7); p("EE");
    for (x = 47; x <= ee + eed + 46; x++) {
        g(x, 7); delay(25); p("%c", 219);
    }

    g(43, 9); p("CE");
    for (x = 47; x <= ce + ced + 46; x++) {
        g(x, 9); delay(25); p("%c", 219);
    }

    g(43, 11); p("REM");
    for (x = 47; x <= rem + remd + 46; x++) {
        g(x, 11); delay(25); p("%c", 219);
    }

    g(43, 13); p("ME");
    for (x = 47; x <= me + med + 46; x++) {
        g(x, 13); delay(25); p("%c", 219);
    }

    g(43, 15); p("IE");
    for (x = 47; x <= ie + ied + 46; x++) {
        g(x, 15); delay(25); p("%c", 219);
    }

    g(43, 17); p("CPE");
    for (x = 47; x <= cpe + cped + 46; x++) {
        g(x, 17); delay(25); p("%c", 219);
    }

    getch();  // Wait for a key press before exiting
}
