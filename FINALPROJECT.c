#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <graphics.h>
#include <dos.h>
#include <time.h>
#define p printf
#define s scanf
#define g gotoxy
#define t textcolor
#define c cprintf
#define MAX_CARS 10
#define STACK_SIZE 10
#define QUEUE_SIZE 5

// Function prototypes
void ticTacToe();
void binaryTraversal();
void binarySearch();
void CarParking();
void Exponent();
void Maze();
void BarGraph();
void fibonacci();
void digi();
void garages();
void facto();
void tower();
void carstack();
void garageq();

// Program 7s
int stack[STACK_SIZE];
int top = -1;

void push(int value) {
    if (top == STACK_SIZE - 1) {
	p("Parking is full. Cannot add Car %d\n", value);
    } else {
	stack[++top] = value;
	p("Car %d has entered the parking.\n", value);
    }
}

int findCarIndex(int car) {
    int i;
    for (i = 0; i <= top; i++) {
	if (stack[i] == car) {
	    return i;
	}
    }
    return -1;
}

int pop(int car) {
    int carIndex = findCarIndex(car), i;
    if (carIndex != -1) {
	for (i = carIndex; i < top; i++) {
	    stack[i] = stack[i + 1];
	}
	top--;
	return carIndex;
    }
    return -1; // Car not found
}

void displayStack() {
    int i;
    if (top == -1) {
	g(57, 4);
	t(3);
	c("Parking is empty.\n");
    } else {
	g(57, 4);
	t(12);
	c("Parking Lot:\n");
	for (i = 0; i <= top; i++) {
	    g(60, 5 + i * 4);  // Adjusted the y-coordinate to avoid gaps
	    t(11);
	    c("  _______\n");
	    g(60, 6 + i * 4);
	    t(11);
	    c(" |       |__\n");
	    g(60, 7 + i * 4);
	    t(11);
	    c(" |  Car%d    |\n", stack[i]);
	    g(60, 8 + i * 4);
	    t(11);
	    c(" |__0____0___|\n");
	}
	p("\n");
    }
}

int queue[QUEUE_SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == QUEUE_SIZE - 1) {
	p("Queue is full. Car %d cannot be parked.\n", value);
    } else {
	if (front == -1) {
	    front = 0;
	}
	queue[++rear] = value;
	p("Car %d successfully parked\n", value);
    }
}

int dequeue() {
    int car;
    if (front == -1) {
	p("Queue is empty. No cars to depart.\n");
	return -1;
    } else {
	car = queue[front++];
	if (front > rear) {
	    front = rear = -1;
	}
	return car;
    }
}

// Car stack function
void carstack() {
    int i, choice, car;
    clrscr();
    do {
        int carIndex;
        g(1, 4);
        t(14);
        c("Enter 1 for Arrival, 2 for Departure, 3 to Exit: ");
        s("%d", &choice);

        if (choice == 1) {
            t(10);
            c("Enter the car's plate number: ");
            s("%d", &car);
            push(car);
        } else if (choice == 2) {
            clrscr(); // Clear the screen

            g(1, 4);
            p("Enter the car's plate number to depart: ");
            s("%d", &car);
            p("Car successfully departed");

            carIndex = pop(car);
            if (carIndex != -1) {
                // Display temporarily departed cars (if any)
                g(57, 8);
                p("Temporary Departed Cars: ");
                for (i = carIndex; i <= top; i++) {
                    g(60, 11 + (i) - carIndex - 1);
                    p("Car %d\n", stack[i]);
                }

                // Prompt the user to press a key before reparking the other cars
                p("Press any key to repark the other cars...");
                getch();
            }
        } else if (choice == 3) {
            p("Exiting the parking program.\n");
        } else {
            p("Invalid choice.\n");
        }

        clrscr(); // Clear the screen
        displayStack();
    } while (choice != 3);

    getch();
}

//Program 1
void Exponent() {
    int x, gd = DETECT, gm;

    // Initialize graphics mode
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Draw the title
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
    setcolor(YELLOW);
    outtextxy(110, 50, "* N SQUARE CUBE *");

    settextstyle(SMALL_FONT, HORIZ_DIR, 5);
    setcolor(LIGHTGRAY);
    outtextxy(170, 80, "(Squares and Cubes of numbers 0 - 10)");

    // Draw the table headers
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    setcolor(LIGHTMAGENTA);
    outtextxy(150, 150, "Number");
    outtextxy(300, 150, "Square");
    outtextxy(450, 150, "Cube");

    // Loop to calculate and display numbers, squares, and cubes
    for (x = 0; x <= 10; x++) {
	char num[3], square[5], cube[7];

	// Convert integers to strings for display
	sprintf(num, "%d", x);
	sprintf(square, "%d", x * x);
	sprintf(cube, "%d", x * x * x);

	// Display the number, square, and cube at specific positions
	setcolor(WHITE);
	outtextxy(150, 170 + x * 20, num);    // Display the number
	outtextxy(300, 170 + x * 20, square); // Display the square
	outtextxy(450, 170 + x * 20, cube);   // Display the cube
    }

    getch();  // Wait for a key press before exiting
    closegraph();  // Close the graphics window
}

//Program 2
void Maze()
{  int x,y;
   clrscr();

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
void BarGraph()
{
      int x,y,cpe,ce,ece,ee,me,ie,rem;

clrscr();

//Screen
       for(x=1; x<=40; x++)
       {
       g(x,1); p("\033[0;31m%c\033[0m",205);
       g(x,24); p("\033[0;31m%c\033[0m",205);
       }
       for(y=1; y<=24; y++)
       {
       g(1,y); p("\033[0;31m%c\033[0m",186);
       g(40,y); p("\033[0;31m%c\033[0m",186);
       }
       g(1,1); p("\033[0;31m%c\033[0m",201); g(40,1); p("\033[0;31m%c\033[0m",187);
       g(1,24); p("\033[0;31m%c\033[0m",200); g(40,24); p("\033[0;31m%c\033[0m",188);
       for(x=41; x<=79; x++)
       {
       g(x,1); p("\033[0;31m%c\033[0m",205);
       g(x,24); p("\033[0;31m%c\033[0m",205);
       }
       for(y=1; y<=24; y++)
       {
       g(41,y); p("\033[0;31m%c\033[0m",186);
       g(79,y); p("\033[0;31m%c\033[0m" ,186);
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
       for(x=1; x<=ece/25; x++)
       {
       g(47+x,5); delay(25); p("\033[0;34m%c\033[0m",219);
       }
       for(x=1; x<=ee/25; x++)
       {
       g(47+x,7); delay(25); p("\033[0;37m%c\033[0m",219);
       }
       for(x=1; x<=ce/25; x++)
       {
       g(47+x,9); delay(25); p("\033[0;36m%c\033[0m",219);
       }
       for(x=1; x<=rem/25; x++)
       {
       g(47+x,11); delay(25); p("\033[0;34m%c\033[0m",219);
       }
       for(x=1; x<=me/25; x++)
       {
       g(47+x,13); delay(25); p("\033[0;37m%c\033[0m",219);
       }
       for(x=1; x<=ie/25; x++)
       {
       g(47+x,15); delay(25); p("\033[0;36m%c\033[0m ",219);
       }
       for(x=1; x<=cpe/25; x++)
       {
       g(47+x,17); delay(25); p("\033[0;34m%c\033[0m",219); t(15);
       }
getch();
}

//Program 4
char box[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int win();
void board();

void ticTacToe(){
    int player = 1, move;
    char place;

    int x, gd = DETECT, gm;

    // Initialize graphics mode
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    do
    {
	    board();
	    player = (player % 2) ? 1 : 2;

	    g(5, 20);
	    p("\033[0;33mPLAYER %d, enter a no.:  \033[0m", player);
	    s("%d", &move);

	    place = (player == 1) ? 'X' : 'O';

	    if (move >= 1 && move <= 9 && box[move] == '0' + move)
		box[move] = place;
	    else
	    {
		p("     INVALID MOVE! TRY AGAIN.");
		 // Keep the same player for another try
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
	p("\033[0m *SYMBOLS*");
	g(5, 10);
	p("\033[0;31mPLAYER 1: X\n    \033[0;36mPLAYER 2: O\n\033[0m");
	g(5, 13);
	p("\033[0;33mHOW TO PLAY: \033[0;37m\n    Enter a number (1-9) to place \n    your symbol on the board.\n    The first to get 3 of her marks in a \n    row wins. The game ties if neither \n    player has 3 consecutive marks. \n\033[0m");
    }

    // Title
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
    setcolor(YELLOW);
    outtextxy(140, 30, "o TIC-TAC-TOE x");

    // Board

    for (x = 15; x <= 45; x++)
    {
	g(x + 30, 12);
	p("\033[0;35m%c", 205);
	g(x + 30, 17);
	p("%c", 205);
    }

    for (y = 1; y <= 14; y++)
    {
	g(55, y + 7);
	p("\033[0;35m%c", 186);
	g(65, y + 7);
	p("%c\033[0m", 186);
    }

    // Assigning numbers for each box
    {
	g(50, 10);
	p("\033[1;37m%c", box[1]);
	g(60, 10);
	p("\033[1;37m%c", box[2]);
	g(70, 10);
	p("\033[1;37m%c", box[3]);
	g(50, 15);
	p("\033[1;37m%c", box[4]);
	g(60, 15);
	p("\033[1;37m%c", box[5]);
	g(70, 15);
	p("\033[1;37m%c", box[6]);
	g(50, 20);
	p("\033[1;37m%c", box[7]);
	g(60, 20);
	p("\033[1;37m%c", box[8]);
	g(70, 20);
	p("\033[1;37m%c", box[9]);
    }
}


// Program 5 Binary Tree Traversal

void drawCircle(int x, int y, int radius) {
    circle(x, y, radius);
    floodfill(x, y, WHITE);
}

void drawLine(int x1, int y1, int x2, int y2) {
    line(x1, y1, x2, y2);
}

void binaryTraversal() {
    int x, y, level;
    char node1[5], node2[5], node3[5], node4[5], node5[5], node6[5], node7[5], node8[5],
	 node9[5], node10[5], node11[5], node12[5], node13[5], node14[5], node15[5];

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    setbkcolor(BLUE);

    //top design
    drawCircle(40,40, 20);
    drawLine(40,40,110,30);
    drawCircle(180,40, 20);
    drawLine(180,40,110,30);
    drawCircle(320,40, 20);
    drawLine(320,40,260,30);
    drawLine(180,40,260,30);
    drawCircle(460,40, 20);
    drawLine(460,40,380,30);
    drawLine(320,40,380,30);
    drawCircle(600,40, 20);
    drawLine(600,40,530,30);
    drawLine(460,40,530,30);

    //bottom design
    drawCircle(40,430, 20);
    drawLine(40,430,110,440);
    drawCircle(180,430, 20);
    drawLine(180,430,110,440);
    drawCircle(320,430, 20);
    drawLine(320,430,260,440);
    drawLine(180,430,260,440);
    drawCircle(460,430, 20);
    drawLine(460,430,380,440);
    drawLine(320,430,380,440);
    drawCircle(600,430, 20);
    drawLine(600,430,530,440);
    drawLine(460,430,530,440);

    // Graphics for title
    setcolor(6);
    settextstyle(0, HORIZ_DIR, 4);
    outtextxy(50, 210, "BINARY TRAVERSAL");
    setcolor(15);

    // Ask user for number of levels
    settextstyle(0, HORIZ_DIR, 1);
    outtextxy(50, 260,"How many levels of binary tree? (Max of 4): ");
    g(51, 17);
    s("%d", &level);

    setbkcolor(BLACK);
    cleardevice(); // Clear the console screen

    textcolor(RED);

    if (level == 1) {
	x = getmaxx() / 2; // Get the center of the screen
	y = 50;
	drawCircle(x, y, 20); // Draw root node
	g(1, 1);
	p("Enter a character (use '-' for null): ");
	g(40, 4);
	s(" %s", node1);

	//
	g(3, 22);
	p("PREORDER:  %s", node1);
	g(3, 23);
	p("POSTORDER: %s", node1);
	g(3, 24);
	p("INORDER:   %s", node1);


    } else if (level == 2) {
	x = getmaxx() / 2;
	y = 50;

	// Draw root node
	drawCircle(x, y, 20);
	g(1, 1);
	p("Enter a character (use '-' for null): ");
	g(40, 4);
	scanf(" %s", node1);

	// Check if the input is a dash
	if (strcmp(node1, "-") == 0) {
	    g(20,17);p("Input is null. Tree construction stopped.");
	} else {
	    // Draw left child
	    drawCircle(x - 50, y + 50, 20);
	    drawLine(x, y + 20, x - 50, y + 30);

	    // Let user input for left child
	    g(1, 1);
	    p("Enter a character (use '-' for null): ");
	    g(34, 7);
	    s(" %s", node2);

	    // Draw right child
	    drawCircle(x + 50, y + 50, 20);
	    drawLine(x, y + 20, x + 50, y + 30);

	    // Let user input for right child
	    g(1, 1);
	    p("Enter a character (use '-' for null): ");
	    g(47, 7);
	    s(" %s", node3);

	    g(3, 22);
	    p("PREORDER:  %s,%s,%s", node1, node2, node3);
	    g(3, 23);
	    p("POSTORDER: %s,%s,%s", node2, node3, node1);
	    g(3, 24);
	    p("INORDER:   %s,%s,%s", node2, node1, node3);
	}
    } else if (level == 3) {
	x = getmaxx() / 2;
	y = 50;

	// Draw root node
	drawCircle(x, y, 20);
	g(1, 1);
	p("Enter a character (use '-' for null): ");
	g(40, 4);
	scanf(" %s", node1);

	// Check if the input is a dash
	if (strcmp(node1, "-") == 0) {
	    g(20,17);p("Input is null. Tree construction stopped.");
	} else {
	    // Draw left child
	    drawCircle(x - 50, y + 50, 20);
	    drawLine(x, y + 20, x - 50, y + 30);

	    // Let the user input for left child
	    g(1, 1);
	    p("Enter a character (use '-' for null): ");
	    g(34, 7);
	    s(" %s", node2);

	    // Check if the input is a dash for the left child
	    if (strcmp(node2, "-") == 0) {
		g(10, 17);
		p("Input for left node is null. Left node construction stopped.");
		strcpy(node4, "-");
		strcpy(node5, "-");
	    } else {
		// 1ST CHILD OF LEFT
		drawCircle(x - 75, y + 100, 20);
		drawLine(x - 75, y + 80, x - 35, y + 50);
		g(1, 1);
		p("Enter a character (use '-' for null): ");
		g(32, 10);
		s(" %s", node4);

		// 2ND CHILD OF LEFT
		drawCircle(x - 25, y + 100, 20);
		drawLine(x - 25, y + 80, x - 45, y + 50);
		g(1, 1);
		p("Enter a character (use '-' for null): ");
		g(38, 10);
		s(" %s", node5);
	    }

	    // Draw right child
	    drawCircle(x + 50, y + 50, 20);
	    drawLine(x, y + 20, x + 50, y + 30);
	    g(1, 1);
	    p("Enter a character (use '-' for null): ");
	    g(47, 7);
	    s(" %s", node3);

	    // Check if the input is a dash for the right child
	    if (strcmp(node3, "-") == 0) {
		g(10, 17);
		p("Input for right node is null. Right node construction stopped.");
		strcpy(node6, "-");
		strcpy(node7, "-");
	    } else {
		// 1ST CHILD OF RIGHT
		drawCircle(x + 25, y + 100, 20);
		drawLine(x + 25, y + 80, x + 45, y + 50);
		g(1, 1);
		p("Enter a character (use '-' for null): ");
		g(44, 10);
		s(" %s", node6);

		// 2ND CHILD OF RIGHT
		drawCircle(x + 75, y + 100, 20);
		drawLine(x + 75, y + 80, x + 55, y + 50);
		g(1, 1);
		p("Enter a character (use '-' for null): ");
		g(50, 10);
		s(" %s", node7);
	    }

	    g(3, 22);
	    p("PREORDER:  %s,%s,%s,%s,%s,%s,%s", node1, node2, node4, node5, node3, node6, node7);
	    g(3, 23);
	    p("POSTORDER: %s,%s,%s,%s,%s,%s,%s", node4, node5, node2, node6, node7, node3, node1);
	    g(3, 24);
	    p("INRODER:   %s,%s,%s,%s,%s,%s,%s", node4, node2, node5, node1, node6, node3, node7);
	}
    } else if (level == 4) {
	x = getmaxx() / 2;
	y = 50;

	// Draw root node
	drawCircle(x, y, 20);
	g(1, 1);
	p("Enter a character (use '-' for null): ");
	g(40, 4);
	s(" %s", node1);

	// Check if the input is a dash
	if (strcmp(node1, "-") == 0) {
	    g(20,17);p("Input is null. Tree construction stopped.");
	} else {
	    // Draw left child
	    drawCircle(x - 50, y + 50, 20);
	    drawLine(x, y + 20, x - 50, y + 30);

	    // Let the user input for left child
	    g(1, 1);
	    p("Enter a character (use '-' for null): ");
	    g(34, 7);
	    s(" %s", node2);

	    // Check if the input is a dash for the left child
	    if (strcmp(node2, "-") == 0) {
		g(10, 17);
		p("Input for left node is null. Left node construction stopped.");
		strcpy(node4, "-");
		strcpy(node5, "-");
		strcpy(node8, "-");
		strcpy(node9, "-");
		strcpy(node10, "-");
		strcpy(node11, "-");
	    } else {
		// 1ST CHILD OF LEFT
		drawCircle(x - 75, y + 100, 20);
		drawLine(x - 75, y + 80, x - 35, y + 50);
		g(1, 1);
		p("Enter a character (use '-' for null): ");
		g(32, 10);
		s(" %s", node4);

		if (strcmp(node4, "-") == 0) {
		    g(10, 17);
		    p("Input for left node is null. Left node construction stopped.");
		    strcpy(node8, "-");
		    strcpy(node9, "-");
		} else {
		    // Draw 8 children connected to level 3
		    drawCircle(x - 180, y + 150, 20);
		    drawLine(x - 180, y + 130, x - 75, y + 100);
		    g(1, 1);
		    p("Enter a character (use '-' for null): ");
		    g(18, 13);
		    s(" %s", node8);

		    drawCircle(x - 130, y + 150, 20);
		    drawLine(x - 130, y + 130, x - 75, y + 100);
		    g(1, 1);
		    p("Enter a character (use '-' for null): ");
		    g(24, 13);
		    s(" %s", node9);
		}

		// 2ND CHILD OF LEFT
		drawCircle(x - 25, y + 100, 20);
		drawLine(x - 25, y + 80, x - 45, y + 50);
		g(1, 1);
		p("Enter a character (use '-' for null): ");
		g(38, 10);
		s(" %s", node5);

		if (strcmp(node5, "-") == 0) {
		    g(10, 17);
		    p("Input for right node is null. Right node construction stopped.");
		    strcpy(node10, "-");
		    strcpy(node11, "-");
		} else {
		    drawCircle(x - 80, y + 150, 20);
		    drawLine(x - 80, y + 130, x - 25, y + 100);
		    g(1, 1);
		    p("Enter a character (use '-' for null): ");
		    g(30, 13);
		    s(" %s", node10);

		    drawCircle(x - 30, y + 150, 20);
		    drawLine(x - 30, y + 130, x - 25, y + 100);
		    g(1, 1);
		    p("Enter a character (use '-' for null): ");
		    g(36, 13);
		    s(" %s", node11);
		}
	    }

	    // Draw right child
	    drawCircle(x + 50, y + 50, 20);
	    drawLine(x, y + 20, x + 50, y + 30);
	    g(1, 1);
	    p("Enter a character (use '-' for null): ");
	    g(47, 7);
	    s(" %s", node3);

	    // Check if the input is a dash for the right child
	    if (strcmp(node3, "-") == 0) {
		g(10, 17);
		p("Input for right node is null. Right node construction stopped.");
		strcpy(node6, "-");
		strcpy(node7, "-");
		strcpy(node12, "-");
		strcpy(node13, "-");
		strcpy(node14, "-");
		strcpy(node15, "-");
	    } else {
		// 1ST CHILD OF RIGHT
		drawCircle(x + 25, y + 100, 20);
		drawLine(x + 25, y + 80, x + 45, y + 50);
		g(1, 1);
		p("Enter a character (use '-' for null): ");
		g(44, 10);
		s(" %s", node6);

		if (strcmp(node6, "-") == 0) {
		    g(10, 17);
		    p("Input for left node is null. Left node construction stopped.");
		    strcpy(node12, "-");
		    strcpy(node13, "-");
		} else {
		    drawCircle(x + 20, y + 150, 20);
		    drawLine(x + 20, y + 130, x + 25, y + 100);
		    g(1, 1);
		    p("Enter a character (use '-' for null): ");
		    g(42, 13);
		    s(" %s", node12);

		    drawCircle(x + 70, y + 150, 20);
		    drawLine(x + 70, y + 130, x + 25, y + 100);
		    g(1, 1);
		    p("Enter a character (use '-' for null): ");
		    g(48, 13);
		    s(" %s", node13);
		}

		drawCircle(x + 75, y + 100, 20);
		drawLine(x + 75, y + 80, x + 55, y + 50);
		g(1, 1);
		p("Enter a character (use '-' for null): ");
		g(50, 10);
		s(" %s", node7);

		if (strcmp(node7, "-") == 0) {
		    g(10, 17);
		    p("Input for right node is null. Right node construction stopped.");
		    strcpy(node14, "-");
		    strcpy(node15, "-");
		} else {
		    drawCircle(x + 120, y + 150, 20);
		    drawLine(x + 120, y + 130, x + 75, y + 100);
		    g(1, 1);
		    p("Enter a character (use '-' for null): ");
		    g(54, 13);
		    s(" %s", node14);

		    drawCircle(x + 170, y + 150, 20);
		    drawLine(x + 170, y + 130, x + 75, y + 100);
		    g(1, 1);
		    p("Enter a character (use '-' for null): ");
		    g(60, 13);
		    s(" %s", node15);
		}
	    }

	    // Print the tree structure
	    g(3, 22);
	    p("PREORDER:  %s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s", node1, node2, node4, node8, node9, node5, node10, node11, node3, node6, node12, node13, node7, node14, node15);
	    g(3, 23);
	    p("POSTORDER: %s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s", node8, node9, node4, node10, node11, node5, node2, node12, node13, node6, node14, node15, node7, node3, node1);
	    g(3, 24);
	    p("INORDER:   %s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s", node8, node4, node9, node2, node10, node5, node11, node1, node12, node6, node13, node3, node14, node7, node15);
	}
    } else {
	p("Out of range. Choose 1-4 only.");
    }

    getch();
    closegraph();

    return 0;
}

// Program 6 Binary Search Tree

void binarySearch() {
    char* nodes[5]; // Array of pointers to strings
    int i, j, x, y;

    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    setbkcolor(BLUE);
    setcolor(6);
    settextstyle(0, HORIZ_DIR, 4);
    outtextxy(30, 40, "BINARY SEARCH TREE");

    setcolor(4);
    settextstyle(0, HORIZ_DIR, 2);
    outtextxy(50, 160, "Reminder:");

    //setcolor(14);
    //settextstyle(2, HORIZ_DIR, 6);
    g(7,9);p("_____________________________________________________________________");

    g(7,13);p("1.Input exactly 5 numbers only");
    g(7,14);p("2.List of sequence of numbers that you can only input:");
    g(10,16);p("\t  1-2-3-4-5\t  5-4-3-2-1\t  3-2-1-5-4\n\t\t  3-5-4-1-2\t  1-5-2-4-3\t  5-1-4-2-3\n\t\t  2-1-5-3-4\t  2-1-3-4-5\t  4-2-1-3-5\t\n\t\t\t\t  4-3-2-1-5");
    g(7,20);p("_____________________________________________________________________");

    g(25,25);p("Press any key to continue.");


    setcolor(15);
    settextstyle(2, HORIZ_DIR, 6);
    outtextxy(100, 332, "");

    getch();
    clrscr();
    cleardevice();
    setbkcolor(BLACK);

    // User input for 5 strings
    printf("Enter 5 characters separated by spaces: ");
    for (i = 0; i < 5; ++i) {
	nodes[i] = (char*)malloc(5 * sizeof(char)); // Assuming each string can store up to 4 characters + null terminator
	scanf(" %4s", nodes[i]);
    }
    x = getmaxx() / 2;
    y = 50;

    if (strcmp(nodes[0], "5") == 0 && strcmp(nodes[1], "4") == 0 && strcmp(nodes[2], "3") == 0 && strcmp(nodes[3], "2") == 0 && strcmp(nodes[4], "1") == 0) {
	// Handle the case when nodes are in "54321" order
	setbkcolor(0);
	drawCircle(x, y, 20);
	g(40, 4);
	p(nodes[0]);

	if (i >= 2) {
	    // Draw left child
	    drawCircle(x - 50, y + 50, 20);
	    drawLine(x, y + 20, x - 50, y + 30);
	    g(34, 7);
	    p(nodes[1]);

	    if (i >= 3) {
		// 1ST CHILD OF LEFT
		drawCircle(x - 75, y + 100, 20);
		drawLine(x - 75, y + 80, x - 35, y + 50);
		g(32, 10);
		p(nodes[2]);

		if (i >= 4) {
		    // 2ND CHILD OF 1ST CHILD OF LEFT
		    drawCircle(x - 100, y + 150, 20);
		    drawLine(x - 100, y + 130, x - 80, y + 100);
		    g(28, 13);
		    p(nodes[3]);

		    if (i >= 5) {
			// 3RD CHILD OF 2ND CHILD OF 1ST CHILD OF LEFT
			drawCircle(x - 125, y + 200, 20);
			drawLine(x - 125, y + 180, x - 105, y + 150);
			g(25, 16);
			p(nodes[4]);




	    // Print the tree structure
	    g(3, 20);
	    p("PREORDER:  5 4 3 2 1");
	    g(3, 21);
	    p("POSTORDER: 1 2 3 4 5");
	    g(3, 22);
	    p("INRODER:  1 2 3 4 5");

		    }
		}
	    }
	}

 } else if (strcmp(nodes[0], "1") == 0 && strcmp(nodes[1], "2") == 0 && strcmp(nodes[2], "3") == 0 && strcmp(nodes[3], "4") == 0 && strcmp(nodes[4], "5") == 0) {
	// Handle the case when nodes are in "12345" order
	drawCircle(x, y, 20);
	g(40, 4);
	p(nodes[0]);

	if (i >= 2) {
	    // Draw right child
	    drawCircle(x + 50, y + 50, 20);
	    drawLine(x, y + 20, x + 50, y + 30);
	    g(47, 7);
	    p(nodes[1]);

	    if (i >= 3) {
		// 1ST CHILD OF RIGHT
		drawCircle(x + 75, y + 100, 20);
		drawLine(x + 75, y + 80, x + 55, y + 50);
		g(50, 10);
		p(nodes[2]);

		if (i >= 4) {
		    // 2ND CHILD OF 1ST CHILD OF RIGHT
		    drawCircle(x + 100, y + 150, 20);
		    drawLine(x + 100, y + 130, x + 80, y + 100);
		    g(53, 13);
		    p(nodes[3]);

		    if (i >= 5) {
			// 3RD CHILD OF 2ND CHILD OF 1ST CHILD OF RIGHT
			drawCircle(x + 125, y + 200, 20);
			drawLine(x + 125, y + 180, x + 105, y + 150);
			g(56,16); p(nodes[4]);
	    // Print the tree structure
	    g(3, 20);
	    p("PREORDER:  %s,%s,%s,%s,%s", nodes[0], nodes[1], nodes[2], nodes[3], nodes[4]);
	    g(3, 21);
	    p("POSTORDER: %s,%s,%s,%s,%s", nodes[0], nodes[1], nodes[2], nodes[3], nodes[4]);
	    g(3, 22);
	    p("INORDER:   %s,%s,%s,%s,%s", nodes[0], nodes[1], nodes[2], nodes[3], nodes[4]);



		    }
		}
	    }
	}




    } else if (strcmp(nodes[0], "3") == 0 && strcmp(nodes[1], "2") == 0 && strcmp(nodes[2], "1") == 0 && strcmp(nodes[3], "5") == 0 && strcmp(nodes[4], "4") == 0) {
	// Handle the case when nodes are in "32154" order
	drawCircle(x, y, 20);
	g(40, 4);
	p(nodes[0]);

	if (i >= 2) {
	    // Draw left child
	    drawCircle(x - 50, y + 50, 20);
	    drawLine(x, y + 20, x - 50, y + 30);
	    g(34, 7);
	    p(nodes[1]);

	    if (i >= 3) {
		// 1ST CHILD OF LEFT
		    drawCircle(x - 75, y + 100, 20);
		    drawLine(x - 75, y + 80, x - 35, y + 50);
		g(32, 10);
		p(nodes[2]);

		if (i >= 4) {

	    // Draw right child
	    drawCircle(x + 50, y + 50, 20);
	    drawLine(x, y + 20, x + 50, y + 30);
	    g(47, 7);

		    p(nodes[3]);

		    if (i >= 5) {
		// 1ST CHILD OF RIGHT
		     drawCircle(x + 25, y + 100, 20);
		     drawLine(x + 25, y + 80, x + 45, y + 50);
		g(44, 10);
			p(nodes[4]);

	    // Print the tree structure
	    g(3, 20);
	    p("PREORDER:  3 2 1 5 4");
	    g(3, 21);
	    p("POSTORDER: 1 2 4 5 3");
	    g(3, 22);
	    p("INORDER:   1 2 3 4 5");

		    }
		}
	    }
	}


    } else if (strcmp(nodes[0], "3") == 0 && strcmp(nodes[1], "5") == 0 && strcmp(nodes[2], "4") == 0 && strcmp(nodes[3], "1") == 0 && strcmp(nodes[4], "2") == 0) {
	// Handle the case when nodes are in "35412" order
	drawCircle(x, y, 20);
	g(40, 4);
	p(nodes[0]);

	if (i >= 2) {
	    // Draw left child
	    drawCircle(x - 50, y + 50, 20);
	    drawLine(x, y + 20, x - 50, y + 30);
	    g(34, 7);
	    p(nodes[3]);

	    if (i >= 3) {
		// 2ND CHILD OF LEFT
		    drawCircle(x - 25, y + 100, 20);
		    drawLine(x - 25, y + 80, x - 45, y + 50);
		g(38, 10);
		p(nodes[4]);

		if (i >= 4) {

	    // Draw right child
	    drawCircle(x + 50, y + 50, 20);
	    drawLine(x, y + 20, x + 50, y + 30);
	    g(47, 7);

		    p(nodes[1]);

		    if (i >= 5) {
		// 1ST CHILD OF RIGHT
		     drawCircle(x + 25, y + 100, 20);
		     drawLine(x + 25, y + 80, x + 45, y + 50);
		g(44, 10);
			p(nodes[2]);


	    // Print the tree structure
	    g(3, 20);
	    p("PREORDER: 3 1 2 5 4");
	    g(3, 21);
	    p("POSTORDER: 2 1 4 5 3");
	    g(3, 22);
	    p("INORDER:   1 2 3 4 5");




		    }
		}
	    }
	}




    } else if (strcmp(nodes[0], "2") == 0 && strcmp(nodes[1], "1") == 0 && strcmp(nodes[2], "3") == 0 && strcmp(nodes[3], "4") == 0 && strcmp(nodes[4], "5") == 0) {
	// Handle the case when nodes are in "21345" order
	drawCircle(x, y, 20);
	g(40, 4);
	p(nodes[0]);

	if (i >= 2) {
	    // Draw left child
	    drawCircle(x - 50, y + 50, 20);
	    drawLine(x, y + 20, x - 50, y + 30);
	    g(34, 7);
	    p(nodes[1]);

	    if (i >= 3) {

	    // Draw right child
	    drawCircle(x + 50, y + 50, 20);
	    drawLine(x, y + 20, x + 50, y + 30);
	    g(47, 7);
	    p(nodes[2]);

	    if (i >= 4) {
		// 1ST CHILD OF RIGHT
		drawCircle(x + 75, y + 100, 20);
		drawLine(x + 75, y + 80, x + 55, y + 50);
		g(50, 10);
		p(nodes[3]);

		if (i >= 5) {
		    // 2ND CHILD OF 1ST CHILD OF RIGHT
		    drawCircle(x + 100, y + 150, 20);
		    drawLine(x + 100, y + 130, x + 80, y + 100);
		    g(53, 13);
		    p(nodes[4]);

	    // Print the tree structure
	    g(3, 20);
	    p("PREORDER:  2 1 3 4 5");
	    g(3, 21);
	    p("POSTORDER: 1 5 4 3 2");
	    g(3, 22);
	    p("INRODER:   1 2 3 4 5");

		    }
		}
	    }
	}


    } else if (strcmp(nodes[0], "2") == 0 && strcmp(nodes[1], "1") == 0 && strcmp(nodes[2], "5") == 0 && strcmp(nodes[3], "3") == 0 && strcmp(nodes[4], "4") == 0) {
	// Handle the case when nodes are in "21534" order
	drawCircle(x, y, 20);
	g(40, 4);
	p(nodes[0]);

	if (i >= 2) {
	    // Draw left child
	    drawCircle(x - 50, y + 50, 20);
	    drawLine(x, y + 20, x - 50, y + 30);
	    g(34, 7);
	    p(nodes[1]);

	    if (i >= 3) {

	    // Draw right child
	    drawCircle(x + 50, y + 50, 20);
	    drawLine(x, y + 20, x + 50, y + 30);
	    g(47, 7);
	    p(nodes[2]);

	    if (i >= 4) {
		// 1ST CHILD OF RIGHT
		     drawCircle(x + 25, y + 100, 20);
		     drawLine(x + 25, y + 80, x + 45, y + 50);
		g(44, 10);
		p(nodes[3]);

		if (i >= 5) {
		    // 2ND CHILD OF 1ST CHILD OF RIGHT
		    drawCircle(x + 70, y + 150, 20);
		    drawLine(x + 70, y + 130, x + 25, y + 100);
		    g(48, 13);
		    p(nodes[4]);

	    // Print the tree structure
	    g(3, 20);
	    p("PREORDER: 2 1 3 4 5");
	    g(3, 21);
	    p("POSTORDER: 1 4 3 5 2");
	    g(3, 22);
	    p("INORDER:   1 2 3 4 5");

		    }
		}
	    }
	}

    } else if (strcmp(nodes[0], "1") == 0 && strcmp(nodes[1], "5") == 0 && strcmp(nodes[2], "2") == 0 && strcmp(nodes[3], "4") == 0 && strcmp(nodes[4], "3") == 0) {
	// Handle the case when nodes are in "15243" order
	drawCircle(x, y, 20);
	g(40, 4);
	p(nodes[0]);

	if (i >= 2) {
	    // Draw right child
	    drawCircle(x + 50, y + 50, 20);
	    drawLine(x, y + 20, x + 50, y + 30);
	    g(47, 7);
	    p(nodes[1]);


	    if (i >= 3) {
		// 1ST CHILD OF RIGHT
		     drawCircle(x + 25, y + 100, 20);
		     drawLine(x + 25, y + 80, x + 45, y + 50);
		g(44, 10);
		p(nodes[2]);

	    if (i >= 4) {

		    // 2ND CHILD OF 1ST CHILD OF RIGHT
		    drawCircle(x + 70, y + 150, 20);
		    drawLine(x + 70, y + 130, x + 25, y + 100);
		    g(48, 13);
		    p(nodes[3]);


		if (i >= 5) {



			// 3RD CHILD OF 2ND CHILD OF 1ST CHILD OF RIGHT
			drawCircle(x + 25, y + 200, 20);
			drawLine(x + 25, y + 180, x + 80, y + 150);
			g(43,16); p(nodes[4]);




	    // Print the tree structure
	    g(3, 20);
	    p("PREORDER: 1 5 2 4 3");
	    g(3, 21);
	    p("POSTORDER: 3 4 2 5 1");
	    g(3, 22);
	    p("INORDER:   1 2 3 4 5");

		    }
		}
	    }
	}

    } else if (strcmp(nodes[0], "5") == 0 && strcmp(nodes[1], "1") == 0 && strcmp(nodes[2], "4") == 0 && strcmp(nodes[3], "2") == 0 && strcmp(nodes[4], "3") == 0) {
	// Handle the case when nodes are in "51423" order
	drawCircle(x, y, 20);
	g(40, 4);
	p(nodes[0]);

	if (i >= 2) {
	    // Draw left child
	    drawCircle(x - 50, y + 50, 20);
	    drawLine(x, y + 20, x - 50, y + 30);
	    g(34, 7);
	    p(nodes[1]);


	    if (i >= 3) {
		    // 2ND CHILD OF LEFT
		    drawCircle(x - 25, y + 100, 20);
		    drawLine(x - 25, y + 80, x - 45, y + 50);
		g(38, 10);
		p(nodes[2]);

	    if (i >= 4) {

		    // 2ND CHILD OF 1ST CHILD OF RIGHT
		    drawCircle(x - 80, y + 150, 20);
		    drawLine(x - 80, y + 130, x - 25, y + 100);
		    g(30, 13);
		    p(nodes[3]);


		if (i >= 5) {



			// 3RD CHILD OF 2ND CHILD OF 1ST CHILD OF RIGHT
			drawCircle(x - 25, y + 200, 20);
			drawLine(x - 80, y + 170, x - 25, y + 180);
			g(37,16); p(nodes[4]);


	    // Print the tree structure
	    g(3, 20);
	    p("PREORDER:  5 1 4 2 3");
	    g(3, 21);
	    p("POSTORDER: 3 2 4 1 5");
	    g(3, 22);
	    p("INORDER:  1 2 3 4 5");





		    }
		}
	    }
	}


} else if (strcmp(nodes[0], "4") == 0 && strcmp(nodes[1], "3") == 0 && strcmp(nodes[2], "2") == 0 && strcmp(nodes[3], "1") == 0 && strcmp(nodes[4], "5") == 0) {
    // Handle the case when nodes are in "43215" order
    drawCircle(x, y, 20);
    g(40, 4);
    p(nodes[0]);

    if (i >= 2) {
	// Draw left child
	drawCircle(x - 50, y + 50, 20);
	drawLine(x, y + 20, x - 50, y + 30);
	g(34, 7);
	p(nodes[1]);

	if (i >= 3) {
		drawCircle(x - 75, y + 100, 20);
		drawLine(x - 75, y + 80, x - 35, y + 50);
		g(32, 10);
                p(nodes[2]);


            if (i >= 4) {
                    // Actions when i >= 5 for "43125" order
                    drawCircle(x - 130, y + 150, 20);
                    drawLine(x - 130, y + 130, x - 75, y + 100);
                    g(24, 13);
                    p(nodes[3]);

                if (i >= 5) {

            // Draw right child
            drawCircle(x + 50, y + 50, 20);
            drawLine(x, y + 20, x + 50, y + 30);
            g(47, 7);
            p(nodes[4]);

            // Print the tree structure
            g(3, 20);
            p("PREORDER:  4 3 2 1 5");
            g(3, 21);
            p("POSTORDER: 1 2 3 5 4");
            g(3, 22);
            p("INORDER:   1 2 3 4 5");




                }
            }
        }
    }
}


else if (strcmp(nodes[0], "4") == 0 && strcmp(nodes[1], "2") == 0 && strcmp(nodes[2], "1") == 0 && strcmp(nodes[3], "3") == 0 && strcmp(nodes[4], "5") == 0) {
    // Handle the case when nodes are in "42135" order
    drawCircle(x, y, 20);
    g(40, 4);
    p(nodes[0]);

    if (i >= 2) {
        // Draw left child
        drawCircle(x - 50, y + 50, 20);
        drawLine(x, y + 20, x - 50, y + 30);
        g(34, 7);
        p(nodes[1]);

        if (i >= 3) {

                drawCircle(x - 75, y + 100, 20);
                drawLine(x - 75, y + 80, x - 35, y + 50);
                g(32, 10);
                p(nodes[2]);
            if (i >= 4) {

                    // Actions when i >= 5 for "43215" order
		    drawCircle(x - 25, y + 100, 20);
		    drawLine(x - 25, y + 80, x - 45, y + 50);
                    g(38, 10);
                    p(nodes[3]);

                if (i >= 5) {



            // Draw right child
            drawCircle(x + 50, y + 50, 20);
            drawLine(x, y + 20, x + 50, y + 30);
            g(47, 7);
            p(nodes[4]);


            // Print the tree structure
            g(3, 20);
            p("PREORDER:  4 2 1 3 5");
            g(3, 21);
            p("POSTORDER: 1 3 2 5 4");
            g(3, 22);
            p("INORDER:   1 2 3 4 5");



                }
            }
        }
    }
}


    else {
	p("Invalid input. Please follow the specified format.");
    }





    getch();
    closegraph();
    return 0;
}

//Program 7
//queue
void carenqueue(int value) {
    if (rear == QUEUE_SIZE - 1) {
	p("Queue is full. Car %d cannot be parked.\n", value);
    } else {
	if (front == -1) {
	    front = 0;
	}
	queue[++rear] = value;
	p("Car %d successfully parked\n", value);
    }
}

int cardequeue() {
    int car;
    if (front == -1) {
	p("Queue is empty. No cars to depart.\n");
	return -1;
    } else {
	car = queue[front++];
	if (front > rear) {
	    front = rear = -1;
	}
	return car;
    }
}

void displayQueue() {
    int i;
    if (front == -1) {
	g(57, 4);
	t(3); c("Parking Lot is empty.\n");
    } else {
	g(57, 4);
	t(12); c("Parking Lot:\n");
	for (i = front; i <= rear; i++) {
	    g(60,5 + i * 4 );  // Adjusted the y-coordinate to avoid gaps
	    t(11); c("  _______\n");
	    g(60, 6 + i * 4 );
	    t(11); c(" |       |__\n");
	    g(60, 7 + i * 4 );
	    t(11); c(" |  Car%d    |\n", queue[i]);
	    g(60, 8 + i * 4 );
	    t(11); c(" |__0____0___|\n");
	}
	p("\n");
    }
}

void garageq() {
    int i, choice, car;

    clrscr();
    do {
	int departedCar;
	g(1, 4);
	t(14); c("Enter 1 for Arrival, 2 for Departure, 3 to Exit: ");
	s("%d", &choice);

	if (choice == 1) {
	    car;
	    t(10); c("Enter the car's plate number: ");
	    s("%d", &car);
	    enqueue(car);
	} else if (choice == 2) {
	    clrscr(); // Clear the screen

	    g(1, 4);
	    p("Car %d is departing.\n", dequeue());
	    p("Car has departed.\n");

	    // Prompt the user to press a key before reparking the other cars
	    p("\nPress any key to go back to parking lot...");
	    getch();
	} else if (choice == 3) {
	    p("Exiting the parking program.\n");
	} else {
	    p("Invalid choice.\n");
	}

	clrscr(); // Clear the screen
	displayQueue();
    } while (choice != 3);

    getch();
}

//Program 9
void fibonacci() {
    int i, n;
    char input[10]; // To store user input
    // initialize first and second terms
    long long int t1 = 0, t2 = 1;
    // initialize the next term (3rd term)
    long long int nextTerm = t1 + t2;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

     // Clear the screen
    cleardevice();
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);
    setcolor(BROWN);
    outtextxy(30, 15, "FIBONACCI SEQUENCE");

    settextstyle(SMALL_FONT, HORIZ_DIR, 5);
    setcolor(LIGHTGRAY);
    outtextxy(90, 60, "(Calculates the Fibonacci Series up to maximum of 47 terms)");

    // get no. of terms from user
    g(1,8);
    p("\033[0m+\033[0;33m  Enter the number of terms:  \033[0m");

    // Use a loop to keep prompting until valid input is received
    while (1) {
	outtextxy(90, 120, "                         "); // Clear previous input
	outtextxy(90, 150, "                       "); // Clear previous output
	g(33, 8); // Move cursor to input area
	s("%s", input);

	//Check if the input is a valid integer
	if (sscanf(input, "%d", &n) !=1 || n < 0 || n > 47) {
	    g(4,9);
	    p("\033[0;31m- Invalid input. Please enter a number between 0 and 47.\033[0m");
	} else {
	    break; //Exit the loop if input is valid
	}
    }

    // print the first term
    g(1,11);
    p("\033[0m+\033[0;33m  Fibonacci Sequence: \033[0m");

    if (n >= 1) {
	g(10,13);
	p("%lld", t1);

	if (n > 1) {
	    p(", %lld", t2);

	    // print 3rd to nth terms
	    for (i = 3; i <= n; ++i) {
		p(", %lld", nextTerm);
		t1 = t2;
		t2 = nextTerm;
		nextTerm = t1 + t2;
	    }
	}
    }
    getch(); // Wait for a key press
    closegraph(); // Close graphics mode
}


//Program 10

long long int fact(long long int);

void facto() {
    long long int n, gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Graphics for title
    setcolor(14);
    settextstyle(0, HORIZ_DIR, 4);
    outtextxy(120, 15, "x FACTORIAL x");

    setcolor(10);
    settextstyle(0, HORIZ_DIR, 1);
    outtextxy(115, 100, "Enter the number to get the factorial (Max of 31): ");
    gotoxy(66, 7);
    scanf("%lld", &n);
    printf("\n\n\n\t\t\t  The factorial of %lld is %lld", n, fact(n));

    getch();
    closegraph();
}

long long int fact(long long int n) {
    if (n == 0 || n == 1) {
	return 1;
    } else {
	return n * fact(n - 1);
    }
}

//Program 11
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
    setcolor(MAGENTA);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);
    outtextxy(100, 50, "TOWER OF HANOI");

    gotoxy(9,9);
    printf("\033[0m(\033[0;31mNOTE: \033[0mYou need to complete the simulation to exit the program.)");
    gotoxy(22,8);
    printf("Enter the number of disks \033[0;31m(Max:9)\033[0m: ");
    scanf("%d", &n);

    // Display initial tower state
    displayInitialTower(n, baseY);
    delay(500);

    towerOfHanoi(n, 0, 2, 1, baseY);
    getch();
    closegraph();
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
	setcolor(YELLOW);
	settextstyle(0, HORIZ_DIR, 6);
	strftime(timeStr, 256, "%I:%M:%S %p", timeinfo);
	outtextxy(70, 170, timeStr);
	timeinfo->tm_sec++;
	mktime(timeinfo);
	delay(1000);
    }
    getch();
    closegraph();
}


// Main menu function
    int main() {
    int choice;

    do {
	clrscr(); // Clear the screen

	g(33,5); t(11); cprintf("MENU LIST\n");
	g(10,8); t(11); cprintf("1. | Exponent\n");
	g(10,10); t(14); cprintf("2. | Maze\n");
	g(10,12); t(13); cprintf("3. | Bar Graph\n");
	g(10,14); t(11); cprintf("4. | Tic Tac Toe\n");
	g(10,16); t(14); cprintf("5. | Binary Tree - TRAVERSAL\n");
	g(10,18); t(13); cprintf("6. | Binary Tree - MAKER\n");
	g(45,8); t(11); cprintf("7.  | Garage - STACK\n");
	g(45,10); t(14); cprintf("8.  | Garage - QUEUE\n");
	g(45,12); t(13); cprintf("9.  | Fibonnaci\n");
	g(45,14); t(11); cprintf("10. | Factorial\n");
	g(45,16); t(14); cprintf("11. | Tower of Hanoi\n");
	g(45,18); t(13); cprintf("12. | Digital Clock\n");
	g(35,20); t(12); cprintf("13. Exit\n");
	g(29,22); t(15); cprintf("Enter your choice: ");
	scanf("%d", &choice);

	switch (choice) {
	    case 1:
		Exponent();
		break;
	    case 2:
		Maze();
		break;
	    case 3:
		BarGraph();
		break;
	    case 4:
		ticTacToe();
		break;
	    case 5:
		binaryTraversal();
		break;
	    case 6:
		binarySearch();
		break;
	    case 7:
		carstack();
		break;
	    case 8:
		garageq();
		break;
	    case 9:
		fibonacci();
		break;
	    case 10:
		facto();
		break;
	    case 11:
		tower();
		break;
	    case 12:
		digi();
		break;
	    case 13:
		printf("Exiting the program. Goodbye!\n");
		break;
	    default:
		printf("Invalid choice. Please enter a valid option.\n");
	}

    } while (choice != 13);



    return 0;
}