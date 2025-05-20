//FormAI DATASET v1.0 Category: Image Steganography ; Style: secure
#include <stdio.h>
#include <stdlib.h>

/* Function to convert decimal to binary */
long int decimalToBinary(int decimalNum)
{
    long int binaryNum = 0, remainder, i = 1;
    while (decimalNum != 0)
    {
        remainder = decimalNum % 2;
        decimalNum /= 2;
        binaryNum += remainder * i;
        i *= 10;
    }
    return binaryNum;
}

/* Function to convert binary to decimal */
int binaryToDecimal(long int binaryNum)
{
    int decimalNum = 0, i = 0, remainder;
    while (binaryNum != 0)
    {
        remainder = binaryNum % 10;
        binaryNum /= 10;
        decimalNum += remainder * pow(2, i);
        ++i;
    }
    return decimalNum;
}

/* Function to write the secret message to the image */
void writeSecretMessage(FILE *inputImage, FILE *outputImage, char *secretMessage)
{
    char imageHeader[54];
    fread(imageHeader, 1, 54, inputImage);
    fwrite(imageHeader, 1, 54, outputImage);

    // Convert the secret message into binary
    int i = 0;
    while (secretMessage[i])
    {
        long int binaryChar = decimalToBinary((int)secretMessage[i]);
        int j = 0;
        while (j < 8)
        {
            char pixel[3];
            fread(pixel, 1, 3, inputImage);
            if (binaryChar % 10)
            {
                if (pixel[0] % 2 == 0)
                    ++pixel[0];
            }
            else
            {
                if (pixel[0] % 2 == 1)
                    --pixel[0];
            }
            fwrite(pixel, 1, 3, outputImage);
            binaryChar /= 10;
            ++j;
        }
        ++i;
    }

    // Copy the remaining pixels from input to output
    char pixel[3];
    while (fread(pixel, 1, 3, inputImage) == 3)
    {
        fwrite(pixel, 1, 3, outputImage);
    }
}

/* Function to read the secret message from the image */
void readSecretMessage(FILE *inputImage)
{
    char pixel[3];
    char message[5000];
    int i = 0, j = 0;
    while (fread(pixel, 1, 3, inputImage) == 3)
    {
        message[j] = (char)(binaryToDecimal(pixel[0] % 2 == 0 ? pixel[0] : pixel[0] - 1));
        ++j;
        if (j == 5000)
            break;
    }
    message[j] = '\0';
    printf("The secret message is:\n%s\n", message);
}

int main()
{
    int choice;
    char inputFileName[50], outputFileName[50], secretMessage[5000];
    FILE *inputFile, *outputFile;

    printf("Welcome to Image Steganography!\n");
    printf("1. Write a secret message to an image\n");
    printf("2. Read a secret message from an image\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the name of the input image: ");
    scanf("%s", inputFileName);

    inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL)
    {
        printf("Error: Unable to open input image file.\n");
        return 1;
    }

    if (choice == 1)
    {
        printf("Enter the name of the output image: ");
        scanf("%s", outputFileName);

        printf("Enter the secret message: ");
        scanf(" %[^\n]s", secretMessage);

        outputFile = fopen(outputFileName, "wb");
        writeSecretMessage(inputFile, outputFile, secretMessage);
        printf("Secret message has been written to the image successfully.\n");
    }
    else if (choice == 2)
    {
        readSecretMessage(inputFile);
    }
    else
    {
        printf("Invalid choice.\n");
    }

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}