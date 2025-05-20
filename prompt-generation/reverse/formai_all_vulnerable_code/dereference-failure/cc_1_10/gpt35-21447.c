//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: innovative
#include <stdio.h>
#include <string.h>

char* toAsciiArt(char* message) {
    int rows = 5;
    int length = strlen(message);
    int cols = 9 * length;
    char* output = malloc(rows * cols);

    // assign spaces to all values in output
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            output[(i * cols) + j] = ' ';
        }
    }

    // create ASCII art for each character in message and append to output
    for(int i = 0; i < length; i++) {
        char c = message[i];
        int startCol = i * 9;
        switch(c) {
            case 'A':
                output[(0 * cols) + startCol + 1] = '/';
                output[(0 * cols) + startCol + 2] = '/';
                output[(1 * cols) + startCol + 1] = '/';
                output[(1 * cols) + startCol + 2] = '/';
                output[(1 * cols) + startCol + 3] = '_';
                output[(1 * cols) + startCol + 4] = '_';
                output[(2 * cols) + startCol + 0] = '/';
                output[(2 * cols) + startCol + 1] = ' ';
                output[(2 * cols) + startCol + 2] = ' ';
                output[(2 * cols) + startCol + 3] = ' ';
                output[(2 * cols) + startCol + 4] = '\\';
                output[(3 * cols) + startCol + 0] = '/';
                output[(3 * cols) + startCol + 1] = ' ';
                output[(3 * cols) + startCol + 2] = ' ';
                output[(3 * cols) + startCol + 3] = ' ';
                output[(3 * cols) + startCol + 4] = '\\';
                output[(4 * cols) + startCol + 1] = '/';
                output[(4 * cols) + startCol + 2] = '/';
                output[(4 * cols) + startCol + 3] = ' ';
                output[(4 * cols) + startCol + 4] = ' ';
                break;
            case 'B':
                output[(0 * cols) + startCol + 0] = '_';
                output[(0 * cols) + startCol + 1] = '_';
                output[(1 * cols) + startCol + 0] = '|';
                output[(2 * cols) + startCol + 0] = '|';
                output[(3 * cols) + startCol + 0] = '|';
                output[(4 * cols) + startCol + 0] = '|';
                output[(1 * cols) + startCol + 1] = '_';
                output[(1 * cols) + startCol + 2] = '_';
                output[(2 * cols) + startCol + 1] = '_';
                output[(2 * cols) + startCol + 2] = '_';
                output[(3 * cols) + startCol + 1] = '_';
                output[(3 * cols) + startCol + 2] = '_';
                output[(4 * cols) + startCol + 1] = '_';
                output[(4 * cols) + startCol + 2] = '_';
                break;
            // and so on for other letters
        }
    }
    return output;
}

int main() {
    char* message = "HELLO WORLD";
    char* asciiArt = toAsciiArt(message);
    int rows = 5;
    int length = strlen(message);
    int cols = 9 * length;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%c", asciiArt[(i * cols) + j]);
        }
        printf("\n");
    }
    free(asciiArt);
}