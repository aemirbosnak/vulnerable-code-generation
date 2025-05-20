//FormAI DATASET v1.0 Category: Image Steganography ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary
void decToBinary(int num, int binaryArr[])
{
    int index = 0;
    while (num > 0) {
        binaryArr[index] = num % 2;
        num /= 2;
        index++;
    }
}

// Function to convert binary to decimal
int binaryToDec(int binaryArr[])
{
    int decimalNum = 0;
    for (int i = 7; i >= 0; i--) {
        if (binaryArr[i] == 1) {
            decimalNum += 1 << (7-i);
        }
    }
    return decimalNum;
}

int main()
{
    // Open the image in read mode
    FILE* fpImage = fopen("image.bmp", "rb");
    if (fpImage == NULL) {
        printf("Error opening image file\n");
        exit(0);
    }

    // Open the secret message file in read mode
    FILE* fpMessage = fopen("secret.txt", "r");
    if (fpMessage == NULL) {
        printf("Error opening secret message file\n");
        exit(0);
    }

    // Skip the BMP header
    fseek(fpImage, 54, SEEK_SET);

    // Read the secret message
    char message[1000];
    fgets(message, 1000, fpMessage);

    // Convert the secret message to binary and store in an array
    int binaryMessage[8000];
    int index = 0;
    for (int i = 0; message[i] != '\0'; i++) {
        decToBinary(message[i], &binaryMessage[index]);
        index += 8;
    }

    // Get the size of the image in bytes
    fseek(fpImage, 0L, SEEK_END);
    int imageSize = ftell(fpImage);

    // Move pointer back to beginning of image data
    fseek(fpImage, 54, SEEK_SET);

    // Write the binary message into the LSB of each pixel in the image
    int pixelData;
    int binaryPixel[8];
    for (int i = 0; i < imageSize; i++) {
        pixelData = fgetc(fpImage);
        decToBinary(pixelData, &binaryPixel[0]);
        if (index >= 8000) {
            break;
        }
        for (int j = 0; j < 8; j++) {
            binaryPixel[7-j] = binaryMessage[index];
            index++;
        }
        int newPixelData = binaryToDec(&binaryPixel[0]);
        fseek(fpImage, -1, SEEK_CUR);
        fputc(newPixelData, fpImage);
    }

    printf("Steganography Successful!\n");

    // Close the files
    fclose(fpImage);
    fclose(fpMessage);

    return 0;
}