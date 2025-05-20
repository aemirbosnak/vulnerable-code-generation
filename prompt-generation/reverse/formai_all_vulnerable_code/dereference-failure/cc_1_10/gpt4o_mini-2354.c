//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Function prototypes
void sync_files(const char *src, const char *dest);
void copy_file(const char *src_file, const char *dest_file);
int compare_files(const char *file1, const char *file2);
void recursive_sync(const char *src, const char *dest);

void usage() {
    printf("Usage: file_sync <source_directory> <destination_directory>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        usage();
        return EXIT_FAILURE;
    }

    sync_files(argv[1], argv[2]);
    printf("Synchronization complete.\n");
    return EXIT_SUCCESS;
}

void sync_files(const char *src, const char *dest) {
    struct stat sb;
    if (stat(src, &sb) == -1 || !S_ISDIR(sb.st_mode)) {
        fprintf(stderr, "Source path is not a directory or does not exist.\n");
        exit(EXIT_FAILURE);
    }

    if (stat(dest, &sb) == -1) {
        if (mkdir(dest, 0700) == -1) {
            perror("Failed to create destination directory");
            exit(EXIT_FAILURE);
        }
    }

    recursive_sync(src, dest);
}

void recursive_sync(const char *src, const char *dest) {
    DIR *dir;
    struct dirent *entry;
    char src_path[BUFFER_SIZE], dest_path[BUFFER_SIZE];

    if ((dir = opendir(src)) == NULL) {
        perror("Failed to open source directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        // Ignore the . and .. entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(src_path, sizeof(src_path), "%s/%s", src, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest, entry->d_name);

        struct stat sb;
        if (stat(src_path, &sb) == -1) {
            perror("Failed to get file stats");
            continue;
        }

        if (S_ISDIR(sb.st_mode)) {
            // Recursively sync directories
            recursive_sync(src_path, dest_path);
        } else {
            // Sync files
            copy_file(src_path, dest_path);
        }
    }

    closedir(dir);
}

void copy_file(const char *src_file, const char *dest_file) {
    if (access(dest_file, F_OK) != -1) {
        // If the file exists, check if it is the same
        if (compare_files(src_file, dest_file) == 0) {
            return; // Files are the same, no need to copy
        }
    }

    FILE *src = fopen(src_file, "rb");
    FILE *dest = fopen(dest_file, "wb");
    
    if (!src || !dest) {
        perror("Failed to open file for copying");
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes;

    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) != 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(src);
    fclose(dest);
}

int compare_files(const char *file1, const char *file2) {
    FILE *f1 = fopen(file1, "rb");
    FILE *f2 = fopen(file2, "rb");

    if (!f1 || !f2) {
        perror("Failed to open files for comparison");
        return -1; // Error
    }

    char buffer1[BUFFER_SIZE], buffer2[BUFFER_SIZE];
    size_t bytes1, bytes2;

    while ((bytes1 = fread(buffer1, 1, sizeof(buffer1), f1)) != 0 && (bytes2 = fread(buffer2, 1, sizeof(buffer2), f2)) != 0) {
        if (bytes1 != bytes2 || memcmp(buffer1, buffer2, bytes1) != 0) {
            fclose(f1);
            fclose(f2);
            return -1; // Files are different
        }
    }

    int end_of_file = feof(f1) && feof(f2);
    fclose(f1);
    fclose(f2);
    
    return end_of_file ? 0 : -1; // 0 if same, -1 if different
}