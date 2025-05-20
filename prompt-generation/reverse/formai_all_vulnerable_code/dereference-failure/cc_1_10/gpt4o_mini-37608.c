//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void print_usage() {
    printf("File Synchronizer Utility\n");
    printf("Usage: sync_files <source_directory> <target_directory>\n");
}

int is_directory(const char *path) {
    struct stat statbuf;
    if (stat(path, &statbuf) != 0) {
        return 0; // Error accessing path
    }
    return S_ISDIR(statbuf.st_mode);
}

void copy_file(const char *source_file, const char *target_file) {
    FILE *src = fopen(source_file, "rb");
    FILE *dest = fopen(target_file, "wb");
    if (!src || !dest) {
        perror("Failed to open file");
        return;
    }
    
    char buffer[BUFFER_SIZE];
    size_t bytes;
    while ((bytes = fread(buffer, 1, BUFFER_SIZE, src)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }
    
    fclose(src);
    fclose(dest);
}

void synchronize_directories(const char *source_dir, const char *target_dir) {
    DIR *dir = opendir(source_dir);
    if (!dir) {
        perror("Failed to open source directory");
        return;
    }
    
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip current and parent directory entries
        }
        
        char source_path[PATH_MAX];
        char target_path[PATH_MAX];
        snprintf(source_path, sizeof(source_path), "%s/%s", source_dir, entry->d_name);
        snprintf(target_path, sizeof(target_path), "%s/%s", target_dir, entry->d_name);

        if (is_directory(source_path)) {
            // Create target directory if it doesn't exist
            mkdir(target_path, 0755);
            // Recursive synchronization
            synchronize_directories(source_path, target_path);
        } else {
            // Copy file from source to target
            copy_file(source_path, target_path);
            printf("Copied: %s to %s\n", source_path, target_path);
        }
    }
    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        print_usage();
        return 1;
    }

    const char *source_dir = argv[1];
    const char *target_dir = argv[2];

    // Check if source directory exists
    if (!is_directory(source_dir)) {
        fprintf(stderr, "Source directory does not exist.\n");
        return 1;
    }

    // Create target directory if it doesn't exist
    if (!is_directory(target_dir)) {
        if (mkdir(target_dir, 0755) != 0) {
            perror("Failed to create target directory");
            return 1;
        }
    }

    // Start synchronization
    printf("Synchronizing from '%s' to '%s'...\n", source_dir, target_dir);
    synchronize_directories(source_dir, target_dir);
    printf("Synchronization complete!\n");

    return 0;
}