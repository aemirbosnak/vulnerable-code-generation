//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512
#define MAX_VALUE 255
#define WATERMARK_VALUE 128

int main(int argc, char **argv) {
    FILE *in_file, *out_file;
    unsigned char *image_data, *watermark_data, *out_data;
    int i, j, k, x, y, watermark_size, pixel_value;
    float alpha, beta;

    if (argc!= 3) {
        printf("Usage: %s input_image output_image\n", argv[0]);
        exit(1);
    }

    in_file = fopen(argv[1], "rb");
    if (in_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    fseek(in_file, 0, SEEK_END);
    image_data = (unsigned char*) malloc(sizeof(unsigned char) * WIDTH * HEIGHT * 3);
    fseek(in_file, 0, SEEK_SET);
    fread(image_data, sizeof(unsigned char), WIDTH * HEIGHT * 3, in_file);
    fclose(in_file);

    watermark_data = (unsigned char*) malloc(sizeof(unsigned char) * WIDTH * HEIGHT * 3);
    for (i = 0; i < WIDTH * HEIGHT; i++) {
        pixel_value = (i % 2) * (MAX_VALUE / 2) + WATERMARK_VALUE;
        watermark_data[i * 3] = pixel_value;
        watermark_data[i * 3 + 1] = pixel_value;
        watermark_data[i * 3 + 2] = pixel_value;
    }

    alpha = (float) WATERMARK_VALUE / (float) MAX_VALUE;
    beta = 1.0 - alpha;

    out_data = (unsigned char*) malloc(sizeof(unsigned char) * WIDTH * HEIGHT * 3);
    for (i = 0; i < WIDTH * HEIGHT; i++) {
        for (j = 0; j < 3; j++) {
            x = i * 3;
            y = j * HEIGHT;
            out_data[x + y] = (unsigned char) ((image_data[x + y] * alpha) + (watermark_data[i] * beta));
        }
    }

    out_file = fopen(argv[2], "wb");
    if (out_file == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    fwrite(out_data, sizeof(unsigned char), WIDTH * HEIGHT * 3, out_file);
    fclose(out_file);

    free(image_data);
    free(watermark_data);
    free(out_data);

    return 0;
}