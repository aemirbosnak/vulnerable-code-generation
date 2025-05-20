//MISTRAL-7B DATASET v1.0 Category: Image Steganography ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define WIDTH 512
#define HEIGHT 512
#define BITS_PER_PIXEL 8
#define QUOTE_LENGTH 34

typedef unsigned char pixel;

void read_pgm(const char* filename, pixel** data, int* width, int* height) {
    FILE* file = fopen(filename, "rb");
    char magic_number[3];
    fgets(magic_number, sizeof(magic_number), file);
    *width = atoi(strtok(strchr(magic_number, ' '), " "));
    *height = atoi(strtok(NULL, " "));
    *data = calloc(*width, *height);
    fread(*data, 1, *width * *height, file);
    fclose(file);
}

void write_pgm(const char* filename, pixel* data, int width, int height) {
    FILE* file = fopen(filename, "wb");
    fprintf(file, "P5\n%d %d\n255\n", width, height);
    fwrite(data, 1, width * height, file);
    fclose(file);
}

bool is_power_of_two(int value) {
    return (value != 0) && ((value & (value - 1)) == 0);
}

void hide_quote(pixel* data, const char* quote) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (QUOTE_LENGTH > (WIDTH * HEIGHT) - (j + i)) break;
            data[i * WIDTH + j] ^= (quote[QUOTE_LENGTH - (WIDTH * HEIGHT + j + i)] << (BITS_PER_PIXEL - 1));
        }
    }
}

void reveal_quote(pixel* data, char* quote) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            quote[WIDTH * HEIGHT + j + i] = data[i * WIDTH + j] >> (BITS_PER_PIXEL - 1);
        }
    }
    quote[QUOTE_LENGTH] = '\0';
}

int main() {
    pixel* image_data;
    char quote[QUOTE_LENGTH + 1];
    int width, height;

    read_pgm("input.pgm", &image_data, &width, &height);

    strcpy(quote, "\"It is a capital mistake to theorize before one has data.\", Sherlock Holmes");

    if (is_power_of_two(WIDTH) && is_power_of_two(HEIGHT)) {
        hide_quote(image_data, quote);
        write_pgm("output.pgm", image_data, WIDTH, HEIGHT);

        printf("Quote hidden successfully!\n");

        pixel* hidden_image_data;
        read_pgm("output.pgm", &hidden_image_data, &width, &height);
        char hidden_quote[QUOTE_LENGTH + 1];
        reveal_quote(hidden_image_data, hidden_quote);
        printf("Revealed quote: %s\n", hidden_quote);

        free(hidden_image_data);
    } else {
        printf("Image dimensions must be a power of 2.\n");
    }

    free(image_data);
    return 0;
}