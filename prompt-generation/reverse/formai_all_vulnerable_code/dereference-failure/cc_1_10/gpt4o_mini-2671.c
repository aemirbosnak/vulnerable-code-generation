//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_METADATA_LENGTH 256
#define MAX_FILES 100

typedef struct {
    char filename[MAX_METADATA_LENGTH];
    char creationDate[MAX_METADATA_LENGTH];
    char author[MAX_METADATA_LENGTH];
    char description[MAX_METADATA_LENGTH];
} Metadata;

void extract_metadata(const char *filename, Metadata *meta) {
    // Simulate metadata extraction
    strcpy(meta->filename, filename);
    snprintf(meta->creationDate, sizeof(meta->creationDate), "2023-09-03");
    snprintf(meta->author, sizeof(meta->author), "John Doe");
    snprintf(meta->description, sizeof(meta->description), "A sample metadata description.");
}

void print_metadata(const Metadata *meta) {
    printf("Filename: %s\n", meta->filename);
    printf("Creation Date: %s\n", meta->creationDate);
    printf("Author: %s\n", meta->author);
    printf("Description: %s\n", meta->description);
    printf("-----------------------------------\n");
}

void list_files(const char *path, Metadata *metadataArr, int *count) {
    DIR *dir = opendir(path);
    struct dirent *entry;

    if (dir == NULL) {
        perror("Failed to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Regular file
            if (*count < MAX_FILES) {
                char fullpath[MAX_METADATA_LENGTH];
                snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);
                extract_metadata(fullpath, &metadataArr[*count]);
                (*count)++;
            } else {
                printf("Max file limit reached. Cannot add more files.\n");
                break;
            }
        }
    }
    closedir(dir);
}

void display_all_metadata(const Metadata *metadataArr, int count) {
    for (int i = 0; i < count; i++) {
        print_metadata(&metadataArr[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory-path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *directoryPath = argv[1];
    Metadata metadataArr[MAX_FILES];
    int fileCount = 0;

    list_files(directoryPath, metadataArr, &fileCount);
    display_all_metadata(metadataArr, fileCount);

    return EXIT_SUCCESS;
}