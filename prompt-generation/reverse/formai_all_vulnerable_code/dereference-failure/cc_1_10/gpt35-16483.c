//FormAI DATASET v1.0 Category: Image Steganography ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  This program demonstrates an image steganography technique where a secret message is embedded
  in an image using the least significant bit (LSB) method.
*/

#define MAX_MESSAGE_LENGTH 1000000

// Function to convert an integer to binary
void intToBinary(int n, int binaryArray[])
{
    int i = 0;
    while (n > 0) {
        binaryArray[i] = n % 2;
        n = n / 2;
        i++;
    }
}

// Function to convert a binary array to an integer value
int binaryToInt(int binaryArray[], int length)
{
    int value = 0;
    int base = 1;
    for (int i = 0; i < length; i++) {
        value += binaryArray[i] * base;
        base *= 2;
    }
    return value;
}

// Function to write a binary string to a file
void writeBinaryStringToFile(char binaryString[], FILE* fp)
{
    int length = strlen(binaryString);
    for (int i = 0; i < length; i += 8) {
        char byteString[9] = { 0 };
        strncpy(byteString, binaryString+i, 8);
        int byte = binaryToInt(byteString, 8);
        fwrite(&byte, sizeof(char), 1, fp);
    }
}

int main()
{
    // Open the original image file and the output file for writing
    FILE* imageFile = fopen("image.bmp", "rb");
    FILE* outputFile = fopen("output.bmp", "wb");

    // Check if both files were opened successfully
    if (imageFile == NULL) {
        printf("Error: Could not open file 'image.bmp'\n");
        exit(1);
    }
    if (outputFile == NULL) {
        printf("Error: Could not open file 'output.bmp'\n");
        exit(1);
    }

    // Read the contents of the image file
    fseek(imageFile, 0, SEEK_END);
    int fileLength = ftell(imageFile);
    rewind(imageFile);
    char* buffer = (char*)malloc(sizeof(char) * fileLength);
    fread(buffer, sizeof(char), fileLength, imageFile);

    // Copy the header of the image to the output file
    fwrite(buffer, sizeof(char), 54, outputFile);

    // Get the length of the secret message to be embedded
    int messageLength;
    printf("Enter the length of the secret message (maximum %d characters): ", MAX_MESSAGE_LENGTH);
    scanf("%d", &messageLength);
    if (messageLength > MAX_MESSAGE_LENGTH) {
        printf("Error: Maximum message length exceeded\n");
        exit(1);
    }

    // Get the secret message from the user
    char message[MAX_MESSAGE_LENGTH];
    printf("Enter the secret message: ");
    scanf(" %[^\n]s", message);

    // Convert the length of the message to binary
    int binaryMessageLength[32] = { 0 };
    intToBinary(messageLength, binaryMessageLength);

    // Embed the length of the message in the LSBs of the first 32 pixels of the image
    int pixelIndex = 54;
    for (int i = 0; i < 32; i++) {
        if ((int)buffer[pixelIndex] % 2 == binaryMessageLength[i]) {
            // LSB is already equal to the bit we want to embed, do nothing
        } else {
            // LSB is not equal to the bit we want to embed, change it
            if ((int)buffer[pixelIndex] == 255) {
                // Pixel value is 255, decrement it by 1 to ensure that LSB can be changed
                buffer[pixelIndex]--;
            } else if ((int)buffer[pixelIndex] == 0) {
                // Pixel value is 0, increment it by 1 to ensure that LSB can be changed
                buffer[pixelIndex]++;
            }

            if ((int)buffer[pixelIndex] % 2 == 0) {
                // LSB is 0 and bit to embed is 1, increment pixel value by 1
                buffer[pixelIndex]++;
            } else {
                // LSB is 1 and bit to embed is 0, decrement pixel value by 1
                buffer[pixelIndex]--;
            }
        }
        pixelIndex += 3; // Move to the next pixel
    }

    // Embed the secret message in the LSBs of the remaining pixels of the image
    int messageIndex = 0;
    for (int i = pixelIndex; i < fileLength; i += 3) {
        if (messageIndex == messageLength) {
            // End of message, break out of loop
            break;
        }
        // Convert the current character of the message to binary
        int binaryMessageChar[8] = { 0 };
        intToBinary((int)message[messageIndex], binaryMessageChar);

        // Embed the binary value of the character in the LSBs of the three pixels
        for (int j = 0; j < 8; j++) {
            if ((int)buffer[i+j%3] % 2 == binaryMessageChar[j]) {
                // LSB is already equal to the bit we want to embed, do nothing
            } else {
                // LSB is not equal to the bit we want to embed, change it
                if ((int)buffer[i+j%3] == 255) {
                    // Pixel value is 255, decrement it by 1 to ensure that LSB can be changed
                    buffer[i+j%3]--;
                } else if ((int)buffer[i+j%3] == 0) {
                    // Pixel value is 0, increment it by 1 to ensure that LSB can be changed
                    buffer[i+j%3]++;
                }

                if ((int)buffer[i+j%3] % 2 == 0) {
                    // LSB is 0 and bit to embed is 1, increment pixel value by 1
                    buffer[i+j%3]++;
                } else {
                    // LSB is 1 and bit to embed is 0, decrement pixel value by 1
                    buffer[i+j%3]--;
                }
            }
        }
        messageIndex++;
    }

    // Write the modified image data to the output file
    fwrite(buffer, sizeof(char), fileLength, outputFile);

    // Close the files and free the memory
    fclose(imageFile);
    fclose(outputFile);
    free(buffer);

    // Display the secret message
    printf("The secret message has been successfully embedded in the image.\n");
    printf("The resulting image can be found in the file 'output.bmp'.\n\n");
    printf("The embedded message is: \"%s\"\n", message);

    return 0;
}