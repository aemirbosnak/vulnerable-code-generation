//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

// Structure to store file information
typedef struct file_info {
    char *name;
    long size;
} file_info;

// Function to compare file sizes
int compare_file_sizes(const void *a, const void *b) {
    const file_info *fa = (const file_info *)a;
    const file_info *fb = (const file_info *)b;
    return (fa->size - fb->size);
}

// Function to get file size
long get_file_size(const char *path) {
    struct stat stat_buf;
    if (stat(path, &stat_buf) != 0) {
        perror("stat");
        return -1;
    }
    return stat_buf.st_size;
}

// Function to get all files in a directory
file_info *get_files_in_dir(const char *dir, int *num_files) {
    DIR *dp;
    struct dirent *entry;
    file_info *files = NULL;
    int i = 0;

    dp = opendir(dir);
    if (dp == NULL) {
        perror("opendir");
        return NULL;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char *path = malloc(strlen(dir) + strlen(entry->d_name) + 2);
        sprintf(path, "%s/%s", dir, entry->d_name);

        long size = get_file_size(path);
        if (size == -1) {
            free(path);
            continue;
        }

        files = realloc(files, (i + 1) * sizeof(file_info));
        files[i].name = path;
        files[i].size = size;
        i++;
    }

    closedir(dp);

    *num_files = i;
    return files;
}

// Function to print file information
void print_file_info(const file_info *file) {
    printf("%s: %ld bytes\n", file->name, file->size);
}

// Function to print file statistics
void print_file_statistics(const file_info *files, int num_files) {
    long total_size = 0;
    long max_size = 0;
    long min_size = -1;

    for (int i = 0; i < num_files; i++) {
        total_size += files[i].size;
        if (files[i].size > max_size) {
            max_size = files[i].size;
        }
        if (min_size == -1 || files[i].size < min_size) {
            min_size = files[i].size;
        }
    }

    printf("Total size: %ld bytes\n", total_size);
    printf("Maximum size: %ld bytes\n", max_size);
    printf("Minimum size: %ld bytes\n", min_size);
    printf("Average size: %.2f bytes\n", (double)total_size / num_files);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int num_files;
    file_info *files = get_files_in_dir(argv[1], &num_files);
    if (files == NULL) {
        return EXIT_FAILURE;
    }

    qsort(files, num_files, sizeof(file_info), compare_file_sizes);

    for (int i = 0; i < num_files; i++) {
        print_file_info(&files[i]);
    }

    print_file_statistics(files, num_files);

    for (int i = 0; i < num_files; i++) {
        free(files[i].name);
    }
    free(files);

    return EXIT_SUCCESS;
}