//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define BUFFER_SIZE 1024

void copy_file(const char *src, const char *dest);
int compare_files(const char *file1, const char *file2);
void synchronize_directories(const char *source, const char *dest);
void list_files(const char *directory);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *source = argv[1];
    const char *dest = argv[2];

    synchronize_directories(source, dest);

    printf("Synchronization complete!\n");
    return EXIT_SUCCESS;
}

void synchronize_directories(const char *source, const char *dest) {
    struct dirent *entry;
    DIR *src_dir = opendir(source);
    if (!src_dir) {
        perror("Failed to open source directory");
        return;
    }

    while ((entry = readdir(src_dir)) != NULL) {
        if (entry->d_name[0] == '.') continue; // Skip hidden files

        char src_path[MAX_PATH];
        char dest_path[MAX_PATH];

        snprintf(src_path, sizeof(src_path), "%s/%s", source, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest, entry->d_name);

        struct stat src_stat, dest_stat;
        if (stat(src_path, &src_stat) == 0) {
            if (stat(dest_path, &dest_stat) != 0 || compare_files(src_path, dest_path)) {
                printf("Copying %s to %s\n", src_path, dest_path);
                copy_file(src_path, dest_path);
            }
        }
    }
    closedir(src_dir);
}

void copy_file(const char *src, const char *dest) {
    FILE *src_file = fopen(src, "rb");
    FILE *dest_file = fopen(dest, "wb");

    if (!src_file || !dest_file) {
        perror("Error opening source or destination file");
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes;

    while ((bytes = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        fwrite(buffer, 1, bytes, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);
}

int compare_files(const char *file1, const char *file2) {
    FILE *f1 = fopen(file1, "rb");
    FILE *f2 = fopen(file2, "rb");

    if (!f1 || !f2) {
        perror("Error opening files for comparison");
        return 1; // Assume files are different if we can't open them
    }

    char buffer1[BUFFER_SIZE];
    char buffer2[BUFFER_SIZE];
    size_t bytes1, bytes2;

    while (1) {
        bytes1 = fread(buffer1, 1, sizeof(buffer1), f1);
        bytes2 = fread(buffer2, 1, sizeof(buffer2), f2);

        if (bytes1 != bytes2 || memcmp(buffer1, buffer2, bytes1) != 0) {
            fclose(f1);
            fclose(f2);
            return 1; // Files are different
        }

        if (bytes1 == 0) break; // End of files reached
    }

    fclose(f1);
    fclose(f2);
    return 0; // Files are the same
}