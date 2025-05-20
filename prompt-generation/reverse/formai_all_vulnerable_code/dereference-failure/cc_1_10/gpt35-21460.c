//FormAI DATASET v1.0 Category: Image Steganography ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define HEADER_SIZE 54
#define BITMASK_BLUE 0xFF0000
#define BITMASK_GREEN 0x00FF00
#define BITMASK_RED 0x0000FF

void createHeader(unsigned char *header, uint32_t width, uint32_t height) {
    uint32_t size = HEADER_SIZE + width * height * 3;
    uint16_t reserved = 0;
    uint32_t offset = HEADER_SIZE;
    uint32_t dibSize = 40;
    uint16_t planes = 1;
    uint16_t bitCount = 24;
    uint32_t compression = 0;
    uint32_t imageSize = width * height * 3;
    uint32_t ppmX = 2835;
    uint32_t ppmY = 2835;
    uint32_t clrUsed = 0;
    uint32_t clrImportant = 0;

    memcpy(&header[0], "BM", 2);
    memcpy(&header[2], &size, 4);
    memcpy(&header[6], &reserved, 2);
    memcpy(&header[8], &reserved, 2);
    memcpy(&header[10], &offset, 4);
    memcpy(&header[14], &dibSize, 4);
    memcpy(&header[18], &width, 4);
    memcpy(&header[22], &height, 4);
    memcpy(&header[26], &planes, 2);
    memcpy(&header[28], &bitCount, 2);
    memcpy(&header[30], &compression, 4);
    memcpy(&header[34], &imageSize, 4);
    memcpy(&header[38], &ppmX, 4);
    memcpy(&header[42], &ppmY, 4);
    memcpy(&header[46], &clrUsed, 4);
    memcpy(&header[50], &clrImportant, 4);
}

void setBit(uint8_t *byte, uint8_t pos, uint8_t val) {
    if (val)
        *byte |= 1 << pos;
    else
        *byte &= ~(1 << pos);
}

void encode(char *message, unsigned char *image, uint32_t imageSize) {
    uint32_t msgLength = strlen(message);
    uint32_t numPixels = imageSize / 3;
    if (msgLength > numPixels / 8) {
        printf("Error: Message too large!\n");
        return;
    }

    unsigned char mask = 0x01;
    uint32_t bytePos = 0; // position of byte in message
    uint8_t bitPos = 0; // position of bit in byte
    uint8_t val;

    for (uint32_t i = 0; i < numPixels; i++) {
        val = message[bytePos] & mask ? 1 : 0; // Get the bit to be encoded
        switch (bitPos) {
            case 0: {
                // Replace LSB of blue pixel with message bit
                setBit(&image[i * 3], 0, val);
                break;
            }
            case 1: {
                // Replace LSB of green pixel with message bit
                setBit(&image[i * 3 + 1], 0, val);
                break;
            }
            case 2: {
                // Replace LSB of red pixel with message bit
                setBit(&image[i * 3 + 2], 0, val);
                break;
            }
            default: {}
        }

        bitPos++;
        if (bitPos == 3) {
            bitPos = 0;
            bytePos++;
            if (bytePos >= msgLength) break;
        }
        mask <<= 1;
        if (!mask) mask = 0x01;
    }
}

char *decode(unsigned char *image, uint32_t imageSize) {
    uint32_t numPixels = imageSize / 3;
    unsigned char mask = 0x01;
    char *message = malloc(numPixels / 8 + 1);
    memset(message, 0, numPixels / 8 + 1);
    uint8_t bit;
    uint32_t bytePos = 0;
    uint8_t bitPos = 0;

    for (uint32_t i = 0; i < numPixels; i++) {
        bit = (image[i * 3] & 0x01) | ((image[i * 3 + 1] & 0x01) << 1) | ((image[i * 3 + 2] & 0x01) << 2);
        if (bit) setBit((unsigned char *) message + bytePos, bitPos, 1);

        bitPos++;
        if (bitPos == 8) {
            bitPos = 0;
            bytePos++;
            if (bytePos >= numPixels / 8) break;
        }
    }
    return message;
}

int main() {
    char message[] = "All hail the cyberpunk revolution of the digital age!";
    uint32_t width = 800, height = 600;
    uint32_t imageSize = width * height * 3;
    unsigned char *image = malloc(imageSize);
    memset(image, 255, imageSize); // Set all pixels to white
    createHeader(image, width, height);
    encode(message, image + HEADER_SIZE, imageSize - HEADER_SIZE);
    FILE *f = fopen("cyberpunk_steganography.bmp", "wb");
    if (!f) {
        printf("Error: Could not open file!\n");
        return -1;
    }
    fwrite(image, 1, imageSize, f);
    fclose(f);
    printf("Message encoded successfully!\n");

    unsigned char *encodedImage = malloc(imageSize);
    memcpy(encodedImage, image, imageSize); // Copy image data to new buffer
    char *decodedMessage = decode(encodedImage + HEADER_SIZE, imageSize - HEADER_SIZE);
    printf("Decoded message: %s\n", decodedMessage);

    free(image);
    free(encodedImage);
    free(decodedMessage);

    return 0;
}