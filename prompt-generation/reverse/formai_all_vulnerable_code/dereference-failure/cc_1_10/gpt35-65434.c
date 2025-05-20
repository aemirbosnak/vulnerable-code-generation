//FormAI DATASET v1.0 Category: Image Steganography ; Style: multiplayer
#include <stdio.h>

// Function to get the nth bit from the right
int getBit(unsigned char ch, int n)
{
    return (ch >> n) & 1;
}

// Function to set the nth bit from the right to 1
void setBit(unsigned char* ch, int n)
{
    *ch = *ch | (1 << n);
}

// Function to set the nth bit from the right to 0
void clearBit(unsigned char* ch, int n)
{
    *ch = *ch & ~(1 << n);
}

// Function to perform image steganography on a given image file
void imageSteganography(char* imgFileName, char* secretMsg)
{
    FILE* imgFile = fopen(imgFileName, "rb");

    // Checking if the image file exists or not
    if (!imgFile)
    {
        printf("Error: Could not open image file '%s'!\n", imgFileName);
        return;
    }

    // Getting the size of the image and calculating the maximum
    // number of characters that can be hidden in the image file
    fseek(imgFile, 0L, SEEK_END);
    int imgSize = ftell(imgFile);
    fseek(imgFile, 0L, SEEK_SET);
    int maxChars = imgSize / 8;

    // Checking if the secret message can be hidden in the image file
    if (strlen(secretMsg) > maxChars)
    {
        printf("Error: '%s' image file does not have enough space to hide the secret message!\n", imgFileName);
        fclose(imgFile);
        return;
    }

    // Reading the image data into a buffer
    unsigned char* imageData = (unsigned char*)calloc(imgSize, sizeof(unsigned char));
    fread(imageData, sizeof(unsigned char), imgSize, imgFile);
    fclose(imgFile);

    // Looping through each byte of the image data to hide the secret message
    int i, j;
    for (i = 0, j = 0; i < imgSize && j < strlen(secretMsg); i += 8, j++)
    {
        // Getting the current 8 bytes from the image data
        unsigned char ch1 = imageData[i];
        unsigned char ch2 = imageData[i + 1];
        unsigned char ch3 = imageData[i + 2];
        unsigned char ch4 = imageData[i + 3];
        unsigned char ch5 = imageData[i + 4];
        unsigned char ch6 = imageData[i + 5];
        unsigned char ch7 = imageData[i + 6];
        unsigned char ch8 = imageData[i + 7];

        // Setting the first bit of each byte to 0 to clear out any
        // existing hidden message
        clearBit(&ch1, 0);
        clearBit(&ch2, 0);
        clearBit(&ch3, 0);
        clearBit(&ch4, 0);
        clearBit(&ch5, 0);
        clearBit(&ch6, 0);
        clearBit(&ch7, 0);
        clearBit(&ch8, 0);

        // Setting the 8th bit of each byte to the next bit of the
        // secret message character
        if (getBit(secretMsg[j], 0))
            setBit(&ch1, 7);
        if (getBit(secretMsg[j], 1))
            setBit(&ch2, 7);
        if (getBit(secretMsg[j], 2))
            setBit(&ch3, 7);
        if (getBit(secretMsg[j], 3))
            setBit(&ch4, 7);
        if (getBit(secretMsg[j], 4))
            setBit(&ch5, 7);
        if (getBit(secretMsg[j], 5))
            setBit(&ch6, 7);
        if (getBit(secretMsg[j], 6))
            setBit(&ch7, 7);
        if (getBit(secretMsg[j], 7))
            setBit(&ch8, 7);

        // Putting the modified bytes back into the image data buffer
        imageData[i] = ch1;
        imageData[i + 1] = ch2;
        imageData[i + 2] = ch3;
        imageData[i + 3] = ch4;
        imageData[i + 4] = ch5;
        imageData[i + 5] = ch6;
        imageData[i + 6] = ch7;
        imageData[i + 7] = ch8;
    }

    // Writing the modified image data back to the image file
    imgFile = fopen(imgFileName, "wb");
    fwrite(imageData, sizeof(unsigned char), imgSize, imgFile);
    fclose(imgFile);
    free(imageData);

    printf("Secret message hidden successfully in '%s' image file!\n", imgFileName);
}

int main()
{
    char imgFileName[] = "image.png";
    char secretMsg[] = "This is a secret message!";

    imageSteganography(imgFileName, secretMsg);

    return 0;
}