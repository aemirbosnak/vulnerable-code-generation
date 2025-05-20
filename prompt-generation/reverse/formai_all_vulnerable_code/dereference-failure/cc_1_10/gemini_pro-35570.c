//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: Ada Lovelace
/**
    A tribute to Ada Lovelace, the first computer programmer.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Forward declarations
typedef struct _Image Image;
Image* image_new(int width, int height);
void image_free(Image* image);
void image_invert(Image* image);
void image_to_ascii(Image* image, char* output);

// Data structures
typedef struct _Image {
    int width;
    int height;
    unsigned char* data;
} Image;

// Function definitions
Image* image_new(int width, int height) {
    Image* image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height * sizeof(unsigned char));
    return image;
}

void image_free(Image* image) {
    free(image->data);
    free(image);
}

void image_invert(Image* image) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->data[i] = 255 - image->data[i];
    }
}

void image_to_ascii(Image* image, char* output) {
    char* ascii_chars = " .:-=+*#%@";
    int ascii_chars_length = strlen(ascii_chars);

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int index = image->data[y * image->width + x] * ascii_chars_length / 256;
            output[y * image->width + x] = ascii_chars[index];
        }
        output[y * image->width + image->width] = '\n';
    }
    output[image->height * image->width] = '\0';
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <input_image> <output_ascii>\n", argv[0]);
        return 1;
    }

    // Load the input image
    FILE* input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    int width, height;
    fread(&width, sizeof(int), 1, input_file);
    fread(&height, sizeof(int), 1, input_file);

    Image* image = image_new(width, height);
    fread(image->data, sizeof(unsigned char), width * height, input_file);
    fclose(input_file);

    // Invert the image
    image_invert(image);

    // Convert the image to ASCII art
    char* output = malloc((width + 1) * height + 1);
    image_to_ascii(image, output);

    // Save the ASCII art to the output file
    FILE* output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        free(output);
        image_free(image);
        return 1;
    }

    fprintf(output_file, "%s", output);
    fclose(output_file);

    // Clean up
    free(output);
    image_free(image);

    return 0;
}