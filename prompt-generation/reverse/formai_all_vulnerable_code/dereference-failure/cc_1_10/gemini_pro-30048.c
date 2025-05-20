//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

Image *new_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height * sizeof(unsigned char));
    return image;
}

void free_image(Image *image) {
    free(image->data);
    free(image);
}

void load_image(Image *image, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        exit(1);
    }

    char header[10];
    fread(header, 1, 10, file);
    if (strncmp(header, "BM", 2) != 0) {
        fprintf(stderr, "Error: Invalid file format\n");
        exit(1);
    }

    int width, height;
    fread(&width, 4, 1, file);
    fread(&height, 4, 1, file);

    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        fprintf(stderr, "Error: Image is too large\n");
        exit(1);
    }

    int offset;
    fread(&offset, 4, 1, file);

    fseek(file, offset, SEEK_SET);

    fread(image->data, 1, width * height, file);

    fclose(file);
}

void save_image(Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        exit(1);
    }

    char header[10] = "BM";
    fwrite(header, 1, 10, file);

    int width = image->width;
    int height = image->height;
    fwrite(&width, 4, 1, file);
    fwrite(&height, 4, 1, file);

    int offset = 54;
    fwrite(&offset, 4, 1, file);

    int bits_per_pixel = 24;
    fwrite(&bits_per_pixel, 2, 1, file);

    int compression = 0;
    fwrite(&compression, 4, 1, file);

    int image_size = width * height * 3;
    fwrite(&image_size, 4, 1, file);

    int horizontal_resolution = 2835;
    int vertical_resolution = 2835;
    fwrite(&horizontal_resolution, 4, 1, file);
    fwrite(&vertical_resolution, 4, 1, file);

    int colors = 0;
    fwrite(&colors, 4, 1, file);

    int important_colors = 0;
    fwrite(&important_colors, 4, 1, file);

    fwrite(image->data, 1, width * height * 3, file);

    fclose(file);
}

void invert_colors(Image *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->data[i] = 255 - image->data[i];
    }
}

void grayscale(Image *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        int gray = (image->data[i] + image->data[i + 1] + image->data[i + 2]) / 3;
        image->data[i] = gray;
        image->data[i + 1] = gray;
        image->data[i + 2] = gray;
    }
}

void blur(Image *image, int radius) {
    if (radius <= 0) {
        return;
    }

    int width = image->width;
    int height = image->height;

    int *box = malloc(radius * radius * sizeof(int));
    int *box_sum = malloc(radius * radius * sizeof(int));
    int *box_count = malloc(radius * radius * sizeof(int));

    for (int i = 0; i < radius * radius; i++) {
        box[i] = 0;
        box_sum[i] = 0;
        box_count[i] = 0;
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int box_index = 0;
            for (int i = -radius; i <= radius; i++) {
                for (int j = -radius; j <= radius; j++) {
                    int x2 = x + i;
                    int y2 = y + j;
                    if (x2 < 0 || x2 >= width || y2 < 0 || y2 >= height) {
                        box_index++;
                        continue;
                    }

                    int index = (y2 * width) + x2;
                    int r = image->data[index];
                    int g = image->data[index + 1];
                    int b = image->data[index + 2];

                    box[box_index] += r;
                    box[box_index + 1] += g;
                    box[box_index + 2] += b;

                    box_sum[box_index] += r + g + b;
                    box_count[box_index]++;
                    
                    box_index += 3;
                }
            }

            int box_sum_index = 0;
            for (int i = -radius; i <= radius; i++) {
                for (int j = -radius; j <= radius; j++) {
                    int index = (y * width) + x;
                    int r = box[box_sum_index] / box_count[box_sum_index];
                    int g = box[box_sum_index + 1] / box_count[box_sum_index];
                    int b = box[box_sum_index + 2] / box_count[box_sum_index];

                    image->data[index] = r;
                    image->data[index + 1] = g;
                    image->data[index + 2] = b;
                    box_sum_index += 3;
                }
            }
        }
    }

    free(box);
    free(box_sum);
    free(box_count);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    char *input_filename = argv[1];
    char *output_filename = argv[2];
    
    Image *image = new_image(MAX_WIDTH, MAX_HEIGHT);
    load_image(image, input_filename);
    
    invert_colors(image);
    blur(image, 5);
    save_image(image, output_filename);
    free_image(image);
    return 0;
}