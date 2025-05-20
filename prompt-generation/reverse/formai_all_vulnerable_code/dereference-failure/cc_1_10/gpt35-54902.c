//FormAI DATASET v1.0 Category: Image Steganography ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Function to hide a message in the image
void hideMessage(char* image_name, char* message)
{
    // Open the image file in binary mode
    FILE* fp = fopen(image_name, "rb");

    if (fp == NULL) {
        printf("Error: Could not open the image file");
        exit(1);
    }

    // Open a file to store the steganographic image
    FILE* fptr = fopen("stego_image.bmp", "wb");

    if (fptr == NULL) {
        printf("Error: Could not create the steganographic image file");
        exit(1);
    }

    int x, y, offset = 54, size, bitCounter = 0, byteCounter = 0;
    unsigned char data, bitMask = 1, bit;

    // Read the image header
    for (x = 0; x < offset; x++) {
        data = getc(fp);
        putc(data, fptr);
    }

    // Calculate the image size
    fseek(fp, 0, SEEK_END);
    size = ftell(fp) - offset;
    fseek(fp, offset, SEEK_SET);

    // Encode the message
    while (bitCounter < 8 * strlen(message)) {

        // Read a pixel from the image
        data = getc(fp);

        // Check if the pixel value is even
        if (data % 2 == 0) {
            bit = (message[byteCounter] & bitMask) >> bitCounter % 8;
        }
        // If the pixel value is odd
        else {
            bit = (message[byteCounter] & bitMask) << bitCounter % 8;
        }

        // Embed the bit in the pixel value
        data = data ^ bit;

        putc(data, fptr);

        bitCounter++;

        // If 8 bits are processed, move to the next byte
        if (bitCounter % 8 == 0) {
            byteCounter++;
        }
    }

    // Write the rest of the image
    while (size > 0) {
        data = getc(fp);
        putc(data, fptr);
        size--;
    }

    printf("Message hidden successfully in the image");

    // Close the files
    fclose(fp);
    fclose(fptr);
}

// Function to retrieve a message from the image
void retrieveMessage(char* image_name)
{
    // Open the steganographic image file in binary mode
    FILE* fp = fopen(image_name, "rb");

    if (fp == NULL) {
        printf("Error: Could not open the steganographic image file");
        exit(1);
    }

    int x, offset = 54, size, bitCounter = 0, byteCounter = 0;
    unsigned char data, bitMask = 1, bit;
    char message[500];

    // Read the image header
    for (x = 0; x < offset; x++) {
        data = getc(fp);
    }

    // Calculate the image size
    fseek(fp, 0, SEEK_END);
    size = ftell(fp) - offset;
    fseek(fp, offset, SEEK_SET);

    // Retrieve the message
    while (bitCounter < 8 * 500) {

        // Read a pixel from the image
        data = getc(fp);

        // Extract the bit from the pixel value
        bit = data & bitMask;

        // Store the bit in the message
        message[byteCounter] |= bit << bitCounter % 8;

        bitCounter++;

        // If 8 bits are processed, move to the next byte
        if (bitCounter % 8 == 0) {
            byteCounter++;
        }
    }

    printf("Retrieved message: %s", message);

    // Close the file
    fclose(fp);
}

int main()
{
    char image_name[] = "image.bmp";
    char message[] = "This is a secret message";

    // Hide the message in the image
    hideMessage(image_name, message);

    // Retrieve the message from the image
    retrieveMessage("stego_image.bmp");

    return 0;
}