//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void embedMessage(char *sourceFile, char *destinationFile, char *message) {
    FILE *fpSource, *fpDest;
    int fileSize, messageLength, i, j;
    char *data, *messageData;
    unsigned char mask = 128;

    fpSource = fopen(sourceFile, "rb");
    if (fpSource == NULL) {
        printf("Source file not found\n");
        exit(1);
    }

    fpDest = fopen(destinationFile, "wb");
    if (fpDest == NULL) {
        printf("Unable to create destination file\n");
        exit(1);
    }

    // Get file size
    fseek(fpSource, 0L, SEEK_END);
    fileSize = ftell(fpSource);
    rewind(fpSource);

    // Allocate memory for file data
    data = (char*) malloc(fileSize + 1);
    if (data == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }

    // Read file data
    fread(data, sizeof(char), fileSize, fpSource);

    // Close source file
    fclose(fpSource);

    // Allocate memory for message data
    messageLength = strlen(message);
    messageData = (char*) malloc(messageLength + 1);
    if (messageData == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    strcpy(messageData, message);

    // Embed message into file data
    for (i = 0, j = 0; i < fileSize; i++, j++) {
        if (j == messageLength) {
            j = 0;
        }
        data[i] |= (messageData[j] & mask) >> (7 - i%8);
    }

    // Write file data to destination file
    fwrite(data, sizeof(char), fileSize, fpDest);

    // Close destination file
    fclose(fpDest);

    // Free memory
    free(data);
    free(messageData);

    printf("Message embedded successfully\n");
}

void extractMessage(char *sourceFile) {
    FILE *fpSource;
    int fileSize, i;
    char *data;
    unsigned char messageChar, mask = 1;

    fpSource = fopen(sourceFile, "rb");
    if (fpSource == NULL) {
        printf("Source file not found\n");
        exit(1);
    }

    // Get file size
    fseek(fpSource, 0L, SEEK_END);
    fileSize = ftell(fpSource);
    rewind(fpSource);

    // Allocate memory for file data
    data = (char*) malloc(fileSize + 1);
    if (data == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }

    // Read file data
    fread(data, sizeof(char), fileSize, fpSource);

    // Close source file
    fclose(fpSource);

    // Extract message from file data
    printf("Embedded message: ");
    for (i = 0; i < fileSize; i++) {
        messageChar = (data[i] & mask) << (7 - i%8);
        printf("%c", messageChar);
    }
    printf("\n");

    // Free memory
    free(data);
}

int main() {
    char filename[] = "test.txt";
    char message[] = "hello world";

    // Embed message into file
    embedMessage(filename, "watermarked.txt", message);

    // Extract message from file
    extractMessage("watermarked.txt");

    return 0;
}