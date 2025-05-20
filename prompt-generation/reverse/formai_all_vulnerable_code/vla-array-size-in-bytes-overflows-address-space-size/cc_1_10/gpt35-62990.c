//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read the image file, convert it to ASCII art and print it out
void ascii_conversion(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: The file \"%s\" couldn't be found\n", filename);
        return;
    }

    // Determine the width and height of the image
    char type[3];
    int width, height;
    fscanf(file, "%s", type);
    fscanf(file, "%d%d", &width, &height);

    // Initialize an array of characters for the ASCII art
    char ascii_art[height][width];

    // Read in the RGB values of each pixel and convert to ASCII character
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int r, g, b;
            fscanf(file, "%d%d%d", &r, &g, &b);

            // Convert the pixel to grayscale and map to ASCII character
            int intensity = (0.2126 * r) + (0.7152 * g) + (0.0722 * b);
            if (intensity >= 230) {
                ascii_art[i][j] = ' ';
            } else if (intensity >= 200) {
                ascii_art[i][j] = '.';
            } else if (intensity >= 180) {
                ascii_art[i][j] = '*';
            } else if (intensity >= 160) {
                ascii_art[i][j] = ':';
            } else if (intensity >= 130) {
                ascii_art[i][j] = 'o';
            } else if (intensity >= 100) {
                ascii_art[i][j] = '&';
            } else if (intensity >= 70) {
                ascii_art[i][j] = '8';
            } else if (intensity >= 50) {
                ascii_art[i][j] = '#';
            } else {
                ascii_art[i][j] = '@';
            }
        }
    }

    // Print out the ASCII art
    printf("---------------------------\n");
    printf("Image converted to ASCII art\n");
    printf("---------------------------\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", ascii_art[i][j]);
        }
        printf("\n");
    }

    fclose(file);
}

int main() {
    printf("The game is afoot! Let's convert an image to ASCII art!\n");
    printf("Please enter the name of the image file you'd like to convert: ");

    // Read in the filename from the user
    char filename[100];
    fgets(filename, 100, stdin);
    filename[strcspn(filename, "\r\n")] = 0;

    // Convert the image to ASCII art and print it out
    ascii_conversion(filename);

    printf("Elementary, my dear Watson!\n");

    return 0;
}