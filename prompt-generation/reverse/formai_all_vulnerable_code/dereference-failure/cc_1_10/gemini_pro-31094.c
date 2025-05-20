//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the image struct
typedef struct {
    int width;
    int height;
    int channels;
    unsigned char *data;
} Image;

// Load an image from a file
Image *load_image(char *filename) {
    // Open the file
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return NULL;
    }

    // Read the header
    int width, height, channels;
    if (fscanf(file, "%d %d %d\n", &width, &height, &channels) != 3) {
        fprintf(stderr, "Error reading header from file: %s\n", filename);
        fclose(file);
        return NULL;
    }

    // Allocate memory for the image
    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        fprintf(stderr, "Error allocating memory for image\n");
        fclose(file);
        return NULL;
    }

    // Set the image dimensions
    image->width = width;
    image->height = height;
    image->channels = channels;

    // Allocate memory for the image data
    image->data = malloc(width * height * channels);
    if (image->data == NULL) {
        fprintf(stderr, "Error allocating memory for image data\n");
        free(image);
        fclose(file);
        return NULL;
    }

    // Read the image data
    if (fread(image->data, width * height * channels, 1, file) != 1) {
        fprintf(stderr, "Error reading image data from file: %s\n", filename);
        free(image->data);
        free(image);
        fclose(file);
        return NULL;
    }

    // Close the file
    fclose(file);

    // Return the image
    return image;
}

// Save an image to a file
void save_image(char *filename, Image *image) {
    // Open the file
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return;
    }

    // Write the header
    fprintf(file, "%d %d %d\n", image->width, image->height, image->channels);

    // Write the image data
    fwrite(image->data, image->width * image->height * image->channels, 1, file);

    // Close the file
    fclose(file);
}

// Invert the colors of an image
void invert_colors(Image *image) {
    for (int i = 0; i < image->width * image->height * image->channels; i++) {
        image->data[i] = 255 - image->data[i];
    }
}

// Apply a grayscale filter to an image
void grayscale(Image *image) {
    for (int i = 0; i < image->width * image->height * image->channels; i += 3) {
        // Calculate the average of the red, green, and blue channels
        int average = (image->data[i] + image->data[i + 1] + image->data[i + 2]) / 3;

        // Set all three channels to the average
        image->data[i] = average;
        image->data[i + 1] = average;
        image->data[i + 2] = average;
    }
}

// Apply a sepia filter to an image
void sepia(Image *image) {
    for (int i = 0; i < image->width * image->height * image->channels; i += 3) {
        // Calculate the sepia values
        int sepiaRed = (image->data[i] * 0.393) + (image->data[i + 1] * 0.769) + (image->data[i + 2] * 0.189);
        int sepiaGreen = (image->data[i] * 0.349) + (image->data[i + 1] * 0.686) + (image->data[i + 2] * 0.168);
        int sepiaBlue = (image->data[i] * 0.272) + (image->data[i + 1] * 0.534) + (image->data[i + 2] * 0.131);

        // Clamp the sepia values to 0-255
        if (sepiaRed > 255) sepiaRed = 255;
        if (sepiaGreen > 255) sepiaGreen = 255;
        if (sepiaBlue > 255) sepiaBlue = 255;

        // Set the sepia values
        image->data[i] = sepiaRed;
        image->data[i + 1] = sepiaGreen;
        image->data[i + 2] = sepiaBlue;
    }
}

// Print the usage
void usage() {
    printf("Usage: image_editor <input_file> <output_file> <filter>\n");
    printf("Where <filter> can be one of the following:\n");
    printf("    - invert\n");
    printf("    - grayscale\n");
    printf("    - sepia\n");
}

// Main function
int main(int argc, char *argv[]) {
    // Parse the command line arguments
    if (argc != 4) {
        usage();
        return 1;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];
    char *filter = argv[3];

    // Load the input image
    Image *image = load_image(input_file);
    if (image == NULL) {
        return 1;
    }

    // Apply the filter
    if (strcmp(filter, "invert") == 0) {
        invert_colors(image);
    } else if (strcmp(filter, "grayscale") == 0) {
        grayscale(image);
    } else if (strcmp(filter, "sepia") == 0) {
        sepia(image);
    } else {
        printf("Invalid filter: %s\n", filter);
        usage();
        free(image);
        return 1;
    }

    // Save the output image
    save_image(output_file, image);

    // Free the image
    free(image->data);
    free(image);

    return 0;
}