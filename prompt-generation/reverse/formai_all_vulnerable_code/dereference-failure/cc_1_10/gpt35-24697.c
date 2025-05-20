//FormAI DATASET v1.0 Category: Image Steganography ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

struct Pixel {
    unsigned char R, G, B;
};

void hideMessage(char *message, struct Pixel *image, int imageSize);
void revealMessage(struct Pixel *image, int imageSize);
bool getBit(char byte, int position);
void flipBit(unsigned char *byte, int position);

int main() {
    char message[MAX_SIZE];
    struct Pixel *image;
    int imageSize;

    // Read image file
    FILE *imageFile = fopen("image.bin", "rb");
    if (imageFile == NULL) {
        printf("Error reading image file.\n");
        exit(EXIT_FAILURE);
    }

    // Get image size
    fseek(imageFile, 0, SEEK_END);
    imageSize = ftell(imageFile);
    rewind(imageFile);

    // Allocate memory for image
    image = (struct Pixel*) malloc(sizeof(struct Pixel) * imageSize);

    // Read pixels from file
    fread(image, sizeof(struct Pixel), imageSize, imageFile);
    fclose(imageFile);

    // Get message from user
    printf("Enter message to hide: ");
    fgets(message, MAX_SIZE, stdin);

    // Hide message in image
    hideMessage(message, image, imageSize);

    // Save modified image to file
    FILE *modifiedImageFile = fopen("modified-image.bin", "wb");
    if (modifiedImageFile == NULL) {
        printf("Error writing modified image file.\n");
        exit(EXIT_FAILURE);
    }
    fwrite(image, sizeof(struct Pixel), imageSize, modifiedImageFile);
    fclose(modifiedImageFile);

    // Reveal message in image
    revealMessage(image, imageSize);

    // Free memory
    free(image);

    return 0;
}

void hideMessage(char *message, struct Pixel *image, int imageSize) {
    int messageIndex = 0;
    int bitIndex = 0;

    for (int i = 0; i < imageSize; i++) {
        if (message[messageIndex] == '\0') {
            break;
        }

        // Hide message in R channel of pixel
        if (bitIndex < 8) {
            flipBit(&(image[i].R), 0); // Ensure even
            if (getBit(message[messageIndex], bitIndex)) {
                flipBit(&(image[i].R), 7);
            }
            bitIndex++;
        }

        // Hide message in G channel of pixel
        if (bitIndex < 8) {
            flipBit(&(image[i].G), 0); // Ensure even
            if (getBit(message[messageIndex], bitIndex)) {
                flipBit(&(image[i].G), 7);
            }
            bitIndex++;
        }

        // Hide message in B channel of pixel
        if (bitIndex < 8) {
            flipBit(&(image[i].B), 0); // Ensure even
            if (getBit(message[messageIndex], bitIndex)) {
                flipBit(&(image[i].B), 7);
            }
            bitIndex++;
        }

        // Move to next message character
        if (bitIndex == 8) {
            bitIndex = 0;
            messageIndex++;
        }
    }
}

void revealMessage(struct Pixel *image, int imageSize) {
    char message[MAX_SIZE];
    int messageIndex = 0;

    for (int i = 0; i < imageSize; i++) {
        if (messageIndex == MAX_SIZE) {
            break;
        }

        // Read message from R channel of pixel
        char messageByte = 0;
        for (int bit = 7; bit >= 0; bit--) {
            messageByte |= getBit(image[i].R, bit) << (7 - bit);
        }
        if (messageByte != '\0') {
            message[messageIndex++] = messageByte;
        }

        // Read message from G channel of pixel
        messageByte = 0;
        for (int bit = 7; bit >= 0; bit--) {
            messageByte |= getBit(image[i].G, bit) << (7 - bit);
        }
        if (messageByte != '\0') {
            message[messageIndex++] = messageByte;
        }

        // Read message from B channel of pixel
        messageByte = 0;
        for (int bit = 7; bit >= 0; bit--) {
            messageByte |= getBit(image[i].B, bit) << (7 - bit);
        }
        if (messageByte != '\0') {
            message[messageIndex++] = messageByte;
        }
    }

    printf("Revealed message: %s\n", message);
}

bool getBit(char byte, int position) {
    return (byte >> position) & 1U;
}

void flipBit(unsigned char *byte, int position) {
    *byte ^= 1UL << position;
}