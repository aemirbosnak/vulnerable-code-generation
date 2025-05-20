//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <time.h>

// Calculate the size of a file in bytes
long get_file_size(const char* filename) {
    struct stat st;
    if (stat(filename, &st) != 0) {
        perror("stat");
        return -1;
    }
    return st.st_size;
}

// Calculate the size of a directory in bytes
long get_directory_size(const char* dirname) {
    DIR* dir = opendir(dirname);
    if (dir == NULL) {
        perror("opendir");
        return -1;
    }
    long total_size = 0;
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        char path[strlen(dirname) + strlen(entry->d_name) + 2];
        sprintf(path, "%s/%s", dirname, entry->d_name);
        struct stat st;
        if (stat(path, &st) != 0) {
            perror("stat");
            closedir(dir);
            return -1;
        }
        if (S_ISDIR(st.st_mode)) {
            long subdir_size = get_directory_size(path);
            if (subdir_size < 0) {
                closedir(dir);
                return -1;
            }
            total_size += subdir_size;
        } else {
            total_size += st.st_size;
        }
    }
    closedir(dir);
    return total_size;
}

// Print the size of a file or directory in a human-readable format
void print_size(const char* path, long size) {
    if (size < 1024) {
        printf("%ld bytes\n", size);
    } else if (size < 1024 * 1024) {
        printf("%.2f KB\n", (double)size / 1024);
    } else if (size < 1024 * 1024 * 1024) {
        printf("%.2f MB\n", (double)size / (1024 * 1024));
    } else {
        printf("%.2f GB\n", (double)size / (1024 * 1024 * 1024));
    }
}

// Print the size of all files and directories in a directory
void print_directory(const char* dirname) {
    DIR* dir = opendir(dirname);
    if (dir == NULL) {
        perror("opendir");
        return;
    }
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        char path[strlen(dirname) + strlen(entry->d_name) + 2];
        sprintf(path, "%s/%s", dirname, entry->d_name);
        struct stat st;
        if (stat(path, &st) != 0) {
            perror("stat");
            closedir(dir);
            return;
        }
        printf("%s: ", path);
        if (S_ISDIR(st.st_mode)) {
            long subdir_size = get_directory_size(path);
            if (subdir_size < 0) {
                closedir(dir);
                return;
            }
            print_size(path, subdir_size);
        } else {
            long file_size = get_file_size(path);
            if (file_size < 0) {
                closedir(dir);
                return;
            }
            print_size(path, file_size);
        }
    }
    closedir(dir);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }
    print_directory(argv[1]);
    return 0;
}