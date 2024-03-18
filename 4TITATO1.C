#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>

#define p printf
#define s scanf
#define g gotoxy

char box[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int win();
void board();

int main()
{
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
