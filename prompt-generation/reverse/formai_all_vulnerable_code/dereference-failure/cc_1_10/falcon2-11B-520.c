//Falcon2-11B DATASET v1.0 Category: Data recovery tool ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a file and store its contents in a buffer
void readFile(const char* filename, char* buffer, int maxSize) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    int fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    buffer[maxSize - 1] = '\0'; // Ensure buffer is null-terminated

    if (fileSize > maxSize) {
        printf("File size exceeds maximum buffer size.\n");
        exit(1);
    }

    fread(buffer, 1, fileSize, file);
    fclose(file);
}

// Function to search for a specific pattern in the buffer
int searchPattern(const char* pattern, char* buffer, int maxSize) {
    int patternLength = strlen(pattern);
    int i, j;

    for (i = 0; i < maxSize - patternLength; i++) {
        for (j = 0; j < patternLength; j++) {
            if (buffer[i + j]!= pattern[j]) {
                break;
            }
        }

        if (j == patternLength) {
            printf("Pattern found at index %d\n", i);
            return 1;
        }
    }

    return 0;
}

int main() {
    char buffer[256];
    int maxSize = 256;

    // Read the file and store its contents in a buffer
    readFile("example.txt", buffer, maxSize);

    // Search for a specific pattern in the buffer
    const char* pattern = "Hello";
    int found = searchPattern(pattern, buffer, maxSize);

    if (found) {
        printf("Pattern found!\n");
    } else {
        printf("Pattern not found.\n");
    }

    return 0;
}