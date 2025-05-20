//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: cheerful
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Here's a delightful C program that's like a secret treasure chest, waiting to reveal the hidden metadata gems within your files.

// Let's start with a dash of magic:
#define METADATA_MAGIC "Meta-Fun"

// Now, we'll create our own metadata container:
typedef struct {
    char magic[8];     // A magic string to identify our treasure
    unsigned int size;  // The size of our hidden riches
    char data[];      // The actual metadata, waiting to be discovered
} MetadataContainer;

// Prepare to embark on our metadata extraction adventure!
int main(int argc, char **argv) {
    // First, let's check if we have a worthy candidate:
    if (argc < 2) {
        printf("Hey there, adventurer! You need to provide a file to unlock its secrets.\n");
        return 1;
    }

    // Open the file, ready to delve into its depths:
    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        printf("Oh no! Couldn't open the file. Check if it exists and you have permission.\n");
        return 1;
    }

    // Seek to the end of the file, where the treasure might be hidden:
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, -fileSize, SEEK_END); // Move back to the start of the potential metadata

    // Let's verify the magic string to ensure we're on the right track:
    MetadataContainer container;
    fread(&container, sizeof(container), 1, file);
    if (strncmp(container.magic, METADATA_MAGIC, 8) != 0) {
        printf("Darn! No metadata treasure here. This file doesn't have our magic touch.\n");
        fclose(file);
        return 1;
    }

    // Hooray! We found our metadata container. Let's extract the goodies:
    char *metadata = calloc(container.size + 1, sizeof(char));
    fread(metadata, container.size, 1, file);

    // Time to unveil the hidden secrets:
    printf("Ta-da! Here's the metadata we found:\n%s\n", metadata);

    // Don't forget to clean up our adventure:
    free(metadata);
    fclose(file);

    printf("And that's a wrap! May you always find the treasures you seek.\n");
    return 0;
}