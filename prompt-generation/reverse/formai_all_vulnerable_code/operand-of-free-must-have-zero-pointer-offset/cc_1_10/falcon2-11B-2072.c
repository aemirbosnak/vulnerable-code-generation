//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encode a message in an image file
void encode(char* fileName, char* message) {
    // Read the image file
    FILE* imageFile = fopen(fileName, "rb");
    if (imageFile == NULL) {
        fprintf(stderr, "Failed to open image file: %s\n", fileName);
        exit(1);
    }

    // Read the image data into a buffer
    unsigned char* imageData = (unsigned char*)malloc(fread(NULL, 1, 0, imageFile));
    fclose(imageFile);

    // Split the image data into rows
    unsigned char* row;
    unsigned char* nextRow;
    unsigned int rowSize = 0;
    for (unsigned int i = 0; i < imageData[0]; i++) {
        row = (unsigned char*)malloc(imageData[0]);
        memcpy(row, &imageData[i], imageData[0]);
        rowSize += imageData[0];
        nextRow = row + imageData[0];
        fwrite(row, 1, imageData[0], stdout);
        free(row);
    }

    // Encode the message into the image data
    unsigned char* encodedData = (unsigned char*)malloc(strlen(message) + rowSize);
    memcpy(encodedData, rowSize, rowSize);
    memcpy(encodedData + rowSize, message, strlen(message));

    // Split the encoded data into rows
    unsigned char* encodedRow;
    unsigned char* nextEncodedRow;
    unsigned int encodedRowSize = 0;
    for (unsigned int i = 0; i < encodedData[0]; i++) {
        encodedRow = (unsigned char*)malloc(encodedData[0]);
        memcpy(encodedRow, &encodedData[i], encodedData[0]);
        encodedRowSize += encodedData[0];
        nextEncodedRow = encodedRow + encodedData[0];
        memcpy(nextEncodedRow, &rowSize, imageData[0]);
        free(encodedRow);
    }

    // Replace the image data with the encoded data
    unsigned char* imageData2 = (unsigned char*)malloc(encodedRowSize);
    memcpy(imageData2, encodedRow, encodedRowSize);

    // Write the modified image data back to the file
    FILE* imageFile2 = fopen(fileName, "wb");
    if (imageFile2 == NULL) {
        fprintf(stderr, "Failed to open image file: %s\n", fileName);
        exit(1);
    }
    fwrite(imageData2, 1, encodedRowSize, imageFile2);
    fclose(imageFile2);

    // Free memory
    free(encodedData);
    free(imageData2);
    free(row);
    free(nextRow);
    free(encodedRow);
    free(nextEncodedRow);
}

// Function to decode a message from an image file
void decode(char* fileName, char* message) {
    // Read the image file
    FILE* imageFile = fopen(fileName, "rb");
    if (imageFile == NULL) {
        fprintf(stderr, "Failed to open image file: %s\n", fileName);
        exit(1);
    }

    // Read the image data into a buffer
    unsigned char* imageData = (unsigned char*)malloc(fread(NULL, 1, 0, imageFile));
    fclose(imageFile);

    // Split the image data into rows
    unsigned char* row;
    unsigned char* nextRow;
    unsigned int rowSize = 0;
    for (unsigned int i = 0; i < imageData[0]; i++) {
        row = (unsigned char*)malloc(imageData[0]);
        memcpy(row, &imageData[i], imageData[0]);
        rowSize += imageData[0];
        nextRow = row + imageData[0];
        fwrite(row, 1, imageData[0], stdout);
        free(row);
    }

    // Decode the message from the image data
    unsigned char* decodedData = (unsigned char*)malloc(strlen(message) + rowSize);
    memcpy(decodedData, rowSize, rowSize);
    memcpy(decodedData + rowSize, message, strlen(message));

    // Split the decoded data into rows
    unsigned char* decodedRow;
    unsigned char* nextDecodedRow;
    unsigned int decodedRowSize = 0;
    for (unsigned int i = 0; i < decodedData[0]; i++) {
        decodedRow = (unsigned char*)malloc(decodedData[0]);
        memcpy(decodedRow, &decodedData[i], decodedData[0]);
        decodedRowSize += decodedData[0];
        nextDecodedRow = decodedRow + decodedData[0];
        memcpy(nextDecodedRow, &rowSize, imageData[0]);
        free(decodedRow);
    }

    // Print the decoded message
    printf("%s\n", decodedData);

    // Free memory
    free(decodedData);
    free(imageData);
    free(row);
    free(nextRow);
    free(decodedRow);
    free(nextDecodedRow);
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <image file> <message>\n", argv[0]);
        exit(1);
    }

    // Encode the message into the image file
    encode(argv[1], argv[2]);

    // Decode the message from the image file
    decode(argv[1], argv[2]);

    return 0;
}