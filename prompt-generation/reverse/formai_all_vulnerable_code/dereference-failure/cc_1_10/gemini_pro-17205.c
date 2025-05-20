//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

// Define the structure of a file or directory
typedef struct FileInfo {
    char *name;
    size_t size;
    time_t mtime;
    bool is_dir;
} FileInfo;

// Recursively traverse a directory and calculate the total size of all files and directories
size_t calculate_dir_size(const char *dirpath) {
    DIR *dir = opendir(dirpath);
    if (dir == NULL) {
        perror("Error opening directory");
        return 0;
    }

    size_t total_size = 0;
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char *fullpath = malloc(strlen(dirpath) + strlen(entry->d_name) + 2);
        sprintf(fullpath, "%s/%s", dirpath, entry->d_name);

        struct stat statbuf;
        if (lstat(fullpath, &statbuf) == -1) {
            perror("Error getting file status");
            free(fullpath);
            continue;
        }

        if (S_ISREG(statbuf.st_mode)) {
            total_size += statbuf.st_size;
        } else if (S_ISDIR(statbuf.st_mode)) {
            total_size += calculate_dir_size(fullpath);
        }

        free(fullpath);
    }

    closedir(dir);
    return total_size;
}

// Print a list of all files and directories in a directory along with their sizes and modification times
void print_dir_info(const char *dirpath, int depth) {
    DIR *dir = opendir(dirpath);
    if (dir == NULL) {
        perror("Error opening directory");
        return;
    }

    char *indent = malloc(depth * 2 + 1);
    memset(indent, ' ', depth * 2);
    indent[depth * 2] = '\0';

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char *fullpath = malloc(strlen(dirpath) + strlen(entry->d_name) + 2);
        sprintf(fullpath, "%s/%s", dirpath, entry->d_name);

        struct stat statbuf;
        if (lstat(fullpath, &statbuf) == -1) {
            perror("Error getting file status");
            free(fullpath);
            continue;
        }

        printf("%s%s", indent, entry->d_name);
        if (S_ISREG(statbuf.st_mode)) {
            printf(" (%zu bytes)", statbuf.st_size);
        } else if (S_ISDIR(statbuf.st_mode)) {
            printf(" (directory)");
        }
        printf(" (mtime: %s)", ctime(&statbuf.st_mtime));
        printf("\n");

        if (S_ISDIR(statbuf.st_mode)) {
            print_dir_info(fullpath, depth + 1);
        }

        free(fullpath);
    }

    free(indent);
    closedir(dir);
}

// Entry point of the program
int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    const char *dirpath = argv[1];

    size_t dir_size = calculate_dir_size(dirpath);
    printf("Total size of directory '%s': %zu bytes\n", dirpath, dir_size);

    printf("Directory listing:\n");
    print_dir_info(dirpath, 0);

    return 0;
}