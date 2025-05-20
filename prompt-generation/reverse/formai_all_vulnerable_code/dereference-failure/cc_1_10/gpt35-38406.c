//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: mathematical
#include <stdio.h>

/*
 * A function that receives an RGB pixel and returns its corresponding grayscale value
 * using the following mathematical formula: Gray = 0.299*R + 0.587*G + 0.114*B
 */
int getGrayScaleValue(int R, int G, int B)
{
    return (int)(0.299 * R + 0.587 * G + 0.114 * B);
}

/*
 * A function that receives a grayscale value and returns the corresponding ASCII character
 * from the ASCII character set. The ASCII characters are chosen to represent different
 * shades of gray, from ' ' (white) to '@' (black).
 */
char getASCIICharacter(int grayValue)
{
    // The selected ASCII characters are based on the following grayscale ranges:
    // - [0, 25]: '@'
    // - [26, 51]: '#'
    // - [52, 77]: '8'
    // - [78, 103]: '&'
    // - [104, 129]: 'o'
    // - [130, 155]: ':'
    // - [156, 181]: '*'
    // - [182, 207]: '.'
    // - [208, 233]: ' '
    // - [234, 255]: ' '

    if (grayValue >= 0 && grayValue <= 25)
    {
        return '@';
    }
    else if (grayValue >= 26 && grayValue <= 51)
    {
        return '#';
    }
    else if (grayValue >= 52 && grayValue <= 77)
    {
        return '8';
    }
    else if (grayValue >= 78 && grayValue <= 103)
    {
        return '&';
    }
    else if (grayValue >= 104 && grayValue <= 129)
    {
        return 'o';
    }
    else if (grayValue >= 130 && grayValue <= 155)
    {
        return ':';
    }
    else if (grayValue >= 156 && grayValue <= 181)
    {
        return '*';
    }
    else if (grayValue >= 182 && grayValue <= 207)
    {
        return '.';
    }
    else if (grayValue >= 208 && grayValue <= 233)
    {
        return ' ';
    }
    else // (grayValue >= 234 && grayValue <= 255)
    {
        return ' ';
    }
}

/*
 * The main function of the program.
 */
int main()
{
    // The input image file:
    FILE* imageFile = fopen("input.ppm", "rb");

    // Check if the file was opened successfully:
    if (imageFile == NULL)
    {
        printf("Unable to open input file.\n");
        return -1;
    }

    // Read the header of the input image file until the end of the header is reached:
    char format[3];
    int width, height, maxColorValue;
    fscanf(imageFile, "%s\n%d %d\n%d\n", format, &width, &height, &maxColorValue);
    while (fgetc(imageFile) != '\n');

    // Print the image dimensions:
    printf("Input image dimensions: %dx%d pixels.\n", width, height);

    // Allocate memory for the pixels array:
    int **pixels = (int**)malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++)
    {
        pixels[i] = (int*)malloc(width * sizeof(int));
    }

    // Read the RGB values of each pixel in the input image file and convert them to grayscale
    // using the getGrayScaleValue function. Then, convert the grayscale values to ASCII characters
    // using the getASCIICharacter function and print them to the console.
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int R, G, B;
            fread(&R, 1, 1, imageFile);
            fread(&G, 1, 1, imageFile);
            fread(&B, 1, 1, imageFile);
            int grayValue = getGrayScaleValue(R, G, B);
            char asciiCharacter = getASCIICharacter(grayValue);
            printf("%c", asciiCharacter);
            pixels[i][j] = grayValue;
        }
        printf("\n");
    }

    // Free the memory allocated for the pixels array and close the input image file:
    for (int i = 0; i < height; i++)
    {
        free(pixels[i]);
    }
    free(pixels);
    fclose(imageFile);

    return 0;
}