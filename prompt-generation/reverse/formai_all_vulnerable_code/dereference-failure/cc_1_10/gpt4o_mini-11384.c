//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_NAME_LENGTH 256
#define MAX_METADATA_LENGTH 512

typedef struct {
    char filename[MAX_NAME_LENGTH];
    char author[MAX_NAME_LENGTH];
    char date[MAX_NAME_LENGTH];
    char description[MAX_METADATA_LENGTH];
    int num_lines;
} Metadata;

void clear_metadata(Metadata* md) {
    memset(md->filename, 0, sizeof(md->filename));
    memset(md->author, 0, sizeof(md->author));
    memset(md->date, 0, sizeof(md->date));
    memset(md->description, 0, sizeof(md->description));
    md->num_lines = 0;
}

void print_metadata(const Metadata* md) {
    printf("Filename: %s\n", md->filename);
    printf("Author: %s\n", md->author);
    printf("Date: %s\n", md->date);
    printf("Description: %s\n", md->description);
    printf("Number of lines: %d\n", md->num_lines);
}

void read_file(const char* filename, Metadata* md) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return;
    }

    clear_metadata(md);
    strncpy(md->filename, filename, MAX_NAME_LENGTH - 1);

    char line[MAX_METADATA_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "Author: ", 8) == 0) {
            strncpy(md->author, line + 8, MAX_NAME_LENGTH - 1);
            md->author[strcspn(md->author, "\n")] = 0; // Remove newline character
        } else if (strncmp(line, "Date: ", 6) == 0) {
            strncpy(md->date, line + 6, MAX_NAME_LENGTH - 1);
            md->date[strcspn(md->date, "\n")] = 0;
        } else if (strncmp(line, "Description: ", 13) == 0) {
            strncpy(md->description, line + 13, MAX_METADATA_LENGTH - 1);
            md->description[strcspn(md->description, "\n")] = 0;
        } else {
            md->num_lines++;
        }
    }

    fclose(file);
}

void extract_metadata_from_files(const char* files[], int num_files) {
    Metadata metadata[MAX_FILES];
    
    for (int i = 0; i < num_files; i++) {
        read_file(files[i], &metadata[i]);
    }

    printf("=== Metadata Extractor ===\n");
    for (int i = 0; i < num_files; i++) {
        printf("\nMetadata for file: %s\n", metadata[i].filename);
        print_metadata(&metadata[i]);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file1> <file2> ... <fileN>\n", argv[0]);
        return EXIT_FAILURE;
    }

    extract_metadata_from_files(argv + 1, argc - 1);
    
    return EXIT_SUCCESS;
}