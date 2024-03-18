#include <stdio.h>
#include <conio.h>
#include <stdlib.h> // Include the stdlib.h header for the exit() function

int main() {
    int i, n;
    // initialize first and second terms
    long long int t1 = 0, t2 = 1;
    // initialize the next term (3rd term)
    long long int nextTerm = t1 + t2;

    clrscr(); // Clear the screen
    // get no. of terms from user
    printf("Enter the number of terms (Max: 47): ");
    // Use a loop to keep prompting until valid input is received
    while (scanf("%d", &n) != 1 || n < 0 || n > 47) {
        printf("Invalid input. Please enter a number between 0 and 47: ");
        // Clear the input buffer
        while (getchar() != '\n');
    }

    // print the first term
    printf("Fibonacci Series: ");

    if (n >= 1) {
        printf("%lld", t1);

        if (n > 1) {
            printf(", %lld", t2);

            // print 3rd to nth terms
            for (i = 3; i <= n; ++i) {
                printf(", %lld", nextTerm);
                t1 = t2;
                t2 = nextTerm;
                nextTerm = t1 + t2;
            }
        }
    }
    getch(); // Wait for a key press
    return 0;
}
