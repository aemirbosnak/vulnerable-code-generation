//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Function to calculate the size of a file
long get_file_size(const char *filename) {
    struct stat st;
    if (stat(filename, &st) == 0) {
        return st.st_size;
    }
    return -1;
}

// Function to compare two files based on their contents
int compare_files(const char *file1, const char *file2) {
    FILE *f1 = fopen(file1, "rb");
    FILE *f2 = fopen(file2, "rb");
    if (!f1 || !f2) {
        return -1; // Error opening files
    }

    char buffer1[BUFFER_SIZE];
    char buffer2[BUFFER_SIZE];
    size_t read1, read2;

    while ((read1 = fread(buffer1, 1, BUFFER_SIZE, f1)) > 0) {
        read2 = fread(buffer2, 1, BUFFER_SIZE, f2);
        if (read1 != read2 || memcmp(buffer1, buffer2, read1) != 0) {
            fclose(f1);
            fclose(f2);
            return 0; // Files differ
        }
    }

    fclose(f1);
    fclose(f2);
    return 1; // Files are identical
}

// Function to copy a file from source to destination
void copy_file(const char *source, const char *destination) {
    FILE *src = fopen(source, "rb");
    FILE *dest = fopen(destination, "wb");
    if (src == NULL || dest == NULL) {
        perror("Failed to open files for copying");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, src)) > 0) {
        fwrite(buffer, 1, bytesRead, dest);
    }

    fclose(src);
    fclose(dest);
}

// Function to synchronize the contents of two directories
void sync_directories(const char *srcDir, const char *destDir) {
    DIR *dir = opendir(srcDir);
    if (!dir) {
        perror("Could not open source directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip the special entries "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char srcPath[512];
        char destPath[512];

        snprintf(srcPath, sizeof(srcPath), "%s/%s", srcDir, entry->d_name);
        snprintf(destPath, sizeof(destPath), "%s/%s", destDir, entry->d_name);

        struct stat st;
        if (stat(srcPath, &st) == 0) {
            if (S_ISREG(st.st_mode)) {
                // If it's a file, synchronize
                if (access(destPath, F_OK) != 0 || get_file_size(srcPath) != get_file_size(destPath) ||
                    compare_files(srcPath, destPath) == 0) {
                    printf("Copying '%s' to '%s'\n", srcPath, destPath);
                    copy_file(srcPath, destPath);
                }
            } else if (S_ISDIR(st.st_mode)) {
                // If it's a directory, recursively sync
                mkdir(destPath, 0755);
                sync_directories(srcPath, destPath);
            }
        }
    }
    closedir(dir);

    // Handle files in destDir that are not in srcDir
    dir = opendir(destDir);
    if (!dir) {
        perror("Could not open destination directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char srcPath[512];
        char destPath[512];

        snprintf(srcPath, sizeof(srcPath), "%s/%s", srcDir, entry->d_name);
        snprintf(destPath, sizeof(destPath), "%s/%s", destDir, entry->d_name);

        if (access(srcPath, F_OK) != 0) {
            printf("File '%s' does not exist in source. Deleting from destination.\n", destPath);
            remove(destPath);
        }
    }

    closedir(dir);
}

// Main function to start synchronization process
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    sync_directories(argv[1], argv[2]);
    printf("Synchronization completed.\n");
    return EXIT_SUCCESS;
}