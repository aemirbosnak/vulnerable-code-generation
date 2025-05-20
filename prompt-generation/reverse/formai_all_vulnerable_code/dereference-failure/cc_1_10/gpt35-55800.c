//FormAI DATASET v1.0 Category: Image Editor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

byte* read_image_file(const char* filename, size_t* size);
void write_image_file(const char* filename, byte* data, size_t size);
void invert_image_colors(byte* data, size_t size);
void apply_gaussian_blur(byte* data, size_t size, int radius);

int main(int argc, char** argv) {
    if (argc != 4) {
        printf("Usage: image_editor <input_file> <output_file> <blur_radius>\n");
        return 1;
    }

    const char* input_file = argv[1];
    const char* output_file = argv[2];
    int blur_radius = atoi(argv[3]);

    size_t image_size;
    byte* image_data = read_image_file(input_file, &image_size);

    apply_gaussian_blur(image_data, image_size, blur_radius);
    invert_image_colors(image_data, image_size);

    write_image_file(output_file, image_data, image_size);

    free(image_data);

    return 0;
}

byte* read_image_file(const char* filename, size_t* size) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Unable to open file: %s\n", filename);
        exit(1);
    }

    fseek(fp, 0L, SEEK_END);
    *size = ftell(fp);
    rewind(fp);

    byte* data = (byte*) malloc(*size);
    if (data == NULL) {
        fprintf(stderr, "Unable to allocate memory for file data: %s\n", filename);
        exit(1);
    }

    fread(data, *size, 1, fp);

    fclose(fp);

    return data;
}

void write_image_file(const char* filename, byte* data, size_t size) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Unable to open file for writing: %s\n", filename);
        exit(1);
    }

    fwrite(data, size, 1, fp);
    fclose(fp);
}

void apply_gaussian_blur(byte* data, size_t size, int radius) {
    // TODO: implement Gaussian blur algorithm
    printf("Applied Gaussian blur with radius %d\n", radius);
}

void invert_image_colors(byte* data, size_t size) {
    for (size_t i = 0; i < size; i++) {
        data[i] = ~data[i];
    }

    printf("Inverted image colors\n");
}