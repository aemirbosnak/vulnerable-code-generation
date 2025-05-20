//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <linux/limits.h>

// Structure to store file information
typedef struct file_info {
    char* path;
    long long size;
} file_info;

// Function to compare file sizes (for qsort)
int compare_file_sizes(const void* a, const void* b) {
    const file_info* fa = (const file_info*)a;
    const file_info* fb = (const file_info*)b;
    return (fa->size < fb->size) ? -1 : (fa->size > fb->size) ? 1 : 0;
}

// Function to get the size of a file
long long get_file_size(const char* path) {
    struct stat statbuf;
    if (stat(path, &statbuf) != 0) {
        perror("stat");
        return -1;
    }
    return statbuf.st_size;
}

// Function to recursively traverse a directory and collect file information
void traverse_directory(const char* path, file_info** files, int* num_files) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return;
    }
    struct dirent* dent;
    while ((dent = readdir(dir)) != NULL) {
        if (strcmp(dent->d_name, ".") == 0 || strcmp(dent->d_name, "..") == 0) {
            continue;
        }
        char* full_path = malloc(PATH_MAX);
        sprintf(full_path, "%s/%s", path, dent->d_name);
        struct stat statbuf;
        if (stat(full_path, &statbuf) != 0) {
            perror("stat");
            free(full_path);
            continue;
        }
        if (S_ISDIR(statbuf.st_mode)) {
            traverse_directory(full_path, files, num_files);
        } else if (S_ISREG(statbuf.st_mode)) {
            file_info* file = malloc(sizeof(file_info));
            file->path = full_path;
            file->size = statbuf.st_size;
            files[(*num_files)++] = file;
        }
        free(full_path);
    }
    closedir(dir);
}

int main() {
    // Initialize an array to store file information
    file_info* files[10000];
    int num_files = 0;

    // Get the current working directory
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd");
        return EXIT_FAILURE;
    }

    // Traverse the current working directory and collect file information
    traverse_directory(cwd, files, &num_files);

    // Sort the files by size
    qsort(files, num_files, sizeof(file_info*), compare_file_sizes);

    // Print the file information
    for (int i = 0; i < num_files; i++) {
        printf("%lld %s\n", files[i]->size, files[i]->path);
        free(files[i]->path);
        free(files[i]);
    }

    return EXIT_SUCCESS;
}