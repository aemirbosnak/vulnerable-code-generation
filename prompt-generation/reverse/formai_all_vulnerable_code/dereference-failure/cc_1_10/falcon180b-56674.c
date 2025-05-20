//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 100
#define HEIGHT 50

char image[HEIGHT][WIDTH];

void load_image(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            char c = fgetc(fp);
            if (c == EOF) {
                printf("Error: File is too short\n");
                exit(1);
            }

            image[i][j] = c;
        }
    }

    fclose(fp);
}

void print_ascii_art(void) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c", image[i][j]);
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
    print_ascii_art();

    return 0;
}