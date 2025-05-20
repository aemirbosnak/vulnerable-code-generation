//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

// Custom data structures
typedef struct FileInfo {
    char *name;
    long size;
} FileInfo;

typedef struct DirectoryInfo {
    char *name;
    long size;
    FileInfo *files;
    int num_files;
} DirectoryInfo;

// Function prototypes
long get_file_size(const char *path);
long get_directory_size(const char *path);
void print_file_info(const FileInfo *file_info);
void print_directory_info(const DirectoryInfo *directory_info);
void free_file_info(FileInfo *file_info);
void free_directory_info(DirectoryInfo *directory_info);

// Main function
int main(int argc, char **argv) {
    // Check arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get directory size
    long size = get_directory_size(argv[1]);

    // Print directory size
    printf("Directory %s size: %ld bytes (%.2f MB)\n", argv[1], size, (double)size / (1024 * 1024));

    return EXIT_SUCCESS;
}

// Get file size
long get_file_size(const char *path) {
    struct stat statbuf;
    if (stat(path, &statbuf) == -1) {
        perror("stat");
        return -1;
    }
    return statbuf.st_size;
}

// Get directory size
long get_directory_size(const char *path) {
    long size = 0;
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return -1;
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        char *full_path = malloc(strlen(path) + strlen(entry->d_name) + 2);
        if (full_path == NULL) {
            perror("malloc");
            closedir(dir);
            return -1;
        }
        strcpy(full_path, path);
        strcat(full_path, "/");
        strcat(full_path, entry->d_name);
        if (entry->d_type == DT_REG) {
            size += get_file_size(full_path);
        } else if (entry->d_type == DT_DIR) {
            size += get_directory_size(full_path);
        }
        free(full_path);
    }
    closedir(dir);
    return size;
}

// Print file information
void print_file_info(const FileInfo *file_info) {
    printf("File: %s\n", file_info->name);
    printf("Size: %ld bytes (%.2f MB)\n", file_info->size, (double)file_info->size / (1024 * 1024));
    printf("\n");
}

// Print directory information
void print_directory_info(const DirectoryInfo *directory_info) {
    printf("Directory: %s\n", directory_info->name);
    printf("Size: %ld bytes (%.2f MB)\n", directory_info->size, (double)directory_info->size / (1024 * 1024));
    printf("\n");
    for (int i = 0; i < directory_info->num_files; i++) {
        print_file_info(&directory_info->files[i]);
    }
}

// Free file information
void free_file_info(FileInfo *file_info) {
    free(file_info->name);
    free(file_info);
}

// Free directory information
void free_directory_info(DirectoryInfo *directory_info) {
    free(directory_info->name);
    for (int i = 0; i < directory_info->num_files; i++) {
        free_file_info(&directory_info->files[i]);
    }
    free(directory_info->files);
    free(directory_info);
}