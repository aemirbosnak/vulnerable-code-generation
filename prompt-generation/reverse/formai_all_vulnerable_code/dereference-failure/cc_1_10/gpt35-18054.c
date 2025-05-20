//FormAI DATASET v1.0 Category: Image Steganography ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to read the image data from a file */
void readImage(char* filename, unsigned char** imageData, int* width, int* height) {
    FILE* fp = fopen(filename, "rb"); // Open the file for reading in binary mode
    
    if(fp == NULL) { // Handle file opening errors
        printf("Error opening file!\n");
        exit(1);
    }
    
    // Read the BMP header to get the image dimensions
    fseek(fp, 18, SEEK_SET);
    fread(width, sizeof(int), 1, fp);
    fread(height, sizeof(int), 1, fp);
    
    int paddingSize = 4 - ((*width) * 3) % 4; // Compute padding size
    
    if(paddingSize == 4) // If padding size is 4, set it to 0
        paddingSize = 0;
    
    // Allocate memory for the image data
    *imageData = (unsigned char*)malloc((*height) * (*width) * 3 * sizeof(unsigned char));
    
    if(*imageData == NULL) { // Handle memory allocation errors
        printf("Error allocating memory for image data!\n");
        exit(1);
    }
    
    // Read the image data from the file
    fseek(fp, 54, SEEK_SET);
    
    for(int i = 0; i < (*height); ++i) {
        for(int j = 0; j < (*width); ++j) {
            fread((*imageData) + (i * (*width) * 3) + (j * 3), sizeof(unsigned char), 3, fp);
        }
        
        fseek(fp, paddingSize, SEEK_CUR); // Skip padding
    }
    
    fclose(fp); // Close the file
}

/* Function to write the image data to a file */
void writeImage(char* filename, unsigned char* imageData, int width, int height) {
    FILE* fp = fopen(filename, "wb"); // Open the file for writing in binary mode
    
    if(fp == NULL) { // Handle file opening errors
        printf("Error opening file!\n");
        exit(1);
    }
    
    // Set the BMP header fields
    int paddingSize = 4 - (width * 3) % 4; // Compute padding size
    
    if(paddingSize == 4) // If padding size is 4, set it to 0
        paddingSize = 0;
    
    int fileSize = 54 + (height * (width * 3 + paddingSize)); // Compute file size
    int pixelsOffset = 54;
    int dibHeaderSize = 40;
    int depth = 24;
    int compression = 0;
    
    // Write the BMP header to the file
    fwrite("BM", sizeof(char), 2, fp);
    fwrite(&fileSize, sizeof(int), 1, fp);
    fwrite("\0\0\0\0", sizeof(char), 4, fp);
    fwrite(&pixelsOffset, sizeof(int), 1, fp);
    fwrite(&dibHeaderSize, sizeof(int), 1, fp);
    fwrite(&width, sizeof(int), 1, fp);
    fwrite(&height, sizeof(int), 1, fp);
    fwrite("\1\0", sizeof(short), 1, fp);
    fwrite(&depth, sizeof(short), 1, fp);
    fwrite(&compression, sizeof(int), 1, fp);
    fwrite("\0\0\0\0", sizeof(int), 1, fp);
    fwrite("\0\0\0\0", sizeof(int), 1, fp);
    fwrite("\0\0\0\0", sizeof(int), 1, fp);
    fwrite("\0\0\0\0", sizeof(int), 1, fp);
    fwrite("\0\0\0\0", sizeof(int), 1, fp);
    
    // Write the image data to the file
    for(int i = 0; i < height; ++i) {
        for(int j = 0; j < width; ++j) {
            fwrite(imageData + (i * width * 3) + (j * 3), sizeof(unsigned char), 3, fp);
        }
        
        fwrite("\0\0\0", sizeof(char), paddingSize, fp); // Write padding
    }
    
    fclose(fp); // Close the file
}

/* Function to hide a message in an image using LSB steganography */
void hideMessageInImage(char* imagePath, char* message, char* outputImagePath) {
    unsigned char* imageData;
    int width, height;
    
    // Read the image data from the file
    readImage(imagePath, &imageData, &width, &height);
    
    int messageLength = strlen(message); // Get the length of the message
    int bitsToHide = messageLength * 8; // Compute the number of bits to hide
    
    // Make sure the message can fit in the image
    if(bitsToHide > (width * height * 3)) {
        printf("Error: Message too long to hide in image!\n");
        exit(1);
    }
    
    int bitIndex = 0; // Index of the current bit of the message
    int pixelIndex = 0; // Index of the current pixel
    
    while(bitIndex < bitsToHide) { // Loop through all bits of the message
        unsigned char bit = message[bitIndex / 8] & (1 << (7 - (bitIndex % 8))); // Get the current bit of the message
        
        if(bit == 0) { // If the current bit is 0, make the LSB of the pixel even
            imageData[pixelIndex] &= ~(1 << 0);
        }
        else { // If the current bit is 1, make the LSB of the pixel odd
            imageData[pixelIndex] |= (1 << 0);
        }
        
        ++bitIndex; // Move to the next bit
        pixelIndex += 3; // Move to the next pixel
    }
    
    // Write the modified image data to a new file
    writeImage(outputImagePath, imageData, width, height);
    
    free(imageData); // Free the allocated memory
}

/* Function to extract a message from an image using LSB steganography */
void extractMessageFromImage(char* imagePath, char* outputFilePath) {
    unsigned char* imageData;
    int width, height;
    
    // Read the image data from the file
    readImage(imagePath, &imageData, &width, &height);
    
    int bitsToExtract = width * height * 3; // Compute the number of bits to extract
    unsigned char* message = (unsigned char*)malloc(bitsToExtract / 8 * sizeof(unsigned char)); // Allocate memory for the extracted message
    
    if(message == NULL) { // Handle memory allocation errors
        printf("Error allocating memory for message!\n");
        exit(1);
    }
    
    int bitIndex = 0; // Index of the current bit of the message
    int pixelIndex = 0; // Index of the current pixel
    
    while(bitIndex < bitsToExtract) { // Loop through all bits of the message
        unsigned char bit = (imageData[pixelIndex] & (1 << 0)) >> 0; // Extract the LSB of the pixel
        
        if(bit == 0) { // If the LSB is even, set the current bit of the message to 0
            message[bitIndex / 8] &= ~(1 << (7 - (bitIndex % 8)));
        }
        else { // If the LSB is odd, set the current bit of the message to 1
            message[bitIndex / 8] |= (1 << (7 - (bitIndex % 8)));
        }
        
        ++bitIndex; // Move to the next bit
        pixelIndex += 3; // Move to the next pixel
    }
    
    // Write the extracted message to a file
    FILE* fp = fopen(outputFilePath, "w"); // Open the file for writing
    
    if(fp == NULL) { // Handle file opening errors
        printf("Error opening file!\n");
        exit(1);
    }
    
    fwrite(message, sizeof(unsigned char), bitsToExtract / 8, fp); // Write the message to the file
    
    fclose(fp); // Close the file
    free(message); // Free the allocated memory
}

/* Main function */
int main() {
    char* imagePath = "image.bmp";
    char* message = "Hello, world! This is a secret message.";
    char* outputImagePath = "output.bmp";
    char* outputFilePath = "output.txt";
    
    hideMessageInImage(imagePath, message, outputImagePath);
    extractMessageFromImage(outputImagePath, outputFilePath);
    
    return 0;
}