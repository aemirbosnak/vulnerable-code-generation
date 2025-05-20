//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom struct to represent metadata
typedef struct Metadata {
    char *name;           // Name of the metadata field
    int size;            // Size of the metadata field in bytes
    unsigned int offset;  // Offset of the metadata field in bytes
} Metadata;

// Custom function to extract metadata from a binary data buffer
Metadata *extract_metadata(unsigned char *data, int data_size) {
    if (data == NULL || data_size <= 0) {
        return NULL;
    }

    // Initialize the metadata array
    Metadata *metadata = malloc(sizeof(Metadata) * 10);  // Assuming a maximum of 10 metadata fields
    int num_metadata = 0;

    // Loop through the data buffer to find metadata fields
    unsigned char *ptr = data;
    while (ptr < data + data_size) {
        // Check for "META" magic number
        if (ptr[0] == 'M' && ptr[1] == 'E' && ptr[2] == 'T' && ptr[3] == 'A') {
            // Get the name of the metadata field
            char name[32] = {0};
            memcpy(name, ptr + 4, 31);

            // Get the size of the metadata field
            int size = *(int *)(ptr + 36);

            // Get the offset of the metadata field
            unsigned int offset = *(unsigned int *)(ptr + 40);

            // Add the metadata field to the array
            metadata[num_metadata].name = malloc(strlen(name) + 1);
            strcpy(metadata[num_metadata].name, name);
            metadata[num_metadata].size = size;
            metadata[num_metadata].offset = offset;
            num_metadata++;
        }

        // Advance the pointer to the next potential metadata field
        ptr += 4;
    }

    // Resize the metadata array to fit the actual number of metadata fields
    metadata = realloc(metadata, sizeof(Metadata) * num_metadata);

    return metadata;
}

// Custom function to print the extracted metadata
void print_metadata(Metadata *metadata, int num_metadata) {
    if (metadata == NULL || num_metadata <= 0) {
        return;
    }

    printf("Wow! Look at all this metadata I found:\n");
    for (int i = 0; i < num_metadata; i++) {
        printf(" - %s: size = %d, offset = %u\n",
            metadata[i].name, metadata[i].size, metadata[i].offset);
    }
}

// Main function
int main() {
    // Get the binary data from a file
    FILE *fp = fopen("data.bin", "rb");
    if (fp == NULL) {
        printf("Oops, I can't find the data file!\n");
        return -1;
    }

    fseek(fp, 0L, SEEK_END);
    int data_size = ftell(fp);
    rewind(fp);
    unsigned char *data = malloc(data_size);
    fread(data, 1, data_size, fp);
    fclose(fp);

    // Extract the metadata from the binary data
    Metadata *metadata = extract_metadata(data, data_size);

    // Print the extracted metadata
    print_metadata(metadata, 10);  // Assuming a maximum of 10 metadata fields

    // Free the allocated memory
    for (int i = 0; i < 10; i++) {
        free(metadata[i].name);
    }
    free(metadata);
    free(data);

    printf("Ta-da! I'm done extracting metadata like a pro!\n");
    return 0;
}