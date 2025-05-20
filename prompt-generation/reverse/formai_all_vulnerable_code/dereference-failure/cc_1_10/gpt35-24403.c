//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>

void printArt(int charHeight, int charWidth, char asciiArt[charHeight][charWidth]);
// prints the ASCII art

int main(void) {
    int charHeight = 5; // height of the ASCII character
    int charWidth = 5; // width of the ASCII character

    char asciiArt[charHeight][charWidth]; // 2D array of the ASCII art

    // initialize the 2D array of the ASCII art
    asciiArt[0][0] = '/';
    asciiArt[0][1] = '^';
    asciiArt[0][2] = '\\';
    asciiArt[0][3] = '^';
    asciiArt[0][4] = '\\';

    asciiArt[1][0] = '|';
    asciiArt[1][1] = '/';
    asciiArt[1][2] = '\\';
    asciiArt[1][3] = '\\';
    asciiArt[1][4] = '|';

    asciiArt[2][0] = '|';
    asciiArt[2][1] = '|';
    asciiArt[2][2] = '|';
    asciiArt[2][3] = '|';
    asciiArt[2][4] = '|';

    asciiArt[3][0] = '|';
    asciiArt[3][1] = '|';
    asciiArt[3][2] = '|';
    asciiArt[3][3] = '|';
    asciiArt[3][4] = '|';

    asciiArt[4][0] = '|';
    asciiArt[4][1] = '|';
    asciiArt[4][2] = '|';
    asciiArt[4][3] = '|';
    asciiArt[4][4] = '|';

    printArt(charHeight, charWidth, asciiArt);
}

void printArt(int charHeight, int charWidth, char asciiArt[charHeight][charWidth]) {
    // prints the ASCII art
    for (int i = 0; i < charHeight; i++) {
        for (int j = 0; j < charWidth; j++) {
            printf("%c", asciiArt[i][j]);
        }
        printf("\n");
    }
}