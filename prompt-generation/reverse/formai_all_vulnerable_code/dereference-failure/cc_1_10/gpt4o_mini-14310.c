//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compute size of the image in bytes
int calculateImageSize(FILE *image) {
    fseek(image, 0, SEEK_END);
    int size = ftell(image);
    fseek(image, 0, SEEK_SET);
    return size;
}

// Function to embed secret message into the least significant bits of the image
void embedMessage(const char *imagePath, const char *message, const char *outputImagePath) {
    FILE *inputImage = fopen(imagePath, "rb");
    if (!inputImage) {
        perror("Error opening input image");
        return;
    }

    int imgSize = calculateImageSize(inputImage);
    unsigned char *imageData = (unsigned char *)malloc(imgSize);
    fread(imageData, 1, imgSize, inputImage);
    fclose(inputImage);

    // Preparing the message
    int messageLength = strlen(message);
    if (messageLength * 8 + 32 > imgSize * 8) {
        printf("Error: Message is too long to embed in the image.\n");
        free(imageData);
        return;
    }

    // Embed length of the message
    for (int i = 0; i < 32; ++i) {
        imageData[i] = (imageData[i] & 0xFE) | ((messageLength >> i) & 0x01);
    }

    // Embed the message
    for (int i = 0; i < messageLength; ++i) {
        for (int j = 0; j < 8; ++j) {
            imageData[i * 8 + 32 + j] = (imageData[i * 8 + 32 + j] & 0xFE) | ((message[i] >> j) & 0x01);
        }
    }

    // Write the modified image data to a new file
    FILE *outputImage = fopen(outputImagePath, "wb");
    if (!outputImage) {
        perror("Error creating output image");
        free(imageData);
        return;
    }

    fwrite(imageData, 1, imgSize, outputImage);
    fclose(outputImage);
    free(imageData);

    printf("Message embedded successfully in the image.\n");
}

// Function to extract secret message from the least significant bits of the image
void extractMessage(const char *imagePath) {
    FILE *inputImage = fopen(imagePath, "rb");
    if (!inputImage) {
        perror("Error opening input image");
        return;
    }

    int imgSize = calculateImageSize(inputImage);
    unsigned char *imageData = (unsigned char *)malloc(imgSize);
    fread(imageData, 1, imgSize, inputImage);
    fclose(inputImage);

    // Extracting length of the message
    int messageLength = 0;
    for (int i = 0; i < 32; ++i) {
        messageLength |= ((imageData[i] & 0x01) << i);
    }

    if (messageLength <= 0 || messageLength * 8 + 32 > imgSize * 8) {
        printf("No message found in the image.\n");
        free(imageData);
        return;
    }

    // Extracting the message
    char *message = (char *)malloc(messageLength + 1);
    for (int i = 0; i < messageLength; ++i) {
        message[i] = 0;
        for (int j = 0; j < 8; ++j) {
            message[i] |= ((imageData[i * 8 + 32 + j] & 0x01) << j);
        }
    }

    message[messageLength] = '\0'; // null terminate the message

    printf("Extracted message: %s\n", message);
    free(imageData);
    free(message);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <embed/extract> <image_path> <output_path/message>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "embed") == 0) {
        embedMessage(argv[2], argv[3], "output_image.png");
    } else if (strcmp(argv[1], "extract") == 0) {
        extractMessage(argv[2]);
    } else {
        printf("Invalid option. Please use 'embed' or 'extract'.\n");
    }

    return 0;
}