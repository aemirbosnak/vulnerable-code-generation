//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>

#define MAX_PATH 1024
#define MAX_FILES 10000

struct file_info {
    char *path;
    size_t size;
    time_t mtime;
};

int compare_file_info(const void *a, const void *b) {
    struct file_info *fa = (struct file_info *)a;
    struct file_info *fb = (struct file_info *)b;
    return fa->size - fb->size;
}

int main() {
    char *root_path = ".";
    size_t total_size = 0;
    struct file_info files[MAX_FILES];
    int num_files = 0;

    // Recursively traverse the directory tree starting from the root path
    DIR *dir = opendir(root_path);
    if (dir == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip hidden files and directories
        if (entry->d_name[0] == '.') {
            continue;
        }

        char path[MAX_PATH];
        snprintf(path, sizeof(path), "%s/%s", root_path, entry->d_name);

        // Get file size and modification time
        struct stat statbuf;
        if (stat(path, &statbuf) == -1) {
            perror("stat");
            continue;
        }

        // Add file information to the array
        struct file_info file_info;
        file_info.path = strdup(path);
        file_info.size = statbuf.st_size;
        file_info.mtime = statbuf.st_mtime;
        files[num_files++] = file_info;

        // Accumulate total size
        total_size += statbuf.st_size;

        // Recursively traverse subdirectories
        if (S_ISDIR(statbuf.st_mode)) {
            main(path);
        }
    }

    closedir(dir);

    // Sort files by size in descending order
    qsort(files, num_files, sizeof(struct file_info), compare_file_info);

    // Print file information
    for (int i = 0; i < num_files; i++) {
        printf("%-60s %10zu bytes %s", files[i].path, files[i].size, ctime(&files[i].mtime));
    }

    // Print total size
    printf("Total size: %zu bytes\n", total_size);

    // Free allocated memory
    for (int i = 0; i < num_files; i++) {
        free(files[i].path);
    }

    return EXIT_SUCCESS;
}