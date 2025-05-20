//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Error codes
#define SUCCESS 0
#define ERR_FILE_NOT_FOUND 1
#define ERR_MEMORY_ALLOCATION 2
#define ERR_INVALID_INPUT 3

// Function prototypes
int readFile(const char *filename, char **buffer);
int processBuffer(char *buffer);
void cleanup(char *buffer);

int main(int argc, char *argv[]) {
    // Check arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return ERR_INVALID_INPUT;
    }

    char *dataBuffer = NULL;
    int errorCode = readFile(argv[1], &dataBuffer);
    
    if (errorCode != SUCCESS) {
        switch(errorCode) {
            case ERR_FILE_NOT_FOUND:
                fprintf(stderr, "Error: File not found '%s'.\n", argv[1]);
                return ERR_FILE_NOT_FOUND;
            case ERR_MEMORY_ALLOCATION:
                fprintf(stderr, "Error: Memory allocation failed.\n");
                return ERR_MEMORY_ALLOCATION;
            default:
                fprintf(stderr, "Unknown error occurred.\n");
                return errorCode;
        }
    }

    errorCode = processBuffer(dataBuffer);
    if (errorCode != SUCCESS) {
        fprintf(stderr, "Error: Processing buffer failed with code %d.\n", errorCode);
        cleanup(dataBuffer);
        return errorCode;
    }

    cleanup(dataBuffer);
    return SUCCESS;
}

// Function to read the entire file into a buffer
int readFile(const char *filename, char **buffer) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        return ERR_FILE_NOT_FOUND;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    *buffer = (char *)malloc(fileSize + 1);
    if (*buffer == NULL) {
        fclose(file);
        return ERR_MEMORY_ALLOCATION;
    }

    size_t bytesRead = fread(*buffer, 1, fileSize, file);
    (*buffer)[bytesRead] = '\0'; // Null-terminate the buffer

    fclose(file);
    return SUCCESS;
}

// Function to process the data in the buffer
int processBuffer(char *buffer) {
    if (buffer == NULL) {
        return ERR_INVALID_INPUT;
    }

    // Process the buffer by counting the words
    int wordCount = 0;
    char *token = strtok(buffer, " \n\r\t");
    while (token != NULL) {
        wordCount++;
        token = strtok(NULL, " \n\r\t");
    }

    printf("Total words in the file: %d\n", wordCount);
    return SUCCESS;
}

// Cleanup function to free allocated memory
void cleanup(char *buffer) {
    if (buffer != NULL) {
        free(buffer);
    }
}