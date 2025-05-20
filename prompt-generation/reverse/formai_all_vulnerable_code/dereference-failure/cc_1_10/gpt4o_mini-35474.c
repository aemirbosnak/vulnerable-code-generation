//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LEN 1024

void sync_files(const char *source_dir, const char *target_dir);
void download_file(const char *source_file, const char *target_file);
int file_needs_sync(const char *source_file, const char *target_file);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <target_directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sync_files(argv[1], argv[2]);
    printf("File synchronization completed.\n");

    return EXIT_SUCCESS;
}

void sync_files(const char *source_dir, const char *target_dir) {
    DIR *dir;
    struct dirent *entry;
    char source_path[MAX_PATH_LEN];
    char target_path[MAX_PATH_LEN];

    if ((dir = opendir(source_dir)) == NULL) {
        perror("Unable to open source directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        // Ignore current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(source_path, sizeof(source_path), "%s/%s", source_dir, entry->d_name);
        snprintf(target_path, sizeof(target_path), "%s/%s", target_dir, entry->d_name);

        struct stat statbuf;
        if (stat(source_path, &statbuf) == -1) {
            perror("Error getting file stats");
            continue;
        }

        // If it's a directory, recursively sync
        if (S_ISDIR(statbuf.st_mode)) {
            mkdir(target_path, 0755);
            sync_files(source_path, target_path);
        } else {
            if (file_needs_sync(source_path, target_path)) {
                download_file(source_path, target_path);
            }
        }
    }

    closedir(dir);
}

void download_file(const char *source_file, const char *target_file) {
    FILE *src, *dest;
    char buffer[8192];
    size_t bytes;

    src = fopen(source_file, "rb");
    if (src == NULL) {
        perror("Error opening source file");
        return;
    }

    dest = fopen(target_file, "wb");
    if (dest == NULL) {
        perror("Error creating target file");
        fclose(src);
        return;
    }

    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(src);
    fclose(dest);
    printf("Synced file: %s to %s\n", source_file, target_file);
}

int file_needs_sync(const char *source_file, const char *target_file) {
    struct stat source_stat, target_stat;

    if (stat(source_file, &source_stat) == -1) {
        perror("Error getting source file stats");
        return 1; // If we cannot access source, consider as needing sync
    }

    if (stat(target_file, &target_stat) == -1) {
        // Target file does not exist, needs download
        return 1;
    }

    // Check if the modification times are different
    return source_stat.st_mtime > target_stat.st_mtime;
}