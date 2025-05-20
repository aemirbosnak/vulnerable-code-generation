//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <time.h>

// Custom data structure to store file information
typedef struct FileInfo {
    char *name;
    long long size;
    time_t last_modified;
} FileInfo;

// Function to compare files by size, used for sorting
int compare_files_by_size(const void *a, const void *b) {
    const FileInfo *fa = (const FileInfo *)a;
    const FileInfo *fb = (const FileInfo *)b;
    return (fa->size > fb->size) ? -1 : (fa->size < fb->size);
}

// Function to traverse a directory and collect file information
void analyze_directory(const char *path, FileInfo **files, int *num_files) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..")) {
            continue;
        }

        char full_path[PATH_MAX];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        struct stat statbuf;
        if (stat(full_path, &statbuf) == -1) {
            perror("stat");
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            analyze_directory(full_path, files, num_files);
        } else if (S_ISREG(statbuf.st_mode)) {
            FileInfo *file = malloc(sizeof(FileInfo));
            file->name = strdup(full_path);
            file->size = statbuf.st_size;
            file->last_modified = statbuf.st_mtime;

            files[*num_files] = file;
            (*num_files)++;
        }
    }

    closedir(dir);
}

int main() {
    printf("C Disk Space Analyzer\n");
    printf("----------------------\n");

    // Get the files from the root directory
    int num_files = 0;
    FileInfo **files = malloc(sizeof(FileInfo *) * 1000);
    analyze_directory("/", files, &num_files);

    // Sort the files by size
    qsort(files, num_files, sizeof(FileInfo *), compare_files_by_size);

    // Print the top 10 largest files
    printf("\nTop 10 Largest Files:\n");
    for (int i = 0; i < 10 && i < num_files; i++) {
        printf("%s\t%.2f MB\n", files[i]->name, (double)files[i]->size / (1024 * 1024));
    }

    // Free the allocated memory
    for (int i = 0; i < num_files; i++) {
        free(files[i]->name);
        free(files[i]);
    }
    free(files);

    return 0;
}