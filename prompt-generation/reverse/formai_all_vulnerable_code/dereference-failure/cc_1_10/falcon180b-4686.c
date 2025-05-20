//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define MAX_FILE_NAME_SIZE 1024

typedef struct {
    char name[MAX_FILE_NAME_SIZE];
    unsigned long long size;
    unsigned long long num_files;
    unsigned long long num_dirs;
} FileSystemInfo;

void print_file_system_info(FileSystemInfo* info) {
    printf("Name: %s\n", info->name);
    printf("Total size: %llu bytes\n", info->size);
    printf("Number of files: %llu\n", info->num_files);
    printf("Number of directories: %llu\n", info->num_dirs);
}

void get_file_system_info(const char* path, FileSystemInfo* info) {
    struct statvfs buf;
    if (statvfs(path, &buf) == -1) {
        printf("Error getting file system info for %s\n", path);
        exit(1);
    }

    strncpy(info->name, path, MAX_FILE_NAME_SIZE - 1);
    info->name[MAX_FILE_NAME_SIZE - 1] = '\0';

    info->size = buf.f_blocks * buf.f_frsize;
    info->num_files = 0;
    info->num_dirs = 0;
}

void traverse_directory(const char* path, FileSystemInfo* info) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        printf("Error opening directory %s\n", path);
        exit(1);
    }

    struct dirent* entry;
    while ((entry = readdir(dir))!= NULL) {
        if (entry->d_type == DT_DIR) {
            info->num_dirs++;
        } else if (entry->d_type == DT_REG || entry->d_type == DT_LNK) {
            info->num_files++;
        }
    }

    closedir(dir);
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        exit(1);
    }

    FileSystemInfo info;
    get_file_system_info(argv[1], &info);

    traverse_directory(argv[1], &info);

    print_file_system_info(&info);

    return 0;
}