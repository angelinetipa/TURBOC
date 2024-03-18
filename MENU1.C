#include <stdio.h>
#include <stdlib.h>
#include <conio.h>  // Header file for console I/O functions
#define p printf  // Define printf as p for shorthand
#define s scanf  // Define scanf as s for shorthand
#define g gotoxy  // Define gotoxy as g for shorthand#include <conio.h>

void code1() {
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

    getch();  // Wait for a key press before exiting    printf("This is Code 1\n");

}

void code2() {
    char name[15], studno[15];  // Declare character arrays for name and student number

    clrscr();  // Clear the console screen

    gotoxy(5, 2); printf("Enter your name: ");
    gotoxy(5, 3); printf("Enter your student no: ");

    gotoxy(21, 2); scanf("%s", &name);  // Input for name
    gotoxy(28, 3); scanf("%s", &studno);  // Input for student number

    gotoxy(40, 12); printf("%s", name);  // Display name
    gotoxy(40, 13); printf("%s", studno);  // Display student number

    getch();  // Wait for a key press before exiting
}

int x, qty;
char items[15];
float uprice, amount, totalamount = 0;
void code3() {
    clrscr();  // Clear the console screen

    g(35, 2); p("PUP STORE");
    g(31, 3); p("BILLING STATEMENT");
    g(5, 5); p("QTY");
    g(15, 5); p("ITEM NAME");
    g(40, 5); p("UNIT PRICE");
    g(60, 5); p("AMOUNT");
    g(35, 12); p("TOTAL AMOUNT");

    for (x = 1; x <= 5; x += 7)
    {
	g(5, x + 5); s("%d", &qty);  // Input quantity
	g(15, x + 5); s("%s", &items);  // Input item name
	g(40, x + 5); s("%f", &uprice);  // Input unit price
	amount = qty * uprice;  // Calculate the amount for the current item
	g(60, x + 5); p("%.2f", amount);  // Display the amount
	totalamount = totalamount + amount;  // Update total amount
	g(60, 12); p("%.2f", totalamount);  // Display total amount
    }

    getch();  // Wait for a key press before exiting
}

int x;
void code4() {
    clrscr();  // Clear the console screen

    g(19, 7); p("N");
    g(36, 7); p("SQUARE");
    g(56, 7); p("CUBE");

    // Loop to display numbers, squares, and cubes
    for (x = 0; x <= 10; x++)
    {
	g(19, x + 9); p("%d", x);           // Display the number
	g(38, x + 9); p("%d", x * x);       // Display the square
	g(57, x + 9); p("%d", x * x * x);   // Display the cube
    }

    getch();  // Wait for a key press before exiting
}

int x, y;
void code5() {
    clrscr();  // Clear the console screen

    // 1st loop
    for (x = 1; x < 80; x++){
	g(x, 3); delay(25); p("%c", 219);  // Draw top border
    }

    for (y = 3; y < 24; y++){
	g(80, y); delay(25); p("%c", 219);  // Draw right border
    }

    for (x = 79; x > 1; x--){
	g(x, 23); delay(25); p("%c", 219);  // Draw bottom border
    }

    for (y = 23; y > 6; y--){
	g(1, y); delay(25); p("%c", 219);  // Draw left border
    }

    // 2nd loop
    for (x = 1; x < 75; x++){
	g(x, 6); delay(25); p("%c", 219);
    }

    for (y = 6; y < 21; y++){
	g(75, y); delay(25); p("%c", 219);
    }

    for (x = 75; x > 6; x--){
	g(x, 20); delay(25); p("%c", 219);
    }

    for (y = 20; y > 8; y--){
	g(6, y); delay(25); p("%c", 219);
    }

    // 3rd loop
    for (x = 6; x < 70; x++){
	g(x, 9); delay(25); p("%c", 219);
    }

    for (y = 9; y < 18; y++){
	g(70, y); delay(25); p("%c", 219);
    }

    for (x = 70; x > 10; x--){
	g(x, 17); delay(25); p("%c", 219);
    }

    for (y = 17; y > 11; y--){
	g(11, y); delay(25); p("%c", 219);
    }

    // 4th loop
    for (x = 11; x < 65; x++){
	g(x, 12); delay(25); p("%c", 219);
    }

    for (y = 12; y < 15; y++){
	g(65, y); delay(25); p("%c", 219);
    }

    for (x = 65; x > 15; x--){
	g(x, 15); delay(25); p("%c", 219);
    }
    getch();  // Wait for a key press before exiting
}

int x, y, cpe, ce, ece, ee, me, ie, rem, cped, ced, eced, eed, med, ied, remd;
void code6() {
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

char box[10]={'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int win();
void board();
void code7() {
int player = 1, i, move;

	char place;
	do
	{
	     board();
	     player = (player % 2)? 1:2;

	     g(8,16); p("ENTER A NUMBER 1-9 \n       PLAYER %d: ", player);
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
	}while (i == -1);

	board();

	if ( i == 1)
	   p("\n PLAYER %d WINS!", --player);
	else
	   p("\n   GAME DRAW");

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
int x,y,num;
clrscr();

//instruction
{
g(8,10); p("PLAYER 1: X\n       PLAYER 2: O");
//g(40,23); textcolor(WHITE + BLINK); p("PRESS ENTER TO START.");
//getch();
}


//board
{
     {
	g(32,5); p("<===============TICTACTOE===============>");
	}

	for(x=15; x<=43; x++)
	{
	g(x+23,12); p("%c", 205);
	g(x+23,16); p("%c", 205);
	}

	for(y=1; y<=13; y++)
	{
	g(47,y+7); p("%c",186);
	g(57,y+7); p("%c", 186);
	}
     }
//assigned numbers
	g(42,10); p("1");
	g(52,10); p("2");
	g(62,10); p("3");
	g(42,14); p("4");
	g(52,14); p("5");
	g(62,14); p("6");
	g(42,18); p("7");
	g(52,18); p("8");
	g(62,18); p("9");

	//assigning numbers for each box
	{
	      g(42,10); p("%c", box[1]);
	      g(52,10); p("%c", box[2]);
	      g(62,10); p("%c", box[3]);
	      g(42,14); p("%c", box[4]);
	      g(52,14); p("%c", box[5]);
	      g(62,14); p("%c", box[6]);
	      g(42,18); p("%c", box[7]);
	      g(52,18); p("%c", box[8]);
	      g(62,18); p("%c", box[9]);

}}

int stack[10], tempStack[10], choice, n, top, x, i;
// Function prototypes
void push();
void pop();
void code8() {
    clrscr();
    top = -1;

    // Input the maximum number of cars the parking garage can accommodate
    p("\n\tHow many cars? (max=10): ");
    s("%d", &n);

    do {
	clrscr();  // Clear the screen before each iteration

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
	g(3, 11);
	p("\n\tDeparture Successful! Car %d has left the parking garage.", unparkCar);
    }
}

int level,x;
void code9() {
    char node[1],node2[1],node3[1],node4[1],node5[1],node6[1],node7[1],node8[1],node9[1],node10[1],node11[1],node12[1],node13[1],node14[1],node15[1],node16[1],node17[1],node18[1],node19[1],node20[1],node21[1],node22[1],node23[1],node24[1],node25[1],node26[1],node27[1],node28[1],node29[1];
    clrscr();  // Clear the console screen
    g(3,3);p("LEVEL FOR BINARY TREE(MAX IS 4): ");
    g(37,3);s("%d",&level);

    clrscr();
    if (level == 1)
    {
	g(35,1);p("BINARY TREE");
	g(40,3);s("%s",node); //LEVEL0

    g(3,5);p("LTR INORDER: %s", node);
    g(3,6);p("TLR PREORDER: %s", node);
    g(3,7);p("LRT POSTORDER: %s", node);
    }
    else if (level == 2)
    {
	g(35,1);p("BINARY TREE");
	g(40,3);s("%s",node); //LEVEL 0
	g(32,5);s("%s",node2); //LEVEL 1 LEFT
	g(48,5);s("%s",node17); //LEVEL 1 RIGHT

    g(3,7);p("LTR INORDER: %s,%s,%s", node2,node,node17);
    g(3,8);p("TLR PREORDER: %s,%s,%s", node,node2,node17);
    g(3,9);p("LRT POSTORDER: %s,%s,%s", node2,node17,node);
    }
    else if (level == 3)
    {
	g(35,1);p("BINARY TREE");
	g(40,3);s("%s",node); //LEVEL 0
	g(32,5);s("%s",node2); //LEVEL 1 LEFT
	g(28,7);s("%s",node3); //LEVEL 1 RIGHT
	g(36,7);s("%s",node10); //LEVEL 2.1 LEFT
	g(48,5);s("%s",node17); //LEVEL 2.1 RIGHT
	g(44,7);s("%s",node18); //LEVEL 2.2 LEFT
	g(52,7);s("%s",node25); //LEVEL 2.2 RIGHT

    //TRAVERSALS
    g(3,9);p("LTR INORDER: %s,%s,%s,%s,%s,%s,%s", node3,node2,node10,node,node18,node17,node25);
    g(3,10);p("TLR PREORDER: %s,%s,%s,%s,%s,%s,%s", node,node2,node3,node10,node17,node18,node25);
    g(3,11);p("LRT POSTORDER: %s,%s,%s,%s,%s,%s,%s", node3,node10,node2,node18,node25,node17,node );
    }
    else if (level == 4)
    {
	g(35,1);p("BINARY TREE");
	g(40,3);s("%s",node); //LEVEL 0
	g(32,5);s("%s",node2); //LEVEL 1 LEFT
	g(28,7);s("%s",node3); //LEVEL 2.1 LEFT
	g(26,9);s("%s",node4); //LEVEL 3.1 LEFT
	g(30,9);s("%s",node7); //LEVEL 3.1 RIGHT
	g(36,7);s("%s",node10); //LEVEL 2.1 RIGHT
	g(34,9);s("%s",node11); //LEVEL 3.2 LEFT
	g(38,9);s("%s",node14); //LEVEL 3.2 RIGHT

	g(48,5);s("%s",node17); //LEVEL 1 RIGHT
	g(44,7);s("%s",node18); //LEVEL 2.2 LEFT
	g(42,9);s("%s",node19); //LEVEL 3.3 LEFT
	g(46,9);s("%s",node22); //LEVEL 3.3 RIGHT
	g(52,7);s("%s",node25); //LEVEL 2.2 RIGHT
	g(50,9);s("%s",node26); //LEVEL 3.4 LEFT
	g(54,9);s("%s",node29); //LEVEL 3.4 RIGHT

    //TRAVERSALS
    g(3,11);p("LTR INORDER: %s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s", node4,node3,node7,node2,node11,node10,node14,node,node19,node18,node22,node17,node26,node25,node29);
    g(3,12);p("TLR PREORDER: %s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s", node,node2,node3,node4,node7,node10,node11,node14,node17,node18,node19,node22,node25,node26,node29);
    g(3,13);p("LRT POSTORDER: %s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s", node4,node7,node3,node11,node14,node10,node2,node19,node22,node18,node26,node29,node25,node17,node );
    }
getch();

}
int main() {
    int choice;

    do {
	clrscr();

	printf("=== Menu ===\n");
	printf("1. Code 1 (loading)\n");
	printf("2. Code 2 (show student name&no.)\n");
	printf("3. Code 3 (pup store)\n");
	printf("4. Code 4 (square&cube numbers)\n");
	printf("5. Code 5 (maze)\n");
	printf("6. Code 6 (total students)\n");
	printf("7. Code 7 (tictactoe)\n");
	printf("8. Code 8 (parking garage)\n");
	printf("9. Code 9 (binary tree)\n");
	printf("10. Exit\n");

	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch (choice) {
	    case 1:
		code1();
		break;
	    case 2:
		code2();
		break;
	    case 3:
		code3();
		break;
	    case 4:
		code4();
		break;
	    case 5:
		code5();
		break;
	    case 6:
		code6();
		break;
	    case 7:
		code7();
		break;
	    case 8:
		code8();
		break;
	    case 9:
		code9();
		break;
	    case 10:
		printf("Exiting the program. Goodbye!\n");
		break;
	    default:
		printf("Invalid choice. Please try again.\n");
	}

       g(60,1); p("\nPress any key to continue...");
       getch();

    } while (choice != 10);

    return 0;
}
