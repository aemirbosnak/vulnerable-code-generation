//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CHAR 128
#define ART_WIDTH 50
#define ART_HEIGHT 10

char art[ART_HEIGHT][ART_WIDTH];
char shapes[10][10] = {
    "##...##..##...##..##...##..##...##..##...##..##...##..##...##..",
    "##....##.##....##.##....##.##....##.##....##.##....##.##....##.",
    "#####   #   #####   #   #####   #   #####   #   #####   #   #####",
    "##....##.##....##.##....##.##....##.##....##.##....##.##....##.",
    "##...##..##...##..##...##..##...##..##...##..##...##..##...##.",
    "###....###....###....###....###....###....###....###....###....",
    "##....##.##....##.##....##.##....##.##....##.##....##.##....##.",
    "##....##.##....##.##....##.##....##.##....##.##....##.##....##.",
    "#####   #   #####   #   #####   #   #####   #   #####   #   #####",
    "##....##.##....##.##....##.##....##.##....##.##....##.##....##."
};

void generate_art(char *text) {
    int i, j, len, shape;
    len = strlen(text);

    for (i = 0; i < len; i++) {
        shape = text[i] - 32;
        if (shape >= 0 && shape < 10) {
            for (j = 0; j < ART_WIDTH; j++) {
                art[i % ART_HEIGHT][j] = shapes[shape][j];
            }
        }
    }
}

void print_art() {
    int i, j;

    for (i = 0; i < ART_HEIGHT; i++) {
        for (j = 0; j < ART_WIDTH; j++) {
            putchar(art[i][j]);
        }
        putchar('\n');
    }
}

int main(int argc, char *argv[]) {
    char text[MAX_CHAR];

    srand(time(NULL));

    if (argc < 2) {
        printf("Usage: %s <text>\n", argv[0]);
        exit(1);
    }

    strcpy(text, argv[1]);
    generate_art(text);
    print_art();

    return 0;
}