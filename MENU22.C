#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <time.h>

#define p printf  // Define printf as p for shorthand
#define g gotoxy   // Define gotoxy as g for shorthand
#define s scanf   // Define scanf as s for shorthand
#define STACK_SIZE 10

//Program 1
int x;
void expo() {
    // Draw the title
    cleardevice();
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

//Program 2
void maze() {
    int x, y;
    cleardevice();  // Clear the console screen
    setbkcolor(BLACK);
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

//Program 3
void barg() {
int x,y,cpe,ce,ece,ee,me,ie,rem;
setbkcolor(BLACK);
cleardevice();

//Screen
       for(x=1; x<=40; x++)
       {
       g(x,1); p("%c",205);
       g(x,24); p("%c",205);
       }
       for(y=1; y<=24; y++)
       {
       g(1,y); p("%c",186);
       g(40,y); p("%c",186);
       }
       g(1,1); p("%c",201); g(40,1); p("%c",187);
       g(1,24); p("%c",200); g(40,24); p("%c",188);
       for(x=41; x<=79; x++)
       {
       g(x,1); p("%c",205);
       g(x,24); p("%c",205);
       }
       for(y=1; y<=24; y++)
       {
       g(41,y); p("%c",186);
       g(79,y); p("%c",186);
       }
       g(41,1); p("%c", 201);g(79,1); p("%c",187);
       g(41,24); p("%c", 200);g(79,24); p("%c",188);
       g(9,3); p("College of Engineering");
       g(14,4); p("SY 2022-2023");
       g(5,6); p("Course       No. of Student");
       g(5,8); p("BSECE");
       g(5,9); p("BSEE");
       g(5,10); p("BSCE");
       g(5,11); p("BSREM");
       g(5,12); p("BSME");
       g(5,13); p("BSIE");
       g(5,14); p("BSCPE");
       g(22,8); s("%d", &ece);
       g(22,9); s("%d", &ee);
       g(22,10); s("%d", &ce);
       g(22,11); s("%d", &rem);
       g(22,12); s("%d", &me);
       g(22,13); s("%d", &ie);
       g(22,14); s("%d", &cpe);

//Graph
       g(49,3); p("BAR GRAPH REPRESENTATION");
       g(43,5); p("ECE");
       g(43,7); p("EE");
       g(43,9); p("CE");
       g(43,11); p("REM");
       g(43,13); p("ME");
       g(43,15); p("IE");
       g(43,17); p("CPE");
       for(x=1; x<=ece; x++)
       {
       g(47+x,5); delay(25); p("%c",219);
       }
       for(x=1; x<=ee; x++)
       {
       g(47+x,7); delay(25); p("%c",219);
       }
       for(x=1; x<=ce; x++)
       {
       g(47+x,9); delay(25); p("%c",219);
       }
       for(x=1; x<=rem; x++)
       {
       g(47+x,11); delay(25); p("%c",219);
       }
       for(x=1; x<=me; x++)
       {
       g(47+x,13); delay(25); p("%c",219);
       }
       for(x=1; x<=ie; x++)
       {
       g(47+x,15); delay(25); p("%c",219);
       }
       for(x=1; x<=cpe; x++)
       {
       g(47+x,17); delay(25); p("%c",219);
       }
getch();
}

//Program4
char box[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int win();
void board();

void tictac(){
    int player = 1, move;
    char place;

    int x, gd = DETECT, gm;

    // Initialize graphics mode
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    do
    {
	    board();
	    player = (player % 2) ? 1 : 2;

	    g(5, 17);
	    p("\033[0mPLAYER %d, enter a no.:   ", player);
	    s("%d", &move);

	    place = (player == 1) ? 'X' : 'O';

	    if (move >= 1 && move <= 9 && box[move] == '0' + move)
		box[move] = place;
	    else
	    {
		p("     INVALID MOVE! TRY AGAIN.");
		player--; // Keep the same player for another try
		getch();
		cleardevice(); // Clear the graphics screen

		// Clear input buffer
		while (getchar() != '\n');

		continue; // Skip the rest of the loop and start over
	    }

	    player++;
	    cleardevice(); // Clear the screen
    } while (win() == -1);

    closegraph();

    if (win() == 1)
	    p("\n    PLAYER %d WINS!", --player);
    else
	    p("\n     GAME DRAW");

    getch();
    return 0;
}


int win()
{
    if (box[1] == box[2] && box[2] == box[3])
	return 1;
    else if (box[4] == box[5] && box[5] == box[6])
	return 1;
    else if (box[7] == box[8] && box[8] == box[9])
	return 1;
    else if (box[1] == box[4] && box[4] == box[7])
	return 1;
    else if (box[2] == box[5] && box[5] == box[8])
	return 1;
    else if (box[3] == box[6] && box[6] == box[9])
	return 1;
    else if (box[1] == box[5] && box[5] == box[9])
	return 1;
    else if (box[3] == box[5] && box[5] == box[7])
	return 1;
    else if (box[1] != '1' && box[2] != '2' && box[3] != '3' && box[4] != '4' && box[5] != '5' && box[6] != '6' && box[7] != '7' && box[8] != '8' && box[9] != '9')
	return 0;
    else
	return -1;
}

void board()
{
    int x, y, num;

    // Instructions and title
    {
	g(5, 9);
	p("\033[0m*SYMBOLS*");
	g(5, 10);
	p("\033[0;31mPLAYER 1: X\n    \033[0;36mPLAYER 2: O\n\033[0m");
	g(5, 13);
	p("HOW TO PLAY: \033[0;37m\n    Enter a number (1-9) to place \n    your symbol on the board.\n\033[0m");
    }

    // Title
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
    setcolor(YELLOW);
    outtextxy(170, 30, "TIC-TAC-TOE");

    // Board

    for (x = 15; x <= 43; x++)
    {
	g(x + 25, 12);
	p("%c", 205);
	g(x + 25, 16);
	p("%c", 205);
    }

    for (y = 1; y <= 13; y++)
    {
	g(49, y + 7);
	p("%c", 186);
	g(59, y + 7);
	p("%c", 186);
    }

    g(5, 19);
    p("Press ENTER after each move!");

    // Assigned numbers
    g(44, 10);
    p("\033[0;33m1");
    g(54, 10);
    p("\033[0;33m2");
    g(64, 10);
    p("\033[0;33m3");
    g(44, 14);
    p("\033[0;33m4");
    g(54, 14);
    p("\033[0;33m5");
    g(64, 14);
    p("\033[0;33m6");
    g(44, 18);
    p("\033[0;33m7");
    g(54, 18);
    p("\033[0;33m8");
    g(64, 18);
    p("\033[0;33m9");

    // Assigning numbers for each box
    {
	g(44, 10);
	p("%c", box[1]);
	g(54, 10);
	p("%c", box[2]);
	g(64, 10);
	p("%c", box[3]);
	g(44, 14);
	p("%c", box[4]);
	g(54, 14);
	p("%c", box[5]);
	g(64, 14);
	p("%c", box[6]);
	g(44, 18);
	p("%c", box[7]);
	g(54, 18);
	p("%c", box[8]);
	g(64, 18);
	p("%c", box[9]);
    }
}

//Program 5
int stack[10], tempStack[10], choice, n, top, x, i;
// Function prototypes
void push();
void pop();

void garages(){
    cleardevice();
    top = -1;

    // Input the maximum number of cars the parking garage can accommodate
    g(2,2);
    p("\n\tHow many cars? (max=10): ");
    s("%d", &n);

    do {
	cleardevice();  // Clear the screen before each iteration

	// Display the parking garage and options on the right side
	g(40, 5);
	p("\tParking Garage\n");
	for (i = top; i >= 0; i--) {
	    g(40, 7 + i);
	    p("\tCar %d\n", stack[i]);
	}

	// Display the options on the left side
	g(1, 5);
	p("\tOPTIONS\n");
	p("\t--------------------\n");
	p("\t1. Arrive\n");
	p("\t2. Depart\n");
	p("\t3. EXIT\n");

	// Display "Enter the choice" just below the options
	p("\t--------------------\n");
	p("\n\tEnter the Choice: ");
	s("%d", &choice);

	switch (choice) {
	    case 1: {
		push();
		break;
	    }
	    case 2: {
		pop();
		break;
	    }
	    case 3: {
		p("\n\tEXIT");
		break;
	    }
	    default: {
		p("\n\tPlease Enter a Valid Choice (1-3)");
	    }
	}

	// Pause to display messages before clearing the screen
	p("\n\tPress any key to continue...");
	getch();

    } while (choice != 3);

    return 0;
}

// Function to push (arrive) a car into the parking garage
void push() {
    if (top >= n - 1) {
	p("\n\tPARKING GARAGE is FULL");
    } else {
	p("\n\t  Car's plate number: ");
	s("%d", &x);

	// Shift existing cars to make space for the arriving car
	for (i = top; i >= 0; i--) {
	    stack[i + 1] = stack[i];
	}

	stack[0] = x;
	top++;
    }
}

// Function to pop (depart) a car from the parking garage
void pop() {
    if (top <= -1) {
	p("\n\tPARKING GARAGE is empty...");
    } else {
	int unparkCar;
	p("\n\t  Car's plate number: ");
	s("%d", &unparkCar);

	// Display only the specified car to depart
	clrscr();
	g(40, 5);
	p("\tParking Garage\n");
	for (i = 0; i <= top; i++) {
	    cleardevice();
	    g(40, 7 + i);
	    if (stack[i] == unparkCar) {
		p("\tCar %d (Departing)\n", stack[i]);
		break;
	    } else {
		g(50, 7 + i);
		p("\t-->car moved\n");
	    }
	}

	// Pause to display messages before clearing the screen
	p("\n\tPress any key to continue...");
	getch();

	// Shift the remaining cars above the departed car
	for (; i < top; i++) {
	    stack[i] = stack[i + 1];
	}

	top--;

	// Display "Depart Successful"
	clrscr();
	cleardevice();
	g(3, 11);
	p("\n\tDeparture Successful! Car %d has left the parking garage.", unparkCar);
    }
}


//Program 6
void garageq() {
p("print");
getch();
}

//Program 7
void treet() {
p("print");
getch();
}

//Program 8
void treem() {
p("print");
getch();
}

//Program 9

void fibo() {
    int i, n;
    // initialize first and second terms
    long long int t1 = 0, t2 = 1;
    // initialize the next term (3rd term)
    long long int nextTerm = t1 + t2;
    clrscr();
    // get no. of terms from user
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    // print the first two terms t1 and t2
    printf("Fibonacci Series: %lld, %lld, ", t1, t2);
    // print 3rd to nth terms
    for (i = 3; i <= n; ++i) {
	printf("%lld, ", nextTerm);
	t1 = t2;
	t2 = nextTerm;
	nextTerm = t1 + t2;
    }
    getch();
    return 0;

}

//Program 10

void fact() {
p("print");
  getch();
}

//Program11
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
}

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

void tower() {
    int n, i;
    int gd = DETECT, gm;
    int baseY = 200; // Set the base Y coordinate for the bottom of the rods

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

//Program 12
int hour, minute, second, milli;
void digi() {
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

int main() {
    int choice;
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    do {
	cleardevice();
	setbkcolor(BLACK);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);
	setcolor(WHITE);
	outtextxy(170, 50, "Menu List");
	settextstyle(COMPLEX_FONT, HORIZ_DIR, 1);
	setcolor(LIGHTGRAY);
	outtextxy(50, 100, "1. Exponent");
	outtextxy(50, 125, "2. Maze");
	outtextxy(50, 150, "3. Bar Graph");
	outtextxy(50, 175, "4. Tic Tac Toe");
	outtextxy(50, 200, "5. Garage - STACK");
	outtextxy(50, 225, "6. Garage - QUEUE");
	outtextxy(300, 100, "7. Binary Tree - TRAVERSAL");
	outtextxy(300, 125, "8. Binary Tree - MAKER");
	outtextxy(300, 150, "9. Fibonacci");
	outtextxy(300, 175, "10. Factorial");
	outtextxy(300, 200, "11. Tower of Hanoi");
	outtextxy(300, 225, "12. Digital Clock");
	outtextxy(260, 260, "13. Exit");

	g(27,22);
	p("\033[1;37m+------------------------+\n\n\n\n\t\t\t  +------------------------+");
	g(30,24);
	p("Enter your choice: ");
	s("%d", &choice);

	switch (choice) {
	    case 1:
		expo();
		break;
	    case 2:
		maze();
		break;
	    case 3:
		barg();
		break;
	    case 4:
		tictac();
		break;
	    case 5:
		garages();
		break;
	    case 6:
		garageq();
		break;
	    case 7:
		treet();
		break;
	    case 8:
		treem();
		break;
	    case 9:
		fibo();
		break;
	    case 10:
		fact();
		break;
	    case 11:
		tower();
		break;
	    case 12:
		digi();
		break;
	    case 13:
		p("Exiting...\n");
		closegraph();
		return 0;
	    default:
		cleardevice();
		settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
		outtextxy(100, 50, "Invalid choice. Please try again.");
		break;
	}

    } while (choice != 13);

    return 0;
}
