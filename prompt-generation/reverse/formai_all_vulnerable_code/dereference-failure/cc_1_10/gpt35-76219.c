//FormAI DATASET v1.0 Category: Image Steganography ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000

typedef struct {
    int width;
    int height;
    unsigned char* pixels;
} Image;

int getBit(unsigned char byte, int bitIndex) {
    return (byte >> bitIndex) & 1;
}

void setBit(unsigned char* byte, int bitIndex, int bitValue) {
    if (bitValue == 0) {
        *byte &= ~(1 << bitIndex);
    } else {
        *byte |= 1 << bitIndex;
    }
}

void hideMessage(Image* image, const char* message) {
    int messageSize = strlen(message) + 1;
    int bitIndex = 0;
    for (int i = 0; i < messageSize; i++) {
        unsigned char byte = message[i];
        for (int bit = 0; bit < 8; bit++) {
            int pixelIndex = i * 8 + bit;
            if (pixelIndex >= image->width * image->height * 3) {
                fprintf(stderr, "Image too small to hide message\n");
                exit(1);
            }
            int rIndex = pixelIndex * 3;
            int gIndex = rIndex + 1;
            int bIndex = gIndex + 1;
            unsigned char* r = &image->pixels[rIndex];
            unsigned char* g = &image->pixels[gIndex];
            unsigned char* b = &image->pixels[bIndex];
            setBit(r, 0, getBit(byte, bitIndex));
            bitIndex++;
            if (bitIndex >= 8) {
                bitIndex = 0;
                byte = message[i + 1];
            }
            setBit(g, 0, getBit(byte, bitIndex));
            bitIndex++;
            if (bitIndex >= 8) {
                bitIndex = 0;
                byte = message[i + 1];
            }
            setBit(b, 0, getBit(byte, bitIndex));
            bitIndex++;
            if (bitIndex >= 8) {
                bitIndex = 0;
                byte = message[i + 1];
            }
        }
    }
}

char* showMessage(Image* image) {
    char* message = (char*)malloc(MAX_SIZE);
    int messageIndex = 0;
    for (int i = 0; i < image->width * image->height * 3; i += 8) {
        unsigned char byte = 0;
        for (int bit = 0; bit < 8; bit++) {
            int pixelIndex = i + bit;
            if (pixelIndex >= image->width * image->height * 3) {
                break;
            }
            int rIndex = pixelIndex * 3;
            int gIndex = rIndex + 1;
            int bIndex = gIndex + 1;
            unsigned char r = image->pixels[rIndex];
            unsigned char g = image->pixels[gIndex];
            unsigned char b = image->pixels[bIndex];
            int rBit = getBit(r, 0);
            int gBit = getBit(g, 0);
            int bBit = getBit(b, 0);
            byte |= rBit << bit;
            byte |= gBit << (bit + 1);
            byte |= bBit << (bit + 2);
        }
        message[messageIndex++] = byte;
        if (byte == 0) {
            break;
        }
    }
    return message;
}

int main(int argc, char** argv) {
    Image image;
    image.width = 320;
    image.height = 240;
    int numPixels = image.width * image.height;
    int numBytes = numPixels * 3;
    image.pixels = (unsigned char*)malloc(numBytes);
    for (int i = 0; i < numBytes; i++) {
        image.pixels[i] = 0;
    }
    const char* message = "I am a happy chatbot!";
    hideMessage(&image, message);

    char* shownMessage = showMessage(&image);
    printf("%s\n", shownMessage);

    free(image.pixels);
    free(shownMessage);
    return 0;
}