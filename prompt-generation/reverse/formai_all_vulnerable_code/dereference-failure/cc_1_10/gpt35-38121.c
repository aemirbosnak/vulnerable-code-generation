//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int width;
    int height;
    unsigned char* pixels;
} Image;

Image* create_image(int width, int height) {
    Image* image = (Image*)malloc(sizeof(Image));
    if(image == NULL) {
        fprintf(stderr, "Error: Could not create image.\n");
        exit(1);
    }

    image->width = width;
    image->height = height;
    image->pixels = (unsigned char*)calloc(width * height * 3, sizeof(unsigned char));
    if(image->pixels == NULL) {
        fprintf(stderr, "Error: Could not create image pixels.\n");
        exit(1);
    }

    return image;
}

void destroy_image(Image* image) {
    if(image == NULL) {
        fprintf(stderr, "Error: image is null.\n");
        exit(1);
    }

    free(image->pixels);
    free(image);
}

void load_image(Image* image, const char* filename) {
    FILE* file;
    file = fopen(filename, "rb");
    if(file == NULL) {
        fprintf(stderr, "Error: Could not open file %s.\n", filename);
        exit(1);
    }

    char header[54];
    fread(header, sizeof(char), 54, file);

    image->width = *(int*)&header[18];
    image->height = *(int*)&header[22];

    int row_size = image->width * 3;
    while(row_size % 4 != 0)
        row_size++;

    image->pixels = (unsigned char*)calloc(row_size * image->height, sizeof(unsigned char));
    if(image->pixels == NULL) {
        fprintf(stderr, "Error: Could not create image pixels.\n");
        exit(1);
    }

    fseek(file, *(int*)&header[10], SEEK_SET);

    for(int i = 0; i < image->height; i++) {
        fread(&image->pixels[(image->height - 1 - i) * row_size], sizeof(unsigned char), row_size, file);
    }

    fclose(file);
}

void save_image(Image* image, const char* filename) {
    FILE* file;
    file = fopen(filename, "wb");
    if(file == NULL) {
        fprintf(stderr, "Error: Could not open file %s.\n", filename);
        exit(1);
    }

    int row_size = image->width * 3;
    while(row_size % 4 != 0)
        row_size++;

    unsigned char header[54] = {
        0x42, 0x4d, 0x36, 0x4c, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00,
        0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x4c, 0x07, 0x00, 0x00, 0x12, 0x0b, 0x00, 0x00, 0x12, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    *(int*)&header[18] = image->width;
    *(int*)&header[22] = image->height;

    fwrite(header, sizeof(unsigned char), 54, file);

    for(int i = 0; i < image->height; i++) {
        fwrite(&image->pixels[(image->height - 1 - i) * row_size], sizeof(unsigned char), row_size, file);
    }

    fclose(file);
}

void flip_image(Image* image) {
    if(image == NULL) {
        fprintf(stderr, "Error: image is null.\n");
        exit(1);
    }

    int row_size = image->width * 3;
    while(row_size % 4 != 0)
        row_size++;

    unsigned char* buffer = (unsigned char*)malloc(row_size * sizeof(unsigned char));

    for(int i = 0; i < image->height / 2; i++) {
        memcpy(buffer, &image->pixels[i * row_size], row_size);
        memcpy(&image->pixels[i * row_size], &image->pixels[(image->height - i - 1) * row_size], row_size);
        memcpy(&image->pixels[(image->height - i - 1) * row_size], buffer, row_size);
    }

    free(buffer);
}

void adjust_brightness(Image* image, int value) {
    if(image == NULL) {
        fprintf(stderr, "Error: image is null.\n");
        exit(1);
    }

    for(int i = 0; i < image->width * image->height * 3; i++) {
        int new_value = (int)image->pixels[i] + value;
        if(new_value < 0) new_value = 0;
        if(new_value > 255) new_value = 255;
        image->pixels[i] = (unsigned char)new_value;
    }
}

void adjust_contrast(Image* image, int value) {
    if(image == NULL) {
        fprintf(stderr, "Error: image is null.\n");
        exit(1);
    }

    float contrast = (float)(value + 100) / 100.0f;

    for(int i = 0; i < image->width * image->height * 3; i++) {
        int new_value = (int)((image->pixels[i] / 255.0f - 0.5f) * contrast + 0.5f) * 255.0f;
        if(new_value < 0) new_value = 0;
        if(new_value > 255) new_value = 255;
        image->pixels[i] = (unsigned char)new_value;
    }
}

int main() {
    Image* image = create_image(0, 0);
    load_image(image, "image.bmp");

    flip_image(image);
    adjust_brightness(image, 50);
    adjust_contrast(image, 50);
    save_image(image, "processed.bmp");

    destroy_image(image);
    return 0;
}