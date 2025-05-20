//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_FILES 100
#define MAX_METADATA_LEN 256
#define MAX_FILE_NAME_LEN 512

typedef struct {
    char filename[MAX_FILE_NAME_LEN];
    uint32_t size; // in bytes
    char mime_type[MAX_METADATA_LEN];
    char creation_date[MAX_METADATA_LEN];
    char modification_date[MAX_METADATA_LEN];
} FileMetadata;

FileMetadata files[MAX_FILES];
int file_count = 0;

bool validate_metadata(FileMetadata *file) {
    if (file->size == 0) return false;
    if (strlen(file->mime_type) == 0) return false;
    if (strlen(file->creation_date) == 0) return false;
    if (strlen(file->modification_date) == 0) return false;

    return true;
}

void extract_metadata(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open file %s\n", filename);
        return;
    }

    fseek(file, 0, SEEK_END);
    uint32_t file_size = ftell(file);
    rewind(file);

    FileMetadata file_metadata;
    strncpy(file_metadata.filename, filename, MAX_FILE_NAME_LEN);
    file_metadata.size = file_size;
    snprintf(file_metadata.mime_type, MAX_METADATA_LEN, "application/octet-stream"); // This is a placeholder
    snprintf(file_metadata.creation_date, MAX_METADATA_LEN, "2023-01-01"); // This is a placeholder
    snprintf(file_metadata.modification_date, MAX_METADATA_LEN, "2023-01-01"); // This is a placeholder

    fclose(file);

    if (validate_metadata(&file_metadata)) {
        files[file_count++] = file_metadata;
    } else {
        fprintf(stderr, "Error: Metadata validation failed for file %s\n", filename);
    }
}

void print_metadata() {
    for (int i = 0; i < file_count; i++) {
        printf("File: %s\n", files[i].filename);
        printf("Size: %u bytes\n", files[i].size);
        printf("MIME Type: %s\n", files[i].mime_type);
        printf("Creation Date: %s\n", files[i].creation_date);
        printf("Modification Date: %s\n", files[i].modification_date);
        printf("-----------------------------------\n");
    }
}

void save_metadata_to_file(const char *output_file) {
    FILE *file = fopen(output_file, "w");
    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open output file %s\n", output_file);
        return;
    }

    for (int i = 0; i < file_count; i++) {
        fprintf(file, "File: %s\n", files[i].filename);
        fprintf(file, "Size: %u bytes\n", files[i].size);
        fprintf(file, "MIME Type: %s\n", files[i].mime_type);
        fprintf(file, "Creation Date: %s\n", files[i].creation_date);
        fprintf(file, "Modification Date: %s\n", files[i].modification_date);
        fprintf(file, "-----------------------------------\n");
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file1> <file2> ... <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *output_file = argv[argc - 1];

    for (int i = 1; i < argc - 1; i++) {
        extract_metadata(argv[i]);
    }

    print_metadata();
    save_metadata_to_file(output_file);

    return EXIT_SUCCESS;
}