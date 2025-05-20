//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 512
#define BIT_COUNT 8

typedef struct {
    unsigned char r, g, b;
} Pixel;

void embedMessage(Pixel *imagePixels, const char *message, int totalPixels) {
    int messageLength = strlen(message);
    int embeddedIndex = 0;

    for (int i = 0; i < totalPixels && embeddedIndex < messageLength; ++i) {
        // Embed each character one bit at a time into the least significant bit
        for (int bit = 0; bit < BIT_COUNT; ++bit) {
            if (embeddedIndex < messageLength) {
                int bitValue = (message[embeddedIndex] >> (BIT_COUNT - 1 - bit)) & 1;
                imagePixels[i].r = (imagePixels[i].r & ~1) | bitValue; // Embed into red channel
                if (bit == BIT_COUNT - 1) {
                    embeddedIndex++;
                }
            } else {
                return;
            }
        }
    }
}

void extractMessage(Pixel *imagePixels, char *extractedMessage, int totalPixels) {
    int index = 0;
    char currentChar = 0;
    
    for (int i = 0; i < totalPixels; ++i) {
        for (int bit = 0; bit < BIT_COUNT; ++bit) {
            currentChar = (currentChar << 1) | (imagePixels[i].r & 1); // Get LSB from red channel
            if (index < MAX_MESSAGE_LENGTH - 1 && bit == BIT_COUNT - 1) {
                extractedMessage[index++] = currentChar;
                currentChar = 0;  // Reset for next character
            }
        }
    }
    extractedMessage[index] = '\0'; // Null terminate the string
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input_image> <output_image> <message_to_embed>\n", argv[0]);
        return 1;
    }

    // Open the image file
    FILE *inputFile = fopen(argv[1], "rb");
    if (!inputFile) {
        perror("Unable to open input image file");
        return 1;
    }

    // Assume a dummy pixel array for simplicity
    int totalPixels = 1000; // This should be calculated based on the actual image format
    Pixel *imagePixels = (Pixel *)malloc(totalPixels * sizeof(Pixel));
    fread(imagePixels, sizeof(Pixel), totalPixels, inputFile);
    fclose(inputFile);
    
    // Embed the message
    embedMessage(imagePixels, argv[3], totalPixels);

    // Save the modified image (to a dummy output file)
    FILE *outputFile = fopen(argv[2], "wb");
    if (!outputFile) {
        perror("Unable to open output image file");
        free(imagePixels);
        return 1;
    }
    fwrite(imagePixels, sizeof(Pixel), totalPixels, outputFile);
    fclose(outputFile);
    
    // Now let's demonstrate message extraction
    char extractedMessage[MAX_MESSAGE_LENGTH];
    extractMessage(imagePixels, extractedMessage, totalPixels);
    
    printf("Extracted Message: %s\n", extractedMessage);

    // Clean up
    free(imagePixels);
    
    return 0;
}