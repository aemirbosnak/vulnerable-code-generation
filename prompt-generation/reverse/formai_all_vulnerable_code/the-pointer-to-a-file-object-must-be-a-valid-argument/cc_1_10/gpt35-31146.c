//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 512
#define HEIGHT 512

float alpha = 0.05;

// Helper functions
float get_pixel(float *image, int x, int y, int width) {
    return image[y * width + x];
}

void set_pixel(float *image, int x, int y, int width, float value) {
    image[y * width + x] = value;
}

float* read_pgm(char *filename, int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    char header[128];
    fgets(header, 128, file);
    if (strcmp(header, "P5\n") != 0) {
        fprintf(stderr, "Error: Input file is not a PGM image\n");
        exit(-1);
    }
    fgets(header, 128, file);
    while (header[0] == '#') {
        fgets(header, 128, file);
    }
    sscanf(header, "%d %d", width, height);
    fgets(header, 128, file);
    int max_val = atoi(header);
    if (max_val != 255) {
        fprintf(stderr, "Error: Input file is not a valid 8-bit PGM image\n");
        exit(-1);
    }
    float *image = (float *) malloc((*width) * (*height) * sizeof(float));
    fread(image, sizeof(unsigned char), (*width) * (*height), file);
    fclose(file);
    return image;
}

void write_pgm(char *filename, float *image, int width, int height) {
    FILE *file = fopen(filename, "wb");
    fprintf(file, "P5\n%d %d\n255\n", width, height);
    fwrite(image, sizeof(unsigned char), width * height, file);
    fclose(file);
}

// Digital watermarking
void embed_watermark(float *image, int width, int height) {
    // Create watermark image
    float *watermark = (float *) malloc(width * height * sizeof(float));
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            float pixel = get_pixel(image, i, j, width);
            set_pixel(watermark, i, j, width, pixel > 127 ? 1 : 0);
        }
    }

    // Embed watermark
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            float pixel = get_pixel(image, i, j, width);
            if (pixel > 127) {
                set_pixel(image, i, j, width, pixel + alpha * (get_pixel(watermark, i, j, width) - pixel));
            } else {
                set_pixel(image, i, j, width, pixel - alpha * (get_pixel(watermark, i, j, width) - pixel));
            }
        }
    }

    free(watermark);
}

int detect_watermark(float *image, int width, int height) {
    // Create watermark image
    float *watermark = (float *) malloc(width * height * sizeof(float));
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            float pixel = get_pixel(image, i, j, width);
            set_pixel(watermark, i, j, width, pixel > 127 ? 1 : 0);
        }
    }

    // Detect watermark
    int count = 0;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            float pixel = get_pixel(image, i, j, width);
            if (pixel > 127 && get_pixel(watermark, i, j, width) == 0) {
                count++;
            } else if (pixel <= 127 && get_pixel(watermark, i, j, width) == 1) {
                count++;
            }
        }
    }

    free(watermark);

    return count;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s input.pgm output.pgm\n", argv[0]);
        return -1;
    }

    // Read image
    int width, height;
    float *image = read_pgm(argv[1], &width, &height);

    // Embed watermark
    embed_watermark(image, width, height);

    // Detect watermark
    int count = detect_watermark(image, width, height);
    printf("Watermark detection rate: %.2f%%\n", 100 * (float) count / (width * height));

    // Write image
    write_pgm(argv[2], image, width, height);

    free(image);

    return 0;
}