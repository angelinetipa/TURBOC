#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
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
    
    clrscr();  // Clear the console screen

    do
    {
        board();
	player = (player % 2) ? 1 : 2;

	g(5, 15);
	p("PLAYER %d, enter a no.:   ", player);
	s("%d", &move);

	place = (player == 1) ? 'X' : 'O';

	if (move >= 1 && move <= 9 && box[move] == '0' + move)
	    box[move] = place;
	else
	{
	    p("     INVALID MOVE! TRY AGAIN.");
	    player--;
	    getch();
	}

	player++;
    } while (win() == -1);

    board();

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

    clrscr();

    // Instructions and title
    {
	g(5, 8);
	p("PLAYER 1: X\n    PLAYER 2: O\n");
	g(5, 11);
	p("HOW TO PLAY: \n    Enter a number (1-9) to place \n    your symbol on the board.\n");
    }

    // Board
    {
	g(32, 5);
	p("<=============== TIC-TAC-TOE ===============>\n");
    }

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

    g(5, 21);
    p("Press ENTER after each move!");

    // Assigned numbers
    g(44, 10);
    p("1");
    g(54, 10);
    p("2");
    g(64, 10);
    p("3");
    g(44, 14);
    p("4");
    g(54, 14);
    p("5");
    g(64, 14);
    p("6");
    g(44, 18);
    p("7");
    g(54, 18);
    p("8");
    g(64, 18);
    p("9");

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
