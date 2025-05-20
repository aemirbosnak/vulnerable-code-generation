//FormAI DATASET v1.0 Category: Ebook reader ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define enum for ebook formats
typedef enum {
    EPUB,
    MOBI,
    PDF
} EbookFormat;

// Define struct for ebook metadata
typedef struct {
    char title[100];
    char author[100];
    EbookFormat format;
    int pageCount;
} EbookMetadata;

// Define struct for ebook
typedef struct {
    EbookMetadata metadata;
    char* content;
} Ebook;

// Function to read ebook from file
Ebook readEbookFromFile(char* filename) {
    // Open file for reading
    FILE* file = fopen(filename, "r");
    // Allocate memory for ebook metadata
    EbookMetadata* metadata = (EbookMetadata*) malloc(sizeof(EbookMetadata));
    // Read metadata from file
    fscanf(file, "Title: %99[^\n]\nAuthor: %99[^\n]\nFormat: %d\nPage Count: %d\n", metadata->title, metadata->author, &(metadata->format), &(metadata->pageCount));
    // Allocate memory for ebook content
    char* content = (char*) malloc(sizeof(char) * metadata->pageCount * 1024);
    // Read content from file
    fread(content, sizeof(char), metadata->pageCount * 1024, file);
    // Create ebook struct and assign metadata and content
    Ebook ebook;
    ebook.metadata = *metadata;
    ebook.content = content;
    // Close file
    fclose(file);
    // Return ebook
    return ebook;
}

// Function to print ebook metadata
void printEbookMetadata(EbookMetadata metadata) {
    printf("\nTitle: %s\nAuthor: %s\nFormat: %d\nPage Count: %d\n", metadata.title, metadata.author, metadata.format, metadata.pageCount);
}

int main() {
    // Read ebook from file
    Ebook ebook = readEbookFromFile("example.epub");
    // Print ebook metadata
    printEbookMetadata(ebook.metadata);
    // Print ebook content
    printf("\n%s\n", ebook.content);
    // Free ebook content memory
    free(ebook.content);
    // Free ebook metadata memory
    free(&ebook.metadata);
    // Return 0 to indicate successful execution
    return 0;
}