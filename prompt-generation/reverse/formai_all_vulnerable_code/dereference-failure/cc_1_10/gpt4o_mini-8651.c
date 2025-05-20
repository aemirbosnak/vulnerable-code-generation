//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_FILES 1000
#define PATH_LENGTH 1024

typedef struct FileInfo {
    char name[PATH_LENGTH];
    long size;
} FileInfo;

void analyze_directory(const char *path, FileInfo files[], int *file_count);
void sort_files(FileInfo files[], int file_count);
void print_summary(FileInfo files[], int file_count);

int main() {
    char path[PATH_LENGTH];
    FileInfo files[MAX_FILES];
    int file_count = 0;

    printf("Welcome to Disk Space Analyzer!\n");
    printf("Enter the directory path to analyze: ");
    fgets(path, sizeof(path), stdin);
    path[strcspn(path, "\n")] = 0; // Remove newline character

    analyze_directory(path, files, &file_count);
    sort_files(files, file_count);
    print_summary(files, file_count);

    return 0;
}

void analyze_directory(const char *path, FileInfo files[], int *file_count) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;

    if (!(dir = opendir(path))) {
        perror("Unable to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char full_path[PATH_LENGTH];
            snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

            if (stat(full_path, &file_stat) == 0) {
                if (S_ISREG(file_stat.st_mode)) { // If it's a regular file
                    strncpy(files[*file_count].name, full_path, PATH_LENGTH);
                    files[*file_count].size = file_stat.st_size;
                    (*file_count)++;
                } else if (S_ISDIR(file_stat.st_mode)) { // If it's a directory, recurse into it
                    analyze_directory(full_path, files, file_count);
                }
            } else {
                perror("Unable to get file status");
            }
        }
    }

    closedir(dir);
}

void sort_files(FileInfo files[], int file_count) {
    for (int i = 0; i < file_count - 1; i++) {
        for (int j = 0; j < file_count - i - 1; j++) {
            if (files[j].size < files[j + 1].size) {
                FileInfo temp = files[j];
                files[j] = files[j + 1];
                files[j + 1] = temp;
            }
        }
    }
}

void print_summary(FileInfo files[], int file_count) {
    printf("\nDisk Space Analysis Summary:\n");
    printf("---------------------------------------------------------\n");
    printf("%-50s | %10s\n", "File Name", "Size (bytes)");
    printf("---------------------------------------------------------\n");
    
    long total_size = 0;
    for (int i = 0; i < file_count; i++) {
        printf("%-50s | %10ld\n", files[i].name, files[i].size);
        total_size += files[i].size;
    }
    
    printf("---------------------------------------------------------\n");
    printf("Total size of analyzed files: %ld bytes\n", total_size);
    printf("---------------------------------------------------------\n");
}