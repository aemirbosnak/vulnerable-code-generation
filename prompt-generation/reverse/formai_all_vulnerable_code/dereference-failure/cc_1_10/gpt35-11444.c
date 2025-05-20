//FormAI DATASET v1.0 Category: Image Steganography ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define IMAGE_SIZE 1024 // Assuming the image is a 1024x1024 image
#define BIT_SIZE 8 // Each pixel will store 8 bits of data

// Function to convert decimal to binary
void decimalToBinary(int num, int* binaryNum)
{
    int i = 0;
    while(num > 0)
    {
        binaryNum[i] = num % 2;
        num = num / 2;
        i++;
    }
}

// Function to convert binary to decimal
int binaryToDecimal(int *binaryNum)
{
    int decimalNum = 0, power = 0;
    for(int i=BIT_SIZE-1; i>=0; i--)
    {
        decimalNum += binaryNum[i]*pow(2, power);
        power++;
    }
    return decimalNum;
}

// Function to hide a message in an image using LSB steganography
void hideMessage(int* imagePixels, int* binaryMsg, int msgSize)
{
    int pixelIndex = 0;
    for(int i=0; i<msgSize*BIT_SIZE; i++)
    {
        if(i%BIT_SIZE == 0)
        {
            pixelIndex++;
        }
        imagePixels[pixelIndex-1] &= ~1; // Set the least significant bit of the pixel to 0
        imagePixels[pixelIndex-1] |= binaryMsg[i]; // Set the least significant bit of the pixel to the next bit of the message
    }
}

// Function to retrieve a message from an image using LSB steganography
void retrieveMessage(int* imagePixels, int* binaryMsg, int msgSize)
{
    int pixelIndex = 0;
    for(int i=0; i<msgSize*BIT_SIZE; i++)
    {
        if(i%BIT_SIZE == 0)
        {
            pixelIndex++;
        }
        binaryMsg[i] = imagePixels[pixelIndex-1] & 1; // Retrieve the least significant bit of the pixel which stores the message bit
    }
}

int main()
{
    int *imagePixels = (int*)malloc(IMAGE_SIZE*IMAGE_SIZE*sizeof(int)); // Allocate memory for image

    // Populate the image pixels with some random values
    for(int i=0; i<IMAGE_SIZE*IMAGE_SIZE; i++)
    {
        imagePixels[i] = rand()%256; // Maximum value would be 255 as we are storing each pixel in 1 byte
    }

    char *message = "This is a secret message!"; // Message to be hidden
    int msgSize = strlen(message); // Retrieve message length in bytes
    int *binaryMessage = (int*)malloc(msgSize*BIT_SIZE*sizeof(int)); // Allocate memory to store binary representation of the message

    // Convert message to binary representation
    for(int i=0; i<msgSize; i++)
    {
        decimalToBinary((int)message[i], &binaryMessage[i*BIT_SIZE]);
    }

    printf("Before steganography:\n");
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            printf("%d ", imagePixels[i*IMAGE_SIZE+j]);
        }
        printf("\n");
    }

    hideMessage(imagePixels, binaryMessage, msgSize); // Hide message in the image

    printf("\nAfter steganography:\n");
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            printf("%d ", imagePixels[i*IMAGE_SIZE+j]);
        }
        printf("\n");
    }

    // Retrieve message from the image
    retrieveMessage(imagePixels, binaryMessage, msgSize);

    printf("\nRetrieved message: ");
    for(int i=0; i<msgSize; i++)
    {
        printf("%c", binaryToDecimal(&binaryMessage[i*BIT_SIZE]));
    }

    free(imagePixels);
    free(binaryMessage);
    return 0;
}