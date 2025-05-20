//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>

#define MAX_FILES 100
#define MAX_METADATA_LENGTH 256

typedef struct {
    char filename[256];
    char metadata[MAX_METADATA_LENGTH];
} Metadata;

void extract_metadata(const char *filepath, Metadata *metadata) {
    // This function simulates metadata extraction from a file
    snprintf(metadata->filename, sizeof(metadata->filename), "%s", filepath);
    
    // Simulate some metadata extraction logic
    snprintf(metadata->metadata, sizeof(metadata->metadata), "Sample metadata for %s", filepath);
}

void print_metadata(const Metadata *metadata) {
    printf("File: %s\n", metadata->filename);
    printf("Metadata: %s\n", metadata->metadata);
}

int read_files_from_directory(const char *directory, Metadata *metadata_list) {
    DIR *dir;
    struct dirent *entry;
    int count = 0;

    if ((dir = opendir(directory)) == NULL) {
        perror("opendir");
        return -1;
    }
    
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Regular file
            if (count >= MAX_FILES) {
                break;
            }
            char filepath[512];
            snprintf(filepath, sizeof(filepath), "%s/%s", directory, entry->d_name);
            extract_metadata(filepath, &metadata_list[count]);
            count++;
        }
    }

    closedir(dir);
    return count;
}

void save_metadata_to_file(const Metadata *metadata_list, int num_files, const char *output_file) {
    FILE *file = fopen(output_file, "w");
    if (file == NULL) {
        perror("fopen");
        return;
    }

    for (int i = 0; i < num_files; i++) {
        fprintf(file, "File: %s\nMetadata: %s\n\n", metadata_list[i].filename, metadata_list[i].metadata);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <directory> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *directory = argv[1];
    const char *output_file = argv[2];
    Metadata metadata_list[MAX_FILES];

    int num_files = read_files_from_directory(directory, metadata_list);
    if (num_files < 0) {
        return EXIT_FAILURE;
    }

    save_metadata_to_file(metadata_list, num_files, output_file);
    printf("Metadata extraction complete. %d files processed.\n", num_files);

    return EXIT_SUCCESS;
}