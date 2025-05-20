//FormAI DATASET v1.0 Category: Image Steganography ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 8 // number of bits in a byte

// function to get the binary representation of a number
void getBinary(unsigned char num, char *binary) {
    int i;
    for (i = SIZE - 1; i >= 0; i--) {
        binary[i] = (num % 2) ? '1' : '0';
        num = num / 2;
    }
}

// function to get the decimal representation of a binary string
unsigned char getDecimal(const char *binary) {
    unsigned char num = 0;
    int i;
    for (i = 0; i < SIZE; i++) {
        num = num * 2 + (binary[i] - '0');
    }
    return num;
}

// function to hide a message in an image
void hideMessage(FILE *img, FILE *out, const char *msg, int *msgLength) {
    // get the image size and skip the header
    fseek(img, 0, SEEK_END);
    int imgSize = ftell(img) - 54;
    fseek(img, 54, SEEK_SET);

    // calculate the number of pixels required to hide the message
    int numPixels = (strlen(msg) + 1) * SIZE / 3;

    // check if the image is large enough to hide the message
    if (numPixels > imgSize) {
        fprintf(stderr, "error: message is too large for the image.\n");
        exit(EXIT_FAILURE);
    }

    // read each pixel in the image
    unsigned char pixel[3];
    int pixelCount = 0;
    int bitCount = 0;
    bool endOfMessage = false;
    while (fread(pixel, sizeof(pixel), 1, img)) {
        // get the binary representation of each pixel component
        char redBinary[SIZE], greenBinary[SIZE], blueBinary[SIZE];
        getBinary(pixel[2], redBinary);
        getBinary(pixel[1], greenBinary);
        getBinary(pixel[0], blueBinary);

        // hide the message in the least significant bit of each component
        if (!endOfMessage) {
            // hide the message bits in the red component
            redBinary[SIZE - 1] = msg[bitCount++];
            if (bitCount == *msgLength * SIZE) {
                redBinary[SIZE - 2] = '1';
                endOfMessage = true;
                *msgLength = bitCount / SIZE;
            }

            // hide the message bits in the green component
            if (!endOfMessage) {
                greenBinary[SIZE - 1] = msg[bitCount++];
                if (bitCount == *msgLength * SIZE) {
                    greenBinary[SIZE - 2] = '1';
                    endOfMessage = true;
                    *msgLength = bitCount / SIZE;
                }
            }

            // hide the message bits in the blue component
            if (!endOfMessage) {
                blueBinary[SIZE - 1] = msg[bitCount++];
                if (bitCount == *msgLength * SIZE) {
                    blueBinary[SIZE - 2] = '1';
                    endOfMessage = true;
                    *msgLength = bitCount / SIZE;
                }
            }
        }

        // write the modified pixel to the output file
        pixel[2] = getDecimal(redBinary);
        pixel[1] = getDecimal(greenBinary);
        pixel[0] = getDecimal(blueBinary);
        fwrite(pixel, sizeof(pixel), 1, out);

        // stop reading pixels if the end of the message has been reached
        if (endOfMessage) break;

        pixelCount++;
        if (pixelCount >= numPixels) {
            fprintf(stderr, "warning: message was truncated to fit in the image.\n");
            *msgLength = pixelCount * 3 / SIZE;
            break;
        }
    }
}

// function to recover the hidden message from an image
void recoverMessage(FILE *img, const char *outFile, int msgLength) {
    // create the output file
    FILE *out = fopen(outFile, "w");
    if (out == NULL) {
        fprintf(stderr, "error: could not create output file.\n");
        exit(EXIT_FAILURE);
    }

    // get the image size and skip the header
    fseek(img, 0, SEEK_END);
    int imgSize = ftell(img) - 54;
    fseek(img, 54, SEEK_SET);

    // read each pixel in the image
    unsigned char pixel[3];
    int pixelCount = 0;
    int bitCount = 0;
    char msgBuffer[SIZE * msgLength + 1];
    while (fread(pixel, sizeof(pixel), 1, img)) {
        // get the binary representation of each pixel component
        char redBinary[SIZE], greenBinary[SIZE], blueBinary[SIZE];
        getBinary(pixel[2], redBinary);
        getBinary(pixel[1], greenBinary);
        getBinary(pixel[0], blueBinary);

        // recover the message bits from the least significant bit of each component
        if (bitCount < msgLength * SIZE) {
            // recover the message bits from the red component
            msgBuffer[bitCount++] = redBinary[SIZE - 1];
            if (bitCount == msgLength * SIZE) break;

            // recover the message bits from the green component
            msgBuffer[bitCount++] = greenBinary[SIZE - 1];
            if (bitCount == msgLength * SIZE) break;

            // recover the message bits from the blue component
            msgBuffer[bitCount++] = blueBinary[SIZE - 1];
            if (bitCount == msgLength * SIZE) break;
        }

        pixelCount++;
        if (pixelCount >= msgLength * SIZE / 3) break;
    }

    // add a null terminator to the message buffer
    msgBuffer[bitCount] = '\0';

    // write the recovered message to the output file
    fprintf(out, "%s", msgBuffer);
    fclose(out);
}

int main(int argc, char *argv[]) {
    // check command line arguments
    if (argc != 4) {
        fprintf(stderr, "usage: %s [hide|recover] [image] [message file]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // open the image file
    FILE *img = fopen(argv[2], "rb");
    if (img == NULL) {
        fprintf(stderr, "error: could not open image file.\n");
        exit(EXIT_FAILURE);
    }

    // open the message file
    FILE *msgFile = fopen(argv[3], "r");
    if (msgFile == NULL) {
        fprintf(stderr, "error: could not open message file.\n");
        exit(EXIT_FAILURE);
    }

    // read the message from the file
    char msgBuffer[256];
    if (fgets(msgBuffer, sizeof(msgBuffer), msgFile) == NULL) {
        fprintf(stderr, "error: could not read message file.\n");
        exit(EXIT_FAILURE);
    }

    // remove the newline character from the message
    int msgLength = strlen(msgBuffer);
    if (msgBuffer[msgLength - 1] == '\n') {
        msgBuffer[msgLength - 1] = '\0';
        msgLength--;
    }

    // close the message file
    fclose(msgFile);

    // perform the requested action
    if (strcmp(argv[1], "hide") == 0) {
        // create the output file for the hidden message
        char outFile[256];
        strcpy(outFile, argv[2]);
        strcat(outFile, ".out");

        // create the output file
        FILE *out = fopen(outFile, "wb");
        if (out == NULL) {
            fprintf(stderr, "error: could not create output file.\n");
            exit(EXIT_FAILURE);
        }

        // copy the header from the input file to the output file
        char headerBuffer[54];
        fread(headerBuffer, sizeof(headerBuffer), 1, img);
        fwrite(headerBuffer, sizeof(headerBuffer), 1, out);

        // hide the message in the image
        hideMessage(img, out, msgBuffer, &msgLength);

        // copy the rest of the image to the output file
        unsigned char buffer[1024];
        while (fread(buffer, sizeof(buffer), 1, img)) {
            fwrite(buffer, sizeof(buffer), 1, out);
        }

        // close the input and output files
        fclose(img);
        fclose(out);

        printf("done. message hidden in image file: %s\n", outFile);
    } else if (strcmp(argv[1], "recover") == 0) {
        // recover the hidden message from the image
        recoverMessage(img, "recovered.txt", msgLength);

        // close the input file
        fclose(img);

        printf("done. message recovered from image file.\n");
    } else {
        fprintf(stderr, "error: invalid action '%s'.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}