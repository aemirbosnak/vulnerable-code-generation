//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25

char image[WIDTH * HEIGHT];

void load_image(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    if (size!= WIDTH * HEIGHT) {
        printf("Error: image has incorrect size\n");
        exit(1);
    }

    fread(image, 1, size, file);
    fclose(file);
}

void print_ascii_art() {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            printf("%c", image[y * WIDTH + x]);
        }
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_image> <output_ascii_art>\n", argv[0]);
        return 1;
    }

    const char* input_image = argv[1];
    const char* output_ascii_art = argv[2];

    load_image(input_image);
    print_ascii_art();

    FILE* output_file = fopen(output_ascii_art, "w");
    if (!output_file) {
        printf("Error: could not create file '%s'\n", output_ascii_art);
        return 1;
    }

    fprintf(output_file, "%s", image);
    fclose(output_file);

    return 0;
}