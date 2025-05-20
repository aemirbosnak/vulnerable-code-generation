//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_PIXEL_VALUE 255

// Function prototypes
void flip_horizontal(int rows, int cols, unsigned char image[rows][cols]);
void flip_vertical(int rows, int cols, unsigned char image[rows][cols]);
void adjust_brightness(int rows, int cols, unsigned char image[rows][cols], int brightness_level);
void adjust_contrast(int rows, int cols, unsigned char image[rows][cols], float contrast_level);

int main()
{
    // Get file name and open file
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter file name: ");
    scanf("%s", filename);
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read file header
    char format[3];
    int cols, rows, max_value;
    fscanf(file, "%s %d %d %d\n", format, &cols, &rows, &max_value);
    if (strcmp(format, "P5") != 0) {
        printf("Error: file format not supported.\n");
        exit(1);
    }
    if (max_value != MAX_PIXEL_VALUE) {
        printf("Error: invalid maximum pixel value.\n");
        exit(1);
    }

    // Read image data
    unsigned char image[rows][cols];
    fread(image, sizeof(unsigned char), rows*cols, file);

    // Print menu and get user choice
    int choice;
    printf("\nMenu:\n1. Flip horizontal\n2. Flip vertical\n3. Adjust brightness\n4. Adjust contrast\n\nEnter your choice: ");
    scanf("%d", &choice);

    // Perform selected task
    switch (choice) {
        case 1:
            flip_horizontal(rows, cols, image);
            break;
        case 2:
            flip_vertical(rows, cols, image);
            break;
        case 3:
            printf("Enter brightness level (between -255 and 255): ");
            int brightness_level;
            scanf("%d", &brightness_level);
            adjust_brightness(rows, cols, image, brightness_level);
            break;
        case 4:
            printf("Enter contrast level (between 0.1 and 10.0): ");
            float contrast_level;
            scanf("%f", &contrast_level);
            adjust_contrast(rows, cols, image, contrast_level);
            break;
        default:
            printf("Invalid choice.\n");
            exit(1);
    }

    // Generate output file name and save modified image
    char output_filename[MAX_FILENAME_LENGTH];
    strncpy(output_filename, filename, strlen(filename) - 4);
    strcat(output_filename, "_modified.pgm");
    FILE* output_file = fopen(output_filename, "wb");
    fprintf(output_file, "P5\n%d %d\n%d\n", cols, rows, MAX_PIXEL_VALUE);
    fwrite(image, sizeof(unsigned char), rows*cols, output_file);
    fclose(output_file);

    printf("Image processed successfully and saved as %s.\n", output_filename);

    return 0;
}

void flip_horizontal(int rows, int cols, unsigned char image[rows][cols])
{
    // Flip image horizontally
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols/2; j++) {
            unsigned char temp = image[i][j];
            image[i][j] = image[i][cols-j-1];
            image[i][cols-j-1] = temp;
        }
    }
}

void flip_vertical(int rows, int cols, unsigned char image[rows][cols])
{
    // Flip image vertically
    for (int i = 0; i < rows/2; i++) {
        for (int j = 0; j < cols; j++) {
            unsigned char temp = image[i][j];
            image[i][j] = image[rows-i-1][j];
            image[rows-i-1][j] = temp;
        }
    }
}

void adjust_brightness(int rows, int cols, unsigned char image[rows][cols], int brightness_level)
{
    // Adjust image brightness
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int new_value = (int) image[i][j] + brightness_level;
            if (new_value < 0) {
                new_value = 0;
            } else if (new_value > MAX_PIXEL_VALUE) {
                new_value = MAX_PIXEL_VALUE;
            }
            image[i][j] = (unsigned char) new_value;
        }
    }
}

void adjust_contrast(int rows, int cols, unsigned char image[rows][cols], float contrast_level)
{
    // Adjust image contrast
    float factor = (259 * (contrast_level + 255)) / (255 * (259 - contrast_level));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int new_value = (int) (factor * (image[i][j] - 128) + 128);
            if (new_value < 0) {
                new_value = 0;
            } else if (new_value > MAX_PIXEL_VALUE) {
                new_value = MAX_PIXEL_VALUE;
            }
            image[i][j] = (unsigned char) new_value;
        }
    }
}