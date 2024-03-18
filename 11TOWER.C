#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void drawDisk(int rod, int diskSize, int y) {
    // Function to draw a disk on the specified rod
    int x = rod * 200 + 120 ; // Adjust the positions based on your window size
    setfillstyle(SOLID_FILL, rod * 100 + 150); // Change color based on rod
    bar(x - diskSize * 13, y + 3, x + diskSize * 13, y + 20);
}

void clearDisk(int rod, int diskSize, int y) {
    // Function to clear a disk from the specified rod
    int x = rod * 200 + 120 ; // Adjust the positions based on your window size
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

int main() {
    int n, i;
    int gd = DETECT, gm;
    int baseY = 200; // Set the base Y coordinate for the bottom of the rods

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI"); // Change the path based on your setup

    // Display title
    setcolor(YELLOW);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);
    outtextxy(100, 50, "TOWER OF HANOI");

    gotoxy(9,9);
    printf("\033[0m(\033[0;31mNOTE: \033[0mYou need to complete the simulation, to exit the program.)");
    gotoxy(22,8);
    printf("Enter the number of disks \033[0;31m(Max:10)\033[0m: ");
    scanf("%d", &n);

    // Display initial tower state
    displayInitialTower(n, baseY);
    delay(500);

    // Run Tower of Hanoi algorithm
    towerOfHanoi(n, 0, 2, 1, baseY);

    getch();
    closegraph(); // Close the graphics window
}
