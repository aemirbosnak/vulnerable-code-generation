//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_FILES 1024
#define MAX_PATH 1024
#define MAX_METADATA_SIZE 512

typedef struct {
    char name[MAX_PATH];
    char created[MAX_METADATA_SIZE];
    char modified[MAX_METADATA_SIZE];
    size_t size;
} FileMetadata;

void get_file_metadata(const char *file_path, FileMetadata *metadata) {
    struct stat file_stat;

    if (stat(file_path, &file_stat) == 0) {
        strncpy(metadata->name, file_path, MAX_PATH);
        snprintf(metadata->created, MAX_METADATA_SIZE, "%s", ctime(&file_stat.st_ctime));
        snprintf(metadata->modified, MAX_METADATA_SIZE, "%s", ctime(&file_stat.st_mtime));
        metadata->size = file_stat.st_size;
    } else {
        perror("Could not retrieve file metadata");
    }
}

void print_metadata(const FileMetadata *metadata) {
    printf("File Name: %s\n", metadata->name);
    printf("Created: %s", metadata->created);
    printf("Modified: %s", metadata->modified);
    printf("Size: %zu bytes\n", metadata->size);
}

void extract_metadata_from_directory(const char *dir_path) {
    struct dirent *entry;
    DIR *dp = opendir(dir_path);
    FileMetadata files[MAX_FILES];
    int file_count = 0;

    if (dp == NULL) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_type == DT_REG) {  // Only process regular files
            char file_path[MAX_PATH];
            snprintf(file_path, MAX_PATH, "%s/%s", dir_path, entry->d_name);
            get_file_metadata(file_path, &files[file_count]);
            file_count++;
            if (file_count >= MAX_FILES) {
                printf("Maximum file limit reached.\n");
                break;
            }
        }
    }

    closedir(dp);

    // Print metadata for all found files
    for (int i = 0; i < file_count; i++) {
        printf("\n--- Metadata for %s ---\n", files[i].name);
        print_metadata(&files[i]);
    }
}

void display_inspirational_message() {
    printf("\n*************************************\n");
    printf("*  Unlocking the secrets of files   *\n");
    printf("* With each line, a story unfolds!  *\n");
    printf("*************************************\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory-path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    display_inspirational_message();
    extract_metadata_from_directory(argv[1]);

    return EXIT_SUCCESS;
}