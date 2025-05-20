//MISTRAL-7B DATASET v1.0 Category: Metadata Extractor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cheerful Metadata Extractor - CME for short

// Structure to represent a single metadata entry
typedef struct {
    char name[50];
    char value[200];
} MetadataEntry;

// Function to extract metadata from a given file
int extractMetadata(const char *filename, MetadataEntry **metadata, size_t *numEntries) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    size_t fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Assume metadata is stored in a BMP format (Replace this with your desired format)
    if (fileSize < 54) {
        printf("Error: File %s is too small to contain metadata\n", filename);
        fclose(file);
        return 1;
    }

    MetadataEntry *metadataArray = calloc(1, sizeof(MetadataEntry) * 10); // Assuming 10 entries as maximum
    size_t numEntriesFound = 0;

    // Parse BMP header
    char bmpHeader[18] = { 'B', 'M', ' ', 0, 0, 54, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    fread(bmpHeader, sizeof(char), 18, file);

    int sizeImage = *(int *)(&bmpHeader[2]);
    int width = *(int *)(&bmpHeader[18]);
    int height = *(int *)(&bmpHeader[22]);

    // Extract metadata entries
    while (numEntriesFound < 10 && ftell(file) < fileSize) {
        // Assume metadata is stored in a specific format (Replace this with your desired format)
        MetadataEntry *entry = &metadataArray[numEntriesFound];
        fread(entry->name, sizeof(char), 49, file);
        fread(entry->value, sizeof(char), 199, file);
        entry->name[49] = '\0';
        entry->value[199] = '\0';
        numEntriesFound++;
    }

    *metadata = metadataArray;
    *numEntries = numEntriesFound;

    fclose(file);
    return 0;
}

// Function to print metadata entries in a cheerful manner
void printMetadata(const MetadataEntry *metadata, size_t numEntries) {
    printf("\nCheerful Metadata Extractor Results:\n");

    for (size_t i = 0; i < numEntries; i++) {
        printf("\nEntry %zu:\n", i + 1);
        printf("Name: %s\n", metadata[i].name);
        printf("Value: %s\n", metadata[i].value);

        // Print some cheerful messages based on the metadata
        if (!strcmp(metadata[i].name, "Author")) {
            printf("What a fantastic creation by %s!\n", metadata[i].value);
        }
        if (!strcmp(metadata[i].name, "Title")) {
            printf("This work is entitled: %s\n", metadata[i].value);
        }
        if (!strcmp(metadata[i].name, "Date")) {
            printf("This work was created on: %s\n", metadata[i].value);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    MetadataEntry *metadata = NULL;
    size_t numEntries = 0;

    if (extractMetadata(argv[1], &metadata, &numEntries)) {
        printf("Error: Failed to extract metadata from file %s\n", argv[1]);
        return 1;
    }

    printMetadata(metadata, numEntries);

    free(metadata);

    printf("\nHappiness and success in your metadata exploration!\n");
    return 0;
}