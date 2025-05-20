//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 8192

void print_usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s <source_directory> <target_directory>\n", prog_name);
}

int is_file_modified(const char *source_file, const char *target_file) {
    struct stat source_stat, target_stat;

    if (stat(source_file, &source_stat) != 0) {
        perror("Failed to get source file status");
        return 0;
    }
    
    if (stat(target_file, &target_stat) != 0) {
        return 1; // Target file does not exist, therefore it's modified
    }

    return source_stat.st_mtime > target_stat.st_mtime; // Check modification time
}

void copy_file(const char *source_file, const char *target_file) {
    FILE *src = fopen(source_file, "rb");
    if (!src) {
        perror("Failed to open source file");
        return;
    }

    FILE *dest = fopen(target_file, "wb");
    if (!dest) {
        perror("Failed to open target file");
        fclose(src);
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes;

    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(src);
    fclose(dest);
}

void sync_directories(const char *source_dir, const char *target_dir) {
    struct dirent *entry;
    DIR *dp = opendir(source_dir);
    if (dp == NULL) {
        perror("Failed to open source directory");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        // Skip current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char source_file[PATH_MAX];
        char target_file[PATH_MAX];

        snprintf(source_file, sizeof(source_file), "%s/%s", source_dir, entry->d_name);
        snprintf(target_file, sizeof(target_file), "%s/%s", target_dir, entry->d_name);

        if (entry->d_type == DT_REG) { // Regular file
            if (is_file_modified(source_file, target_file)) {
                printf("Copying %s to %s\n", source_file, target_file);
                copy_file(source_file, target_file);
            }
        } else if (entry->d_type == DT_DIR) { // Directory
            // Create target directory if it does not exist
            mkdir(target_file, 0755); // Set permissions 755

            // Synchronize subdirectories
            sync_directories(source_file, target_file);
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    sync_directories(argv[1], argv[2]);
    
    return EXIT_SUCCESS;
}