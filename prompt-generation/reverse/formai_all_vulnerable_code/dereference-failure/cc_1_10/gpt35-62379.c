//FormAI DATASET v1.0 Category: Image Steganography ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEADER_SIZE 54 // BMP header size
#define MAX_MESSAGE_SIZE 1024 // Maximum size of the hidden message

// Function to hide the message in the LSB of the pixels
void hideMessage(unsigned char *image, char *message)
{
    int messageLength = strlen(message);
    int imageIndex = HEADER_SIZE; // Starting index after the BMP header
    int bitIndex = 0;

    // For each pixel in the image
    for (int i = 0; i < messageLength; i++)
    {
        // For each bit in the message
        for (int j = 7; j >= 0; j--)
        {
            unsigned char bit = (message[i] >> j) & 1;
            // Set the LSB of the pixel to the bit
            image[imageIndex] = (image[imageIndex] & 0xFE) | bit;
            imageIndex++;
            bitIndex++;
        }
    }
}

// Function to extract the message from the LSB of the pixels
void extractMessage(unsigned char *image)
{
    char message[MAX_MESSAGE_SIZE] = {0};
    int messageIndex = 0;
    int imageIndex = HEADER_SIZE; // Starting index after the BMP header

    // While there is still message to extract
    while (messageIndex < MAX_MESSAGE_SIZE)
    {
        char character = 0;
        // For each bit in the character
        for (int i = 0; i < 8; i++)
        {
            // Extract the bit from the LSB of the pixel
            unsigned char bit = image[imageIndex] & 1;
            character = (character << 1) | bit;
            imageIndex++;
        }
        // If the character is null terminator, break out of loop
        if (character == '\0')
            break;
        message[messageIndex] = character;
        messageIndex++;
    }
    printf("Hidden message:\n%s\n", message);
}

int main()
{
    FILE *fp;
    unsigned char *image;
    char message[MAX_MESSAGE_SIZE];

    // Open the BMP file in binary mode
    fp = fopen("image.bmp", "rb");
    if (!fp)
    {
        printf("File not found.\n");
        return 1;
    }

    // Read the BMP header
    image = malloc(HEADER_SIZE);
    fread(image, 1, HEADER_SIZE, fp);

    // Read the hidden message from the user
    printf("Enter the message to hide in the image:\n");
    fgets(message, MAX_MESSAGE_SIZE, stdin);

    // Hide the message in the image
    hideMessage(image, message);

    // Write the modified image to a new file
    FILE *fp2;
    fp2 = fopen("output.bmp", "wb");
    fwrite(image, 1, HEADER_SIZE, fp2);

    // Free the image buffer
    free(image);

    // Close the files
    fclose(fp);
    fclose(fp2);

    // Open the modified image in binary mode
    fp = fopen("output.bmp", "rb");
    if (!fp)
    {
        printf("File not found.\n");
        return 1;
    }

    // Read the modified BMP header
    image = malloc(HEADER_SIZE);
    fread(image, 1, HEADER_SIZE, fp);

    // Extract the hidden message from the image
    extractMessage(image);

    // Free the image buffer
    free(image);

    // Close the file
    fclose(fp);

    return 0;
}