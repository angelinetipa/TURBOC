#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h> 
#include <graphics.h>
#define p printf
#define s scanf
#define g gotoxy
#define t textcolor
#define c cprintf
#define MAX_CARS 10

char box[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

struct Car {
    char name[20];
    char model[20];
};

struct Car garage[MAX_CARS];
int top = -1;

void push(struct Car car) {
    if (top == MAX_CARS - 1) {
        t(11); c("Garage is full. Cannot add more cars.\n");
        return;
     }
    garage[++top] = car;
    printf("Added %s %s to the garage.\n", car.name, car.model);
}

struct Car pop() {
int i;
    struct Car car;
    int index; // Declare the variable at the beginning of the block

    if (top == -1) {
        struct Car emptyCar = {"", ""};
	t(10); c("Garage is empty. No cars to remove.\n");
        return emptyCar;
    }

    printf("Cars in the garage:\n");
    for (i = 0; i <= top; i++) {
        printf("%d. %s %s\n", i, garage[i].name, garage[i].model);
    }

    do {
        printf("Enter the index of the car you want to remove: ");
        scanf("%d", &index);
    } while (index < 0 || index > top);

    car = garage[index];
    for (i = index; i < top; i++) {
        garage[i] = garage[i + 1];
    }
    top--;

    printf("Removed %s %s from the garage.\n", car.name, car.model);
    return car;
}

void CarParking() {
    int choice;
    struct Car car;

    while (1) {
        printf("\nAvailable slots: %d", MAX_CARS - (top + 1));
        printf("          Taken slots: %d\n", top + 1);
        printf("\n1. Add a car to the garage\n");
        printf("2. Remove a car from the garage\n");
        printf("3. Back to main menu\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the car: ");
                scanf("%s", car.name);
                printf("Enter the model of the car: ");
                scanf("%s", car.model);
                push(car);
                break;
            case 2:
                car = pop();
                break;
            case 3:
                return; // Go back to the main menu
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}



// Function prototypes
void ticTacToe();
void BinaryTree();
void CarParking();
void Exponent();
void Maze();
void BarGraph();

void board(char box[]); // Declare board outside of ticTacToe
int win ();


int main() {
    int choice;

    do {
	clrscr(); // Clear the screen

	g(33,5); t(11); cprintf("MENU LIST:\n");
	g(2,8); t(11); cprintf("1. PROGRAM ONE | Exponent\n");
	g(2,10); t(14); cprintf("2. PROGRAM TWO | Maze\n");
	g(2,12); t(13); cprintf("3. PROGRAM THREE | Bar Graph\n");
	g(2,14); t(11); cprintf("4. PROGRAM FOUR | Tic Tac Toe\n");
	g(2,16); t(14); cprintf("5. PROGRAM FIVE | Garage - STACK\n");
	g(2,18); t(13); cprintf("6. PROGRAM SIX | Garage - QUEUE\n");
	g(38,8); t(11); cprintf("7. PROGRAM SEVEN | Binary Tree - TRAVERSAL\n");
	g(38,10); t(14); cprintf("8. PROGRAM EIGHT | Binary Tree - MAKER\n");
	g(38,12); t(13); cprintf("9. PROGRAM NINE | Fibonnaci\n");
	g(38,14); t(11); cprintf("10.. PROGRAM TEN | Factorial\n");
	g(38,16); t(14); cprintf("11. PROGRAM ELEVEN | Tower of Hanoi\n");
	g(38,18); t(13); cprintf("12. PROGRAM TWELVE | Digital Clock\n");
	g(2,20); t(12);cprintf("13. Exit\n");
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
		ticTacToe();
                break;
            case 6:
		ticTacToe();
                break;
            case 7:
		ticTacToe();
                break;
            case 8:
		ticTacToe();
                break;
            case 9:
		ticTacToe();
                break;
            case 10:
		ticTacToe();
                break;
            case 11:
		ticTacToe();
                break;
            case 12:
		ticTacToe();
                break;
            case 13:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

        if (choice != 7) {
            printf("\nPress any key to continue...");
            getch();
        }

    } while (choice != 7);

    return 0;
}


void Exponent() {
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
    for (x = 0; x <= 10; x++) {
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

void BarGraph()
{
int x,y,cpe,ce,ece,ee,me,ie,rem;

clrscr();

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

void ticTacToe() {
    int player = 1, i , move;
    char place;

    do {
        clrscr();
        textcolor(YELLOW);
        board(box); // Pass the box array to board function
        player = (player % 2)? 1:2;
	     g(5,5); t(13); c("Players mark tile in turns.");
	     g(5,6); t(13); c("The first player to get 3");
	     g(5,7); t(13); c("of her marks in a row");
	     g(5,8); t(13); c("(up,down,across,diagonally)");
	     g(5,9); t(13); c("is the winner. The game ties");
	     g(5,10); t(13); c("if neither player");
	     g(5,11); t(13); c("has 3 consecutive marks.");
	     g(5,15); t(11); c("PLAYER %d", player);
	     g(5,16); t(11); c("PLEASE ENTER A NUMBER(1-9): ", player);
	     s("%d", &move);

	     place = (player == 1)? 'X' : 'O';

	     if (move == 1 && box[1] == '1')
		box[1] = place;

	     else if (move ==2 && box[2] == '2')
		box[2] = place;

	     else if (move ==3 && box[3] == '3')
		box[3] = place;

	     else if (move ==4 && box[4] == '4')
		box[4] = place;

	     else if (move ==5 && box[5] == '5')
		box[5] = place;

	     else if (move ==6 && box[6] == '6')
		box[6] = place;

	     else if (move ==7 && box[7] == '7')
		box[7] = place;

	     else if (move ==8 && box[8] == '8')
		box[8] = place;

	     else if (move ==9 && box[9] == '9')
		box[9] = place;

	     else
	     {
		p("INVALID ");

		player--;
		getch();
	     }
	     i = win();
         player++;
    } while (i == -1);

    board(box); // Pass the box array to board function

    if (i == 1)
        printf("\n   --> PLAYER %d WINS! CONGRATULATIONS :> <-- ", --player);
    else
        printf("\n  --> GAME DRAW TRY AGAIN :< <-- ");

    getch();
}

void board(char box[]) {
    int x, y;

    // Board
    for (x = 37; x <= 79; x++) {
        g(50, 2);
        p("-TICTACTOE BOARD-");
        g(x, 9);
        p("%c", 205);
        g(x, 16);
        p("%c", 205);
    }

    for (y = 1; y < 20; y++) {
        g(50, y + 3);
        p("%c", 186);
        g(65, y + 3);
        p("%c", 186);
    }

    g(65, 9);
    p("%c", 206);
    g(50, 9);
    p("%c", 206);
    g(50, 16);
    p("%c", 206);
    g(65, 16);
    p("%c", 206);
    g(43, 6);
    p("1");
    g(58, 6);
    p("2");
    g(73, 6);
    p("3");
    g(43, 12);
    p("4");
    g(58, 12);
    p("5");
    g(73, 12);
    p("6");
    g(43, 19);
    p("7");
    g(58, 19);
    p("8");
    g(73, 19);
    p("9");

    // Assigning numbers for each box
    g(43, 6);
    p("%c", box[1]);
    g(58, 6);
    p("%c", box[2]);
    g(73, 6);
    p("%c", box[3]);
    g(43, 12);
    p("%c", box[4]);
    g(58, 12);
    p("%c", box[5]);
    g(73, 12);
    p("%c", box[6]);
    g(43, 19);
    p("%c", box[7]);
    g(58, 19);
    p("%c", box[8]);
    g(73, 19);
    p("%c", box[9]);
}
int win() {
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
    else if (box[1] != '1' && box[2] != '2' && box[3] != '3' 
          && box[4] != '4' && box[5] != '5' && box[6] != '6' 
          && box[7] != '7' && box[8] != '8' && box[9] != '9')
        return 0;
    else
        return -1;
}

void BinaryTree()
{
    int level,x;
    char node[1],node2[1],node3[1],node4[1],node5[1],node6[1],node7[1],node8[1],node9[1],node10[1],node11[1],node12[1],node13[1],node14[1],node15[1],node16[1],node17[1],node18[1],node19[1],node20[1],node21[1],node22[1],node23[1],node24[1],node25[1],node26[1],node27[1],node28[1],node29[1],node30[1],node31[1];
    clrscr();
    g(3,3);p("ENTER YOUR TREE LEVEL(MAX IS 5): ");
    g(37,3);s("%d",&level);

    clrscr();
    if (level == 1)
    {
	g(20,1);p("[PLEASE ENTER A VARIABLE IN THE BINARY TREE]");
	g(40,3);s("%s",node);

    g(3,5);p("LTR: %s", node);
    g(3,6);p("LRT: %s", node);
    g(3,7);p("TLR: %s", node);
    }
    else if (level == 2)
    {
	g(20,1);p("[PLEASE ENTER A VARIABLE IN THE BINARY TREE]");
	g(40,3);s("%s",node);
	g(32,5);s("%s",node2);
	g(48,5);s("%s",node17);

    g(3,7);p("LTR: %s,%s,%s", node2,node,node17);
    g(3,8);p("LRT: %s,%s,%s", node2,node17,node);
    g(3,9);p("TLR: %s,%s,%s", node,node2,node17);
    }
    else if (level == 3)
    {
    g(20,1);p("[PLEASE ENTER A VARIABLE IN THE BINARY TREE]");
    g(40,3);s("%s",node);
    g(32,5);s("%s",node2);
    g(28,7);s("%s",node3);
    g(36,7);s("%s",node10);
    g(48,5);s("%s",node17);
    g(44,7);s("%s",node18);
    g(52,7);s("%s",node25);

    g(3,9);p("LTR: %s,%s,%s,%s,%s,%s,%s", node3,node2,node10,node,node18,node17,node25);
    g(3,10);p("LRT: %s,%s,%s,%s,%s,%s,%s", node3,node10,node2,node18,node25,node17,node);
    g(3,11);p("TLR: %s,%s,%s,%s,%s,%s,%s", node,node2,node3,node10,node17,node18,node25);
    }
    else if (level == 4)
    {
    g(20,1);p("[PLEASE ENTER A VARIABLE IN THE BINARY TREE]");
    g(40,3);s("%s",node);
    g(32,5);s("%s",node2);
    g(28,7);s("%s",node3);
    g(26,9);s("%s",node4);
    g(30,9);s("%s",node7);
    g(36,7);s("%s",node10);
    g(34,9);s("%s",node11);
    g(38,9);s("%s",node14);
    g(48,5);s("%s",node17);
    g(44,7);s("%s",node18);
    g(42,9);s("%s",node19);
    g(46,9);s("%s",node22);
    g(52,7);s("%s",node25);
    g(50,9);s("%s",node26);
    g(54,9);s("%s",node29);

    g(3,11);p("LTR: %s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s", node4,node3,node7,node2,node11,node10,node14,node,node19,node18,node22,node17,node26,node25,node29);
    g(3,12);p("LRT: %s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s", node4,node7,node3,node11,node14,node10,node2,node19,node22,node18,node26,node29,node25,node17,node);
    g(3,13);p("TLR: %s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s", node,node2,node3,node4,node7,node10,node11,node14,node17,node18,node19,node22,node25,node26,node29);
    }
    else if (level == 5)
    {
	g(20,1);p("[PLEASE ENTER A VARIABLE IN THE BINARY TREE]");
	g(40,3);s("%s",node);
	g(32,5);s("%s",node2);
    g(28,7);s("%s",node3);
    g(26,9);s("%s",node4);
    g(25,11);s("%s",node5);
    g(27,11);s("%s",node6);
    g(30,9);s("%s",node7);
    g(29,11);s("%s",node8);
    g(31,11);s("%s",node9);
    g(36,7);s("%s",node10);
    g(34,9);s("%s",node11);
    g(33,11);s("%s",node12);
    g(35,11);s("%s",node13);
    g(38,9);s("%s",node14);
    g(37,11);s("%s",node15);
    g(39,11);s("%s",node16);
	g(48,5);s("%s",node17);
    g(44,7);s("%s",node18);
    g(42,9);s("%s",node19);
    g(41,11);s("%s",node20);
    g(43,11);s("%s",node21);
    g(46,9);s("%s",node22);
    g(45,11);s("%s",node23);
    g(47,11);s("%s",node24);
    g(52,7);s("%s",node25);
    g(50,9);s("%s",node26);
    g(49,11);s("%s",node27);
    g(51,11);s("%s",node28);
    g(54,9);s("%s",node29);
    g(53,11);s("%s",node30);
    g(55,11);s("%s",node31);


    g(3,15);p("LTR: %s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s", node5,node4,node6,node3,node8,node7,node9,node2,node12,node11,node13,node10,node15,node14,node16,node,node20,node19,node21,node18,node23,node22,node24,node17,node27,node26,node28,node25,node30,node29,node31);
    g(3,16);p("LRT: %s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s", node5,node6,node4,node8,node9,node7,node3,node12,node13,node11,node15,node16,node14,node10,node2,node20,node21,node19,node23,node24,node22,node18,node27,node28,node26,node30,node31,node29,node25,node17,node);
    g(3,17);p("TLR: %s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s", node,node2,node3,node4,node5,node6,node7,node8,node9,node10,node11,node12,node13,node14,node15,node16,node17,node18,node19,node20,node21,node22,node23,node24,node25,node26,node27,node28,node29,node30,node31);
    }
    else
    {
    clrscr();
	g(3,3);p("YOUR INPUT IS TOO MUCH FOR THE PROGRAM TO HANDLE. DO YOU WISH TO TRY AGAIN? Y/N: ");
    }

getch();
}

                                                                                         