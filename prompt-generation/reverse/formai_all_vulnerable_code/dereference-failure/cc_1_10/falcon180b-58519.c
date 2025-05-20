//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100

// Function to shift the bytes in a buffer
void shiftBuffer(unsigned char* buffer, int amount) {
    int i;
    for (i = 0; i < amount; i++) {
        buffer[i] = buffer[i + 1];
    }
    buffer[amount] = 0;
}

// Function to read a file into a buffer
int readFile(FILE* file, unsigned char* buffer) {
    int bytesRead;
    bytesRead = fread(buffer, 1, MAX_FILE_NAME_LENGTH, file);
    if (bytesRead!= MAX_FILE_NAME_LENGTH) {
        printf("Error: Could not read file\n");
        exit(1);
    }
    return bytesRead;
}

// Function to write a buffer to a file
int writeFile(FILE* file, unsigned char* buffer) {
    int bytesWritten;
    bytesWritten = fwrite(buffer, 1, MAX_FILE_NAME_LENGTH, file);
    if (bytesWritten!= MAX_FILE_NAME_LENGTH) {
        printf("Error: Could not write file\n");
        exit(1);
    }
    return bytesWritten;
}

// Function to recover a deleted file
int recoverFile(char* fileName, char* recoveredFileName) {
    FILE* inputFile;
    FILE* outputFile;
    unsigned char buffer[MAX_FILE_NAME_LENGTH];

    // Open the input file
    inputFile = fopen(fileName, "rb");
    if (inputFile == NULL) {
        printf("Error: Could not open input file\n");
        exit(1);
    }

    // Open the output file
    outputFile = fopen(recoveredFileName, "wb");
    if (outputFile == NULL) {
        printf("Error: Could not open output file\n");
        exit(1);
    }

    // Read the input file
    int bytesRead = readFile(inputFile, buffer);

    // Shift the bytes in the buffer
    int i;
    for (i = 0; i < bytesRead; i++) {
        if (buffer[i] == 0) {
            shiftBuffer(buffer, i);
            bytesRead -= i;
            i = 0;
        }
    }

    // Write the buffer to the output file
    int bytesWritten = writeFile(outputFile, buffer);

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    return bytesWritten;
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <deleted_file_name> <recovered_file_name>\n", argv[0]);
        exit(1);
    }

    char* deletedFileName = argv[1];
    char* recoveredFileName = argv[2];

    int bytesRecovered = recoverFile(deletedFileName, recoveredFileName);
    printf("Recovered %d bytes to %s\n", bytesRecovered, recoveredFileName);

    return 0;
}