//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} pixel;

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input image> <output image> <message>\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "rb");
    if (input == NULL) {
        perror("Error opening input image");
        return 1;
    }

    FILE *output = fopen(argv[2], "wb");
    if (output == NULL) {
        perror("Error opening output image");
        return 1;
    }

    int width, height;
    fread(&width, sizeof(int), 1, input);
    fread(&height, sizeof(int), 1, input);

    pixel **image = malloc(sizeof(pixel *) * height);
    for (int i = 0; i < height; i++) {
        image[i] = malloc(sizeof(pixel) * width);
        fread(image[i], sizeof(pixel), width, input);
    }

    int message_length = strlen(argv[3]);
    int message_index = 0;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (message_index < message_length) {
                image[i][j].r = (image[i][j].r & 0xFE) | ((argv[3][message_index++] >> 6) & 0x01);
                image[i][j].g = (image[i][j].g & 0xFE) | ((argv[3][message_index++] >> 4) & 0x01);
                image[i][j].b = (image[i][j].b & 0xFE) | ((argv[3][message_index++] >> 2) & 0x01);
            }
        }
    }

    fwrite(&width, sizeof(int), 1, output);
    fwrite(&height, sizeof(int), 1, output);
    for (int i = 0; i < height; i++) {
        fwrite(image[i], sizeof(pixel), width, output);
        free(image[i]);
    }
    free(image);

    fclose(input);
    fclose(output);

    return 0;
}