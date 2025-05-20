//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_METADATA_LENGTH 256
#define MAX_FILENAME_LENGTH 256

typedef struct Metadata {
    char filename[MAX_FILENAME_LENGTH];
    char filetype[MAX_METADATA_LENGTH];
    long filesize;
    char last_modified[MAX_METADATA_LENGTH];
} Metadata;

void extract_metadata(const char *filepath, Metadata *metadata) {
    struct stat file_stat;
    
    if (stat(filepath, &file_stat) == -1) {
        perror("Failed to get file status");
        return;
    }

    strcpy(metadata->filename, filepath);
    metadata->filesize = file_stat.st_size;
    strftime(metadata->last_modified, sizeof(metadata->last_modified), "%Y-%m-%d %H:%M:%S", localtime(&file_stat.st_mtime));

    // Simple file type detection
    const char *dot = strrchr(filepath, '.');
    if (!dot || dot == filepath) {
        strcpy(metadata->filetype, "unknown");
    } else {
        strcpy(metadata->filetype, dot + 1);
    }
}

void print_metadata(const Metadata *metadata) {
    printf("File: %s\n", metadata->filename);
    printf("Type: %s\n", metadata->filetype);
    printf("Size: %ld bytes\n", metadata->filesize);
    printf("Last Modified: %s\n", metadata->last_modified);
}

void extract_metadata_from_directory(const char *directory) {
    struct dirent *entry;
    DIR *dp = opendir(directory);
    if (dp == NULL) {
        perror("Failed to open directory");
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) {  // Regular file
            char filepath[MAX_FILENAME_LENGTH];
            snprintf(filepath, sizeof(filepath), "%s/%s", directory, entry->d_name);
            Metadata metadata;
            extract_metadata(filepath, &metadata);
            print_metadata(&metadata);
            printf("\n");
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *directory = argv[1];
    
    // Check if the provided path is a directory
    struct stat statbuf;
    if (stat(directory, &statbuf) != 0 || !S_ISDIR(statbuf.st_mode)) {
        fprintf(stderr, "%s is not a valid directory.\n", directory);
        return EXIT_FAILURE;
    }

    extract_metadata_from_directory(directory);

    return EXIT_SUCCESS;
}