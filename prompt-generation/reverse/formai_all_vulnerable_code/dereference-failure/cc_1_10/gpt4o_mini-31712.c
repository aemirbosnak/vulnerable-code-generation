//GPT-4o-mini DATASET v1.0 Category: Text to ASCII art generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a single character to ASCII art
void printChar(char c) {
    char *asciiArt[][8] = {
        {' ',' ',' ','#',' ',' ',' ',' '},  // space
        {' ',' ','#','#',' ',' ',' ',' '},  // '@'
        {' ',' ','#','#','#','#',' ',' '},  // 'A'
        {'#','#','#','#','#','#',' ',' '},  // 'B'
        {'#','#',' ','#','#','#',' ',' '},  // 'C'
        {'#','#','#','#','#','#','#'},      // 'D'
        {'#','#',' ','#','#',' ','#'},      // 'E'
        {'#','#','#','#',' ',' ',' '},      // 'F'
        {' ','#','#','#','#',' ','#'},      // 'G'
        {'#','#',' ','#','#','#','#'},      // 'H'
        {'#',' ','#',' ','#','#','#'},      // 'I'
        {' ',' ','#',' ','#','#','#'},      // 'J'
        {'#','#',' ','#','#',' ',' '},      // 'K'
        {'#','#',' ','#','#',' ',' ','#'},  // 'L'
        {'#',' ','#','#',' ','#','#'},      // 'M'
        {'#','#',' ','#',' ',' ','#'},      // 'N'
        {'#','#','#','#','#','#','#'},      // 'O'
        {'#','#','#','#','#',' ','#'},      // 'P'
        {'#','#',' ','#','#',' ','#'},      // 'Q'
        {'#','#','#','#','#','#','#'},      // 'R'
        {' ','#','#','#','#',' ','#'},      // 'S'
        {'#','#',' ','#','#',' ','#'},      // 'T'
        {'#','#',' ','#','#','#','#'},      // 'U'
        {'#','#',' ','#',' ','#',' ',' '},  // 'V'
        {'#',' ','#','#',' ','#',' ','#'},  // 'W'
        {'#','#',' ','#','#',' ','#'},      // 'X'
        {'#',' ','#','#',' ',' ','#'},      // 'Y'
        {'#','#',' ','#','#','#',' '},      // 'Z'
        // Rest just spaces for simplicity 
    };

    if (c >= 'A' && c <= 'Z') {
        int index = c - 'A';
        for (int i = 0; i < 8; i++) {
            printf("%s", asciiArt[index][i]);
        }
        printf("\n");
    } else if (c == ' ') {
        for (int i = 0; i < 8; i++) {
            printf("        \n");
        }
    } else {
        printf("Character not supported for ASCII art.\n");
    }
}

// Function to convert a string to ASCII art
void printStringAsASCIIArt(const char *str) {
    while (*str) {
        printChar(*str++);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("Generating ASCII Art for: \"%s\"\n", argv[1]);
    printStringAsASCIIArt(argv[1]);

    return 0;
}