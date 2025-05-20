//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

// Structure to store file size and path
typedef struct file_info {
    char path[256];
    long size;
} file_info;

// Function to compare two file_info structures by size in descending order
int compare_file_info(const void *a, const void *b) {
    const file_info *fa = (const file_info *)a;
    const file_info *fb = (const file_info *)b;
    return (fa->size < fb->size) - (fa->size > fb->size);
}

// Function to get the size of a file or directory
long get_file_size(const char *path) {
    struct stat statbuf;
    if (stat(path, &statbuf) == 0) {
        return statbuf.st_size;
    } else {
        return -1;
    }
}

// Function to traverse a directory and collect file sizes
void traverse_directory(const char *path, file_info *files, int *num_files) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char subpath[256];
        sprintf(subpath, "%s/%s", path, entry->d_name);

        if (entry->d_type == DT_DIR) {
            traverse_directory(subpath, files, num_files);
        } else {
            files[*num_files].size = get_file_size(subpath);
            strcpy(files[*num_files].path, subpath);
            (*num_files)++;
        }
    }

    closedir(dir);
}

int main() {
    // Array to store file sizes and paths
    file_info files[1000];

    // Number of files found
    int num_files = 0;

    // Traverse the root directory
    traverse_directory("/", files, &num_files);

    // Sort the files by size in descending order
    qsort(files, num_files, sizeof(file_info), compare_file_info);

    // Print the top 10 largest files
    printf("Top 10 largest files:\n");
    for (int i = 0; i < 10 && i < num_files; i++) {
        printf("%20ld  %s\n", files[i].size, files[i].path);
    }

    return 0;
}