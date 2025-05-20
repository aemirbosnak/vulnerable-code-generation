//FormAI DATASET v1.0 Category: Image Steganography ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function to convert decimal value to binary array
void decimalToBinary(int decimalValue, int binaryArray[], int size)
{
    int i = size-1;
    while(decimalValue > 0)
    {
        binaryArray[i] = decimalValue % 2;
        decimalValue /= 2;
        i--;
    }
    // padding remaining bits with 0
    while(i >= 0)
    {
        binaryArray[i] = 0;
        i--;
    }
}

// function to convert binary array to decimal value
int binaryToDecimal(int binaryArray[], int size)
{
    int decimalValue = 0;
    for(int i=0; i<size; i++)
    {
        decimalValue += binaryArray[i] * pow(2, size-1-i);
    }
    return decimalValue;
}

// function to change the least significant bit of a pixel value
int changeLSB(int pixelValue, int bitValue)
{
    if(bitValue == 0 && pixelValue % 2 == 1)
    {
        pixelValue--;
    }
    else if(bitValue == 1 && pixelValue % 2 == 0)
    {
        pixelValue++;
    }
    return pixelValue;
}

int main()
{
    // initializing variables and pointers
    FILE *imageFilePtr, *stegoImageFilePtr;
    unsigned char *imageData, *stegoImageData;
    int imageSize, imageWidth, imageHeight, bit;
    int secretDataSize, secretDataBinaryArray[16], extractDataBinaryArray[16];
    char *secretData, extractData;

    // reading the input image file
    imageFilePtr = fopen("inputImage.bmp", "rb");
    if(imageFilePtr == NULL)
    {
        printf("Error reading file.\n");
        exit(0);
    }

    // getting image dimensions and data size
    fseek(imageFilePtr, 0x0012, SEEK_SET);
    fread(&imageWidth, sizeof(imageWidth), 1, imageFilePtr);
    fread(&imageHeight, sizeof(imageHeight), 1, imageFilePtr);
    fseek(imageFilePtr, 0x0022, SEEK_SET);
    fread(&imageSize, sizeof(imageSize), 1, imageFilePtr);

    // allocating memory for image data
    imageData = (unsigned char*)malloc(imageSize*sizeof(unsigned char));

    // reading image data into the memory block
    fseek(imageFilePtr, 0x0036, SEEK_SET);
    fread(imageData, sizeof(unsigned char), imageSize, imageFilePtr);
    fclose(imageFilePtr);

    // reading secret data to be hidden
    secretData = (char*)malloc(16*sizeof(char));
    printf("Enter the secret data to be hidden:\n");
    fgets(secretData, 16, stdin);

    // converting the secret message to binary
    for(int i=0; i<16; i++)
    {
        decimalToBinary((int)secretData[i], &secretDataBinaryArray[i], 8);
    }

    // checking if data can be accommodated in the image
    if(imageSize < ((imageWidth*3)*imageHeight*8)+16)
    {
        printf("Error: secret message too long to be hidden in image.\n");
        exit(0);
    }

    // initializing counter variables
    int pixelCount = 0, bitCount = 0;

    // hiding secret data in the least significant bit of each pixel value
    while(pixelCount < imageSize)
    {
        for(int i=0; i<3; i++)
        {
            if(bitCount == 16)
            {
                // stop hiding data once all bits of secret message have been hidden
                break;
            }
            // covert current secret message bit to integer
            bit = secretDataBinaryArray[bitCount];
            // hide secret message bit in current pixel value's least significant bit
            imageData[pixelCount+i] = changeLSB(imageData[pixelCount+i], bit);
            // move to next bit of secret message
            bitCount++;
        }
        // move to next pixel
        pixelCount += 3;
    }

    // writing stego image data to file
    stegoImageData = (unsigned char*)malloc(imageSize*sizeof(unsigned char));
    for(int i=0; i<imageSize; i++)
    {
        stegoImageData[i] = imageData[i];
    }
    stegoImageFilePtr = fopen("stegoImage.bmp", "wb");
    if(stegoImageFilePtr == NULL)
    {
        printf("Error writing file.\n");
        exit(0);
    }
    fwrite(imageData, sizeof(unsigned char), imageSize, stegoImageFilePtr);
    fclose(stegoImageFilePtr);

    printf("Secret data successfully hidden in image!\n");

    // extracting hidden data from stego image
    printf("Extracting hidden data from stego image...\n");

    // initializing counter variables
    pixelCount = 0, bitCount = 0;
    // extracting hidden data from the least significant bit of each pixel value
    for(int i=0; i<16; i++)
    {
        for(int j=0; j<8; j++)
        {
            int pixelValue = stegoImageData[pixelCount];
            // extract least significant bit of pixel value and store in binary array for extracted data
            extractDataBinaryArray[bitCount] = pixelValue % 2;
            bitCount++;
            // move to next pixel value
            pixelCount++;
        }
    }
    // covert binary array to decimal to get original message
    extractData = (char)binaryToDecimal(extractDataBinaryArray, 16*8);
    printf("Extracted hidden data: %c\n", extractData);

    return 0;
}