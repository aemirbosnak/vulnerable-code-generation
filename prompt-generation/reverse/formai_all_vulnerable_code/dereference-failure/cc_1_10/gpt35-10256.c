//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define KB 1024
#define MB (KB * KB)
#define GB (MB * KB)

void print_usage() {
    printf("Usage: disk-analyzer <directory_path>\n");
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        print_usage();
        return 1;
    }

    char* dir_path = argv[1];
    DIR* dir = opendir(dir_path);

    if (dir == NULL) {
        printf("Error: Could not open directory %s.\n", dir_path);
        return 1;
    }

    struct dirent* entry;
    struct stat file_stat;

    long long total_size = 0;
    long long file_count = 0;
    
    printf("Disk Usage for directory %s:\n", dir_path);

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char file_path[256];
        sprintf(file_path, "%s/%s", dir_path, entry->d_name);

        if (stat(file_path, &file_stat) == -1) {
            printf("Error: Could not get file status for %s.\n", file_path);
            continue;
        }

        if (S_ISREG(file_stat.st_mode)) {
            long long size = file_stat.st_size;
            total_size += size;
            file_count++;
        } else if (S_ISDIR(file_stat.st_mode)) {
            char* sub_dir_path = file_path;
            long long sub_dir_size = 0;
            int sub_dir_file_count = 0;

            DIR* sub_dir = opendir(sub_dir_path);

            if (sub_dir == NULL) {
                printf("Error: Could not open directory %s.\n", sub_dir_path);
                continue;
            }

            struct dirent* sub_entry;
            struct stat sub_file_stat;

            while ((sub_entry = readdir(sub_dir)) != NULL) {
                if (strcmp(sub_entry->d_name, ".") == 0 || strcmp(sub_entry->d_name, "..") == 0) {
                    continue;
                }

                char sub_file_path[256];
                sprintf(sub_file_path, "%s/%s", sub_dir_path, sub_entry->d_name);

                if (stat(sub_file_path, &sub_file_stat) == -1) {
                    printf("Error: Could not get file status for %s.\n", sub_file_path);
                    continue;
                }

                if (S_ISREG(sub_file_stat.st_mode)) {
                    long long size = sub_file_stat.st_size;
                    sub_dir_size += size;
                    sub_dir_file_count++;
                }
            }

            closedir(sub_dir);

            total_size += sub_dir_size;
            file_count += sub_dir_file_count;

            printf("%-20s %10lld files    %10lld bytes\n", sub_dir_path, sub_dir_file_count, sub_dir_size);
        }
    }

    closedir(dir);

    printf("\n%-20s %10lld files    %10lld bytes\n", "TOTAL:", file_count, total_size);
    printf("%-20s %10.2f GB\n", "TOTAL SIZE:", (float)total_size / GB);

    return 0;
}