//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// Function to flip an image (horizontally)
void flip_image(int width, int height, int image[height][width]) {
    int i, j, temp;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width / 2; j++) {
            temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
}

// Function to adjust brightness and contrast of an image
void adjust_image(int width, int height, int image[height][width], float brightness, float contrast) {
    int i, j, pixel;
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            pixel = image[i][j];
            pixel = (int)(factor * (pixel - 128) + 128 + brightness);
            if (pixel < 0) {
                pixel = 0;
            }
            if (pixel > 255) {
                pixel = 255;
            }
            image[i][j] = pixel;
        }
    }
}

// Main function
int main() {
    FILE *input_file, *output_file;
    int width, height, i, j, pixel;

    // Open input file
    input_file = fopen("input_file.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file!\n");
        return 1;
    }

    // Read image dimensions
    fscanf(input_file, "%d %d", &width, &height);

    // Allocate memory for image
    int **image = (int **)malloc(height * sizeof(int *));
    for (i = 0; i < height; i++) {
        image[i] = (int *)malloc(width * sizeof(int));
    }

    // Read image data from file
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            fscanf(input_file, "%d", &pixel);
            image[i][j] = pixel;
        }
    }

    // Close input file
    fclose(input_file);

    // Flip image
    flip_image(width, height, image);

    // Adjust image (brightness and contrast)
    adjust_image(width, height, image, 50.0, 50.0);

    // Open output file
    output_file = fopen("output_file.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file!\n");
        return 1;
    }

    // Write image dimensions to output file
    fprintf(output_file, "%d %d\n", width, height);

    // Write image data to output file
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            fprintf(output_file, "%d ", image[i][j]);
        }
        fprintf(output_file, "\n");
    }

    // Close output file
    fclose(output_file);

    // Free memory allocated for image
    for (i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}