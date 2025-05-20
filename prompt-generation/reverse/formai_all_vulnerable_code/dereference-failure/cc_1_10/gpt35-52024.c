//FormAI DATASET v1.0 Category: Image Steganography ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Function to get the bits from the given character
void charToBits(char c, int *bits)
{
    for(int i=7; i>=0; i--)
    {
        bits[i] = c % 2;
        c /= 2;
    }
}

// Function to get the character from the given bits
char bitsToChar(int *bits)
{
    int c = 0;
    for(int i=0; i<8; i++)
    {
        c = c*2 + bits[i];
    }
    return (char)c;
}

// Main function
int main(int argc, char *argv[])
{
    FILE *fpIn, *fpOut;
    char *inFileName, *outFileName;
    char *message;
    int messageSize, imageSize;
    int *bits, *imageBits;

    // Check for command line arguments
    if(argc < 4)
    {
        printf("Usage: %s <input image> <output image> <message>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get the input image file name
    inFileName = argv[1];

    // Open the input image file
    fpIn = fopen(inFileName, "rb");
    if(fpIn == NULL)
    {
        printf("Unable to open file %s\n", inFileName);
        exit(EXIT_FAILURE);
    }

    // Get the output image file name
    outFileName = argv[2];

    // Open the output image file
    fpOut = fopen(outFileName, "wb");
    if(fpOut == NULL)
    {
        printf("Unable to create file %s\n", outFileName);
        exit(EXIT_FAILURE);
    }

    // Get the message to hide
    message = argv[3];

    // Calculate the size of the message
    messageSize = 0;
    while(*(message+messageSize) != '\0')
    {
        messageSize++;
    }

    // Allocate memory for the bits of the message
    bits = (int*)calloc(messageSize*8, sizeof(int));
    if(bits == NULL)
    {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    // Convert message to bits
    for(int i=0; i<messageSize; i++)
    {
        charToBits(*(message+i), bits+(i*8));
    }

    // Calculate the size of the input image
    fseek(fpIn, 0L, SEEK_END);
    imageSize = ftell(fpIn);

    // Go to the beginning of the input image
    fseek(fpIn, 0L, SEEK_SET);

    // Allocate memory for the bits of the input image
    imageBits = (int*)calloc(imageSize*8, sizeof(int));
    if(imageBits == NULL)
    {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    // Read the input image
    int count = 0;
    unsigned char byte;
    while(fread(&byte, sizeof(unsigned char), 1, fpIn) == 1)
    {
        charToBits(byte, imageBits+(count*8));
        count++;
    }

    // Hide the message in the input image
    int index = 0;
    for(int i=0; i<messageSize*8; i++)
    {
        if(bits[i] == 0 && imageBits[index]%2 == 1)
        {
            imageBits[index]--;
        }
        else if(bits[i] == 1 && imageBits[index]%2 == 0)
        {
            imageBits[index]++;
        }
        index++;
        if(index%8 == 0 && i != messageSize*8-1)
        {
            index++;
        }
    }

    // Write the output image
    for(int i=0; i<imageSize*8; i+=8)
    {
        byte = bitsToChar(imageBits+i);
        fwrite(&byte, sizeof(unsigned char), 1, fpOut);
    }

    printf("Message hidden successfully!\n");

    // Close the files and free the memory
    fclose(fpIn);
    fclose(fpOut);
    free(bits);
    free(imageBits);

    return 0;
}