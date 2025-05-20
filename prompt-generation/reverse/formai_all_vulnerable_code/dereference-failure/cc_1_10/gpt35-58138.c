//FormAI DATASET v1.0 Category: Image Steganography ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define BYTES_PER_PIXEL 3
#define HEADER_SIZE 54
#define BUFFER_SIZE 4096

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} Pixel;

uint8_t* readBitmapHeader(FILE* bitmapFile) {
    uint8_t* header = (uint8_t*) malloc(HEADER_SIZE * sizeof(uint8_t));
    fread(header, sizeof(uint8_t), HEADER_SIZE, bitmapFile);
    return header;
}

Pixel* readBitmapPixels(FILE* bitmapFile, int width, int height) {
    Pixel* pixels = (Pixel*) malloc(width * height * sizeof(Pixel));
    int padding = (4 - (width * BYTES_PER_PIXEL) % 4) % 4;
    for (int y = height - 1; y >= 0; y--) {
        for (int x = 0; x < width; x++) {
            Pixel* pixel = &pixels[x + y * width];
            fread(pixel, sizeof(Pixel), 1, bitmapFile);
        }
        fseek(bitmapFile, padding, SEEK_CUR);
    }
    return pixels;
}

void hideMessage(Pixel* pixels, int size, char* message) {
    Pixel mask = {1, 1, 0};
    int messageIndex = 0;
    for (int i = 0; i < size; i++) {
        Pixel* pixel = &pixels[i];
        if (messageIndex < strlen(message)) {
            char ch = message[messageIndex];
            for (int j = 0; j < 8; j++) {
                Pixel* bit = &pixels[i + j];
                uint8_t value = ((ch >> j) & 1);
                bit->red = (bit->red & ~(mask.red)) | (value << 0);
                bit->green = (bit->green & ~(mask.green)) | (value << 1);
                bit->blue = (bit->blue & ~(mask.blue)) | (value << 0);
            }
            messageIndex++;
            i += 7;
        } else {
            break;
        }
    }
}

void saveBitmapHeader(FILE* bitmapFile, uint8_t* header) {
    fwrite(header, sizeof(uint8_t), HEADER_SIZE, bitmapFile);
}

void saveBitmapPixels(FILE* bitmapFile, int width, int height, Pixel* pixels) {
    int padding = (4 - (width * BYTES_PER_PIXEL) % 4) % 4;
    for (int y = height - 1; y >= 0; y--) {
        for (int x = 0; x < width; x++) {
            fwrite(&pixels[x + y * width], sizeof(Pixel), 1, bitmapFile);
        }
        for (int i = 0; i < padding; i++) {
            fputc(0, bitmapFile);
        }
    }
}

void encodeBitmap(char* sourcePath, char* destinationPath, char* message) {
    FILE* sourceFile = fopen(sourcePath, "rb");
    if (sourceFile != NULL) {
        FILE* destinationFile = fopen(destinationPath, "wb");
        if (destinationFile != NULL) {
            uint8_t* header = readBitmapHeader(sourceFile);
            int width = *(int*) (header + 18);
            int height = *(int*) (header + 22);
            printf("Width: %d\n", width);
            printf("Height: %d\n", height);
            Pixel* pixels = readBitmapPixels(sourceFile, width, height);
            int size = width * height;
            hideMessage(pixels, size, message);
            saveBitmapHeader(destinationFile, header);
            saveBitmapPixels(destinationFile, width, height, pixels);
            fclose(destinationFile);
            printf("Encoded secret message successfully\n");
        } else {
            printf("Error: Could not create file %s\n", destinationPath);
        }
        fclose(sourceFile);
    } else {
        printf("Error: Could not open file %s\n", sourcePath);
    }
}

char* extractMessage(Pixel* pixels, int size) {
    char* message = (char*) malloc(BUFFER_SIZE * sizeof(char));
    memset(message, 0, BUFFER_SIZE * sizeof(char));
    Pixel mask = {1, 1, 0};
    int messageIndex = 0;
    for (int i = 0; i < size; i++) {
        Pixel* pixel = &pixels[i];
        uint8_t bit = ((pixel->red & mask.red) >> 0)
                    | ((pixel->green & mask.green) >> 1)
                    | ((pixel->blue & mask.blue) >> 0);
        message[messageIndex / 8] |= bit << (messageIndex % 8);
        messageIndex++;
        if (message[messageIndex / 8] == '\0') {
            break;
        }
    }
    return message;
}

void decodeBitmap(char* sourcePath) {
    FILE* sourceFile = fopen(sourcePath, "rb");
    if (sourceFile != NULL) {
        uint8_t* header = readBitmapHeader(sourceFile);
        int width = *(int*) (header + 18);
        int height = *(int*) (header + 22);
        printf("Width: %d\n", width);
        printf("Height: %d\n", height);
        int size = width * height;
        Pixel* pixels = readBitmapPixels(sourceFile, width, height);
        char* message = extractMessage(pixels, size);
        printf("Secret message: %s\n", message);
        free(message);
        free(pixels);
        free(header);
        fclose(sourceFile);
    } else {
        printf("Error: Could not open file %s\n", sourcePath);
    }
}

int main(int argc, char** argv) {
    if (argc == 4) {
        char* command = argv[1];
        char* sourcePath = argv[2];
        char* destinationPath = argv[3];
        if (strcmp(command, "encode") == 0) {
            char* message = "This is a secret message hidden inside an image";
            encodeBitmap(sourcePath, destinationPath, message);
        } else if (strcmp(command, "decode") == 0) {
            decodeBitmap(sourcePath);
        } else {
            printf("Invalid command: %s\n", command);
        }
    } else {
        printf("Usage: %s <command> <source> <destination>\n", argv[0]);
        printf("Commands:\n");
        printf("  encode - hide secret message inside image\n");
        printf("  decode - extract secret message from image\n");
    }
    return 0;
}