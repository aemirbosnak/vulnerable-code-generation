//FormAI DATASET v1.0 Category: Image Steganography ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

// Function to get binary representation of integer value
char* decimalToBinary(int decimalValue)
{
    int binaryDigit, remainder, i;
    char* binaryString = (char*)malloc(sizeof(char) * 9);
    memset(binaryString, '0', 8);

    for (i = 7; i >= 0; i--)
    {
        binaryDigit = 1 << i;
        remainder = decimalValue % (binaryDigit * 2);
        if (remainder >= binaryDigit)
        {
            binaryString[7 - i] = '1';
        }
    }

    binaryString[8] = '\0';

    return binaryString;
}

// Function to get integer value of binary string
int binaryToDecimal(char* binaryString)
{
    int decimalValue = 0, i;

    for (i = 0; i < 8; i++)
    {
        if (binaryString[i] == '1')
        {
            decimalValue += 1 << (7 - i);
        }
    }

    return decimalValue;
}

// Function to hide message in an image using steganography
int hideMessage(char* imageName, char* message)
{
    // Open image file in read and write mode
    FILE* fp = fopen(imageName, "rb+");
    if (fp == NULL)
    {
        printf("Error: Could not open image file '%s'\n", imageName);
        return FALSE;
    }

    // Set the file pointer to the beginning of the image data
    fseek(fp, 54, SEEK_SET);

    // Calculate the maximum number of characters that can be hidden in the image
    int maxChars = (ftell(fp) - 54) / 3;

    int messageLength = strlen(message);
    if (messageLength > maxChars)
    {
        printf("Error: The message is too big to fit in the image\n");
        fclose(fp);
        return FALSE;
    }

    // Write the length of the message as binary to the first 16 bytes of the image
    char* binaryLength = decimalToBinary(messageLength);
    fseek(fp, 2, SEEK_SET);
    fputc(binaryToDecimal(binaryLength), fp);
    fputc(binaryToDecimal(binaryLength + 8), fp);

    // Write the message, one character at a time, to the image
    int i, j, pixelByte;
    char c, binaryChar[9], pixel[3] = { 0 };
    int messageIndex = 0;
    for (i = 0; i < maxChars; i++)
    {
        // Read the RGB values of the next pixel in the image
        fread(pixel, sizeof(char), 3, fp);

        for (j = 0; j < 3; j++)
        {
            // Convert the RGB value into binary
            binaryChar[8] = '\0';
            strncpy(binaryChar, decimalToBinary((int)pixel[j]), 8);

            // Check if the current bit of the binary representation of the pixel value matches the bit of the message to be hidden
            if (messageIndex < messageLength)
            {
                c = message[messageIndex];
                if (c != ' ')
                {
                    if (binaryChar[7] != c)
                    {
                        binaryChar[7] = c;
                    }
                    messageIndex++;
                }
            }

            // Convert the modified binary back to its integer representation
            pixelByte = binaryToDecimal(binaryChar);

            // Write the modified RGB value to the image
            pixel[j] = (char)pixelByte;
            fseek(fp, -1 * (3 - j), SEEK_CUR);
            fwrite(&pixel[j], sizeof(char), 1, fp);
        }

        if (messageIndex == messageLength)
        {
            break;
        }
    }

    // Close the image file
    fclose(fp);

    return TRUE;
}

// Function to reveal a hidden message in an image using steganography
char* revealMessage(char* imageName)
{
    // Open image file in read mode
    FILE* fp = fopen(imageName, "rb");
    if (fp == NULL)
    {
        printf("Error: Could not open image file '%s'\n", imageName);
        return NULL;
    }

    // Read the length of the hidden message from the first 16 bytes of the image
    fseek(fp, 2, SEEK_SET);
    char binaryLength[17] = { 0 };
    sprintf(binaryLength, "%s%s", decimalToBinary(fgetc(fp)), decimalToBinary(fgetc(fp)));

    int messageLength = binaryToDecimal(binaryLength);

    // Read the hidden message from the image
    int i, j, pixelByte, messageIndex = 0;
    char binaryChar[9], pixel[3] = { 0 }, * message = (char*)malloc(sizeof(char) * messageLength);
    memset(message, '\0', messageLength);

    for (i = 0; i < messageLength / 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            // Read the RGB value of the next pixel in the image
            fread(&pixel[j], sizeof(char), 1, fp);

            // Convert the RGB value into binary
            binaryChar[8] = '\0';
            strncpy(binaryChar, decimalToBinary((int)pixel[j]), 8);

            // Retrieve the hidden bit of the binary representation of the pixel value
            message[messageIndex++] = binaryChar[7];
        }
    }

    // Close the image file
    fclose(fp);

    return message;
}

int main()
{
    // Hide a message in an image
    char* imageName = "image.bmp";
    char* message = "Hello, world!";
    if (hideMessage(imageName, message) == TRUE)
    {
        printf("Message hidden in image '%s': %s\n", imageName, message);
    }

    // Reveal a hidden message from an image
    char* revealedMessage = revealMessage(imageName);
    if (revealedMessage != NULL)
    {
        printf("Hidden message in image '%s': %s\n", imageName, revealedMessage);
    }

    return 0;
}