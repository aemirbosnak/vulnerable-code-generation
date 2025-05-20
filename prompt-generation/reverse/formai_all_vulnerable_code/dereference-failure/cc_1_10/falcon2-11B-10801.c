//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_IMAGE_WIDTH 800
#define MAX_IMAGE_HEIGHT 600

typedef struct {
    unsigned char* pixels;
    int width;
    int height;
} Image;

void error(const char* message) {
    perror(message);
    exit(EXIT_FAILURE);
}

Image* load_image(const char* filename) {
    Image* image = NULL;
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        error("Cannot open file");
    }
    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    rewind(file);

    if (file_size < 4) {
        error("Invalid image file");
    }

    image = (Image*)malloc(sizeof(Image));
    if (image == NULL) {
        error("Memory allocation failed");
    }

    image->pixels = (unsigned char*)malloc(file_size);
    if (image->pixels == NULL) {
        error("Memory allocation failed");
    }

    fread(image->pixels, file_size, 1, file);
    image->width = file_size / (MAX_IMAGE_WIDTH * sizeof(unsigned char));
    image->height = MAX_IMAGE_HEIGHT;
    return image;
}

void save_image(Image* image, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        error("Cannot create file");
    }

    fwrite(image->pixels, MAX_IMAGE_WIDTH * MAX_IMAGE_HEIGHT * sizeof(unsigned char), 1, file);
    fclose(file);
}

void print_image(Image* image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            printf("%02x ", image->pixels[y * image->width + x]);
        }
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <input_image> <output_image>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image* input_image = load_image(argv[1]);
    if (input_image == NULL) {
        return EXIT_FAILURE;
    }

    Image* output_image = (Image*)malloc(sizeof(Image));
    if (output_image == NULL) {
        error("Memory allocation failed");
    }

    output_image->pixels = (unsigned char*)malloc(MAX_IMAGE_WIDTH * MAX_IMAGE_HEIGHT * sizeof(unsigned char));
    if (output_image->pixels == NULL) {
        error("Memory allocation failed");
    }

    memcpy(output_image->pixels, input_image->pixels, MAX_IMAGE_WIDTH * MAX_IMAGE_HEIGHT * sizeof(unsigned char));

    save_image(output_image, argv[2]);

    free(input_image->pixels);
    free(input_image);
    free(output_image->pixels);
    free(output_image);

    return EXIT_SUCCESS;
}