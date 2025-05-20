//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_PATH 1024
#define MAX_FILES 1000

typedef struct FileInfo {
    char name[MAX_PATH];
    long size;
} FileInfo;

void get_directory_info(const char *path, FileInfo files[], int *file_count) {
    struct dirent *entry;
    struct stat file_stat;
    DIR *dp;

    dp = opendir(path);
    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_name[0] == '.') continue; // Skip hidden files and directories
        char full_path[MAX_PATH];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
        
        if (stat(full_path, &file_stat) == -1) {
            perror("stat");
            continue;
        }

        if (!S_ISDIR(file_stat.st_mode)) { // Only consider files
            strcpy(files[*file_count].name, full_path);
            files[*file_count].size = file_stat.st_size;
            (*file_count)++;
            if (*file_count >= MAX_FILES) {
                fprintf(stderr, "Warning: Reached maximum file count of %d\n", MAX_FILES);
                break;
            }
        }
    }
    closedir(dp);
}

void sort_files_by_size(FileInfo files[], int file_count) {
    for (int i = 0; i < file_count - 1; i++) {
        for (int j = i + 1; j < file_count; j++) {
            if (files[i].size > files[j].size) {
                FileInfo temp = files[i];
                files[i] = files[j];
                files[j] = temp;
            }
        }
    }
}

void print_report(FileInfo files[], int file_count) {
    long total_size = 0;

    printf("Disk Space Analyzer Report:\n");
    printf("%-50s %10s\n", "File Name", "Size (bytes)");
    printf("%s\n", "--------------------------------------------------");

    for (int i = 0; i < file_count; i++) {
        printf("%-50s %10ld\n", files[i].name, files[i].size);
        total_size += files[i].size;
    }
    
    printf("%s\n", "--------------------------------------------------");
    printf("Total disk space used: %ld bytes\n", total_size);
}

int main(int argc, char *argv[]) {
    FileInfo files[MAX_FILES];
    int file_count = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    get_directory_info(argv[1], files, &file_count);
    sort_files_by_size(files, file_count);
    print_report(files, file_count);

    return EXIT_SUCCESS;
}