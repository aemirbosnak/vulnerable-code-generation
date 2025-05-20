//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "exciting_file.txt"
#define BUFFER_SIZE 256

// Function prototypes
void checkFileOpening(FILE *file);
void checkMemoryAllocation(void *ptr);
void writeToFile(const char *data);
void readFromFile(void);
void handleError(const char *errorMessage);

int main() {
    char input[BUFFER_SIZE];

    printf("🎉 Welcome to the Exciting File Handler! 🎉\n");
    // Let's write something awesome into the file
    printf("Please enter some text to write to the file: ");
    fgets(input, BUFFER_SIZE, stdin);

    // Writing to the file
    writeToFile(input);
    
    // Now, let's read back from the file
    printf("Let's read what we just wrote... 📖\n");
    readFromFile();

    printf("✨ All done! Thanks for using the Exciting File Handler! ✨\n");
    return 0;
}

void writeToFile(const char *data) {
    FILE *file = fopen(FILENAME, "w");
    checkFileOpening(file); // Check if file opened.

    // Write to the file!
    if (fputs(data, file) == EOF) {
        handleError("Failed to write data to the file.");
    }
    
    printf("🚀 Successfully wrote to the file: %s", data);
    fclose(file); // Don't forget to close it!
}

void readFromFile(void) {
    FILE *file = fopen(FILENAME, "r");
    checkFileOpening(file); // Check if file opened.

    char *buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
    checkMemoryAllocation(buffer); // Check memory allocation.
    
    printf("Reading from the file... 📜\n");
    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        printf("💬 %s", buffer);
    }

    free(buffer); // Free the allocated memory
    fclose(file); // Don't forget to close it!
}

void checkFileOpening(FILE *file) {
    if (file == NULL) {
        handleError("Could not open file!");
    }
}

void checkMemoryAllocation(void *ptr) {
    if (ptr == NULL) {
        handleError("Memory allocation failed!");
    }
}

void handleError(const char *errorMessage) {
    fprintf(stderr, "🚨 ERROR: %s 🚨\n", errorMessage);
    exit(EXIT_FAILURE); // Exit the program with an error status.
}