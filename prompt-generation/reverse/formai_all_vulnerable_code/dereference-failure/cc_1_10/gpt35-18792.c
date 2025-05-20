//FormAI DATASET v1.0 Category: Image Steganography ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Define bitmap file headers
struct BitmapHeader {
    char fileType[2];
    int fileSize;
    short reserved1;
    short reserved2;
    int pixelOffset;
};

//Define DIB header
struct DIBHeader {
    int size;
    int width;
    int height;
    short colorPlane;
    short bitsPerPixel;
    int compression;
    int imageSize;
    int xPixelsPerMeter;
    int yPixelsPerMeter;
    int colorUsed;
    int colorImportant;
};

//Function to read bitmap header
void readBitmapHeader(FILE *fp, struct BitmapHeader *bh) {
    fread(bh->fileType, 2, 1, fp);
    fread(&bh->fileSize, 4, 1, fp);
    fread(&bh->reserved1, 2, 1, fp);
    fread(&bh->reserved2, 2, 1, fp);
    fread(&bh->pixelOffset, 4, 1, fp);
}

//Function to read DIB header
void readDIBHeader(FILE *fp, struct DIBHeader *dh) {
    fread(&dh->size, 4, 1, fp);
    fread(&dh->width, 4, 1, fp);
    fread(&dh->height, 4, 1, fp);
    fread(&dh->colorPlane, 2, 1, fp);
    fread(&dh->bitsPerPixel, 2, 1, fp);
    fread(&dh->compression, 4, 1, fp);
    fread(&dh->imageSize, 4, 1, fp);
    fread(&dh->xPixelsPerMeter, 4, 1, fp);
    fread(&dh->yPixelsPerMeter, 4, 1, fp);
    fread(&dh->colorUsed, 4, 1, fp);
    fread(&dh->colorImportant, 4, 1, fp);
}

//Function to encode message into image
void encodeMessage(char *message, char *imagePath) {
    FILE *fp = fopen(imagePath, "rb+");
    struct BitmapHeader bh;
    struct DIBHeader dh;
    readBitmapHeader(fp, &bh);
    readDIBHeader(fp, &dh);
    int imageSize = dh.width * dh.height * 3;
    char *imageData = malloc(imageSize);
    fseek(fp, bh.pixelOffset, SEEK_SET);
    fread(imageData, imageSize, 1, fp);
    int imageBitIndex = 0;
    int messageBitIndex = 0;
    while (message[messageBitIndex] != '\0') {
        char letter = message[messageBitIndex];
        int binary[8];
        int index = 0;
        while (letter > 0) {
            binary[index] = letter % 2;
            letter = letter / 2;
            index++;
        }
        int binaryIndex = 0;
        while (binaryIndex < 8) {
            int imageRed = imageData[imageBitIndex];
            int imageGreen = imageData[imageBitIndex + 1];
            int imageBlue = imageData[imageBitIndex + 2];
            int red = imageRed / 2;
            int green = imageGreen / 2;
            int blue = imageBlue / 2;
            if (binary[binaryIndex] == 1) {
                if (imageRed % 2 == 0) {
                    red++;
                }
                if (imageGreen % 2 == 0) {
                    green++;
                }
                if (imageBlue % 2 == 0) {
                    blue++;
                }
            }
            else {
                if (imageRed % 2 == 1) {
                    red--;
                }
                if (imageGreen % 2 == 1) {
                    green--;
                }
                if (imageBlue % 2 == 1) {
                    blue--;
                }
            }
            imageData[imageBitIndex] = red;
            imageData[imageBitIndex + 1] = green;
            imageData[imageBitIndex + 2] = blue;
            imageBitIndex += 3;
            binaryIndex++;
        }
        messageBitIndex++;
    }
    fseek(fp, bh.pixelOffset, SEEK_SET);
    fwrite(imageData, imageSize, 1, fp);
    free(imageData);
    fclose(fp);
}

//Function to decode message from image
char *decodeMessage(char *imagePath) {
    FILE *fp = fopen(imagePath, "rb");
    struct BitmapHeader bh;
    struct DIBHeader dh;
    readBitmapHeader(fp, &bh);
    readDIBHeader(fp, &dh);
    int imageSize = dh.width * dh.height * 3;
    char *imageData = malloc(imageSize);
    fseek(fp, bh.pixelOffset, SEEK_SET);
    fread(imageData, imageSize, 1, fp);
    char *message = malloc(10000);
    int messageIndex = 0;
    int imageBitIndex = 0;
    while (1) {
        int binary[8];
        int binaryIndex = 0;
        while (binaryIndex < 8) {
            int imageRed = imageData[imageBitIndex];
            int imageGreen = imageData[imageBitIndex + 1];
            int imageBlue = imageData[imageBitIndex + 2];
            int redBinary = imageRed % 2 == 0 ? 0 : 1;
            int greenBinary = imageGreen % 2 == 0 ? 0 : 1;
            int blueBinary = imageBlue % 2 == 0 ? 0 : 1;
            binary[binaryIndex] = redBinary * 4 + greenBinary * 2 + blueBinary;
            imageBitIndex += 3;
            binaryIndex++;
        }
        int letter = 0;
        int power = 1;
        int index = 7;
        while (index >= 0) {
            letter += binary[index] * power;
            power = power * 2;
            index--;
        }
        if (letter == 0) {
            message[messageIndex] = '\0';
            break;
        }
        message[messageIndex] = (char)letter;
        messageIndex++;
    }
    fclose(fp);
    return message;
}

int main() {
    char *message = "Hello, world!";
    char *imagePath = "image.bmp";
    encodeMessage(message, imagePath);
    char *decodedMessage = decodeMessage(imagePath);
    printf("%s\n", decodedMessage);
    free(decodedMessage);
    return 0;
}