//FormAI DATASET v1.0 Category: Image Editor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILE_NAME_LEN 256
#define MAX_PIXEL_VAL 255

typedef struct Image {
    int width;
    int height;
    int max_val;
    int* pixels;
} Image;

// Function to check if a file with given name exists
bool file_exists(const char* file_name) {
    FILE* file = fopen(file_name, "r");
    if (file) {
        fclose(file);
        return true;
    }
    return false;
}

// Function to get a pixel value from an image
int get_pixel(const Image* img, int x, int y) {
    return img->pixels[y * img->width + x];
}

// Function to set a pixel value of an image
void set_pixel(Image* img, int x, int y, int value) {
    img->pixels[y * img->width + x] = value;
}

// Function to load an image from a PGM file
Image* load_image(const char* file_name) {
    // Check if file exists
    if (!file_exists(file_name)) {
        printf("Error: file '%s' does not exist.\n", file_name);
        return NULL;
    }

    // Open file
    FILE* file = fopen(file_name, "r");
    if (!file) {
        printf("Error: could not open file '%s'.\n", file_name);
        return NULL;
    }

    // Read PGM header
    char magic_number[3];
    fscanf(file, "%2s", magic_number);
    if (strncmp(magic_number, "P5", 2) != 0) {
        printf("Error: file '%s' is not a PGM file.\n", file_name);
        fclose(file);
        return NULL;
    }
    int width, height, max_val;
    fscanf(file, "%d %d %d", &width, &height, &max_val);
    if (max_val > MAX_PIXEL_VAL) {
        printf("Error: file '%s' has too high pixel value (%d).\n", file_name, max_val);
        fclose(file);
        return NULL;
    }

    // Allocate memory for image
    Image* img = malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->max_val = max_val;
    img->pixels = malloc(sizeof(int) * height * width);

    // Read pixel data
    fread(img->pixels, sizeof(int), height * width, file);

    // Close file
    fclose(file);

    printf("Loaded image '%s'.\n", file_name);

    return img;
}

// Function to save an image to a PGM file
void save_image(const Image* img, const char* file_name) {
    // Open file
    FILE* file = fopen(file_name, "w");
    if (!file) {
        printf("Error: could not open file '%s' for writing.\n", file_name);
        return;
    }

    // Write PGM header
    fprintf(file, "P5\n%d %d\n%d\n", img->width, img->height, img->max_val);

    // Write pixel data
    fwrite(img->pixels, sizeof(int), img->height * img->width, file);

    // Close file
    fclose(file);

    printf("Saved image '%s'.\n", file_name);
}

// Function to invert an image (i.e., 255 - pixel value)
void invert(Image* img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            int pixel = get_pixel(img, x, y);
            set_pixel(img, x, y, img->max_val - pixel);
        }
    }
}

// Function to generate a negative image (i.e., negate colors)
void negative(Image* img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            int pixel = get_pixel(img, x, y);
            int r = img->max_val - ((pixel >> 16) & 0xFF);
            int g = img->max_val - ((pixel >> 8) & 0xFF);
            int b = img->max_val - (pixel & 0xFF);
            set_pixel(img, x, y, (r << 16) | (g << 8) | b);
        }
    }
}

// Function to generate a grayscale image
void grayscale(Image* img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            int pixel = get_pixel(img, x, y);
            int r = (pixel >> 16) & 0xFF;
            int g = (pixel >> 8) & 0xFF;
            int b = pixel & 0xFF;
            int gray = (r * 0.3) + (g * 0.59) + (b * 0.11); // luminosity method
            set_pixel(img, x, y, gray | (gray << 8) | (gray << 16));
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s [options] input_file output_file\n", argv[0]);
        printf("\nOptions:\n");
        printf("  -i: invert colors\n");
        printf("  -n: generate negative image\n");
        printf("  -g: generate grayscale image\n");
        return 0;
    }

    // Parse options
    bool invert_colors = false;
    bool negative_image = false;
    bool grayscale_image = false;
    for (int i = 1; i < argc - 2; i++) {
        if (strcmp(argv[i], "-i") == 0) {
            invert_colors = true;
        } else if (strcmp(argv[i], "-n") == 0) {
            negative_image = true;
        } else if (strcmp(argv[i], "-g") == 0) {
            grayscale_image = true;
        } else {
            printf("Error: unknown option '%s'.\n", argv[i]);
            return 0;
        }
    }

    // Load image
    Image* img = load_image(argv[argc - 2]);
    if (!img) {
        return 0;
    }

    // Apply modifications
    if (invert_colors) {
        invert(img);
    }
    if (negative_image) {
        negative(img);
    }
    if (grayscale_image) {
        grayscale(img);
    }

    // Save image
    save_image(img, argv[argc - 1]);

    // Free memory
    free(img->pixels);
    free(img);

    return 0;
}