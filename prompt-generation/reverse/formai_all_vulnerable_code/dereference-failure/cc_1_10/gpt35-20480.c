//FormAI DATASET v1.0 Category: File Synchronizer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

// Function to check if a directory exists
int directory_exists(const char *path) {
    struct stat stats;
    if (stat(path, &stats) == -1) {
        return 0;
    }
    return S_ISDIR(stats.st_mode);
}

// Function to create a directory
void create_directory(const char *path) {
    if (!directory_exists(path)) {
        int success = mkdir(path, 0777);
        if (success == -1) {
            printf("Error creating directory %s\n", path);
            exit(1);
        }
    }
}

// Function to copy a file
void copy_file(const char *source, const char *destination) {
    char command[100];
    sprintf(command, "cp %s %s", source, destination);
    system(command);
}

// Function to synchronize two directories
void synchronize_directories(const char *source_dir, const char *destination_dir) {
    DIR *source = opendir(source_dir);
    if (source == NULL) {
        printf("Error opening directory %s\n", source_dir);
        exit(1);
    }
    struct dirent *dir;
    while ((dir = readdir(source)) != NULL) {
        if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0) {
            continue;
        }
        char *path = malloc(strlen(destination_dir) + strlen(dir->d_name) + 2);
        sprintf(path, "%s/%s", destination_dir, dir->d_name);
        if (dir->d_type == DT_DIR) {
            create_directory(path);
            synchronize_directories(dir->d_name, path);
        } else {
            struct stat source_stats;
            char *source_path = malloc(strlen(source_dir) + strlen(dir->d_name) + 2);
            sprintf(source_path, "%s/%s", source_dir, dir->d_name);
            if (stat(source_path, &source_stats) == -1) {
                printf("Error getting stats for file %s\n", source_path);
                continue;
            }
            struct stat destination_stats;
            if (stat(path, &destination_stats) == -1) {
                copy_file(source_path, path);
            } else if (source_stats.st_mtime > destination_stats.st_mtime) {
                copy_file(source_path, path);
            }
            free(source_path);
        }
        free(path);
    }
    closedir(source);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: file_synchronizer <source_dir> <destination_dir>\n");
        exit(1);
    }
    synchronize_directories(argv[1], argv[2]);
    printf("Done synchronizing files\n");
    return 0;
}