//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024

typedef struct FileInfo {
    char name[MAX_PATH];
    long size;
} FileInfo;

void analyze_directory(const char *path, FileInfo **files, int *file_count);
void print_file_info(FileInfo *files, int count);
void free_file_info(FileInfo *files);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FileInfo *files = NULL; 
    int file_count = 0;

    analyze_directory(argv[1], &files, &file_count);
    
    printf("Disk Space Analysis for: %s\n", argv[1]);
    print_file_info(files, file_count);
    
    free_file_info(files);
    return EXIT_SUCCESS;
}

void analyze_directory(const char *path, FileInfo **files, int *file_count) {
    DIR *dir = opendir(path);
    struct dirent *entry;
    struct stat file_stat;

    if (!dir) {
        perror("Could not open directory");
        return;
    }
    
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char full_path[MAX_PATH];
            snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
            
            if (stat(full_path, &file_stat) == -1) {
                perror("Could not get file status");
                continue;
            }
            
            if (S_ISREG(file_stat.st_mode)) {
                *files = realloc(*files, sizeof(FileInfo) * (*file_count + 1));
                if (*files == NULL) {
                    perror("Memory allocation failed");
                    closedir(dir);
                    return;
                }
                
                strncpy((*files)[*file_count].name, full_path, MAX_PATH);
                (*files)[*file_count].size = file_stat.st_size;
                (*file_count)++;
            } else if (S_ISDIR(file_stat.st_mode)) {
                analyze_directory(full_path, files, file_count);
            }
        }
    }
    
    closedir(dir);
}

void print_file_info(FileInfo *files, int count) {
    long total_size = 0;
    printf("%-50s %s\n", "File Name", "Size (bytes)");
    printf("%-50s %s\n", "---------", "------------");

    for (int i = 0; i < count; i++) {
        printf("%-50s %ld\n", files[i].name, files[i].size);
        total_size += files[i].size;
    }
    
    printf("%-50s %ld\n", "Total Size:", total_size);
}

void free_file_info(FileInfo *files) {
    free(files);
}