//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WIDTH 30
#define HEIGHT 10

typedef struct {
    char text[WIDTH];
    int x, y;
} position;

void print_ascii_art(position pos, char symbol) {
    int row = pos.y / HEIGHT, col = pos.x / WIDTH;
    int offset = row * WIDTH + col;

    if (row < 0 || row >= HEIGHT || col < 0 || col >= WIDTH) {
        printf("Out of bounds error at (%d, %d)\n", pos.x, pos.y);
        return;
    }

    char ascii[HEIGHT][WIDTH];
    ascii[row][col] = symbol;

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == row && j == col) continue;

            ascii[i][j] = ' ';
            if (j > 0) ascii[i][j-1] = ' ';
            if (i > 0) ascii[i-1][j] = ' ';
            if (i > 0 && j > 0) ascii[i-1][j-1] = ' ';
        }
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", ascii[i][j]);
        }
        printf("\n");
    }
}

void process_text(char *text) {
    position pos = {""};
    int len = strlen(text);

    for (int i = 0; i < len; i++) {
        char c = text[i];

        switch (tolower(c)) {
            case 'a': pos.x++; break;
            case 'e': pos.y++; break;
            case 'i': pos.x -= 2; pos.y++; break;
            case 'o': pos.x -= 3; pos.y += 2; break;
            case 'u': pos.x -= 4; pos.y -= 1; break;
            default: pos.x = 0; pos.y = 0;
        }

        if (pos.x < 0) pos.x = 0;
        if (pos.y < 0) pos.y = 0;

        print_ascii_art(pos, c);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    process_text(argv[1]);

    return 0;
}