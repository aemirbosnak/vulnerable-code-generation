//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define BUFFER_SIZE 8192

// Function to create a recovery directory if it doesn't exist
void create_recovery_directory(const char *recovery_dir) {
    struct stat st = {0};
    if (stat(recovery_dir, &st) == -1) {
        mkdir(recovery_dir, 0700);
        printf("Created recovery directory: %s\n", recovery_dir);
    } else {
        printf("Recovery directory already exists: %s\n", recovery_dir);
    }
}

// Function to copy a file
int copy_file(const char *source_path, const char *dest_path) {
    FILE *src_file = fopen(source_path, "rb");
    if (!src_file) {
        perror("Failed to open source file");
        return -1;
    }

    FILE *dest_file = fopen(dest_path, "wb");
    if (!dest_file) {
        fclose(src_file);
        perror("Failed to create destination file");
        return -1;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read, bytes_written;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        bytes_written = fwrite(buffer, 1, bytes_read, dest_file);
        if (bytes_written < bytes_read) {
            fprintf(stderr, "Error writing to file: %s\n", dest_path);
            fclose(src_file);
            fclose(dest_file);
            return -1;
        }
    }

    fclose(src_file);
    fclose(dest_file);
    return 0;
}

// Function to recover files from a directory
void recover_files(const char *directory_path, const char *extension, const char *recovery_dir) {
    DIR *dir = opendir(directory_path);
    if (!dir) {
        perror("Could not open directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Only regular files
            char *dot = strrchr(entry->d_name, '.');
            if (dot && strcmp(dot, extension) == 0) {
                char source_path[MAX_PATH];
                char dest_path[MAX_PATH];

                snprintf(source_path, sizeof(source_path), "%s/%s", directory_path, entry->d_name);
                snprintf(dest_path, sizeof(dest_path), "%s/%s", recovery_dir, entry->d_name);

                printf("Recovering: %s -> %s\n", source_path, dest_path);
                if (copy_file(source_path, dest_path) != 0) {
                    fprintf(stderr, "Failed to recover: %s\n", source_path);
                }
            }
        }
    }
    closedir(dir);
}

// Main function to execute the recovery tool
int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <directory_path> <file_extension> <recovery_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *directory_path = argv[1];
    const char *file_extension = argv[2];
    const char *recovery_directory = argv[3];

    printf("Starting data recovery...\n");
    create_recovery_directory(recovery_directory);
    recover_files(directory_path, file_extension, recovery_directory);
    printf("Data recovery completed!\n");

    return EXIT_SUCCESS;
}