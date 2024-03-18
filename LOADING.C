#include <stdio.h>
#include <conio.h>  // Header file for console I/O functions
#define p printf  // Define printf as p for shorthand
#define s scanf  // Define scanf as s for shorthand
#define g gotoxy  // Define gotoxy as g for shorthand

// Main function
void main()
{
    char uname[15], pwd[15];  // Declare character arrays for username and password
    int x;  // Declare integer variable x

    clrscr();  // Clear the console screen

    // Set cursor position and prompt for username and password
    g(25, 10); p("USERNAME: "); g(25, 12); p("PASSWORD: ");
    g(34, 10); s("%s", &uname); g(34, 12); s("%s", &pwd);

    // Loop for loading animation
    for (x = 1; x <= 79; x++)
    {
        g(1, 23); p("Loading...");
        g(75, 23); p("%d", x + 21);  // Display the progress number
        delay(50);  // Introduce a delay for animation effect
        g(x, 24); delay(50); p("%c", 219);  // Display a block character for animation
    }

    g(1, 23); p("Loading Complete");  // Display loading completion message

    getch();  // Wait for a key press before exiting
}
