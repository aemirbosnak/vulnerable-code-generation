//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH_LENGTH 1024
#define MAX_FILES 1024

typedef struct {
    char path[MAX_PATH_LENGTH];
    long size;
} FileInfo;

void analyze_directory(const char *path, FileInfo *files, int *file_count) {
    struct dirent *entry;
    struct stat file_stat;
    char full_path[MAX_PATH_LENGTH];
    
    DIR *dir = opendir(path);
    if (!dir) {
        perror("Failed to open directory");
        return;
    }
    
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;  // Skip the special directories
        }
        
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
        if (stat(full_path, &file_stat) == 0) {
            if (S_ISDIR(file_stat.st_mode)) {
                analyze_directory(full_path, files, file_count);  // Recursive call for directories
            } else if (S_ISREG(file_stat.st_mode)) {
                // Store file information
                if (*file_count < MAX_FILES) {
                    strcpy(files[*file_count].path, full_path);
                    files[*file_count].size = file_stat.st_size;
                    (*file_count)++;
                }
            }
        } else {
            perror("Failed to get file status");
        }
    }
    closedir(dir);
}

void print_report(FileInfo *files, int file_count) {
    long total_size = 0;

    printf("\nDisk Space Analysis Report:\n");
    printf("| %-50s | %-12s |\n", "File Path", "File Size (bytes)");
    printf("|--------------------------------------------------|\n");

    for (int i = 0; i < file_count; i++) {
        printf("| %-50s | %-12ld |\n", files[i].path, files[i].size);
        total_size += files[i].size;
    }

    printf("|--------------------------------------------------|\n");
    printf("| %-50s | %-12ld |\n", "Total", total_size);
    printf("|--------------------------------------------------|\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FileInfo files[MAX_FILES];
    int file_count = 0;

    analyze_directory(argv[1], files, &file_count);
    print_report(files, file_count);

    return EXIT_SUCCESS;
}