//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024
#define BUFFER_SIZE 4096

void sync_files(const char *source, const char *target) {
    FILE *source_file, *target_file;
    char buffer[BUFFER_SIZE];
    size_t bytes_read, bytes_written;

    // Open the source file for reading
    source_file = fopen(source, "rb");
    if (!source_file) {
        perror("Failed to open source file");
        exit(EXIT_FAILURE);
    }

    // Open the target file for writing (create if not exists)
    target_file = fopen(target, "wb");
    if (!target_file) {
        perror("Failed to open target file");
        fclose(source_file);
        exit(EXIT_FAILURE);
    }

    // Copy the content
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, source_file)) > 0) {
        bytes_written = fwrite(buffer, 1, bytes_read, target_file);
        if (bytes_written < bytes_read) {
            perror("Error writing to target file");
            fclose(source_file);
            fclose(target_file);
            exit(EXIT_FAILURE);
        }
    }

    // Close the files
    fclose(source_file);
    fclose(target_file);
}

void copy_directory(const char *source_dir, const char *target_dir) {
    struct dirent *entry;
    struct stat statbuf;
    char source_path[MAX_PATH], target_path[MAX_PATH];
    DIR *dir = opendir(source_dir);

    if (!dir) {
        perror("Failed to open source directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip "." and ".."
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            snprintf(source_path, MAX_PATH, "%s/%s", source_dir, entry->d_name);
            snprintf(target_path, MAX_PATH, "%s/%s", target_dir, entry->d_name);
            
            // Get the status of the file
            if (stat(source_path, &statbuf) == -1) {
                perror("Stat failed");
                continue;
            }

            if (S_ISDIR(statbuf.st_mode)) {
                // Create a directory in the target location
                mkdir(target_path, 0755);
                // Recur for subdirectory
                copy_directory(source_path, target_path);
            } else {
                // File exists, we need to compare and sync if different
                FILE *file1 = fopen(source_path, "rb");
                FILE *file2 = fopen(target_path, "rb");
                
                if (!file2) {
                    // Target file does not exist - copy the file
                    sync_files(source_path, target_path);
                } else {
                    // Compare files
                    int different = 0;
                    char buf1[BUFFER_SIZE], buf2[BUFFER_SIZE];
                    size_t read1, read2;

                    while (!different && (read1 = fread(buf1, 1, BUFFER_SIZE, file1)) > 0) {
                        read2 = fread(buf2, 1, BUFFER_SIZE, file2);
                        if (read1 != read2 || memcmp(buf1, buf2, read1) != 0) {
                            different = 1;
                        }
                    }

                    // If different or an error occurred
                    if (different) {
                        sync_files(source_path, target_path);
                    }

                    fclose(file1);
                    fclose(file2);
                }
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <target_directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *source_dir = argv[1];
    const char *target_dir = argv[2];

    // Create target directory if it does not exist
    mkdir(target_dir, 0755);

    // Start the synchronization process
    copy_directory(source_dir, target_dir);

    printf("Synchronization complete!\n");
    return 0;
}