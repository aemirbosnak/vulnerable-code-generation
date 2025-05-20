//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// The image dimensions struct
typedef struct
{
    int rows;
    int cols;
} ImageDimensions;

// Convert the color intensity to ASCII character
char intensityToChar(int intensity)
{
    const char *characters = " .:-=+*#%@";
    int numChars = strlen(characters);
    int intensityStep = 256 / numChars;
    int index = intensity / intensityStep;
    if (index >= numChars)
    {
        index = numChars - 1;
    }
    return characters[index];
}

// Convert the image to ASCII art
void convertImageToASCII(char *filename)
{
    FILE *fp;
    fp = fopen(filename, "rb");
    if (fp != NULL)
    {
        // Read the image dimensions
        ImageDimensions dimensions;
        fread(&dimensions, sizeof(dimensions), 1, fp);
        printf("Image dimensions: %d x %d\n", dimensions.rows, dimensions.cols);

        // Allocate memory for the image data
        int **imageData = malloc(dimensions.rows * sizeof(int *));
        for (int i = 0; i < dimensions.rows; i++)
        {
            imageData[i] = malloc(dimensions.cols * sizeof(int));
        }

        // Read the image data
        for (int i = 0; i < dimensions.rows; i++)
        {
            for (int j = 0; j < dimensions.cols; j++)
            {
                int intensity;
                fread(&intensity, sizeof(intensity), 1, fp);
                imageData[i][j] = intensity;
            }
        }

        // Convert the image data to ASCII art
        for (int i = 0; i < dimensions.rows; i++)
        {
            for (int j = 0; j < dimensions.cols; j++)
            {
                char character = intensityToChar(imageData[i][j]);
                printf("%c", character);
            }
            printf("\n");
        }

        // Free the memory
        for (int i = 0; i < dimensions.rows; i++)
        {
            free(imageData[i]);
        }
        free(imageData);

        // Close the file
        fclose(fp);
    }
}

int main(void)
{
    convertImageToASCII("test_image.dat");
    return 0;
}