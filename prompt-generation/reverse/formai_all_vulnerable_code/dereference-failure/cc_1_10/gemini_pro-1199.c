//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

// Struct to store file information
typedef struct file_info {
    char *name;
    long size;
    time_t last_modified;
} file_info;

// Function to compare file sizes
int compare_file_sizes(const void *a, const void *b) {
    file_info *fa = (file_info *)a;
    file_info *fb = (file_info *)b;
    return (int)(fb->size - fa->size);
}

// Function to traverse a directory and collect file information
void traverse_directory(const char *path, file_info **files, int *num_files) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char *full_path = malloc(strlen(path) + strlen(entry->d_name) + 2);
        sprintf(full_path, "%s/%s", path, entry->d_name);

        struct stat statbuf;
        if (stat(full_path, &statbuf) == -1) {
            perror("stat");
            free(full_path);
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            traverse_directory(full_path, files, num_files);
        } else {
            file_info *file = malloc(sizeof(file_info));
            file->name = strdup(full_path);
            file->size = statbuf.st_size;
            file->last_modified = statbuf.st_mtime;
            files[*num_files] = file;
            (*num_files)++;
        }

        free(full_path);
    }

    closedir(dir);
}

// Function to print file information
void print_file_info(file_info *file) {
    printf("%s\t%ld\t%s", file->name, file->size, ctime(&file->last_modified));
}

// Function to free file information
void free_file_info(file_info *file) {
    free(file->name);
    free(file);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>", argv[0]);
        return EXIT_FAILURE;
    }

    const char *path = argv[1];

    // Allocate memory for file information
    file_info **files = malloc(sizeof(file_info *) * 10000);
    int num_files = 0;

    // Traverse the directory and collect file information
    traverse_directory(path, files, &num_files);

    // Sort the files by size
    qsort(files, num_files, sizeof(file_info *), compare_file_sizes);

    // Print the file information
    printf("File Name\tSize (bytes)\tLast Modified\n");
    for (int i = 0; i < num_files; i++) {
        print_file_info(files[i]);
    }

    // Free the file information
    for (int i = 0; i < num_files; i++) {
        free_file_info(files[i]);
    }
    free(files);

    return EXIT_SUCCESS;
}