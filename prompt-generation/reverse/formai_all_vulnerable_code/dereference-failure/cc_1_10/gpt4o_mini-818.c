//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_METADATA_LENGTH 512

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    char creation_date[MAX_METADATA_LENGTH];
    char last_modified[MAX_METADATA_LENGTH];
    char file_size[MAX_METADATA_LENGTH];
} FileMetadata;

void getMetadata(const char *filename, FileMetadata *metadata) {
    struct stat file_stat;

    if (stat(filename, &file_stat) == 0) {
        strncpy(metadata->filename, filename, MAX_FILENAME_LENGTH);
        sprintf(metadata->creation_date, "%ld", file_stat.st_ctime);
        sprintf(metadata->last_modified, "%ld", file_stat.st_mtime);
        sprintf(metadata->file_size, "%lld", (long long)file_stat.st_size);
    } else {
        perror("Failed to get file information");
        exit(EXIT_FAILURE);
    }
}

void printMetadata(const FileMetadata *metadata) {
    printf("Filename: %s\n", metadata->filename);
    printf("Creation Date: %s\n", metadata->creation_date);
    printf("Last Modified: %s\n", metadata->last_modified);
    printf("File Size: %s bytes\n", metadata->file_size);
    printf("--------------------------------\n");
}

void extractMetadataFromDirectory(const char *dir_name) {
    DIR *dir;
    struct dirent *ent;
    char full_path[MAX_FILENAME_LENGTH];
    FileMetadata metadata;

    if ((dir = opendir(dir_name)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            // Skip the current and parent directory entries
            if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
                continue;
            }

            snprintf(full_path, sizeof(full_path), "%s/%s", dir_name, ent->d_name);
            getMetadata(full_path, &metadata);
            printMetadata(&metadata);
        }
        closedir(dir);
    } else {
        perror("Could not open directory");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    extractMetadataFromDirectory(argv[1]);
    return EXIT_SUCCESS;
}