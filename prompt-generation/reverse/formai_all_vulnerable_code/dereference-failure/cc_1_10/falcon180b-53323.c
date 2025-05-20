//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 24

unsigned char image[HEIGHT][WIDTH];

void load_image(const char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    unsigned char* buffer = malloc(size);
    fread(buffer, size, 1, fp);
    fclose(fp);

    int x = 0, y = 0;
    for (int i = 0; i < size; i += 3) {
        image[y][x] = buffer[i];
        x++;
        if (x == WIDTH) {
            x = 0;
            y++;
        }
    }
}

void print_ascii_art(int x, int y) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", image[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input_image> <output_ascii_art>\n", argv[0]);
        return 1;
    }

    load_image(argv[1]);

    char* output_filename = argv[2];
    FILE* fp = fopen(output_filename, "w");
    if (fp == NULL) {
        printf("Error opening file: %s\n", output_filename);
        exit(1);
    }

    print_ascii_art(0, 0);

    fclose(fp);

    return 0;
}