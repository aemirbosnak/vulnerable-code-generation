//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

// Custom data structure to store file data
typedef struct file_data {
    char *name;
    size_t size;
} file_data_t;

// Custom comparator function for sorting files by size
int compare_files(const void *a, const void *b) {
    const file_data_t *fa = (const file_data_t *)a;
    const file_data_t *fb = (const file_data_t *)b;
    return (int)(fb->size - fa->size);
}

// Recursive function to traverse directories and collect file data
void analyze_directory(const char *dir_path, file_data_t **files, size_t *files_count) {
    DIR *dir = opendir(dir_path);
    if (!dir) {
        perror("Error opening directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..")) {
            continue;  // Skip current and parent directories
        }

        char full_path[PATH_MAX];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);

        struct stat file_stat;
        if (lstat(full_path, &file_stat) < 0) {
            perror("Error getting file stat");
            continue;
        }

        if (S_ISDIR(file_stat.st_mode)) {
            // Recursively analyze subdirectories
            analyze_directory(full_path, files, files_count);
        } else {
            // Add file to the list of files
            (*files_count)++;
            *files = realloc(*files, sizeof(file_data_t) * (*files_count));
            (*files)[*files_count - 1] = (file_data_t){
                .name = strdup(entry->d_name),
                .size = file_stat.st_size,
            };
        }
    }

    closedir(dir);
}

// Main function to analyze the C drive space
int main() {
    // Allocate memory for file data
    file_data_t *files = NULL;
    size_t files_count = 0;

    // Analyze the C drive
    analyze_directory("C:", &files, &files_count);

    // Sort the files by size
    qsort(files, files_count, sizeof(file_data_t), compare_files);

    // Print the top 10 largest files
    printf("Top 10 Largest Files:\n");
    for (size_t i = 0; i < 10 && i < files_count; i++) {
        printf("%s\t%.2f MB\n", files[i].name, (double)files[i].size / (1024 * 1024));
    }

    // Free the allocated memory
    for (size_t i = 0; i < files_count; i++) {
        free(files[i].name);
    }
    free(files);

    return 0;
}