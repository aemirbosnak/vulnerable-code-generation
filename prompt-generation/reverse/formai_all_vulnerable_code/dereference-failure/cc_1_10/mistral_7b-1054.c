//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define WIDTH 30
#define HEIGHT 10

void draw_box(int x, int y, int width, int height) {
    int i, j;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
                printf("%c", 201);
            else
                printf(" ");
        }
        printf("\n");
    }
}

void print_ascii_name(char *name) {
    int i, j, k, len;
    char c;

    len = strlen(name);

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            k = (i + j) % len;

            c = name[k] < 97 ? ' ' : toupper(name[k]);

            if (c == ' ') {
                printf("   ");
            } else {
                printf("%c", c);
            }
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    char name[100];

    if (argc != 2) {
        printf("Usage: %s <name>\n", argv[0]);
        return 1;
    }

    strcpy(name, argv[1]);

    draw_box(0, 0, WIDTH, HEIGHT);
    print_ascii_name(name);

    return 0;
}