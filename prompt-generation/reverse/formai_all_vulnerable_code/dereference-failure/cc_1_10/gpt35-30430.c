//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define ASCII_ROWS 70
#define ASCII_COLS 120

// Function to convert image to ASCII art
void convertToASCII(char *imagePath, char *asciiArtPath)
{
    //Opening the image file
    FILE *imageFile = fopen(imagePath, "rb");

    if (imageFile == NULL)
    {
        printf("Unable to open image file.");
        return;
    }

    // Opening the file to write the ASCII art
    FILE *asciiArtFile = fopen(asciiArtPath, "w");

    if (asciiArtFile == NULL)
    {
        printf("Unable to write ASCII art.");
        fclose(imageFile);
        return;
    }

    // Defining characters to represent shades of gray
    char shades[] = {'#', '&', '$', '@', 'o', '*', ':', '-', '.', ' '};

    // Allocating memory to store RGB values
    unsigned char * rgb = (unsigned char *)malloc(3);

    // Reading each pixel from the image
    for (int i = 0; i < ASCII_ROWS; i++)
    {
        for (int j = 0; j < ASCII_COLS; j++)
        {
            // Reading RGB values of pixel
            fread(rgb, 1, 3, imageFile);

            //Calculating average intensity of RGB values
            int intensity = (rgb[0] + rgb[1] + rgb[2]) / 3;

            // Converting intensity to corresponding character shade
            int index = intensity * 10 / 255;

            // Writing the corresponding character shade to ASCII art file
            fprintf(asciiArtFile, "%c", shades[index]);
        }

        // Writing new line character to ASCII art file
        fprintf(asciiArtFile, "\n");
    }

    // Freeing allocated memory and closing files
    free(rgb);
    fclose(imageFile);
    fclose(asciiArtFile);
}

// Main function
int main()
{
    char imagePath[] = "image.jpg";
    char asciiArtPath[] = "ascii-art.txt";

    convertToASCII(imagePath, asciiArtPath);

    printf("ASCII art created successfully.");

    return 0;
}