//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 200
#define MAX_HEIGHT 200

unsigned char img[MAX_HEIGHT][MAX_WIDTH];   // 2D array to store the image
char ascii_map[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'}; // ASCII characters to represent different shades of the image

int main(int argc, char *argv[]) {
    if (argc != 2) {   // Check if correct number of arguments are provided
        printf("Usage: ./image2ascii <image_file_path>\n");
        exit(1);
    }

    FILE *fp = fopen(argv[1], "rb");
    if (!fp) {   // Check if file exists
        printf("Error: File not found.\n");
        exit(1);
    }

    // Read and store the image dimensions
    int width, height, max_color;
    char format[5];
    fscanf(fp, "%s %d %d %d", format, &width, &height, &max_color);
 
    if (strcmp(format, "P5") != 0 || width > MAX_WIDTH || height > MAX_HEIGHT) {  // Check if PGM format is correct and image size is within the limit
        printf("Error: Invalid image format or size.\n");
        exit(1);
    }

    // Read and store the image data
    fread(img, sizeof(unsigned char), height * width, fp);
    fclose(fp);

    // Convert the image data to ASCII art
    printf("\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int index = img[i][j] * 10 / 255;   // Calculate the index based on the shade of the pixel
            printf("%c", ascii_map[index]);   // Print the corresponding ASCII character
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}