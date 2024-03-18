#include <graphics.h>
#include <conio.h>

void main()
{
    int x, gd = DETECT, gm;

    // Initialize graphics mode
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Draw the title
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
    setcolor(YELLOW);
    outtextxy(170, 50, "N SQUARE CUBE");

    // Draw the table headers
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    setcolor(WHITE);
    outtextxy(100, 120, "Number");
    outtextxy(300, 120, "Square");
    outtextxy(500, 120, "Cube");

    // Loop to calculate and display numbers, squares, and cubes
    for (x = 0; x <= 10; x++)
    {
	char num[3], square[5], cube[7];

	// Convert integers to strings for display
	sprintf(num, "%d", x);
	sprintf(square, "%d", x * x);
	sprintf(cube, "%d", x * x * x);

	// Display the number, square, and cube at specific positions
	outtextxy(100, 140 + x * 20, num);    // Display the number
	outtextxy(300, 140 + x * 20, square); // Display the square
	outtextxy(500, 140 + x * 20, cube);   // Display the cube
    }

    getch();  // Wait for a key press before exiting
    closegraph();  // Close the graphics window
}
