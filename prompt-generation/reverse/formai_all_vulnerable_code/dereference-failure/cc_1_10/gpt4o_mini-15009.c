//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

typedef unsigned char pixel;

typedef struct {
    int width;
    int height;
    pixel pixels[MAX_HEIGHT][MAX_WIDTH][3]; // RGB
} Image;

void print_error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(EXIT_FAILURE);
}

Image* load_image(const char *filepath) {
    Image *img = malloc(sizeof(Image));
    FILE *file = fopen(filepath, "rb");

    if (!file) {
        print_error("Could not open file.");
    }

    // Simple BMP header reading for the sake of example
    fseek(file, 18, SEEK_SET);
    fread(&img->width, sizeof(int), 1, file);
    fread(&img->height, sizeof(int), 1, file);
    
    fseek(file, 54, SEEK_SET); // Skip to pixel data
    fread(img->pixels, sizeof(pixel), img->width * img->height * 3, file);

    fclose(file);
    return img;
}

void save_image(const char *filepath, Image *img) {
    FILE *file = fopen(filepath, "wb");

    if (!file) {
        print_error("Could not save image file.");
    }

    // Writing a simple BMP header
    fputs("BM", file);
    int file_size = 54 + img->width * img->height * 3;
    fwrite(&file_size, sizeof(int), 1, file);
    fwrite(&(int){0}, sizeof(int), 1, file); // Reserved
    int offset = 54;
    fwrite(&offset, sizeof(int), 1, file); // Offset to pixel data
    int info_header_size = 40;
    fwrite(&info_header_size, sizeof(int), 1, file); // Info header size
    fwrite(&img->width, sizeof(int), 1, file);
    fwrite(&img->height, sizeof(int), 1, file);
    // Always 1 for planes and 24 for bits per pixel
    fwrite(&(short){1}, sizeof(short), 1, file);
    fwrite(&(short){24}, sizeof(short), 1, file);
    fwrite(&(int){0}, sizeof(int), 1, file); // Compression (0)
    int data_size = img->width * img->height * 3;
    fwrite(&data_size, sizeof(int), 1, file);
    fwrite(&(int){2835}, sizeof(int), 1, file); // X pixels per meter
    fwrite(&(int){2835}, sizeof(int), 1, file); // Y pixels per meter
    fwrite(&(int){0}, sizeof(int), 1, file); // Colors in the palette
    fwrite(&(int){0}, sizeof(int), 1, file); // Important color count

    fwrite(img->pixels, sizeof(pixel), img->width * img->height * 3, file);
    fclose(file);
}

void flip_image(Image *img) {
    for (int i = 0; i < img->height / 2; ++i) {
        for (int j = 0; j < img->width; ++j) {
            pixel temp[3];
            memcpy(temp, img->pixels[i][j], 3);
            memcpy(img->pixels[i][j], img->pixels[img->height - 1 - i][j], 3);
            memcpy(img->pixels[img->height - 1 - i][j], temp, 3);
        }
    }
}

void change_brightness(Image *img, int offset) {
    for (int y = 0; y < img->height; ++y) {
        for (int x = 0; x < img->width; ++x) {
            for (int c = 0; c < 3; ++c) {
                int new_value = img->pixels[y][x][c] + offset;
                img->pixels[y][x][c] = new_value < 0 ? 0 : (new_value > 255 ? 255 : new_value);
            }
        }
    }
}

void change_contrast(Image *img, float factor) {
    for (int y = 0; y < img->height; ++y) {
        for (int x = 0; x < img->width; ++x) {
            for (int c = 0; c < 3; ++c) {
                int new_value = (img->pixels[y][x][c] - 128) * factor + 128;
                img->pixels[y][x][c] = new_value < 0 ? 0 : (new_value > 255 ? 255 : new_value);
            }
        }
    }
}

void free_image(Image *img) {
    free(img);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input_image> <output_image> <option>\n", argv[0]);
        fprintf(stderr, "Options: flip, brightness <value>, contrast <factor>\n");
        return EXIT_FAILURE;
    }

    Image *img = load_image(argv[1]);
    if (strcmp(argv[3], "flip") == 0) {
        flip_image(img);
    } else if (strcmp(argv[3], "brightness") == 0 && argc == 5) {
        int value = atoi(argv[4]);
        change_brightness(img, value);
    } else if (strcmp(argv[3], "contrast") == 0 && argc == 5) {
        float factor = atof(argv[4]);
        change_contrast(img, factor);
    } else {
        print_error("Invalid option or arguments.");
    }

    save_image(argv[2], img);
    free_image(img);
    return EXIT_SUCCESS;
}