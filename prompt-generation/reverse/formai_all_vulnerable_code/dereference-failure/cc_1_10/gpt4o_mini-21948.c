//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_PATH 1024

// Function to compare two files based on size and modification time
int files_are_equal(const char *src_path, const char *dst_path) {
    struct stat src_stat, dst_stat;

    if (stat(src_path, &src_stat) != 0 || stat(dst_path, &dst_stat) != 0) {
        return 0; // Unable to get stats for one or both files
    }

    return src_stat.st_size == dst_stat.st_size && 
           src_stat.st_mtime == dst_stat.st_mtime;
}

// Function to copy source file to destination
void copy_file(const char *src_path, const char *dst_path) {
    FILE *src_file = fopen(src_path, "rb");
    if (!src_file) {
        perror("Cannot open source file");
        return;
    }
    
    FILE *dst_file = fopen(dst_path, "wb");
    if (!dst_file) {
        perror("Cannot open destination file");
        fclose(src_file);
        return;
    }

    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        fwrite(buffer, 1, bytes, dst_file);
    }

    fclose(src_file);
    fclose(dst_file);
}

// Function to synchronize files from the source directory to the destination directory
void synchronize_directories(const char *src_dir, const char *dst_dir) {
    struct dirent *entry;
    DIR *dir = opendir(src_dir);
    
    if (!dir) {
        perror("Cannot open source directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip . and ..
        }

        char src_path[MAX_PATH];
        char dst_path[MAX_PATH];

        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
        snprintf(dst_path, sizeof(dst_path), "%s/%s", dst_dir, entry->d_name);

        struct stat src_stat;
        if (stat(src_path, &src_stat) == 0) {
            // Check if destination file exists
            if (access(dst_path, F_OK) == -1) {
                printf("Copying new file: %s to %s\n", src_path, dst_path);
                copy_file(src_path, dst_path);
            } else if (!files_are_equal(src_path, dst_path)) {
                printf("Updating file: %s to %s\n", src_path, dst_path);
                copy_file(src_path, dst_path);
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

    // The paths provided by the user
    const char *source_directory = argv[1];
    const char *destination_directory = argv[2];

    // Synchronize the directories
    synchronize_directories(source_directory, destination_directory);

    printf("Synchronization completed between %s and %s\n", source_directory, destination_directory);
    return EXIT_SUCCESS;
}