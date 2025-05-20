//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_IMAGE_SIZE 4096 // Maximum image size
#define MAX_BRIGHTNESS 255 // Maximum brightness value
#define MIN_BRIGHTNESS 0 // Minimum brightness value

int main(int argc, char* argv[]) {

    // Check for correct arguments
    if (argc != 5) {
        printf("Usage: %s <input file> <output file> <brightness> <contrast>\n", argv[0]);
        return 1;
    }

    // Open input and output files
    FILE* infile = fopen(argv[1], "r");
    FILE* outfile = fopen(argv[2], "w");

    // Check if files have been opened successfully
    if (infile == NULL || outfile == NULL) {
        printf("Error opening files\n");
        return 1;
    }

    // Read image header
    char line[MAX_IMAGE_SIZE];
    int width = 0, height = 0, max_val = 0;

    fgets(line, MAX_IMAGE_SIZE, infile);
    if (strchr(line, '#'))
        do { fgets(line, MAX_IMAGE_SIZE, infile); } while (strchr(line, '#'));
    sscanf(line, "%d %d", &width, &height);

    fgets(line, MAX_IMAGE_SIZE, infile);
    if (strchr(line, '#'))
        do { fgets(line, MAX_IMAGE_SIZE, infile); } while (strchr(line, '#'));
    sscanf(line, "%d", &max_val);

    // Check if image size is within limits
    if (width > MAX_IMAGE_SIZE || height > MAX_IMAGE_SIZE) {
        printf("Error: Image size is too large\n");
        return 1;
    }

    // Allocate memory for image data
    unsigned char** img_data = (unsigned char**)malloc(height * sizeof(unsigned char*));
    for (int i = 0; i < height; i++)
        img_data[i] = (unsigned char*)malloc(width * sizeof(unsigned char));

    // Read image data into array
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            img_data[i][j] = fgetc(infile);

    // Apply brightness and contrast adjustments to image
    int brightness = atoi(argv[3]);
    int contrast = atoi(argv[4]);

    // Check if brightness value is within limits
    if (brightness < MIN_BRIGHTNESS || brightness > MAX_BRIGHTNESS) {
        printf("Error: Brightness value is out of range\n");
        return 1;
    }

    // Check if contrast value is within limits
    if (contrast < MIN_BRIGHTNESS || contrast > MAX_BRIGHTNESS) {
        printf("Error: Contrast value is out of range\n");
        return 1;
    }

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++) {
            // Adjust brightness
            int new_val = img_data[i][j] + brightness;

            // Adjust contrast
            new_val = (((new_val - MIN_BRIGHTNESS) * contrast) / (MAX_BRIGHTNESS - MIN_BRIGHTNESS)) + MIN_BRIGHTNESS;

            // Set new pixel value
            img_data[i][j] = (unsigned char)new_val;
        }

    // Write output image header
    fprintf(outfile, "P5\n%d %d\n%d\n", width, height, max_val);

    // Write output image data
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            fputc(img_data[i][j], outfile);

    // Close input and output files
    fclose(infile);
    fclose(outfile);

    // Free memory allocated for image data
    for (int i = 0; i < height; i++)
        free(img_data[i]);
    free(img_data);

    return 0;
}