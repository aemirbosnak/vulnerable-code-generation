//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

typedef struct {
    char name[256];
    long size;
} File;

void analyze_directory(const char *dir_name, File **files, int *file_count, long *total_size) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;

    if (!(dir = opendir(dir_name))) {
        perror("Failed to open directory");
        return;
    }

    while ((entry = readdir(dir))) {
        char path[512];
        snprintf(path, sizeof(path), "%s/%s", dir_name, entry->d_name);
        
        if (entry->d_type == DT_REG) { // Regular file
            if (stat(path, &file_stat) == 0) {
                (*files)[*file_count].size = file_stat.st_size;
                strncpy((*files)[*file_count].name, path, sizeof((*files)[*file_count].name) - 1);
                (*files)[*file_count].name[sizeof((*files)[*file_count].name) - 1] = '\0';
                *total_size += file_stat.st_size;
                (*file_count)++;
            }
        } else if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            analyze_directory(path, files, file_count, total_size); // Recursive call for subdirectory
        }
    }

    closedir(dir);
}

void print_summary(File *files, int file_count, long total_size) {
    printf("Summary of disk usage:\n");
    printf("Total number of files: %d\n", file_count);
    printf("Total size of files: %ld bytes\n", total_size);
    printf("Files listed below:\n");

    for (int i = 0; i < file_count; i++) {
        printf(" - %s: %ld bytes\n", files[i].name, files[i].size);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *start_dir = argv[1];
    File *files = malloc(10000 * sizeof(File));  // Example for maximum file count 
    if (files == NULL) {
        perror("Failed to allocate memory");
        return EXIT_FAILURE;
    }

    int file_count = 0;
    long total_size = 0;

    analyze_directory(start_dir, &files, &file_count, &total_size);
    print_summary(files, file_count, total_size);

    free(files);
    return EXIT_SUCCESS;
}