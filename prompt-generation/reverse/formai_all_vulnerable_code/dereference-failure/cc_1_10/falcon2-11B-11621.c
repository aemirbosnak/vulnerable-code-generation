//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_image> <output_image>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    FILE *output_file = fopen(argv[2], "wb");
    if (!input_file ||!output_file) {
        perror("Error opening files");
        return 1;
    }

    int width, height, channels;
    fseek(input_file, 0, SEEK_END);
    long size = ftell(input_file);
    rewind(input_file);
    fread(&width, sizeof(int), 1, input_file);
    fread(&height, sizeof(int), 1, input_file);
    fread(&channels, sizeof(int), 1, input_file);

    fseek(input_file, 0, SEEK_SET);
    unsigned char *image_data = (unsigned char *) malloc(size);
    fread(image_data, 1, size, input_file);

    fseek(output_file, 0, SEEK_END);
    fwrite(&width, sizeof(int), 1, output_file);
    fwrite(&height, sizeof(int), 1, output_file);
    fwrite(&channels, sizeof(int), 1, output_file);
    fwrite(&size, sizeof(long), 1, output_file);
    fseek(output_file, 0, SEEK_SET);

    unsigned char *output_data = (unsigned char *) malloc(size);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            unsigned char r, g, b;
            fread(&r, sizeof(unsigned char), 1, input_file);
            fread(&g, sizeof(unsigned char), 1, input_file);
            fread(&b, sizeof(unsigned char), 1, input_file);
            output_data[y * width * channels + 3 * x + 0] = r;
            output_data[y * width * channels + 3 * x + 1] = g;
            output_data[y * width * channels + 3 * x + 2] = b;
        }
    }

    fseek(output_file, 0, SEEK_SET);
    fwrite(image_data, 1, size, output_file);

    fclose(input_file);
    fclose(output_file);

    free(image_data);
    free(output_data);

    return 0;
}