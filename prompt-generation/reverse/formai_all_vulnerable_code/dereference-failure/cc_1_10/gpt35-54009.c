//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: shape shifting
#include <stdio.h>
#include <string.h>

#define MAX_CHARS 1000
#define MAX_ROWS 10

void printHorizontal(char symbol, int width) {
    for (int i = 0; i < width; i++) {
        printf("%c", symbol);
    }
    printf("\n");
}

void printVertical(char symbol, int height) {
    for (int i = 0; i < height; i++) {
        printf("%c\n", symbol);
    }
}

void printText(char text[], char ascii[][MAX_CHARS], int numChars, int numRows) {
    for (int row = 0; row < numRows; row++) {
        for (int i = 0; i < numChars; i++) {
            char ch = text[i];
            if (ch >= 'A' && ch <= 'Z') {
                ch = ch - 'A' + 'a';
            }
            int index = ch - ' ';
            if (index < 0 || index >= MAX_CHARS) {
                continue;
            }
            printf("%s", ascii[row] + index * MAX_ROWS);
        }
        printf("\n");
    }
}

int main() {
    char text[] = "ASCII ART";
    char ascii[MAX_ROWS][MAX_CHARS * 95] = {""};

    // Generate horizontal symbols
    for (char ch = ' '; ch <= '~'; ch++) {
        for (int width = 1; width <= 5; width++) {
            char line[MAX_CHARS] = "";
            for (int i = 0; i < width; i++) {
                strcat(line, &ch);
            }
            strcat(ascii[ch - ' '], line);
        }
    }

    // Generate vertical symbols
    for (char ch = ' '; ch <= '~'; ch++) {
        char line[MAX_CHARS] = "";
        for (int i = 0; i < 5; i++) {
            strcat(line, &ch);
            strcat(line, "\n");
        }
        strcat(ascii[ch - ' '], line);
    }

    // Print ASCII art
    printHorizontal('-', strlen(text) * 6 + 1);
    printText(text, ascii, strlen(text), 5);
    printHorizontal('-', strlen(text) * 6 + 1);

    return 0;
}