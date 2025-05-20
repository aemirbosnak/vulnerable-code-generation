//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>
#include <string.h>

#define BUF_LEN 1024
#define TAB_SIZE 4

typedef struct {
    char name[BUF_LEN];
    unsigned long long size;
} File;

void get_files(const char* path, File* files, int* count) {
    DIR* dir = opendir(path);
    if (!dir) {
        printf("Error opening directory: %s\n", path);
        exit(1);
    }

    struct dirent* entry;
    while ((entry = readdir(dir))!= NULL) {
        if (entry->d_type == DT_REG) {
            char full_path[BUF_LEN];
            snprintf(full_path, BUF_LEN, "%s/%s", path, entry->d_name);

            struct statvfs fs_stat;
            if (statvfs(full_path, &fs_stat) == 0) {
                files[*count].size = fs_stat.f_blocks * fs_stat.f_frsize;
            } else {
                printf("Error getting file size: %s\n", full_path);
                exit(1);
            }

            strcpy(files[*count].name, entry->d_name);
            (*count)++;
        }
    }

    closedir(dir);
}

void print_files(File* files, int count) {
    printf("Name\t\tSize\n");
    for (int i = 0; i < count; i++) {
        printf("%-*s\t%llu\n", (int)(TAB_SIZE * strlen(files[i].name)), files[i].name, files[i].size);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s directory\n", argv[0]);
        exit(1);
    }

    File files[1000];
    int count = 0;

    get_files(argv[1], files, &count);
    print_files(files, count);

    return 0;
}