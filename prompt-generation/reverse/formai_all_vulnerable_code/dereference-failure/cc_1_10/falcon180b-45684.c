//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24

// Structure for a character
typedef struct {
    char ch;
    int color;
} Character;

// Function to print a character with color
void print_char(Character ch) {
    printf("\x1B[38;5;%dm%c\x1B[0m", ch.color, ch.ch);
}

// Function to print a row of characters
void print_row(Character* row, int count) {
    for (int i = 0; i < count; i++) {
        print_char(row[i]);
    }
    printf("\n");
}

// Function to print the ASCII art
void print_art(Character* art, int height, int width) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            print_char(art[y * width + x]);
        }
    }
}

// Function to generate the ASCII art from a string
void generate_art(char* input, Character* art) {
    int x = 0, y = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (isspace(input[i])) {
            x = 0;
            y++;
        } else {
            art[y * MAX_WIDTH + x++] = (Character){input[i], 7};
        }
        if (x >= MAX_WIDTH) {
            x = 0;
            y++;
        }
    }
}

int main() {
    char input[1000];
    printf("Enter a string to convert to ASCII art: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character

    Character art[MAX_HEIGHT * MAX_WIDTH];
    generate_art(input, art);

    print_art(art, MAX_HEIGHT, MAX_WIDTH);

    return 0;
}