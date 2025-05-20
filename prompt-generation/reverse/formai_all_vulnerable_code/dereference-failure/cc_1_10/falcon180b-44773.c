//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

#define MAX_DIR_SIZE 1024
#define MAX_FILE_SIZE 1024

typedef struct {
    char path[MAX_DIR_SIZE];
    unsigned long long size;
} Directory;

int compare_directories(const void* a, const void* b) {
    return strcmp(((const Directory*)a)->path, ((const Directory*)b)->path);
}

void read_directory(const char* directory, Directory* directories, int* num_directories) {
    DIR* dir = opendir(directory);
    if (!dir) {
        printf("Error opening directory '%s': %s\n", directory, strerror(errno));
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dir))!= NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char path[MAX_DIR_SIZE];
        snprintf(path, MAX_DIR_SIZE, "%s/%s", directory, entry->d_name);

        struct statvfs statvfs_buf;
        if (statvfs(path, &statvfs_buf) == 0) {
            Directory dir_info;
            strncpy(dir_info.path, path, MAX_DIR_SIZE);
            dir_info.size = statvfs_buf.f_blocks * statvfs_buf.f_frsize;

            directories[*num_directories] = dir_info;
            (*num_directories)++;
        }
    }

    closedir(dir);
}

void print_directories(Directory* directories, int num_directories) {
    qsort(directories, num_directories, sizeof(Directory), compare_directories);

    for (int i = 0; i < num_directories; i++) {
        printf("%-40s %10llu\n", directories[i].path, directories[i].size);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    Directory directories[MAX_DIR_SIZE];
    int num_directories = 0;

    read_directory(argv[1], directories, &num_directories);
    print_directories(directories, num_directories);

    return 0;
}