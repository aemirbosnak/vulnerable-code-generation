//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ASCII art characters
char *chars[] = {
    "█", "▓", "▒", ".", " ",
};

// Image struct
typedef struct {
    int width;
    int height;
    char **data;
} Image;

// Load an image from a file
Image *load_image(const char *filename) {
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    // Read the header
    int width, height;
    fscanf(file, "%d %d\n", &width, &height);

    // Allocate memory for the image
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(sizeof(char *) * height);

    // Read the image data
    for (int i = 0; i < height; i++) {
        image->data[i] = malloc(sizeof(char) * width);
        fscanf(file, "%s\n", image->data[i]);
    }

    // Close the file
    fclose(file);

    return image;
}

// Save an image to a file
void save_image(const char *filename, Image *image) {
    // Open the file
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return;
    }

    // Write the header
    fprintf(file, "%d %d\n", image->width, image->height);

    // Write the image data
    for (int i = 0; i < image->height; i++) {
        fprintf(file, "%s\n", image->data[i]);
    }

    // Close the file
    fclose(file);
}

// Convert an image to ASCII art
void ascii_art(Image *image) {
    // Calculate the average brightness of each pixel
    float avg_brightness[image->width][image->height];
    for (int i = 0; i < image->width; i++) {
        for (int j = 0; j < image->height; j++) {
            int r = image->data[j][i] & 0xFF;
            int g = image->data[j][i] >> 8 & 0xFF;
            int b = image->data[j][i] >> 16 & 0xFF;
            avg_brightness[i][j] = (r + g + b) / 3.0;
        }
    }

    // Convert the average brightness to an ASCII character
    for (int i = 0; i < image->width; i++) {
        for (int j = 0; j < image->height; j++) {
            int index = (int)(avg_brightness[i][j] / 255.0 * (sizeof(chars) / sizeof(char *)));
            image->data[j][i] = chars[index];
        }
    }
}

// Print an image to the console
void print_image(Image *image) {
    for (int i = 0; i < image->height; i++) {
        printf("%s\n", image->data[i]);
    }
}

int main(int argc, char **argv) {
    // Check if the user has specified an input file
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input file>\n", argv[0]);
        return 1;
    }

    // Load the image from the file
    Image *image = load_image(argv[1]);
    if (image == NULL) {
        return 1;
    }

    // Convert the image to ASCII art
    ascii_art(image);

    // Print the image to the console
    print_image(image);

    // Save the image to a file
    save_image("output.txt", image);

    // Free the memory allocated for the image
    for (int i = 0; i < image->height; i++) {
        free(image->data[i]);
    }
    free(image->data);
    free(image);

    return 0;
}