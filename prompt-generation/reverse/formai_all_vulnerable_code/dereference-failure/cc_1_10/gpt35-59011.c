//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: complete
#include <stdio.h>
#include <stdlib.h>

/* Function to embed message into image */
void embedMessage(char* imageFilePath, char* messageFilePath, char* outputFilePath) {
    FILE *inputImage, *inputMessage, *outputImage;
    int imageSize, messageSize, i, j;
    char *imageBuffer, *messageBuffer;
    
    // Open input image file
    inputImage = fopen(imageFilePath, "rb");
    if (inputImage == NULL) {
        printf("Could not open input image file\n");
        exit(1);
    }
    
    // Open input message file
    inputMessage = fopen(messageFilePath, "rb");
    if (inputMessage == NULL) {
        printf("Could not open input message file\n");
        exit(1);
    }
    
    // Open output image file
    outputImage = fopen(outputFilePath, "wb");
    if (outputImage == NULL) {
        printf("Could not open output image file\n");
        exit(1);
    }
    
    // Get size of input image and allocate buffer
    fseek(inputImage, 0, SEEK_END);
    imageSize = ftell(inputImage);
    fseek(inputImage, 0, SEEK_SET);
    imageBuffer = (char*)malloc(imageSize);
    if (imageBuffer == NULL) {
        printf("Could not allocate memory for image buffer\n");
        exit(1);
    }
    
    // Get size of input message and allocate buffer
    fseek(inputMessage, 0, SEEK_END);
    messageSize = ftell(inputMessage);
    fseek(inputMessage, 0, SEEK_SET);
    messageBuffer = (char*)malloc(messageSize);
    if (messageBuffer == NULL) {
        printf("Could not allocate memory for message buffer\n");
        exit(1);
    }
    
    // Read input image and message into buffers
    fread(imageBuffer, 1, imageSize, inputImage);
    fread(messageBuffer, 1, messageSize, inputMessage);
    
    // Embed message into image
    for (i = 0, j = 0; i < imageSize; i += 3) {
        if (j < messageSize) {
            imageBuffer[i] = ((imageBuffer[i] >> 2) << 2) | (messageBuffer[j] >> 6);
            imageBuffer[i+1] = ((imageBuffer[i+1] >> 2) << 2) | ((messageBuffer[j] & 0x3F) >> 4);
            imageBuffer[i+2] = ((imageBuffer[i+2] >> 2) << 2) | ((messageBuffer[j] & 0x0F) >> 2);
            j++;
        }
    }
    
    // Write output image with embedded message
    fwrite(imageBuffer, 1, imageSize, outputImage);
    
    // Free buffers and close files
    free(imageBuffer);
    free(messageBuffer);
    fclose(inputImage);
    fclose(inputMessage);
    fclose(outputImage);
}

/* Function to extract message from image */
void extractMessage(char* imageFilePath, char* outputFilePath) {
    FILE *inputImage, *outputMessage;
    int imageSize, i, j, messageSize;
    char c1, c2, c3, c4, *imageBuffer, *messageBuffer;
    
    // Open input image file
    inputImage = fopen(imageFilePath, "rb");
    if (inputImage == NULL) {
        printf("Could not open input image file\n");
        exit(1);
    }
    
    // Open output message file
    outputMessage = fopen(outputFilePath, "wb");
    if (outputMessage == NULL) {
        printf("Could not open output message file\n");
        exit(1);
    }
    
    // Get size of input image and allocate buffer
    fseek(inputImage, 0, SEEK_END);
    imageSize = ftell(inputImage);
    fseek(inputImage, 0, SEEK_SET);
    imageBuffer = (char*)malloc(imageSize);
    if (imageBuffer == NULL) {
        printf("Could not allocate memory for image buffer\n");
        exit(1);
    }
    
    // Read input image into buffer
    fread(imageBuffer, 1, imageSize, inputImage);
    
    // Extract message from image
    for (i = 0, j = 0; i < imageSize; i += 3) {
        if (j % 4 == 0) {
            c1 = imageBuffer[i] & 0x3F;
            c2 = ((imageBuffer[i+1] << 2) & 0x3F) | ((imageBuffer[i] >> 6) & 0x03);
            c3 = ((imageBuffer[i+2] << 4) & 0x3F) | ((imageBuffer[i+1] >> 4) & 0x0F);
            c4 = (imageBuffer[i+2] >> 2) & 0x3F;
            putc(c1, outputMessage);
            putc(c2, outputMessage);
            putc(c3, outputMessage);
            putc(c4, outputMessage);
            j++;
        } else {
            j++;
        }
    }
    
    // Close files and free buffer
    fclose(inputImage);
    fclose(outputMessage);
    free(imageBuffer);
}

int main() {
    char* imageFilePath = "input.png";
    char* messageFilePath = "message.txt";
    char* outputFilePath = "output.png";
    char* extractedMessageFilePath = "extracted.txt";
    
    // Embed message into image
    embedMessage(imageFilePath, messageFilePath, outputFilePath);
    
    // Extract message from image
    extractMessage(outputFilePath, extractedMessageFilePath);
    
    return 0;
}