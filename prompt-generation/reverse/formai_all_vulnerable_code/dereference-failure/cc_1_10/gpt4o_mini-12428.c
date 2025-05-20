//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

// Function prototypes
void countWordsInFile(const char *filename);
void processBuffer(char *buffer, size_t size, int *wordCount);
char* readFromFile(const char *filename);
void freeResources(char *buffer);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Loop through each file provided
    for (int i = 1; i < argc; i++) {
        printf("Processing file: %s\n", argv[i]);
        countWordsInFile(argv[i]);
    }

    return 0;
}

// Function to count words in a file
void countWordsInFile(const char *filename) {
    char *buffer = readFromFile(filename);
    if (buffer == NULL) {
        fprintf(stderr, "Error reading file: %s\n", filename);
        return;
    }

    int wordCount = 0;
    processBuffer(buffer, strlen(buffer), &wordCount);
    printf("Total words in %s: %d\n", filename, wordCount);

    freeResources(buffer);
}

// Function to read the entire content of a file into a buffer
char* readFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    size_t fileLength = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = (char *)malloc(fileLength + 1);
    if (buffer == NULL) {
        perror("Error allocating memory");
        fclose(file);
        return NULL;
    }

    fread(buffer, 1, fileLength, file);
    buffer[fileLength] = '\0'; // Null-terminate the string
    fclose(file);
    return buffer;
}

// Function to process the buffer and count words
void processBuffer(char *buffer, size_t size, int *wordCount) {
    int inWord = 0;
    
    for (size_t i = 0; i < size; i++) {
        if (isspace(buffer[i])) {
            if (inWord) {
                (*wordCount)++;
                inWord = 0;
            }
        } else {
            inWord = 1;
        }
    }
    
    // If we were in a word at the end of the buffer, count it
    if (inWord) {
        (*wordCount)++;
    }
}

// Function to free allocated resources
void freeResources(char *buffer) {
    free(buffer);
}