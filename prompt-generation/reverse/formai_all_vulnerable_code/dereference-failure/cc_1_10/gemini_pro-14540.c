//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

// File structure
typedef struct file_info {
    char *name;
    char *path;
    size_t size;
    time_t mtime;
} file_info;

// Function to compare files by name
int compare_files(const void *a, const void *b) {
    const file_info *fa = (const file_info *)a;
    const file_info *fb = (const file_info *)b;
    return strcmp(fa->name, fb->name);
}

// Function to print file information
void print_file_info(const file_info *file) {
    printf("File: %s\n", file->name);
    printf("Path: %s\n", file->path);
    printf("Size: %zu bytes\n", file->size);
    printf("Modified: %s\n", ctime(&file->mtime));
}

// Function to recover files
int recover_files(const char *dirpath) {
    // Open directory
    DIR *dir = opendir(dirpath);
    if (!dir) {
        perror("opendir");
        return -1;
    }

    // Get list of files
    struct dirent *entry;
    file_info *files = NULL;
    size_t num_files = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Get file information
        struct stat statbuf;
        char path[PATH_MAX];
        snprintf(path, sizeof(path), "%s/%s", dirpath, entry->d_name);
        if (stat(path, &statbuf) == -1) {
            perror("stat");
            continue;
        }

        // Create file structure
        file_info *file = malloc(sizeof(file_info));
        if (!file) {
            perror("malloc");
            continue;
        }
        file->name = strdup(entry->d_name);
        file->path = strdup(path);
        file->size = statbuf.st_size;
        file->mtime = statbuf.st_mtime;

        // Add file to list
        files = realloc(files, (num_files + 1) * sizeof(file_info));
        if (!files) {
            perror("realloc");
            continue;
        }
        files[num_files++] = *file;
    }

    // Close directory
    closedir(dir);

    // Sort files by name
    qsort(files, num_files, sizeof(file_info), compare_files);

    // Print file information
    for (size_t i = 0; i < num_files; i++) {
        print_file_info(&files[i]);
    }

    // Free memory
    for (size_t i = 0; i < num_files; i++) {
        free(files[i].name);
        free(files[i].path);
    }
    free(files);

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <dirpath>\n", argv[0]);
        return -1;
    }

    // Recover files
    if (recover_files(argv[1]) == -1) {
        return -1;
    }

    return 0;
}