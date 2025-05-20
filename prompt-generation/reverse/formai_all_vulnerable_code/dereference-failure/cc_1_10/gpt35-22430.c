//FormAI DATASET v1.0 Category: Image Editor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void load_image(char* filename);
void flip_bottom_up();
void grayscale();
void blit(char* filename, int x, int y);

typedef struct {
    int width;
    int height;
    int channels;
    unsigned char* data;
} Image;

static Image current_image;

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <image-file>\n", argv[0]);
        exit(1);
    }

    load_image(argv[1]);

    // Apply filters and effects
    flip_bottom_up();
    grayscale();
    blit("logo.png", 100, 100);

    // Save the modified image
    char* output_filename = "modified.png";
    FILE* output_file = fopen(output_filename, "wb");
    if (!output_file) {
        printf("Error: could not open output file %s\n", output_filename);
        exit(1);
    }
    fwrite(current_image.data, current_image.width * current_image.height * current_image.channels, 1, output_file);
    fclose(output_file);

    free(current_image.data);
    return 0;
}

void load_image(char* filename) {
    FILE* input_file = fopen(filename, "rb");
    if (!input_file) {
        printf("Error: could not open input file %s\n", filename);
        exit(1);
    }

    char header[54];
    fread(header, sizeof(char), 54, input_file);
    current_image.width = *(int*)(header + 18);
    current_image.height = *(int*)(header + 22);
    current_image.channels = 3;

    int padding = (4 - (current_image.width * current_image.channels) % 4) % 4;
    int data_size = (current_image.width * current_image.height * current_image.channels) + padding * current_image.height;

    current_image.data = (unsigned char*)malloc(data_size);
    if (!current_image.data) {
        printf("Error: could not allocate memory\n");
        exit(1);
    }

    fread(current_image.data, sizeof(unsigned char), data_size, input_file);
    fclose(input_file);
}

void flip_bottom_up() {
    int row_size = current_image.width * current_image.channels;
    unsigned char* temp_row = (unsigned char*)malloc(row_size);
    for (int y = 0; y < current_image.height / 2; y++) {
        int top_offset = y * row_size;
        int bottom_offset = (current_image.height - y - 1) * row_size;
        memcpy(temp_row, current_image.data + top_offset, row_size);
        memcpy(current_image.data + top_offset, current_image.data + bottom_offset, row_size);
        memcpy(current_image.data + bottom_offset, temp_row, row_size);
    }
    free(temp_row);
}

void grayscale() {
    for (int y = 0; y < current_image.height; y++) {
        for (int x = 0; x < current_image.width; x++) {
            int offset = (y * current_image.width + x) * current_image.channels;
            unsigned char* pixel = current_image.data + offset;
            float gray_value = 0.2126f * pixel[0] + 0.7152f * pixel[1] + 0.0722f * pixel[2];
            pixel[0] = pixel[1] = pixel[2] = (unsigned char)gray_value;
        }
    }
}

void blit(char* filename, int x, int y) {
    Image logo;
    load_image(filename);
    logo = current_image;

    int row_size = current_image.width * current_image.channels;
    for (int logo_y = 0; logo_y < logo.height; logo_y++) {
        for (int logo_x = 0; logo_x < logo.width; logo_x++) {
            int logo_offset = (logo_y * logo.width + logo_x) * logo.channels;
            int y_offset = (y + logo_y) * row_size;
            int x_offset = (x + logo_x) * 3;
            memcpy(current_image.data + y_offset + x_offset, logo.data + logo_offset, logo.channels);
        }
    }
}