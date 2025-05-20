//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

void printChar(char c, int size) {
    int i;
    for (i = 0; i < size; i++) {
        putchar(c);
    }
}

void printRow(char* row, int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (row[i] == '1') {
            printChar('#', 3);
        } else {
            printChar(' ', 3);
        }
    }
    putchar('\n');
}

void printText(char* text, int size) {
    // Determine number of rows needed
    int numRows = 5;
    int i;
    for (i = 0; i < size; i++) {
        if (text[i] == '\n') {
            numRows += 5;
        }
    }

    // Allocate memory for rows
    char** rows = (char**) malloc(numRows * sizeof(char*));
    for (i = 0; i < numRows; i++) {
        rows[i] = (char*) malloc(size * 5 * sizeof(char));
    }

    // Generate rows for each letter
    int currRow = 0;
    for (i = 0; i < size; i++) {
        char c = text[i];
        if (c == '\n') {
            currRow += 5;
            continue;
        }

        int j;
        for (j = 0; j < 5; j++) {
            char* row = rows[currRow + j] + i * 5;
            switch (c) {
                case 'a':
                    switch (j) {
                        case 0:
                            row[1] = row[2] = row[3] = '1';
                            break;
                        case 1:
                            row[0] = row[4] = row[1] = row[3] = '1';
                            break;
                        case 2:
                            row[0] = row[2] = row[4] = row[1] = row[3] = '1';
                            break;
                        case 3:
                            row[0] = row[4] = row[1] = row[2] = row[3] = '1';
                            break;
                        case 4:
                            row[0] = row[4] = row[2] = row[3] = '1';
                            break;
                    }
                    break;
                case 'b':
                    switch (j) {
                        case 0:
                            row[0] = row[1] = row[2] = row[3] = '1';
                            break;
                        case 1:
                            row[0] = row[4] = row[1] = row[3] = '1';
                            break;
                        case 2:
                            row[0] = row[4] = row[1] = row[2] = row[3] = '1';
                            break;
                        case 3:
                            row[0] = row[4] = row[1] = row[3] = '1';
                            break;
                        case 4:
                            row[0] = row[4] = row[1] = row[2] = row[3] = '1';
                            break;
                    }
                    break;
                // ... (add more letters here)
            }
        }
    }

    // Print out the ASCII art
    for (i = 0; i < numRows; i++) {
        printRow(rows[i], size * 5);
    }

    // Free memory
    for (i = 0; i < numRows; i++) {
        free(rows[i]);
    }
    free(rows);
}

int main() {
    char text[] = "Hello, World!\n";
    printText(text, sizeof(text)/sizeof(char) - 1);

    return 0;
}