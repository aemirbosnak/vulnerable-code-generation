//FormAI DATASET v1.0 Category: Image Steganography ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Helper function to convert decimal to binary
void decimalToBinary(int decimal, int binary[])
{
    int i = 0;
    while (decimal > 0) {
        binary[i] = decimal % 2;
        i++;
        decimal = decimal / 2;
    }
}

// Helper function to convert binary to decimal
int binaryToDecimal(int binary[])
{
    int decimal = 0, i = 0, base = 1;
    while (i < 8) {
        decimal += binary[i] * base;
        base *= 2;
        i++;
    }
    return decimal;
}

int main()
{
    // Opening the input image file
    FILE *fileptr1 = fopen("input.bmp", "rb");
    if (fileptr1 == NULL) {
        printf("Cannot open file!\n");
        exit(0);
    }

    // Creating the output image file
    FILE *fileptr2 = fopen("output.bmp", "wb");
    if (fileptr2 == NULL) {
        printf("Cannot open file!\n");
        exit(0);
    }

    // Reading the header of the input image file
    unsigned char header[54] = {0};
    fread(header, sizeof(unsigned char), 54, fileptr1);

    // Writing the header of the output image file
    fwrite(header, sizeof(unsigned char), 54, fileptr2);

    // Finding the size of the input image data
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];
    int bit_depth = *(int *)&header[28];
    int size = width * height * bit_depth / 8;

    // Reading the input image data
    unsigned char data[size];
    fread(data, sizeof(unsigned char), size, fileptr1);

    // Closing the input image file
    fclose(fileptr1);

    // Reading the message to be hidden in the image
    char message[] = "Hello, world!";
    int message_length = sizeof(message) / sizeof(message[0]);

    // Hiding the message in the image
    int message_index = 0;
    for (int i = 0; i < size; i++) {
        int binary[8] = {0};
        decimalToBinary(data[i], binary);
        if (message_index < message_length) {
            binary[0] = message[message_index];
            message_index++;
        }
        data[i] = binaryToDecimal(binary);
    }

    // Writing the output image data
    fwrite(data, sizeof(unsigned char), size, fileptr2);

    // Closing the output image file
    fclose(fileptr2);

    printf("Message hidden in the image successfully!");

    return 0;
}