//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 50
#define MAX_PIXEL_VALUE 255

int flipImage(int **pixels, int width, int height) {
    // Allocate memory for the flipped image
    int **flipped = malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++) {
        flipped[i] = malloc(sizeof(int) * width);
    }

    // Flip the image
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            flipped[row][col] = pixels[row][width - col - 1];
        }
    }

    // Update the original image with the flipped image
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            pixels[row][col] = flipped[row][col];
        }
    }

    // Free memory used by the flipped image
    for (int i = 0; i < height; i++) {
        free(flipped[i]);
    }
    free(flipped);

    return 0;
}

int adjustBrightness(int **pixels, int width, int height, int adjustment) {
    // Adjust the brightness of the image
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            pixels[row][col] = pixels[row][col] + adjustment;

            // Keep pixel values within the range of 0 to MAX_PIXEL_VALUE
            if (pixels[row][col] < 0) {
                pixels[row][col] = 0;
            } else if (pixels[row][col] > MAX_PIXEL_VALUE) {
                pixels[row][col] = MAX_PIXEL_VALUE;
            }
        }
    }

    return 0;
}

int adjustContrast(int **pixels, int width, int height, double adjustment) {
    // Adjust the contrast of the image
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            double newPixelValue = (pixels[row][col] - (MAX_PIXEL_VALUE / 2)) * adjustment + (MAX_PIXEL_VALUE / 2);

            // Keep pixel values within the range of 0 to MAX_PIXEL_VALUE
            if (newPixelValue < 0) {
                newPixelValue = 0;
            } else if (newPixelValue > MAX_PIXEL_VALUE) {
                newPixelValue = MAX_PIXEL_VALUE;
            }

            pixels[row][col] = (int) newPixelValue;
        }
    }

    return 0;
}

int main() {
    char file_name[MAX_FILE_NAME];

    // Get the file name of the image
    printf("Enter the file name of the image: ");
    scanf("%s", file_name);

    // Open the image file
    FILE *fp = fopen(file_name, "r");

    if (fp == NULL) {
        printf("Could not open file %s", file_name);
        return 1;
    }

    int width, height;

    // Get the width and height of the image
    fscanf(fp, "%d %d", &width, &height);

    int **pixels = malloc(sizeof(int *) * height);

    for (int i = 0; i < height; i++) {
        pixels[i] = malloc(sizeof(int) * width);
    }

    // Get the pixel values of the image
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            fscanf(fp, "%d", &pixels[row][col]);
        }
    }

    fclose(fp);

    int choice;

    // Display the menu
    printf("\nMenu\n");
    printf("1. Flip image horizontally\n");
    printf("2. Adjust brightness\n");
    printf("3. Adjust contrast\n");
    printf("4. Save image and exit\n");

    do {
        // Get the user's choice
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Flip the image horizontally
                flipImage(pixels, width, height);
                printf("Image flipped horizontally\n");
                break;
            case 2: {
                // Adjust the brightness of the image
                int adjustment;
                printf("Enter the brightness adjustment (-255 to 255): ");
                scanf("%d", &adjustment);
                adjustBrightness(pixels, width, height, adjustment);
                printf("Brightness adjusted\n");
                break;
            }
            case 3: {
                // Adjust the contrast of the image
                double adjustment;
                printf("Enter the contrast adjustment (0.1 to 10.0): ");
                scanf("%lf", &adjustment);
                adjustContrast(pixels, width, height, adjustment);
                printf("Contrast adjusted\n");
                break;
            }
            case 4: {
                // Save the image and exit the program
                char output_file_name[MAX_FILE_NAME];
                printf("Enter the output file name: ");
                scanf("%s", output_file_name);

                FILE *output_file = fopen(output_file_name, "w");

                if (output_file == NULL) {
                    printf("Could not open file %s", output_file_name);
                    return 1;
                }

                fprintf(output_file, "%d %d\n", width, height);

                for (int row = 0; row < height; row++) {
                    for (int col = 0; col < width; col++) {
                        fprintf(output_file, "%d ", pixels[row][col]);
                    }
                    fprintf(output_file, "\n");
                }

                fclose(output_file);
                printf("Image saved\n");
                return 0;
            }
            default:
                printf("Invalid choice, please try again\n");
                break;
        }
    } while (1);

    return 0;
}