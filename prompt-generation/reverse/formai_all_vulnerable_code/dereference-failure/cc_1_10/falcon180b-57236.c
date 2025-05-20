//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert image to ASCII art
void image_to_ascii(char *filename, int width, int height) {
    FILE *fp;
    char ch;
    int i, j, k, l, count = 0;
    char *line = (char *) malloc((width + 1) * sizeof(char));

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            fread(&ch, sizeof(char), 1, fp);
            if (ch == 0) {
                printf("  ");
            } else if (ch < 64) {
                printf(".");
            } else if (ch < 96) {
                printf(":");
            } else if (ch < 128) {
                printf("-");
            } else if (ch < 160) {
                printf("=");
            } else if (ch < 192) {
                printf("+");
            } else if (ch < 224) {
                printf("*");
            } else if (ch < 240) {
                printf("%");
            } else if (ch < 248) {
                printf("&");
            } else if (ch < 252) {
                printf("@");
            } else if (ch < 254) {
                printf("^");
            } else if (ch < 256) {
                printf("~");
            }
        }
        printf("\n");
    }

    fclose(fp);
    free(line);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <filename> <width> <height>\n", argv[0]);
        return 1;
    }

    int width = atoi(argv[2]);
    int height = atoi(argv[3]);

    image_to_ascii(argv[1], width, height);

    return 0;
}