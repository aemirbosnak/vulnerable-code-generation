//FormAI DATASET v1.0 Category: Data recovery tool ; Style: shape shifting
// Shape Shifting C Data Recovery Tool
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for maximum file size and block size
#define MAX_FILE_SIZE 10000000 // 10 MB 
#define BLOCK_SIZE 512

// Function to read data from file
void readFile(char *filename, char *buffer) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Failed to open file %s.\n", filename);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    if (size > MAX_FILE_SIZE) {
        printf("File is too large to recover.\n");
        exit(1);
    }
    rewind(fp);
    fread(buffer, size, 1, fp);
    fclose(fp);
}

// Function to write data to file
void writeFile(char *filename, char *data, int size) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Failed to open file %s.\n", filename);
        exit(1);
    }
    fwrite(data, size, 1, fp);
    fclose(fp);
}

// Function to shape shift recovered data
void shapeShift(char *data, int size, int key, int method) {
    switch(method) {
        case 1: // XOR encryption
            for (int i = 0; i < size; i++) {
                data[i] = data[i] ^ key;
            }
            break;
        case 2: // Caesar cipher
            for (int i = 0; i < size; i++) {
                data[i] = (data[i] + key) % 256;
            }
            break;
        case 3: // Reverse string
            for (int i = 0, j = size - 1; i < j; i++, j--) {
                char temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
            break;
        case 4: // Base64 encode
            // TODO: Implement Base64
            break;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <filename> <key> <method>\n", argv[0]);
        printf("Methods: 1=XOR, 2=Caesar, 3=Reverse, 4=Base64\n");
        exit(1);
    }
    char *filename = argv[1];
    int key = atoi(argv[2]);
    int method = atoi(argv[3]);

    char *buffer = (char *) malloc(MAX_FILE_SIZE);
    readFile(filename, buffer);
    shapeShift(buffer, strlen(buffer), key, method);
    writeFile("recovered.data", buffer, strlen(buffer));
    printf("Data successfully recovered and shape shifted.\n");
    
    free(buffer); // Always free allocated memory

    return 0;
}