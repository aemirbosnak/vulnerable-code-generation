//FormAI DATASET v1.0 Category: Image Editor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

// Function to read the file and return the size of the image
int read_file(char* filename, unsigned char** img_data);

// Function to write the image data to a file
void write_file(char* filename, unsigned char* img_data, int img_size);

// Function to invert the colors of the image
void invert_colors(unsigned char* img_data, int img_size);

// Function to make the image grayscale
void grayscale(unsigned char* img_data, int img_size);

int main(int argc, char** argv) {
    if (argc != 4) {
        printf("Usage: %s [input image] [output image] [operation]\n", argv[0]);
        printf("Operations:\n");
        printf("    1 - Invert colors\n");
        printf("    2 - Grayscale\n");
        return 1;
    }

    char* input_file = argv[1];
    char* output_file = argv[2];
    int operation = atoi(argv[3]);

    unsigned char* img_data;
    int img_size = read_file(input_file, &img_data);

    switch (operation) {
        case 1:
            invert_colors(img_data, img_size);
            break;
        case 2:
            grayscale(img_data, img_size);
            break;
        default:
            printf("Invalid operation: %d\n", operation);
            return 1;
    }

    write_file(output_file, img_data, img_size);

    free(img_data);

    return 0;
}

int read_file(char* filename, unsigned char** img_data) {
    FILE* f = fopen(filename, "rb");
    if (f == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    fseek(f, 0, SEEK_END);
    int size = ftell(f);
    fseek(f, 0, SEEK_SET);

    *img_data = (unsigned char*) malloc (sizeof(unsigned char) * size);

    int read = fread(*img_data, sizeof(unsigned char), size, f);
    if (read != size) {
        printf("Error: Could not read file %s\n", filename);
        exit(1);
    }

    fclose(f);

    return size;
}

void write_file(char* filename, unsigned char* img_data, int img_size) {
    FILE* f = fopen(filename, "wb");
    if (f == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    int written = fwrite(img_data, sizeof(unsigned char), img_size, f);
    if (written != img_size) {
        printf("Error: Could not write to file %s\n", filename);
        exit(1);
    }

    fclose(f);
}

void invert_colors(unsigned char* img_data, int img_size) {
    for (int i = 0; i < img_size; i++) {
        img_data[i] = 255 - img_data[i];
    }
}

void grayscale(unsigned char* img_data, int img_size) {
    for (int i = 0; i < img_size; i += 3) {
        unsigned char avg = (img_data[i] + img_data[i + 1] + img_data[i + 2]) / 3;
        img_data[i] = avg;
        img_data[i + 1] = avg;
        img_data[i + 2] = avg;
    }
}