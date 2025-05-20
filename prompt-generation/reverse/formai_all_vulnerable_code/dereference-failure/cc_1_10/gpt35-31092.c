//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 80

// This function prints the ASCII art to the console
void printASCIIArt(char ascii_art[MAX_HEIGHT][MAX_WIDTH], int width, int height) {
    int i, j;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%c", ascii_art[i][j]);
        }
        printf("\n");
    }
}

// This function converts characters to ASCII art characters
char getASCIIChar(char c) {
    switch(c) {
        case 'A':
        case 'a':
            return '@';
        case 'B':
        case 'b':
            return '8';
        case 'C':
        case 'c':
            return '(';
        case 'D':
        case 'd':
            return '|)';
        case 'E':
        case 'e':
            return '3';
        case 'F':
        case 'f':
            return '#';
        case 'G':
        case 'g':
            return '6';
        case 'H':
        case 'h':
            return '|-|';
        case 'I':
        case 'i':
            return '!';
        // Uncomment more cases to add more characters
        /*
        case 'J':
        case 'j':
            return '_|';
        case 'K':
        case 'k':
            return '|<';
        case 'L':
        case 'l':
            return '|_';
        case 'M':
        case 'm':
            return '/\\/\\';
        case 'N':
        case 'n':
            return '|\\|';
        case 'O':
        case 'o':
            return '0';
        case 'P':
        case 'p':
            return '|D';
        case 'Q':
        case 'q':
            return '(,)';
        case 'R':
        case 'r':
            return '|2';
        case 'S':
        case 's':
            return '$';
        case 'T':
        case 't':
            return '-';
        case 'U':
        case 'u':
            return '|_|';
        case 'V':
        case 'v':
            return '\\/';
        case 'W':
        case 'w':
            return '\\/\\/';
        case 'X':
        case 'x':
            return '><';
        case 'Y':
        case 'y':
            return '`/';
        case 'Z':
        case 'z':
            return '2';
        */
        default:
            return ' ';
    }
}

int main() {
    char input_string[100];
    char ascii_art[MAX_HEIGHT][MAX_WIDTH];
    int width = 0, height = 0, i, j;

    // Get user input string
    printf("Enter a string to convert to ASCII art:\n");
    fgets(input_string, 100, stdin);

    // Remove trailing newline character from input string
    input_string[strcspn(input_string, "\n")] = 0;

    // Convert input string to ASCII art
    for (i = 0; i < strlen(input_string); i++) {
        char c = input_string[i];
        if (c == ' ') {
            // Add space character
            for (j = 0; j < height; j++) {
                ascii_art[j][width] = ' ';
            }
            width++;
        } else {
            // Add ASCII art character
            char ascii_char = getASCIIChar(c);

            // Split ASCII art character into rows
            char rows[MAX_HEIGHT][5] = {"", "", "", "", "", "", "", "", "", ""};
            int num_rows = 0;
            char* p = strtok(&ascii_char, "\n");
            while (p != NULL) {
                strcpy(rows[num_rows], p);
                num_rows++;
                p = strtok(NULL, "\n");
            }

            // Add rows to ASCII art array
            for (j = 0; j < num_rows; j++) {
                strcpy(&ascii_art[j][width * 5], rows[j]);
            }
            width++;
            height = num_rows;
        }
    }

    // Print the ASCII art to the console
    printASCIIArt(ascii_art, width * 5, height);

    return 0;
}