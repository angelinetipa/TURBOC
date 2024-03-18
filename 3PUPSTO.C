#include<stdio.h>
#include<conio.h>

#define p printf  // Define printf as p for shorthand
#define s scanf    // Define scanf as s for shorthand
#define g gotoxy   // Define gotoxy as g for shorthand

void main()
{
    int x, qty;
    char items[15];
    float uprice, amount, totalamount = 0;

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
