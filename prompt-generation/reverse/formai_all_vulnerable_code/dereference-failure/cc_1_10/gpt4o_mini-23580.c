//GPT-4o-mini DATASET v1.0 Category: Pixel Art Generator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 20
#define HEIGHT 20

void clearScreen() {
    // Clear the terminal screen using ANSI escape sequence
    printf("\033[H\033[J");
}

void drawPixelArt(char art[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Draw the pixel art character with a space
            printf("%c ", art[y][x]);
        }
        printf("\n");
    }
}

void createDiamond(char art[HEIGHT][WIDTH]) {
    // Initialize with spaces
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            art[y][x] = ' ';
        }
    }

    // Draw the diamond shape
    for (int i = 0; i < 5; i++) {
        art[2 - i][WIDTH / 2] = '*'; // Top half
        art[2 + i][WIDTH / 2] = '*'; // Bottom half
        art[2 - i][WIDTH / 2 - i] = '*'; // Left side
        art[2 - i][WIDTH / 2 + i] = '*'; // Right side
        art[2 + i][WIDTH / 2 - i] = '*'; // Left side
        art[2 + i][WIDTH / 2 + i] = '*'; // Right side
    }
}

void displayInstructions() {
    printf("Welcome to the Pixel Art Generator!\n");
    printf("This program generates a simple pixel art representation of a diamond shape.\n");
    printf("Press Enter to see the diamond...\n");
}

int main() {
    clearScreen();
    
    displayInstructions();
    getchar(); // Wait for the user to press Enter

    char pixelArt[HEIGHT][WIDTH];
    createDiamond(pixelArt);

    clearScreen();
    printf("Here is your diamond pixel art:\n");
    drawPixelArt(pixelArt);
    
    return 0;
}