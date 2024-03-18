#include <stdio.h>
#include <conio.h>

#define p printf
#define s scanf
#define g gotoxy

int stack[10], tempStack[10], choice, n, top, x, i;

// Function prototypes
void push();
void pop();

int main()
{
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
