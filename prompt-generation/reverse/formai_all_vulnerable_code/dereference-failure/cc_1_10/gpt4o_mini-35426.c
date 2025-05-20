//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom error codes
#define MEMORY_ALLOCATION_ERROR 1
#define FILE_OPEN_ERROR 2
#define FILE_READ_ERROR 3

void handleError(int errorCode) {
    switch (errorCode) {
        case MEMORY_ALLOCATION_ERROR:
            fprintf(stderr, "Error: Memory allocation failed!\n");
            break;
        case FILE_OPEN_ERROR:
            fprintf(stderr, "Error: Could not open the file!\n");
            break;
        case FILE_READ_ERROR:
            fprintf(stderr, "Error: Could not read from the file!\n");
            break;
        default:
            fprintf(stderr, "Unknown error occurred.\n");
            break;
    }
    exit(EXIT_FAILURE);
}

char *readFileContents(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        handleError(FILE_OPEN_ERROR);
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    char *buffer = (char *)malloc(fileSize + 1);
    if (!buffer) {
        fclose(file);
        handleError(MEMORY_ALLOCATION_ERROR);
    }

    size_t bytesRead = fread(buffer, 1, fileSize, file);
    if (bytesRead != fileSize) {
        free(buffer);
        fclose(file);
        handleError(FILE_READ_ERROR);
    }

    buffer[bytesRead] = '\0'; // Null-terminate the string
    fclose(file);
    return buffer;
}

void displayFileContents(const char *contents) {
    if (contents == NULL) {
        fprintf(stdout, "No content to display.\n");
        return;
    }
    printf("File Contents:\n----------------\n%s\n", contents);
}

void interactiveMenu() {
    char choice;
    char filename[256];

    do {
        printf("File Reader Menu:\n");
        printf("1. Read File\n");
        printf("2. Exit\n");
        printf("Choose an option: ");
        
        choice = getchar();
        while (getchar() != '\n'); // Clear the input buffer

        switch (choice) {
            case '1':
                printf("Enter the filename to read: ");
                if (fgets(filename, sizeof(filename), stdin)) {
                    filename[strcspn(filename, "\n")] = 0; // Remove newline

                    char *fileContents = readFileContents(filename);
                    displayFileContents(fileContents);
                    free(fileContents);
                } else {
                    fprintf(stderr, "Error reading filename.\n");
                }
                break;
            case '2':
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
                break;
        }
    } while (choice != '2');
}

int main() {
    printf("Welcome to the File Reader Program!\n");
    interactiveMenu();
    return 0;
}