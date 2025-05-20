//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

// Define the maximum length of a file path
#define MAX_PATH_LENGTH 1024

// Define the struct to store the file information
typedef struct file_info {
    char *path;
    long size;
} file_info;

// Compare two file_info structs by size
int compare_file_info(const void *a, const void *b) {
    const file_info *fa = (const file_info *)a;
    const file_info *fb = (const file_info *)b;
    return fb->size - fa->size;
}

// Get the file size of a file
long get_file_size(const char *path) {
    struct stat statbuf;
    if (stat(path, &statbuf) != 0) {
        return -1;
    }
    return statbuf.st_size;
}

// Get the file information of a file
file_info *get_file_info(const char *path) {
    file_info *info = malloc(sizeof(file_info));
    if (info == NULL) {
        return NULL;
    }

    info->path = strdup(path);
    if (info->path == NULL) {
        free(info);
        return NULL;
    }

    info->size = get_file_size(path);
    if (info->size == -1) {
        free(info->path);
        free(info);
        return NULL;
    }

    return info;
}

// Get the file information of all files in a directory
file_info **get_directory_files(const char *path, int *count) {
    DIR *dir;
    struct dirent *entry;
    file_info **files = NULL;
    int i = 0;

    dir = opendir(path);
    if (dir == NULL) {
        return NULL;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char *file_path = malloc(strlen(path) + strlen(entry->d_name) + 2);
        if (file_path == NULL) {
            closedir(dir);
            return NULL;
        }

        sprintf(file_path, "%s/%s", path, entry->d_name);
        file_info *info = get_file_info(file_path);
        if (info == NULL) {
            free(file_path);
            closedir(dir);
            return NULL;
        }

        files = realloc(files, (i + 1) * sizeof(file_info *));
        if (files == NULL) {
            free(file_path);
            free(info);
            closedir(dir);
            return NULL;
        }

        files[i++] = info;
        free(file_path);
    }

    closedir(dir);

    *count = i;
    return files;
}

// Print the file information of a file
void print_file_info(const file_info *info) {
    printf("%s: %ld bytes\n", info->path, info->size);
}

// Print the file information of all files in a directory
void print_directory_files(const char *path) {
    int count;
    file_info **files = get_directory_files(path, &count);
    if (files == NULL) {
        return;
    }

    qsort(files, count, sizeof(file_info *), compare_file_info);

    for (int i = 0; i < count; i++) {
        print_file_info(files[i]);
        free(files[i]->path);
        free(files[i]);
    }

    free(files);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }

    print_directory_files(argv[1]);

    return 0;
}