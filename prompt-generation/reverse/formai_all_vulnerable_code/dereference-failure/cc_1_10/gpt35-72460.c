//FormAI DATASET v1.0 Category: Image Editor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define CHANNELS 3
#define CHANNEL_SIZE 256

void apply_grayscale(unsigned char* image, int width, int height) {
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            int index = (i * width + j) * CHANNELS;

            unsigned char r = image[index];
            unsigned char g = image[index + 1];
            unsigned char b = image[index + 2];

            unsigned char gray = 0.3*r + 0.59*g + 0.11*b;

            image[index] = image[index + 1] = image[index + 2] = gray;
        }
    }
}

void apply_negative(unsigned char* image, int width, int height) {
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            int index = (i * width + j) * CHANNELS;

            unsigned char r = image[index];
            unsigned char g = image[index + 1];
            unsigned char b = image[index + 2];

            image[index] = CHANNEL_SIZE - r;
            image[index + 1] = CHANNEL_SIZE - g;
            image[index + 2] = CHANNEL_SIZE - b;
        }
    }
}

int read_ppm(char* filename, unsigned char** image, int* width, int* height) {
    FILE* stream = fopen(filename, "r");
    if(!stream) {
        return -1;
    }

    char format[3];
    if(fscanf(stream, "%2s", format) != 1 || format[0] != 'P' || format[1] != '6') {
        fclose(stream);
        return -2;
    }

    int channels;
    if(fscanf(stream, "%d %d\n%d", width, height, &channels) != 3 || channels != 255) {
        fclose(stream);
        return -3;
    }

    *image = (unsigned char*)malloc((*width) * (*height) * CHANNELS * sizeof(unsigned char));
    fread(*image, 1, (*width) * (*height) * CHANNELS, stream);

    fclose(stream);
    return 0;
}

int write_ppm(char* filename, unsigned char* image, int width, int height) {
    FILE* stream = fopen(filename, "w");
    if(!stream) {
        return -1;
    }

    fprintf(stream, "P6\n%d %d\n%d\n", width, height, CHANNEL_SIZE);
    fwrite(image, 1, width * height * CHANNELS, stream);

    fclose(stream);
    return 0;
}

int main(int argc, char** argv) {
    if(argc == 1) {
        fprintf(stderr, "Usage: %s <input-file>\n", argv[0]);
        return 1;
    }

    char* filename = argv[1];

    unsigned char* image;
    int width, height;

    int result = read_ppm(filename, &image, &width, &height);
    switch(result) {
        case -1:
            fprintf(stderr, "Could not open file: %s\n", filename);
            return 1;
        case -2:
            fprintf(stderr, "Invalid file format: %s\n", filename);
            return 2;
        case -3:
            fprintf(stderr, "Invalid file contents: %s\n", filename);
            return 3;
        default:
            break;
    }

    apply_grayscale(image, width, height);
    apply_negative(image, width, height);

    char output_filename[512];
    snprintf(output_filename, sizeof(output_filename), "edited_%s", filename);

    result = write_ppm(output_filename, image, width, height);
    if(result != 0) {
        fprintf(stderr, "Could not write file: %s\n", output_filename);
        return 4;
    }

    printf("Successfully edited image: %s\nSaved as: %s\n", filename, output_filename);

    free(image);
    return 0;
}