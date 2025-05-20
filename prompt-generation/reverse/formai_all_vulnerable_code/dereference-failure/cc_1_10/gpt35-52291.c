//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert the given image to ASCII art
void convertImgToAscii(char* imgPath, int width, int height, char* asciiChars)
{
    // Open the image file
    FILE * imgFile = fopen(imgPath, "rb");
    if (imgFile == NULL)
    {
        printf("ERROR: Failed to open image file!\n");
        exit(1);
    }

    // Allocate space for the pixel data
    unsigned char * image = (unsigned char *) malloc(width * height * sizeof(unsigned char));
    if (image == NULL)
    {
        printf("ERROR: Failed to allocate memory for image data!\n");
        exit(1);
    }

    // Read the pixel data from the image file
    fread(image, width * height, 1, imgFile);

    // Close the image file
    fclose(imgFile);

    // Convert the pixel data to ASCII characters based on their grayscale value
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculate the grayscale value of the current pixel
            int pixelValue = image[i * width + j];

            // Convert the grayscale value to the corresponding ASCII character
            char asciiChar = asciiChars[(pixelValue * strlen(asciiChars)) / 256];

            // Print the ASCII character to the console
            printf("%c", asciiChar);
        }

        // Print a newline character to move to the next row
        printf("\n");
    }

    // Free the memory allocated for the image data
    free(image);
}

int main()
{
    // Define the image path, width, height, and ASCII characters to use
    char * imgPath = "example_image.png";
    int width = 120;
    int height = 80;
    char * asciiChars = "@B%8WM#*oahkbdpqwmZO0QLCJYXzcvn/\|(){}[]?-_+~<>i!lI;:,\"^`'. ";

    // Convert the image to ASCII art
    convertImgToAscii(imgPath, width, height, asciiChars);

    // Exit the program with a success status
    return 0;
}