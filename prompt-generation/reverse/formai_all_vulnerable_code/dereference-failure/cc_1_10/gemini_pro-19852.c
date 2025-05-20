//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Image representation
typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

// Load an image from a file
Image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        return NULL;
    }

    // Read the header
    int width, height;
    fscanf(fp, "P5 %d %d 255\n", &width, &height);

    // Allocate memory for the image data
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height);

    // Read the image data
    fread(image->data, 1, width * height, fp);

    // Close the file
    fclose(fp);

    return image;
}

// Free the memory allocated for an image
void free_image(Image *image) {
    free(image->data);
    free(image);
}

// Save an image to a file
void save_image(const char *filename, Image *image) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        return;
    }

    // Write the header
    fprintf(fp, "P5 %d %d 255\n", image->width, image->height);

    // Write the image data
    fwrite(image->data, 1, image->width * image->height, fp);

    // Close the file
    fclose(fp);
}

// Convert an image to grayscale
void grayscale(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int r = image->data[y * image->width + x];
            int g = image->data[y * image->width + x];
            int b = image->data[y * image->width + x];

            // Calculate the average of the RGB values
            int gray = (r + g + b) / 3;

            // Set the grayscale value
            image->data[y * image->width + x] = gray;
        }
    }
}

// Apply a Gaussian blur to an image
void gaussian_blur(Image *image, double sigma) {
    // Create a temporary image to store the blurred result
    Image *temp = malloc(sizeof(Image));
    temp->width = image->width;
    temp->height = image->height;
    temp->data = malloc(image->width * image->height);

    // Apply the Gaussian blur to each pixel in the image
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            // Calculate the Gaussian kernel for the pixel
            double kernel[3][3];
            double sum = 0.0;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    double x2 = (double)(x + i);
                    double y2 = (double)(y + j);
                    double exponent = -(x2 * x2 + y2 * y2) / (2 * sigma * sigma);
                    kernel[i + 1][j + 1] = exp(exponent) / (2 * M_PI * sigma * sigma);
                    sum += kernel[i + 1][j + 1];
                }
            }

            // Normalize the kernel
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    kernel[i][j] /= sum;
                }
            }

            // Apply the kernel to the pixel
            double blurred_value = 0.0;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int x2 = x + i;
                    int y2 = y + j;
                    if (x2 >= 0 && x2 < image->width && y2 >= 0 && y2 < image->height) {
                        blurred_value += kernel[i + 1][j + 1] * (double)image->data[y2 * image->width + x2];
                    }
                }
            }

            // Set the blurred value in the temporary image
            temp->data[y * image->width + x] = (unsigned char)round(blurred_value);
        }
    }

    // Copy the blurred image back to the original image
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            image->data[y * image->width + x] = temp->data[y * image->width + x];
        }
    }

    // Free the temporary image
    free_image(temp);
}

// Edge detection using the Sobel operator
void sobel_edge_detection(Image *image) {
    // Create a temporary image to store the edge detection result
    Image *temp = malloc(sizeof(Image));
    temp->width = image->width;
    temp->height = image->height;
    temp->data = malloc(image->width * image->height);

    // Apply the Sobel operator to each pixel in the image
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            // Calculate the gradients in the x and y directions
            int gx = 0;
            int gy = 0;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int x2 = x + i;
                    int y2 = y + j;
                    if (x2 >= 0 && x2 < image->width && y2 >= 0 && y2 < image->height) {
                        gx += j * image->data[y2 * image->width + x2];
                        gy += i * image->data[y2 * image->width + x2];
                    }
                }
            }

            // Calculate the gradient magnitude
            double magnitude = sqrt(gx * gx + gy * gy);

            // Threshold the gradient magnitude
            if (magnitude > 127) {
                temp->data[y * image->width + x] = 255;
            } else {
                temp->data[y * image->width + x] = 0;
            }
        }
    }

    // Copy the edge detection result back to the original image
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            image->data[y * image->width + x] = temp->data[y * image->width + x];
        }
    }

    // Free the temporary image
    free_image(temp);
}

// Main function
int main(int argc, char **argv) {
    // Check the number of arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_image> [<output_image>]\n", argv[0]);
        return 1;
    }

    // Load the input image
    Image *image = load_image(argv[1]);
    if (!image) {
        return 1;
    }

    // Convert the image to grayscale
    grayscale(image);

    // Apply a Gaussian blur to the image
    gaussian_blur(image, 1.0);

    // Apply edge detection to the image
    sobel_edge_detection(image);

    // Save the output image
    if (argc >= 3) {
        save_image(argv[2], image);
    } else {
        save_image("output.pgm", image);
    }

    // Free the image
    free_image(image);

    return 0;
}