//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024
#define MAX_FILENAME 256
#define BLOCK_SIZE 4096

typedef struct {
    char name[MAX_FILENAME];
    unsigned long size;
} FileInfo;

void analyze_directory(const char *path, FileInfo **files, int *count);
void sort_files(FileInfo *files, int count);
void display_file_info(FileInfo *files, int count);
void free_files(FileInfo *files);

int main(int argc, char *argv[]) {
    char *path;
    FileInfo *files = NULL;
    int count = 0;

    if (argc > 1) {
        path = argv[1];
    } else {
        path = ".";
    }

    analyze_directory(path, &files, &count);
    
    if (count > 0) {
        sort_files(files, count);
        display_file_info(files, count);
        free_files(files);
    } else {
        printf("No files found in the specified directory.\n");
    }

    return 0;
}

void analyze_directory(const char *path, FileInfo **files, int *count) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_info;
    char full_path[MAX_PATH];

    dir = opendir(path);
    if (dir == NULL) {
        perror("Unable to open directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue; // skip hidden files and directories
        }

        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
        if (stat(full_path, &file_info) == -1) {
            perror("Unable to get file info");
            continue; // skip if we can't get file info
        }

        if (S_ISREG(file_info.st_mode)) { // Regular file
            *files = realloc(*files, ((*count) + 1) * sizeof(FileInfo));
            strncpy((*files)[*count].name, entry->d_name, MAX_FILENAME);
            (*files)[*count].size = (file_info.st_size / BLOCK_SIZE) * BLOCK_SIZE; // Round down to nearest block
            (*count)++;
        }
    }

    closedir(dir);
}

void sort_files(FileInfo *files, int count) {
    int i, j;
    FileInfo temp;

    // Simple bubble sort for demonstration, could be optimized
    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (files[j].size < files[j + 1].size) {
                temp = files[j];
                files[j] = files[j + 1];
                files[j + 1] = temp;
            }
        }
    }
}

void display_file_info(FileInfo *files, int count) {
    printf("Disk Space Analyzer Results:\n");
    printf("%-30s %10s\n", "File Name", "Size (Bytes)");
    printf("---------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-30s %10lu\n", files[i].name, files[i].size);
    }
}

void free_files(FileInfo *files) {
    free(files);
}