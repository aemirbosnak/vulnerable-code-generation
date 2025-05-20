//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25

void print_image(char *data, int size) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c", data[i * WIDTH + j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char filename[100];
    char *data;
    int size;

    // Get filename from command line argument
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    strcpy(filename, argv[1]);

    // Open file and read data
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'.\n", filename);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    data = malloc(size);
    if (data == NULL) {
        printf("Error: Could not allocate memory.\n");
        exit(1);
    }
    fread(data, 1, size, fp);
    fclose(fp);

    // Convert image to ASCII art
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            int gray = (data[(y * WIDTH + x) * 3] + data[(y * WIDTH + x) * 3 + 1] + data[(y * WIDTH + x) * 3 + 2]) / 3;
            if (gray < 128) {
                printf(" ");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }

    // Free memory and exit
    free(data);
    return 0;
}