//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define image struct
typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

// Load image from file
Image *load_image(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        printf("Error: Could not allocate memory for image\n");
        fclose(fp);
        return NULL;
    }

    // Read header
    fread(&image->width, sizeof(int), 1, fp);
    fread(&image->height, sizeof(int), 1, fp);

    // Read data
    image->data = malloc(image->width * image->height * sizeof(unsigned char));
    if (image->data == NULL) {
        printf("Error: Could not allocate memory for image data\n");
        fclose(fp);
        free(image);
        return NULL;
    }
    fread(image->data, sizeof(unsigned char), image->width * image->height, fp);

    fclose(fp);

    return image;
}

// Save image to file
void save_image(Image *image, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    // Write header
    fwrite(&image->width, sizeof(int), 1, fp);
    fwrite(&image->height, sizeof(int), 1, fp);

    // Write data
    fwrite(image->data, sizeof(unsigned char), image->width * image->height, fp);

    fclose(fp);
}

// Invert image colors
void invert_image(Image *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->data[i] = 255 - image->data[i];
    }
}

// Apply grayscale filter to image
void grayscale_image(Image *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        unsigned char gray = (image->data[i] + image->data[i + 1] + image->data[i + 2]) / 3;
        image->data[i] = gray;
        image->data[i + 1] = gray;
        image->data[i + 2] = gray;
    }
}

// Apply sepia filter to image
void sepia_image(Image *image) {
    for (int i = 0; i < image->width * image->height; i += 3) {
        unsigned char r = image->data[i];
        unsigned char g = image->data[i + 1];
        unsigned char b = image->data[i + 2];
        image->data[i] = (r * 0.393 + g * 0.769 + b * 0.189);
        image->data[i + 1] = (r * 0.349 + g * 0.686 + b * 0.168);
        image->data[i + 2] = (r * 0.272 + g * 0.534 + b * 0.131);
    }
}

// Apply blur filter to image
void blur_image(Image *image) {
    // Create temporary image for storing blurred data
    Image *temp = malloc(sizeof(Image));
    temp->width = image->width;
    temp->height = image->height;
    temp->data = malloc(image->width * image->height * sizeof(unsigned char));

    // Apply blur filter
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int sum = 0;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int nx = x + i;
                    int ny = y + j;
                    if (nx >= 0 && nx < image->width && ny >= 0 && ny < image->height) {
                        sum += image->data[ny * image->width + nx];
                    }
                }
            }
            temp->data[y * image->width + x] = sum / 9;
        }
    }

    // Copy blurred data to original image
    memcpy(image->data, temp->data, image->width * image->height * sizeof(unsigned char));

    // Free temporary image
    free(temp->data);
    free(temp);
}

// Print image data
void print_image(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            printf("%d ", image->data[y * image->width + x]);
        }
        printf("\n");
    }
}

// Free image memory
void free_image(Image *image) {
    free(image->data);
    free(image);
}

// Main function
int main() {
    // Load image from file
    Image *image = load_image("image.bmp");
    if (image == NULL) {
        return 1;
    }

    // Print original image data
    printf("Original image data:\n");
    print_image(image);

    // Invert image colors
    invert_image(image);

    // Print inverted image data
    printf("\nInverted image data:\n");
    print_image(image);

    // Apply grayscale filter to image
    grayscale_image(image);

    // Print grayscale image data
    printf("\nGrayscale image data:\n");
    print_image(image);

    // Apply sepia filter to image
    sepia_image(image);

    // Print sepia image data
    printf("\nSepia image data:\n");
    print_image(image);

    // Apply blur filter to image
    blur_image(image);

    // Print blurred image data
    printf("\nBlurred image data:\n");
    print_image(image);

    // Save image to file
    save_image(image, "edited_image.bmp");

    // Free image memory
    free_image(image);

    return 0;
}