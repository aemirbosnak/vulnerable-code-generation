//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024

void sync_file(const char *source_path, const char *dest_path) {
    FILE *src_file, *dest_file;
    char buffer[1024];
    size_t bytes;

    src_file = fopen(source_path, "rb");
    if (!src_file) {
        perror("Failed to open source file");
        return;
    }

    dest_file = fopen(dest_path, "wb");
    if (!dest_file) {
        perror("Failed to open destination file");
        fclose(src_file);
        return;
    }

    while ((bytes = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        fwrite(buffer, 1, bytes, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);
    printf("Synchronized file: %s to %s\n", source_path, dest_path);
}

void check_and_sync(const char *source_dir, const char *dest_dir) {
    struct stat src_stat, dest_stat;
    DIR *dir;
    struct dirent *entry;
    
    dir = opendir(source_dir);
    if (!dir) {
        perror("Failed to open source directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char source_file[MAX_PATH];
        char dest_file[MAX_PATH];

        snprintf(source_file, sizeof(source_file), "%s/%s", source_dir, entry->d_name);
        snprintf(dest_file, sizeof(dest_file), "%s/%s", dest_dir, entry->d_name);

        if (stat(source_file, &src_stat) == -1) {
            perror("Failed to stat source file");
            continue;
        }

        if (stat(dest_file, &dest_stat) == -1) {
            // File doesn't exist in destination, copy it
            sync_file(source_file, dest_file);
        } else {
            // Check if source file is newer than the destination file
            if (difftime(src_stat.st_mtime, dest_stat.st_mtime) > 0) {
                sync_file(source_file, dest_file);
            } else {
                printf("No need to sync: %s is up to date.\n", dest_file);
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *source_directory = argv[1];
    const char *destination_directory = argv[2];

    check_and_sync(source_directory, destination_directory);

    return EXIT_SUCCESS;
}