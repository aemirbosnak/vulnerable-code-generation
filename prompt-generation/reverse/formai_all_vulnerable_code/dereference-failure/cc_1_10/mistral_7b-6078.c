//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WIDTH 50
#define HEIGHT 5

void generate_ascii(char text[100], char ascii[WIDTH][HEIGHT]) {
    int x, y, i, len, index;
    char c, direction = 'd';

    for (i = 0; text[i]; i++) {
        c = tolower(text[i]);
        if (c >= 'a' && c <= 'z') {
            index = c - 'a';
            x = index % WIDTH;
            y = index / WIDTH;
            if (y >= 0 && y < HEIGHT && x >= 0 && x < WIDTH) {
                ascii[y][x] = c;
            }
        }
    }

    x = 0;
    y = 0;
    putchar('\n');
    for (i = 0; i < HEIGHT; i++) {
        putchar('|');
        for (len = 0; len < WIDTH; len++) {
            if (ascii[i][len] != '\0') {
                putchar(ascii[i][len]);
                x++;
            } else {
                if (x > 0) {
                    putchar(direction == 'd' ? ' ' : '^');
                    putchar(' ');
                    x = 0;
                }
            }
        }
        putchar('|');
        putchar('\n');
        if (i < HEIGHT - 1) {
            putchar('+');
            for (len = 0; len < WIDTH + 2; len++) {
                putchar('-');
            }
            putchar('+\n');
        }
        direction = direction == 'd' ? '^' : 'd';
    }
}

int main(int argc, char *argv[]) {
    char text[100], ascii[WIDTH][HEIGHT];

    if (argc != 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    strncpy(text, argv[1], sizeof(text) - 1);
    text[sizeof(text) - 1] = '\0';

    generate_ascii(text, ascii);

    return 0;
}