//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILES 100
#define MAX_FILENAME_LEN 256

// Structure to hold file metadata
typedef struct {
    char filename[MAX_FILENAME_LEN];
    size_t size;
    char *content;
} Metadata;

// Function prototypes
void printMetadata(Metadata *meta);
int extractKeywords(const char *content, const char *keywords[], int keywordCount);
void addJoke(const char *filename);

int main() {
    printf("Welcome to the C Metadata Extractor, aka the \"Data Detective\"!\n");
    printf("I will help you uncover the juicy details hidden in your files!\n");

    Metadata files[MAX_FILES];
    int fileCount = 0;

    // Loop to gather file information
    while (fileCount < MAX_FILES) {
        printf("Enter the filename (or type 'exit' to finish): ");
        char input[MAX_FILENAME_LEN];
        fgets(input, sizeof(input), stdin);
        
        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0) {
            printf("Hooray! You're finished! Total files processed: %d\n", fileCount);
            break;
        }

        // Open the file and fetch metadata
        FILE *file = fopen(input, "r");
        if (!file) {
            printf("Oh no! I can’t find the file \"%s\". Make sure it exists or stop making jokes!\n", input);
        } else {
            fseek(file, 0, SEEK_END);
            files[fileCount].size = ftell(file);
            fseek(file, 0, SEEK_SET);

            // Allocate memory for file content
            files[fileCount].content = (char *)malloc(files[fileCount].size + 1);
            fread(files[fileCount].content, 1, files[fileCount].size, file);
            files[fileCount].content[files[fileCount].size] = '\0'; // Null-terminate

            strncpy(files[fileCount].filename, input, MAX_FILENAME_LEN);
            printf("Successfully opened \"%s\". Size: %zu bytes.\n", files[fileCount].filename, files[fileCount].size);
            fileCount++;
            fclose(file);
        }
    }

    // Print out the metadata for each file
    printf("\nLet's see what we found:\n");
    for (int i = 0; i < fileCount; i++) {
        printMetadata(&files[i]);
        addJoke(files[i].filename);
        free(files[i].content); // Free allocated content
    }

    printf("Thank you for using the Data Detective! Don't forget to tip your programmer!\n");
    return 0;
}

// Function to print metadata of a file
void printMetadata(Metadata *meta) {
    printf("\nFile: %s\n", meta->filename);
    printf("Size: %zu bytes\n", meta->size);
    // You can add more metadata printing here later on
    printf("Content Preview: %.50s...\n", meta->content); // Print the first 50 characters
}

// Function to count keywords in the file content
int extractKeywords(const char *content, const char *keywords[], int keywordCount) {
    // This function would actually do something intelligent, but we're just here for the laughs.
    int count = 0;

    for (int i = 0; i < keywordCount; i++) {
        if (strstr(content, keywords[i]) != NULL) {
            count++;
            printf("Keyword \"%s\" found! 🎉\n", keywords[i]);
        } else {
            printf("Keyword \"%s\"? Nope! Not today! 🚫\n", keywords[i]);
        }
    }
    return count;
}

// Function to add a random joke based on the filename
void addJoke(const char *filename) {
    printf("Why did the developer go broke?\n");
    printf("Because they used up all their cache on the file \"%s\"!\n\n", filename);
}