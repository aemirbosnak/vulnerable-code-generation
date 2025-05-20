//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold metadata information
typedef struct {
    char *title;
    char *author;
    char *date;
    char *keywords;
} Metadata;

// Function to create a new Metadata instance
Metadata* create_metadata(const char *title, const char *author, const char *date, const char *keywords) {
    Metadata *metadata = (Metadata *)malloc(sizeof(Metadata));
    metadata->title = strdup(title);
    metadata->author = strdup(author);
    metadata->date = strdup(date);
    metadata->keywords = strdup(keywords);
    return metadata;
}

// Function to display metadata
void display_metadata(Metadata *metadata) {
    if (!metadata) {
        printf("Metadata not found!\n");
    } else {
        printf("Title: %s\n", metadata->title);
        printf("Author: %s\n", metadata->author);
        printf("Date: %s\n", metadata->date);
        printf("Keywords: %s\n", metadata->keywords);
    }
}

// Function to free memory of metadata
void free_metadata(Metadata *metadata) {
    free(metadata->title);
    free(metadata->author);
    free(metadata->date);
    free(metadata->keywords);
    free(metadata);
}

// Function to simulate searching for metadata
Metadata* search_metadata() {
    // This is where a detective might find relevant metadata
    printf("Sherlock Holmes deep in thought...\n");
    printf("As I peruse the dusty volumes of the library, I stumble across an intriguing manuscript...\n");
    
    // Let's pretend we have discovered a manuscript with specific metadata
    return create_metadata("The Adventure of the Speckled Band", 
                           "Sir Arthur Conan Doyle", 
                           "1892",
                           "mystery, detective, literature");
}

int main() {
    printf("Welcome to the Metadata Extractor in the Style of Sherlock Holmes!\n");
    printf("Detective Holmes is on the case, seeking the metadata...\n");

    // Sherlock's insightful search for metadata begins
    Metadata *found_metadata = search_metadata();
    
    // The metadata is displayed in the dim light of 221B Baker Street
    display_metadata(found_metadata);

    // Conclude the case and free the memory
    printf("The case is solved, but the adventure goes on...\n");
    free_metadata(found_metadata);

    return 0;
}