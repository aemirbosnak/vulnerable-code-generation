//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void print_usage() {
    printf("Usage: file_sync <source_directory> <target_directory>\n");
}

int file_exists(const char *file_path) {
    return access(file_path, F_OK) != -1;
}

void copy_file(const char *source_path, const char *target_path) {
    FILE *source = fopen(source_path, "rb");
    if (!source) {
        perror("Failed to open source file");
        exit(EXIT_FAILURE);
    }

    FILE *target = fopen(target_path, "wb");
    if (!target) {
        perror("Failed to open target file");
        fclose(source);
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, sizeof(char), BUFFER_SIZE, source)) > 0) {
        fwrite(buffer, sizeof(char), bytesRead, target);
    }

    fclose(source);
    fclose(target);
}

int should_sync(const char *source_path, const char *target_path) {
    struct stat src_stat, tgt_stat;
    if (stat(source_path, &src_stat) != 0 || stat(target_path, &tgt_stat) != 0) {
        return 1; // Synchronize if either file doesn't exist
    }
    return src_stat.st_mtime > tgt_stat.st_mtime; // Sync if source is newer
}

void sync_directory(const char *source_dir, const char *target_dir) {
    DIR *dir = opendir(source_dir);
    if (!dir) {
        perror("Failed to open source directory");
        exit(EXIT_FAILURE);
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') // Skip hidden files and directories
            continue;

        char source_file_path[PATH_MAX];
        char target_file_path[PATH_MAX];

        snprintf(source_file_path, sizeof(source_file_path), "%s/%s", source_dir, entry->d_name);
        snprintf(target_file_path, sizeof(target_file_path), "%s/%s", target_dir, entry->d_name);

        if (entry->d_type == DT_DIR) {
            mkdir(target_file_path, 0755); // Create the target directory if it doesn't exist
            sync_directory(source_file_path, target_file_path); // Recursive sync
        } else if (entry->d_type == DT_REG) {
            if (!file_exists(target_file_path) || should_sync(source_file_path, target_file_path)) {
                printf("Copying file: %s to %s\n", source_file_path, target_file_path);
                copy_file(source_file_path, target_file_path);
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return EXIT_FAILURE;
    }

    const char *source_directory = argv[1];
    const char *target_directory = argv[2];

    struct stat statbuf;
    if (stat(source_directory, &statbuf) != 0 || !S_ISDIR(statbuf.st_mode)) {
        fprintf(stderr, "Error: Source directory does not exist or is not a directory\n");
        return EXIT_FAILURE;
    }

    if (stat(target_directory, &statbuf) != 0) {
        if (mkdir(target_directory, 0755) != 0) {
            perror("Failed to create target directory");
            return EXIT_FAILURE;
        }
    } else if (!S_ISDIR(statbuf.st_mode)) {
        fprintf(stderr, "Error: Target path exists and is not a directory\n");
        return EXIT_FAILURE;
    }

    sync_directory(source_directory, target_directory);
    printf("Synchronization complete.\n");

    return EXIT_SUCCESS;
}