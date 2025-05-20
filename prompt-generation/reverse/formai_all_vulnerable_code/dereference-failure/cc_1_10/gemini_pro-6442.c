//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 100
#define HEIGHT 100
#define MAX_CHAR 100

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixel;

typedef struct {
    pixel pixels[WIDTH][HEIGHT];
} image;

char* ascii_chars = " .,-~:;!?@$%*&#+=-";

void read_image(char* filename, image* img) {
    FILE* f = fopen(filename, "rb");
    if (f == NULL) {
        perror("Error opening file");
        exit(1);
    }
    fread(img->pixels, sizeof(pixel), WIDTH * HEIGHT, f);
    fclose(f);
}

char get_ascii_char(pixel p) {
    double avg = (p.red + p.green + p.blue) / 3.0;
    int index = (int)round(avg * (MAX_CHAR - 1) / 255.0);
    return ascii_chars[index];
}

void convert_image_to_ascii(image* img, char* output) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            char c = get_ascii_char(img->pixels[x][y]);
            output[y * WIDTH + x] = c;
        }
    }
}

void write_ascii_image(char* filename, char* output) {
    FILE* f = fopen(filename, "w");
    if (f == NULL) {
        perror("Error opening file");
        exit(1);
    }
    fprintf(f, "%s", output);
    fclose(f);
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <input_image> <output_ascii>\n", argv[0]);
        return 1;
    }

    image img;
    read_image(argv[1], &img);

    char* output = malloc(WIDTH * HEIGHT);
    convert_image_to_ascii(&img, output);

    write_ascii_image(argv[2], output);

    free(output);

    return 0;
}