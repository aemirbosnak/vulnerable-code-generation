//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Function to read the content of the source file
void readFile(const char* filePath, char** buffer, size_t* size) {
    FILE* file = fopen(filePath, "r");
    if (file == NULL) {
        perror("Unable to open source file");
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    *size = ftell(file);
    fseek(file, 0, SEEK_SET);

    *buffer = malloc(*size + 1);
    if (*buffer == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fread(*buffer, 1, *size, file);
    (*buffer)[*size] = '\0'; // Null terminate the string

    fclose(file);
}

// Function to write content to the destination file
void writeFile(const char* filePath, const char* content) {
    FILE* file = fopen(filePath, "w");
    if (file == NULL) {
        perror("Unable to open destination file");
        exit(EXIT_FAILURE);
    }

    fputs(content, file);
    fclose(file);
}

// Function to synchronize files
void synchronizeFiles(const char* source, const char* destination) {
    char* content = NULL;
    size_t size = 0;

    printf("Starting the tranquil process of synchronizing files...\n");

    // Read content from the source file
    readFile(source, &content, &size);

    // Write content to the destination file
    writeFile(destination, content);

    printf("The gentle whispers of the source have been mirrored into the destination.\n");

    free(content); // Free the allocated memory
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char* sourceFile = argv[1];
    const char* destinationFile = argv[2];

    // Invoke the synchronization process
    synchronizeFiles(sourceFile, destinationFile);

    printf("The synchronization has completed peacefully. 🌼\n");
    return 0;
}