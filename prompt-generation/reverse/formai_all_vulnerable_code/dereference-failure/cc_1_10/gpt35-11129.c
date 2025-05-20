//FormAI DATASET v1.0 Category: Data recovery tool ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILESIZE 104857600 // 100 MB

// Function to check if a file exists
int fileExists(char* filename) {
    FILE* file;
    if ((file = fopen(filename, "r"))) {
        fclose(file);
        return 1;
    }
    return 0;
}

// Function to read data from file
char* readFile(char* filename) {
    FILE* file;
    char* buffer = malloc(MAX_FILESIZE + 1);
    memset(buffer, 0, MAX_FILESIZE + 1);
    if ((file = fopen(filename, "rb"))) {
        fread(buffer, 1, MAX_FILESIZE, file);
        fclose(file);
        return buffer;
    }
    free(buffer);
    return NULL;
}

// Function to recover data
void recoverData(char* filename) {
    if (fileExists(filename)) {
        char* data = readFile(filename);
        if (data) {
            printf("Data recovered from file %s:\n%s", filename, data);
            free(data);
        } else {
            printf("Error reading data from file %s\n", filename);
        }
    } else {
        printf("File %s does not exist\n", filename);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    recoverData(argv[1]);
    return 0;
}