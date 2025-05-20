//Falcon2-11B DATASET v1.0 Category: Image to ASCII art converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Helper function to count number of pixels in an image
int countPixels(char* image) {
    int count = 0;
    for (int i = 0; image[i]!= '\0'; i++) {
        if (image[i] == '1') {
            count++;
        }
    }
    return count;
}

// Main function to convert image to ASCII art
void convertToASCII(char* image) {
    int width = countPixels(image);
    int height = strlen(image);
    int x = 0, y = 0;
    int gap = 0;

    // Convert image to ASCII art
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (image[i * width + j] == '1') {
                printf("*");
            } else {
                printf(" ");
            }
            if (j!= width - 1) {
                printf(" ");
            }
        }
        printf("\n");
        y++;
        gap++;
    }
}

int main() {
    // Read image from user
    char* image = (char*)malloc(sizeof(char) * 100);
    printf("Enter the image in binary: ");
    fgets(image, 100, stdin);

    // Convert image to ASCII art
    convertToASCII(image);

    // Free memory
    free(image);

    return 0;
}