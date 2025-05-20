//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert an image to ASCII art
void convertImageToAscii(char *imageName, int imageWidth) {
    // Open the image file in binary mode
    FILE *imageFile = fopen(imageName, "rb");

    // If the file does not exist or cannot be opened, display an error message
    if (imageFile == NULL) {
        printf("Error: Could not open file %s\n", imageName);
        return;
    }

    // Get the size of the image
    fseek(imageFile, 0, SEEK_END);
    long int fileSize = ftell(imageFile);
    fseek(imageFile, 0, SEEK_SET);

    // Calculate the number of rows in the ASCII art image
    int numOfRows = fileSize / (3 * imageWidth);

    // Allocate memory for the image data and the ASCII art image
    char *imageData = (char*)malloc(fileSize * sizeof(char));
    char *asciiArt = (char*)malloc((numOfRows * imageWidth + numOfRows) * sizeof(char));

    // Read the image data into imageData
    fread(imageData, sizeof(char), fileSize, imageFile);

    // Close the image file
    fclose(imageFile);

    // Loop through the imageData and convert each pixel to a character in the ASCII art image
    int asciiArtIndex = 0;
    for (int i = 0; i < fileSize; i += 3) {
        int red = imageData[i];
        int green = imageData[i + 1];
        int blue = imageData[i + 2];
        int grayScale = (red + green + blue) / 3;
        char asciiChar;

        // Map the grayscale value to a character in the ASCII art image
        if (grayScale >= 240) {
            asciiChar = ' ';
        } else if (grayScale >= 210) {
            asciiChar = '.';
        } else if (grayScale >= 180) {
            asciiChar = '-';
        } else if (grayScale >= 150) {
            asciiChar = '+';
        } else if (grayScale >= 120) {
            asciiChar = '*';
        } else if (grayScale >= 90) {
            asciiChar = '#';
        } else if (grayScale >= 60) {
            asciiChar = '&';
        } else if (grayScale >= 30) {
            asciiChar = '%';
        } else {
            asciiChar = '@';
        }

        asciiArt[asciiArtIndex++] = asciiChar;

        // Add a line break if necessary
        if ((i / 3) % imageWidth == imageWidth - 1) {
            asciiArt[asciiArtIndex++] = '\n';
        }
    }

    // Display the ASCII art image
    printf("%s", asciiArt);

    // Free the memory allocated for the image data and ASCII art image
    free(imageData);
    free(asciiArt);
}

int main() {
    // Get the name of the image file and the width of the ASCII art image from the user
    char imageName[100];
    int imageWidth;

    printf("Enter the name of the image file (including file extension): ");
    scanf("%s", imageName);

    printf("Enter the width of the ASCII art image: ");
    scanf("%d", &imageWidth);

    // Convert the image to ASCII art
    convertImageToAscii(imageName, imageWidth);

    return 0;
}