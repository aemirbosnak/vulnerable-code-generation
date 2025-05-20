//FormAI DATASET v1.0 Category: Image Steganography ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Function to hide the message in the image
void hideData(FILE *fp, FILE *fp1, char *msg)
{
    char buffer[BUFFER_SIZE];
    int i = 0, j = 0, msgLen = strlen(msg);

    // Write the length of message to image
    fwrite(&msgLen, sizeof(int), 1, fp1);

    // Read the image data and hide the message
    while (fread(buffer, sizeof(char), BUFFER_SIZE, fp) != 0)
    {
        for (i = 0; i < BUFFER_SIZE; i += 2)
        {
            if (j < msgLen)
            {
                // Hide the message bit in the image pixel bit
                buffer[i] = (buffer[i] & 0xFE) | ((msg[j] >> 7) & 0x01);
                buffer[i + 1] = (buffer[i + 1] & 0xFE) | ((msg[j] >> 6) & 0x01);
                j++;
            }
        }

        // Write the modified pixel data to image
        fwrite(buffer, sizeof(char), BUFFER_SIZE, fp1);
    }

    printf("Message is successfully hidden inside the image.\n");
}

// Function to extract the data from the image
void extractData(FILE *fp, char *msg)
{
    char buffer[BUFFER_SIZE];
    int i = 0, j = 0, msgLen = 0;

    // Read the length of message from image
    fread(&msgLen, sizeof(int), 1, fp);

    // Read the image data and extract the message
    while (fread(buffer, sizeof(char), BUFFER_SIZE, fp) != 0)
    {
        for (i = 0; i < BUFFER_SIZE; i += 2)
        {
            if (j < msgLen)
            {
                // Extract the message bit from the image pixel bit
                msg[j] |= (buffer[i] & 0x01) << 7;
                msg[j] |= (buffer[i + 1] & 0x01) << 6;
                j++;
            }
        }
    }

    printf("Extracted message from the image is: %s\n", msg);
}

int main()
{
    char *msg = "Hello, this is a secret message!";
    char *image = "sample_image.bmp";

    FILE *fp, *fp1;

    // Open the image file in binary read mode
    fp = fopen(image, "rb");

    if (fp == NULL)
    {
        printf("Error: Unable to open image file!\n");
        exit(1);
    }

    // Create a new image file to hide the message
    fp1 = fopen("hidden_image.bmp", "wb");

    if (fp1 == NULL)
    {
        printf("Error: Unable to create image file to hide the message!\n");
        exit(1);
    }

    // Hide the message inside the image
    hideData(fp, fp1, msg);

    // Close the files
    fclose(fp);
    fclose(fp1);

    // Open the hidden image file in binary read mode
    fp = fopen("hidden_image.bmp", "rb");

    if (fp == NULL)
    {
        printf("Error: Unable to open hidden image file!\n");
        exit(1);
    }

    // Extract the message from the hidden image file
    extractData(fp, msg);

    // Close the file
    fclose(fp);

    return 0;
}