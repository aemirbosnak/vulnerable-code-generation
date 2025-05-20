//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WIDTH 80
#define HEIGHT 45

char image[HEIGHT][WIDTH];

void load_image(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Cannot open file %s\n", filename);
        exit(1);
    }

    int i = 0, j = 0;
    char c;
    while ((c = fgetc(fp))!= EOF) {
        if (c == '\n') {
            i++;
            j = 0;
        } else {
            image[i][j++] = toupper(c);
        }
    }

    fclose(fp);
}

void print_ascii_art(int x, int y) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (image[i][j] == 'X') {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    load_image(argv[1]);

    int x = (WIDTH - strlen(argv[1]) * 8) / 2;
    int y = (HEIGHT - 8) / 2;

    print_ascii_art(x, y);

    return 0;
}