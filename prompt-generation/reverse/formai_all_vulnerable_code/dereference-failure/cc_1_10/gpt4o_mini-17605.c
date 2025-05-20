//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define PATH_MAX 4096
#define BUFFER_SIZE 1024

void print_usage(char *program_name) {
    fprintf(stderr, "Usage: %s <source_dir> <dest_dir>\n", program_name);
}

int is_directory(const char *path) {
    struct stat statbuf;
    stat(path, &statbuf);
    return S_ISDIR(statbuf.st_mode);
}

void copy_file(const char *source, const char *destination) {
    FILE *src = fopen(source, "rb");
    FILE *dest = fopen(destination, "wb");
    char buffer[BUFFER_SIZE];
    size_t bytes;

    if (!src || !dest) {
        fprintf(stderr, "Error opening files for copy\n");
        return;
    }

    while ((bytes = fread(buffer, 1, BUFFER_SIZE, src)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(src);
    fclose(dest);
}

void sync_directories(const char *source, const char *dest) {
    struct dirent *entry;
    DIR *dp = opendir(source);

    if (!dp) {
        fprintf(stderr, "Error opening directory: %s\n", source);
        return;
    }

    char source_path[PATH_MAX];
    char dest_path[PATH_MAX];

    while ((entry = readdir(dp)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(source_path, sizeof(source_path), "%s/%s", source, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest, entry->d_name);

        if (is_directory(source_path)) {
            mkdir(dest_path, 0755);
            sync_directories(source_path, dest_path);
        } else {
            copy_file(source_path, dest_path);
        }
    }

    closedir(dp);
}

void print_sync_info(const char *source, const char *dest) {
    printf("Synchronizing from %s to %s...\n", source, dest);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *source_directory = argv[1];
    const char *destination_directory = argv[2];

    if (!is_directory(source_directory) || !is_directory(destination_directory)) {
        fprintf(stderr, "Both source and destination must be valid directories.\n");
        return EXIT_FAILURE;
    }

    print_sync_info(source_directory, destination_directory);
    sync_directories(source_directory, destination_directory);
    printf("Synchronization completed.\n");

    return EXIT_SUCCESS;
}