//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void flip_image(char* image_file);
void adjust_brightness_contrast(char* image_file, float brightness, float contrast);

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        printf("Please enter command line arguments to execute image processing tasks.\n");
        return 0;
    }

    char* task = argv[1];
    char* image_file = argv[2];

    if (tolower(*task) == 'f') {
        flip_image(image_file);
    } else if (tolower(*task) == 'a') {
        float brightness = atof(argv[3]);
        float contrast = atof(argv[4]);
        adjust_brightness_contrast(image_file, brightness, contrast);
    } else {
        printf("Invalid task specified. Please specify 'F' or 'A'");
    }

    return 0;
}

void flip_image(char* image_file) {
    FILE *fp = fopen(image_file, "r+b");
    if (fp == NULL) {
        printf("Error opening file: %s", image_file);
        return;
    }

    fseek(fp, 0, SEEK_END);
    int file_size = ftell(fp);
    rewind(fp);

    unsigned char* image_data = (unsigned char*) malloc(sizeof(unsigned char) * file_size);
    fread(image_data, sizeof(unsigned char), file_size, fp);
    fclose(fp);

    int width = *(int*)(image_data + 18);
    int height = *(int*)(image_data + 22);
    int bitdepth = *(int*)(image_data + 28) / 8;

    unsigned char* row_data = (unsigned char*) malloc(sizeof(unsigned char) * width * bitdepth);

    for (int row = 0; row < height/2; row++) {
        int row_offset = row * width * bitdepth;
        int flip_row_offset = (height - row - 1) * width * bitdepth;

        memcpy(row_data, image_data + row_offset, width * bitdepth);
        memcpy(image_data + row_offset, image_data + flip_row_offset, width * bitdepth);
        memcpy(image_data + flip_row_offset, row_data, width * bitdepth);
    }

    fp = fopen(image_file, "w+b");
    if (fp == NULL) {
        printf("Error opening file: %s", image_file);
        return;
    }

    fwrite(image_data, sizeof(unsigned char), file_size, fp);
    fclose(fp);

    free(row_data);
    free(image_data);

    printf("Image flipped successfully.");
}

void adjust_brightness_contrast(char* image_file, float brightness, float contrast) {
    FILE *fp = fopen(image_file, "r+b");
    if (fp == NULL) {
        printf("Error opening file: %s", image_file);
        return;
    }

    fseek(fp, 0, SEEK_END);
    int file_size = ftell(fp);
    rewind(fp);

    unsigned char* image_data = (unsigned char*) malloc(sizeof(unsigned char) * file_size);
    fread(image_data, sizeof(unsigned char), file_size, fp);
    fclose(fp);

    int width = *(int*)(image_data + 18);
    int height = *(int*)(image_data + 22);
    int bitdepth = *(int*)(image_data + 28) / 8;

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            int pixel_offset = row * width * bitdepth + col * bitdepth;
            float pixel_value = 0.0;

            for (int i = 0; i < bitdepth; i++) {
                pixel_value += *(image_data + pixel_offset + i);
            }

            pixel_value /= bitdepth;
            pixel_value += brightness;

            float temp = contrast * (pixel_value - 128) + 128;
            for (int i = 0; i < bitdepth; i++) {
                float value = *(image_data + pixel_offset + i);
                value = value - pixel_value + temp;
                value = value < 0 ? 0 : value > 255 ? 255 : value;
                *(image_data + pixel_offset + i) = (unsigned char)value;
            }
        }
    }

    fp = fopen(image_file, "w+b");
    if (fp == NULL) {
        printf("Error opening file: %s", image_file);
        return;
    }

    fwrite(image_data, sizeof(unsigned char), file_size, fp);
    fclose(fp);

    free(image_data);

    printf("Image brightness/contrast adjusted successfully.");
}