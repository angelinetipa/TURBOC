#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define p printf
#define s scanf
#define g gotoxy


void main()
{
    int level,x;
    char node[1],node2[1],node3[1],node4[1],node5[1],node6[1],node7[1],node8[1],node9[1],node10[1],node11[1],node12[1],node13[1],node14[1],node15[1],node16[1],node17[1],node18[1],node19[1],node20[1],node21[1],node22[1],node23[1],node24[1],node25[1],node26[1],node27[1],node28[1],node29[1],node30[1],node31[1];
    clrscr();
    g(3,3);p("LEVEL FOR BINARY TREE(MAX IS 4): ");
    g(37,3);s("%d",&level);

    clrscr();
    if (level == 1)
    {
	g(20,1);p("BINARY TREE");
	g(40,3);s("%s",node);

    g(3,5);p("LTR: %s", node);
    g(3,6);p("LRT: %s", node);
    g(3,7);p("TLR: %s", node);
    }
    else if (level == 2)
    {
	g(20,1);p("BINARY TREE");
	g(40,3);s("%s",node);
	g(32,5);s("%s",node2);
	g(48,5);s("%s",node17);

    g(3,7);p("LTR: %s,%s,%s", node2,node,node17);
    g(3,8);p("LRT: %s,%s,%s", node2,node17,node);
    g(3,9);p("TLR: %s,%s,%s", node,node2,node17);
    }
    else if (level == 3)
    {
	g(20,1);p("BINARY TREE");
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
	g(20,1);p("BINARY TREE");
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
    else
    {
    clrscr();
	g(3,3);p("YOUR INPUT IS TOO MUCH FOR THE PROGRAM TO HANDLE. DO YOU WISH TO TRY AGAIN? Y/N: ");
    }

getch();
}
