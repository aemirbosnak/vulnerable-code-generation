//FormAI DATASET v1.0 Category: Image Steganography ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PIXEL_MAX 255
#define PIXEL_BYTE_SIZE 3

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

void encodeMessage(char *message, FILE *imageFile) {
    Pixel pixel;
    int bitCount = 0;
    char messageChar;
    int messageIndex = 0;
    
    while ((messageChar = message[messageIndex++])) {
        for (int i = 0; i < 8; i++) {
            if (bitCount % PIXEL_BYTE_SIZE == 0) {
                if (fread(&pixel, sizeof(Pixel), 1, imageFile) != 1) {
                    printf("Error reading input image!");
                    exit(EXIT_FAILURE);
                }
            }
            
            int bit = (messageChar & (1 << i)) > 0;
            
            switch (bitCount % PIXEL_BYTE_SIZE) {
                case 0:
                    pixel.r = (pixel.r & ~(1 << (bitCount % 8))) | (bit << (bitCount % 8));
                    break;
                case 1:
                    pixel.g = (pixel.g & ~(1 << (bitCount % 8))) | (bit << (bitCount % 8));
                    break;
                case 2:
                    pixel.b = (pixel.b & ~(1 << (bitCount % 8))) | (bit << (bitCount % 8));
                    break;
            }
            
            bitCount++;
            
            if (bitCount % PIXEL_BYTE_SIZE == 0) {
                fseek(imageFile, -sizeof(Pixel), SEEK_CUR);
                
                if (fwrite(&pixel, sizeof(Pixel), 1, imageFile) != 1) {
                    printf("Error writing output image!");
                    exit(EXIT_FAILURE);
                }
            }
        }
    }
    
    // Terminate message with null character
    for (int i = 0; i < 8; i++) {
        if (bitCount % PIXEL_BYTE_SIZE == 0) {
            if (fread(&pixel, sizeof(Pixel), 1, imageFile) != 1) {
                printf("Error reading input image!");
                exit(EXIT_FAILURE);
            }
        }

        switch (bitCount % PIXEL_BYTE_SIZE) {
            case 0:
                pixel.r = (pixel.r & ~(1 << (bitCount % 8))) | (0 << (bitCount % 8));
                break;
            case 1:
                pixel.g = (pixel.g & ~(1 << (bitCount % 8))) | (0 << (bitCount % 8));
                break;
            case 2:
                pixel.b = (pixel.b & ~(1 << (bitCount % 8))) | (0 << (bitCount % 8));
                break;
        }

        bitCount++;

        if (bitCount % PIXEL_BYTE_SIZE == 0) {
            fseek(imageFile, -sizeof(Pixel), SEEK_CUR);

            if (fwrite(&pixel, sizeof(Pixel), 1, imageFile) != 1) {
                printf("Error writing output image!");
                exit(EXIT_FAILURE);
            }
        }
    }
}

void decodeMessage(FILE *imageFile) {
    Pixel pixel;
    int bitCount = 0;
    char message[256];
    int messageIndex = 0;
    char messageChar = 0;
    
    while (1) {
        if (bitCount % PIXEL_BYTE_SIZE == 0) {
            if (fread(&pixel, sizeof(Pixel), 1, imageFile) != 1) {
                printf("Error reading input image!");
                exit(EXIT_FAILURE);
            }
        }
        
        int bit = (pixel.r & (1 << (bitCount % 8))) > 0;
        messageChar = messageChar | (bit << (bitCount % 8));
        bitCount++;
        
        if (bitCount % 8 == 0) {
            if (messageChar == '\0') {
                break;
            }
            
            message[messageIndex++] = messageChar;
            messageChar = 0;
        }
        
        if (bitCount % PIXEL_BYTE_SIZE == 0) {
            fseek(imageFile, -sizeof(Pixel), SEEK_CUR);
        }
    }
    
    printf("Decoded Message: %s", message);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s (<e>ncode | <d>ecode) <input image> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    FILE *imageFile = fopen(argv[2], "rb+");

    if (!imageFile) {
        printf("Error opening input image!");
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "e") == 0) {
        encodeMessage(argv[3], imageFile);
    } else if (strcmp(argv[1], "d") == 0) {
        decodeMessage(imageFile);
    }
    
    fclose(imageFile);

    return EXIT_SUCCESS;
}