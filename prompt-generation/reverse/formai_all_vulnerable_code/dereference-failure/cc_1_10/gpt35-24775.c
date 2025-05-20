//FormAI DATASET v1.0 Category: Image Steganography ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define HEADER_SIZE 54

// Function to get the binary equivalent of a decimal number
int *decimalToBinary(int n)
{
    int *binary = (int *)malloc(8 * sizeof(int));
    int i = 0;
    while (n > 0)
    {
        binary[i++] = n % 2;
        n = n / 2;
    }
    // Add zeros to complete the 8 bits
    for (int j = i; j < 8; j++)
    {
        binary[j] = 0;
    }
    return binary;
}

// Function to get the decimal equivalent of a binary array
int binaryToDecimal(int *binary)
{
    int decimal = 0;
    int base = 1;
    for (int i = 7; i >= 0; i--)
    {
        decimal += binary[i] * base;
        base *= 2;
    }
    return decimal;
}

int main()
{
    FILE *fp = fopen("image.bmp", "rb+");
    if (fp == NULL)
    {
        printf("Error: Unable to open file\n");
        return 0;
    }

    // Read the header
    unsigned char header[HEADER_SIZE];
    fread(header, sizeof(unsigned char), HEADER_SIZE, fp);

    // Get the image width and height
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Calculate the number of pixels in the image
    int numPixels = width * height;

    // Allocate memory to store the pixel data
    unsigned char *pixels = (unsigned char *)malloc(sizeof(unsigned char) * numPixels * 3);

    // Read the pixel data
    fread(pixels, sizeof(unsigned char), numPixels * 3, fp);

    // Get the message to be hidden in the image
    char message[100];
    printf("Enter message to hide: ");
    scanf("%[^\n]", message);

    int messageLength = strlen(message);

    // Encode the message in the image
    int pixelIndex = 0;
    int bitIndex = 0;
    for (int i = 0; i < messageLength; i++)
    {
        // Get the binary equivalent of the current character
        int *binary = decimalToBinary(message[i]);

        // Embed the bits in the first 3 pixels
        for (int j = 0; j < 8; j++)
        {
            if (bitIndex % 3 == 0)
            {
                pixelIndex++;
            }
            int pixelValue = (int)pixels[pixelIndex];
            int bit = binary[j];

            // Modify the least significant bit
            pixelValue = (pixelValue & 0xFE) | bit;
            pixels[pixelIndex] = (unsigned char)pixelValue;

            bitIndex++;
        }
    }

    // Write the modified pixel data to the file
    fseek(fp, HEADER_SIZE, SEEK_SET);
    fwrite(pixels, sizeof(unsigned char), numPixels * 3, fp);

    fclose(fp);

    return 0;
}