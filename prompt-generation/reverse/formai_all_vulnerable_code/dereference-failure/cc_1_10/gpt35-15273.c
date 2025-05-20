//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

void analyze_directory(const char *dir_path, int *total_size, int *file_count)
{
    struct stat st;
    struct dirent *entry;
    DIR *dir = opendir(dir_path);
    if (!dir) {
        fprintf(stderr, "Error opening directory: %s\n", dir_path);
        exit(EXIT_FAILURE);
    }
    while ((entry = readdir(dir)) != NULL) {
        char full_path[512];
        strcpy(full_path, dir_path);
        strcat(full_path, "/");
        strcat(full_path, entry->d_name);
        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            int size = 0;
            int count = 0;
            analyze_directory(full_path, &size, &count);
            (*total_size) += size;
            (*file_count) += count;
        } else if (entry->d_type == DT_REG) {
            if (stat(full_path, &st) == 0) {
                (*total_size) += st.st_size;
                (*file_count)++;
            }
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s directory\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    char *dir_path = argv[1];
    int total_size = 0;
    int file_count = 0;
    analyze_directory(dir_path, &total_size, &file_count);
    printf("Total size: %d bytes\n", total_size);
    printf("Number of files: %d\n", file_count);
    return 0;
}