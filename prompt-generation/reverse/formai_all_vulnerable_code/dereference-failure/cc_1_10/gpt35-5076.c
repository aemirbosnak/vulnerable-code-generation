//FormAI DATASET v1.0 Category: Image Steganography ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert decimal to binary
void decimalToBinary(int decimal, int *binaryArr, int size) {
    int i;
    for (i = size - 1; i >= 0; i--) {
        *(binaryArr + i) = decimal % 2;
        decimal /= 2;
    }
}

// function to convert binary to decimal
int binaryToDecimal(int *binaryArr, int size) {
    int decimal = 0, i;
    for (i = 0; i < size; i++) {
        decimal += *(binaryArr + i) * pow(2, (size - 1) - i);
    }
    return decimal;
}

// main function
int main() {
    FILE *originalImg, *stegoImg, *secretMsg;
    unsigned char header[54];

    // open the original image file
    originalImg = fopen("original.bmp", "rb");
    if (originalImg == NULL) {
        printf("Error: Unable to open original image file\n");
        exit(1);
    }

    // open the stego image file to write the encoded image
    stegoImg = fopen("stego.bmp", "wb");
    if (stegoImg == NULL) {
        printf("Error: Unable to open stego image file\n");
        exit(1);
    }

    // read the header of the original image
    fread(header, sizeof(unsigned char), 54, originalImg);

    // write the header of the original image to the stego image
    fwrite(header, sizeof(unsigned char), 54, stegoImg);

    // open the secret message file to be hidden in the image
    secretMsg = fopen("secret.txt", "rb");
    if (secretMsg == NULL) {
        printf("Error: Unable to open secret message file\n");
        exit(1);
    }

    // read the secret message from the file
    char secretMessage[100];
    fgets(secretMessage, 100, secretMsg);

    // convert secret message to binary
    int binaryMessage[strlen(secretMessage) * 8];
    int i, j, k = 0;
    for (i = 0; i < strlen(secretMessage); i++) {
        decimalToBinary(secretMessage[i], &binaryMessage[k], 8);
        k += 8;
    }

    // loop through the image pixel data, embedding the secret message.
    unsigned char pixel;
    int binaryPixel[8];
    int bit;
    i = 0;
    j = 0;
    k = 0;
    while (fread(&pixel, sizeof(unsigned char), 1, originalImg) == 1) {
        // convert pixel to binary
        decimalToBinary(pixel, binaryPixel, 8);

        // check if the binary message has been fully embedded
        if (k == strlen(secretMessage) * 8) {
            // write the remaining pixels from the original image to the stego image
            fwrite(&pixel, sizeof(unsigned char), 1, stegoImg);
        } else {
            // embed the message in the pixel data
            if (i < 54 && j < 3) {
                // skip over the header information for the first three pixels
                fwrite(&pixel, sizeof(unsigned char), 1, stegoImg);
                i++;
                if (i == 54 && j < 2) {
                    i = 0;
                    j++;
                }
            } else {
                bit = binaryMessage[k];
                binaryPixel[7] = bit;
                k++;
                pixel = binaryToDecimal(binaryPixel, 8);
                fwrite(&pixel, sizeof(unsigned char), 1, stegoImg);
            }
        }
    }

    // close the open files
    fclose(originalImg);
    fclose(stegoImg);
    fclose(secretMsg);

    printf("Secret message embedded successfully in the image\n");

    return 0;
}