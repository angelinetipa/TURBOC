#include <stdio.h>
#include <graphics.h>
#include <conio.h>

#define p printf  // Define printf as p for shorthand
#define g gotoxy   // Define gotoxy as g for shorthand
#define s scanf   // Define scanf as s for shorthand

int x;
void expo() {
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    // Draw the title
    setbkcolor(BLACK);
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
}

void maze() {
    int x, y;
    cleardevice();  // Clear the console screen
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

void tower() {
    // Your tower() function code starts here
    void drawDisk(int rod, int diskSize, int y) {
        // Function to draw a disk on the specified rod
        int x = rod * 250 + 70 ; // Adjust the positions based on your window size
        setfillstyle(SOLID_FILL, rod * 100 + 150); // Change color based on rod
        bar(x - diskSize * 13, y + 3, x + diskSize * 13, y + 20);
    }

    void clearDisk(int rod, int diskSize, int y) {
    // Function to clear a disk from the specified rod
    int x = rod * 250 + 70 ; // Adjust the positions based on your window size
    setfillstyle(SOLID_FILL, getbkcolor()); // Set fill color to background color
    bar(x - diskSize * 13, y + 3, x + diskSize * 13, y + 20);
}

    void moveDisk(int from_rod, int to_rod, int diskSize, int y) {
    // Function to move a disk from one rod to another
    clearDisk(from_rod, diskSize, y); // Clear the disk from the source rod
    drawDisk(to_rod, diskSize, y); // Draw the disk on the destination rod
    delay(1000); // Delay for visualization

    void towerOfHanoi(int n, int from_rod, int to_rod, int aux_rod, int baseY) {
    if (n == 1) {
	// Move disk 1 from rod 'from_rod' to rod 'to_rod'
	moveDisk(from_rod, to_rod, 1, baseY + n * 20);
	return;
    }

    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod, baseY);

    // Move disk 'n' from rod 'from_rod' to rod 'to_rod'
    moveDisk(from_rod, to_rod, n, baseY + n * 20);

    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod, baseY);
}

    void displayInitialTower(int n, int baseY) {
    // Function to display the initial state of Tower of Hanoi
    int y = baseY + 20;// Base Y coordinate
    int i;
    // Draw disks on the first rod
    for (i = 1; i <= n; i++) {
	drawDisk(0, i, y );
	y += 20; // Adjust Y coordinate for the next disk
    }
}

    int main() {
        int n, i;
        int gd = DETECT, gm;
        int baseY = 200; // Set the base Y coordinate for the bottom of the rods

        // Initialize graphics mode
        initgraph(&gd, &gm, "C:\\Turboc3\\BGI"); // Change the path based on your setup

        // Display title
    	setcolor(WHITE);
    	settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);
   	outtextxy(100, 50, "TOWER OF HANOI");

  	gotoxy(25,8);
   	printf("Enter the number of disks: ");
   	scanf("%d", &n);

   	// Display initial tower state
   	displayInitialTower(n, baseY);
    	delay(500);

        towerOfHanoi(n, 0, 2, 1, baseY);
    	getch();
    }
}

int main() {
    int choice;

    do {
	clrscr();
	p("Menu List");
	p("1. Exponent");
	p("2. Maze");
	p( "3. Bar Graph");
	p( "4. Tic Tac Toe");
	p("5. Garage - STACK");
	p("6. Garage - QUEUE");
	p("7. Binary Tree - TRAVERSAL");
	p("8. Binary Tree - MAKEER");
	p("9. Fibonacci");
	p("10. Factorial");
	p("11. Tower of Hanoi");
	p("12. Digital Clock");
	p("13. Exit");

	g(25,20);
	p("+------------------------+\n\n\n\n\t\t\t+------------------------+");
	g(28,22);
	p("Enter your choice: ");
	s("%d", &choice);

	switch (choice) {
	    case 1:
		expo();
		break;
	    case 2:
		maze();
		break;
	   // case 3:
	       //	code3();
	       //	break;
	    case 3:
		p("Exiting...\n");
		closegraph();
		return 0;
	    default:
		cleardevice();
		settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
		outtextxy(100, 50, "Invalid choice. Please try again.");
		break;
	}

    } while (choice != 3);

    return 0;
}
