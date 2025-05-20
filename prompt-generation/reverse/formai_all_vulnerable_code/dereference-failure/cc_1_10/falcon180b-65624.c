//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the metadata struct
typedef struct {
    char *filename;
    int filesize;
    char *author;
    char *date;
    char *title;
} metadata;

// Function to extract metadata
metadata *extract_metadata(char *filename) {
    metadata *metadata = malloc(sizeof(metadata));
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }
    fseek(file, 0, SEEK_END);
    metadata->filesize = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *buffer = malloc(metadata->filesize);
    fread(buffer, metadata->filesize, 1, file);
    fclose(file);

    // Extract author
    char *author = strstr(buffer, "author:");
    if (author!= NULL) {
        author += 8;
        metadata->author = strdup(author);
    } else {
        metadata->author = NULL;
    }

    // Extract date
    char *date = strstr(buffer, "date:");
    if (date!= NULL) {
        date += 6;
        metadata->date = strdup(date);
    } else {
        metadata->date = NULL;
    }

    // Extract title
    char *title = strstr(buffer, "title:");
    if (title!= NULL) {
        title += 7;
        metadata->title = strdup(title);
    } else {
        metadata->title = NULL;
    }

    // Extract filename
    metadata->filename = strdup(filename);

    return metadata;
}

// Function to print metadata
void print_metadata(metadata *metadata) {
    printf("Filename: %s\n", metadata->filename);
    printf("Filesize: %d bytes\n", metadata->filesize);
    if (metadata->author!= NULL) {
        printf("Author: %s\n", metadata->author);
    } else {
        printf("Author: Unknown\n");
    }
    if (metadata->date!= NULL) {
        printf("Date: %s\n", metadata->date);
    } else {
        printf("Date: Unknown\n");
    }
    if (metadata->title!= NULL) {
        printf("Title: %s\n", metadata->title);
    } else {
        printf("Title: Unknown\n");
    }
}

// Main function
int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    char *filename = argv[1];
    metadata *metadata = extract_metadata(filename);
    print_metadata(metadata);
    free(metadata->author);
    free(metadata->date);
    free(metadata->title);
    free(metadata->filename);
    free(metadata);
    return 0;
}