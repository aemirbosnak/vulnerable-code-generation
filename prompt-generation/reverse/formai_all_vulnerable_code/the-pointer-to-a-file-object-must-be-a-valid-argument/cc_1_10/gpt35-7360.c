//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

char image[MAX_HEIGHT][MAX_WIDTH];

char ascii_chars[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

int max_gray_level;

void read_image(char *filename) {
    FILE *fp;
    char buffer[100];

    fp = fopen(filename, "r");

    // Skip the first two lines
    fgets(buffer, 100, fp);
    fgets(buffer, 100, fp);

    // Read the image information
    fscanf(fp, "%d %d\n", &max_gray_level, &max_gray_level);

    // Read the image pixels
    for (int i = 0; i < MAX_HEIGHT; i++) {
        for (int j = 0; j < MAX_WIDTH; j++) {
            int pixel;
            fscanf(fp, "%d", &pixel);
            image[i][j] = pixel;
        }
    }

    fclose(fp);
}

void convert_to_ascii() {
    for (int i = 0; i < MAX_HEIGHT; i++) {
        for (int j = 0; j < MAX_WIDTH; j++) {
            int gray_level = image[i][j] * 10 / max_gray_level;

            if (gray_level >= 10) {
                gray_level = 9;
            }

            char ascii_char = ascii_chars[gray_level];

            printf("%c", ascii_char);
        }

        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    
    read_image(argv[1]);

    convert_to_ascii();

    return 0;
}