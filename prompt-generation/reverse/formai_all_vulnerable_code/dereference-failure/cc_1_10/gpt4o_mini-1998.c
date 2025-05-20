//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_PATH_LENGTH 4096
#define MAX_FILES 512

typedef struct FileInfo {
    char name[MAX_PATH_LENGTH];
    unsigned long size;
} FileInfo;

void analyze_directory(const char *dir_path, FileInfo *files, int *file_count) {
    struct dirent *entry;
    struct stat file_stat;
    DIR *dp = opendir(dir_path);

    if (!dp) {
        perror("Failed to open directory");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        char file_path[MAX_PATH_LENGTH];
        if (entry->d_type == DT_DIR) {
            // Skip the '.' and '..' directories
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                snprintf(file_path, sizeof(file_path), "%s/%s", dir_path, entry->d_name);
                analyze_directory(file_path, files, file_count);  // Recursion for subdirectory
            }
        } else {
            snprintf(file_path, sizeof(file_path), "%s/%s", dir_path, entry->d_name);
            if (stat(file_path, &file_stat) == 0) {
                if (*file_count < MAX_FILES) {
                    strncpy(files[*file_count].name, entry->d_name, MAX_PATH_LENGTH);
                    files[*file_count].size = file_stat.st_size;
                    (*file_count)++;
                } else {
                    printf("Exceeded maximum file storage.\n");
                    break;
                }
            }
        }
    }
    closedir(dp);
}

void print_report(FileInfo *files, int file_count) {
    unsigned long total_size = 0;
    printf("\nDisk Space Analysis Report:\n");
    printf("-------------------------------------------------------\n");
    printf("| %-50s | %10s |\n", "File Name", "File Size (Bytes)");
    printf("-------------------------------------------------------\n");

    for (int i = 0; i < file_count; i++) {
        printf("| %-50s | %10lu |\n", files[i].name, files[i].size);
        total_size += files[i].size;
    }
    
    printf("-------------------------------------------------------\n");
    printf("| Total Size Used: %10lu |\n", total_size);
    printf("-------------------------------------------------------\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FileInfo files[MAX_FILES];
    int file_count = 0;

    analyze_directory(argv[1], files, &file_count);
    print_report(files, file_count);

    return EXIT_SUCCESS;
}