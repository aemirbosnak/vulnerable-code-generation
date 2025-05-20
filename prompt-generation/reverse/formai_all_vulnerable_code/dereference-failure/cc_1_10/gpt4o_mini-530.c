//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 8192

void print_usage(const char *prog_name) {
    printf("Usage: %s <source_directory> <target_directory>\n", prog_name);
}

int copy_file(const char *source_path, const char *target_path) {
    FILE *source = fopen(source_path, "rb");
    if (!source) {
        perror("Failed to open source file");
        return -1;
    }

    FILE *target = fopen(target_path, "wb");
    if (!target) {
        perror("Failed to open target file");
        fclose(source);
        return -1;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes;

    while ((bytes = fread(buffer, 1, BUFFER_SIZE, source)) > 0) {
        fwrite(buffer, 1, bytes, target);
    }

    fclose(source);
    fclose(target);
    return 0;
}

void sync_file(const char *source_file, const char *target_file) {
    struct stat source_stat, target_stat;

    if (stat(source_file, &source_stat) == -1) {
        perror("Error retrieving source file statistics");
        return;
    }

    if (stat(target_file, &target_stat) == -1) {
        // File does not exist at target, copy it
        printf("Copying new file: %s to %s\n", source_file, target_file);
        copy_file(source_file, target_file);
    } else {
        // Compare modification times
        if (difftime(source_stat.st_mtime, target_stat.st_mtime) > 0) {
            printf("Updating file: %s to %s\n", source_file, target_file);
            copy_file(source_file, target_file);
        } else {
            printf("No need to update: %s\n", target_file);
        }
    }
}

void sync_directory(const char *source_dir, const char *target_dir) {
    DIR *dir = opendir(source_dir);
    if (!dir) {
        perror("Failed to open source directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') continue; // Skip hidden files

        char source_path[PATH_MAX];
        char target_path[PATH_MAX];

        snprintf(source_path, sizeof(source_path), "%s/%s", source_dir, entry->d_name);
        snprintf(target_path, sizeof(target_path), "%s/%s", target_dir, entry->d_name);

        if (entry->d_type == DT_REG) {
            // Regular file, sync it
            sync_file(source_path, target_path);
        } else if (entry->d_type == DT_DIR) {
            // Directory, create target directory then sync sub-directory
            mkdir(target_path, 0755);
            sync_directory(source_path, target_path);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *source_dir = argv[1];
    const char *target_dir = argv[2];

    // Create the target directory if it doesn't exist
    mkdir(target_dir, 0755);

    printf("Synchronizing directories...\n");
    sync_directory(source_dir, target_dir);
    printf("Synchronization complete.\n");

    return EXIT_SUCCESS;
}