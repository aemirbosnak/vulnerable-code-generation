//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024
#define MAX_FILES 1000

typedef struct {
    char source[MAX_PATH_LENGTH];
    char destination[MAX_PATH_LENGTH];
    int sync_state; // 0: Unchanged, 1: Updated, 2: Exists only in source
} FileEntry;

void list_files(const char *dirname, FileEntry files[], int *file_count);
void sync_files(const FileEntry files[], int file_count);
void copy_file(const char *src, const char *dest);
int file_exists(const char *path);
void print_usage();
void create_directory(const char *dir);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return EXIT_FAILURE;
    }

    FileEntry files[MAX_FILES];
    int file_count = 0;

    list_files(argv[1], files, &file_count);
    list_files(argv[2], files, &file_count);

    sync_files(files, file_count);

    return EXIT_SUCCESS;
}

void list_files(const char *dirname, FileEntry files[], int *file_count) {
    struct dirent *entry;
    DIR *dp = opendir(dirname);
    if (dp == NULL) {
        perror("Error opening directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_type == DT_REG) {
            snprintf(files[*file_count].source, MAX_PATH_LENGTH, "%s/%s", dirname, entry->d_name);
            snprintf(files[*file_count].destination, MAX_PATH_LENGTH, "%s/%s", dirname, entry->d_name);
            files[*file_count].sync_state = 0;
            (*file_count)++;
        }
    }
    closedir(dp);
}

void sync_files(const FileEntry files[], int file_count) {
    for (int i = 0; i < file_count; i++) {
        if (files[i].sync_state == 0) {
            if (!file_exists(files[i].destination)) {
                copy_file(files[i].source, files[i].destination);
                printf("Copied: %s to %s\n", files[i].source, files[i].destination);
            } else {
                printf("Exists: %s\n", files[i].destination);
            }
        }
    }
}

void copy_file(const char *src, const char *dest) {
    FILE *source_file = fopen(src, "rb");
    FILE *dest_file = fopen(dest, "wb");

    if (source_file == NULL || dest_file == NULL) {
        perror("Error opening file for copy");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFSIZ];
    size_t size;

    while ((size = fread(buffer, 1, BUFSIZ, source_file)) > 0) {
        fwrite(buffer, 1, size, dest_file);
    }

    fclose(source_file);
    fclose(dest_file);
}

int file_exists(const char *path) {
    struct stat buffer;
    return (stat(path, &buffer) == 0);
}

void print_usage() {
    printf("Usage: sync <source_directory> <destination_directory>\n");
}

void create_directory(const char *dir) {
    // Placeholder for future directory creation
}