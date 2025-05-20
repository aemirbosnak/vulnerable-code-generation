//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_FILES 100
#define MAX_FILE_SIZE 1024 * 1024

// Structure to store file information
struct FileInfo {
    char name[256];
    size_t size;
    time_t timestamp;
};

// Function to get file information
struct FileInfo get_file_info(const char *filename) {
    struct FileInfo file_info;
    struct stat file_stat;

    // Get file stat
    if (stat(filename, &file_stat) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }

    // Get file name
    strcpy(file_info.name, filename);

    // Get file size
    file_info.size = file_stat.st_size;

    // Get file timestamp
    file_info.timestamp = file_stat.st_mtime;

    return file_info;
}

// Function to compare two file infos
int compare_file_infos(const void *a, const void *b) {
    const struct FileInfo *file_info_a = (const struct FileInfo *)a;
    const struct FileInfo *file_info_b = (const struct FileInfo *)b;

    // Compare file names
    int cmp = strcmp(file_info_a->name, file_info_b->name);
    if (cmp != 0) {
        return cmp;
    }

    // Compare file sizes
    if (file_info_a->size != file_info_b->size) {
        return file_info_a->size - file_info_b->size;
    }

    // Compare file timestamps
    return file_info_a->timestamp - file_info_b->timestamp;
}

// Function to backup files
void backup_files(const char *source_dir, const char *target_dir) {
    // Create target directory if it doesn't exist
    if (mkdir(target_dir, 0755) == -1) {
        perror("mkdir");
        exit(EXIT_FAILURE);
    }

    // Open source directory
    DIR *source_dirp = opendir(source_dir);
    if (source_dirp == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    // Get all files in source directory
    struct dirent *dp;
    struct FileInfo file_infos[MAX_FILES];
    int num_files = 0;
    while ((dp = readdir(source_dirp)) != NULL) {
        // Skip hidden files
        if (dp->d_name[0] == '.') {
            continue;
        }

        // Get file info
        struct FileInfo file_info = get_file_info(dp->d_name);

        // Add file info to array
        file_infos[num_files++] = file_info;
    }

    // Sort file infos by name
    qsort(file_infos, num_files, sizeof(struct FileInfo), compare_file_infos);

    // Backup files
    for (int i = 0; i < num_files; i++) {
        // Open source file
        FILE *source_fp = fopen(file_infos[i].name, "rb");
        if (source_fp == NULL) {
            perror("fopen");
            continue;
        }

        // Open target file
        FILE *target_fp = fopen(file_infos[i].name, "wb");
        if (target_fp == NULL) {
            perror("fopen");
            continue;
        }

        // Copy file
        char buffer[MAX_FILE_SIZE];
        size_t bytes_read;
        while ((bytes_read = fread(buffer, sizeof(char), MAX_FILE_SIZE, source_fp)) > 0) {
            fwrite(buffer, sizeof(char), bytes_read, target_fp);
        }

        // Close files
        fclose(source_fp);
        fclose(target_fp);
    }

    // Close source directory
    closedir(source_dirp);
}

// Main function
int main(int argc, char **argv) {
    // Check arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_dir> <target_dir>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Backup files
    backup_files(argv[1], argv[2]);

    return EXIT_SUCCESS;
}