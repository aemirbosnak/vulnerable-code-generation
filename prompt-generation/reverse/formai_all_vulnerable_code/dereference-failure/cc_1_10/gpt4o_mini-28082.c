//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_FILENAME_LENGTH 256
#define BUFFER_SIZE 1024

typedef struct {
    FILE *file;
    char filename[MAX_FILENAME_LENGTH];
} FileHandler;

void handleError(const char *context) {
    fprintf(stderr, "Error: %s: %s\n", context, strerror(errno));
    exit(EXIT_FAILURE);
}

FileHandler* openFile(const char *filename, const char *mode) {
    FileHandler *handler = malloc(sizeof(FileHandler));
    if (handler == NULL) {
        handleError("Failed to allocate FileHandler");
    }

    strncpy(handler->filename, filename, MAX_FILENAME_LENGTH - 1);
    handler->filename[MAX_FILENAME_LENGTH - 1] = '\0';

    handler->file = fopen(filename, mode);
    if (handler->file == NULL) {
        free(handler);
        handleError("Failed to open file");
    }

    return handler;
}

void closeFile(FileHandler *handler) {
    if (handler == NULL) {
        return; // Nothing to close
    }

    if (fclose(handler->file) != 0) {
        handleError("Failed to close file");
    }
    
    free(handler);
}

void writeToFile(FileHandler *handler, const char *text) {
    if (handler == NULL || handler->file == NULL) {
        handleError("Invalid file handler");
    }

    if (fputs(text, handler->file) == EOF) {
        handleError("Failed to write to file");
    }
}

void readFromFile(FileHandler *handler) {
    if (handler == NULL || handler->file == NULL) {
        handleError("Invalid file handler");
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, handler->file) != NULL) {
        printf("%s", buffer);
    }

    if (ferror(handler->file)) {
        handleError("Failed to read from file");
    }
}

void clearFileContent(FileHandler *handler) {
    if (handler == NULL || handler->file == NULL) {
        handleError("Invalid file handler");
    }

    // Closing file to reset the content
    closeFile(handler);
    handler->file = fopen(handler->filename, "w");
    if (handler->file == NULL) {
        handleError("Failed to reopen file for writing");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FileHandler *fileHandler = openFile(argv[1], "a+");

    // Writing sample content to file
    writeToFile(fileHandler, "Hello, World!\n");
    writeToFile(fileHandler, "This is a C error-handling example.\n");

    // Reseting file pointer to the beginning for reading
    rewind(fileHandler->file);

    printf("Contents of the file:\n");
    readFromFile(fileHandler);

    fclose(fileHandler->file);
    free(fileHandler);

    // Clear the file content for demonstration
    fileHandler = openFile(argv[1], "r+");
    printf("\nClearing the file content...\n");
    clearFileContent(fileHandler);
    printf("File content cleared. Current content:\n");
    rewind(fileHandler->file); // Check if the content is cleared
    readFromFile(fileHandler);

    closeFile(fileHandler);
    return EXIT_SUCCESS;
}