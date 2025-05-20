//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define MAX_PATH 1024

typedef struct {
    char name[MAX_PATH];
    unsigned long long size;
    unsigned long long num_files;
    unsigned long long num_dirs;
} Directory;

void get_directory_info(const char *path, Directory *dir) {
    DIR *dp;
    struct dirent *dirp;
    struct statvfs buf;

    dp = opendir(path);
    if (dp == NULL) {
        printf("Error: Cannot open directory '%s'\n", path);
        exit(1);
    }

    if (statvfs(path, &buf) == -1) {
        printf("Error: Cannot get disk space info for directory '%s'\n", path);
        exit(1);
    }

    dir->size = buf.f_blocks * buf.f_frsize;

    while ((dirp = readdir(dp))!= NULL) {
        if (dirp->d_type == DT_DIR) {
            dir->num_dirs++;
        } else {
            dir->num_files++;
        }
    }

    closedir(dp);
}

void print_directory_info(Directory *dir) {
    printf("Directory: %s\n", dir->name);
    printf("Size: %llu bytes\n", dir->size);
    printf("Number of files: %llu\n", dir->num_files);
    printf("Number of directories: %llu\n", dir->num_dirs);
    printf("\n");
}

void analyze_directory(const char *path) {
    Directory dir;

    strncpy(dir.name, path, MAX_PATH);
    get_directory_info(path, &dir);
    print_directory_info(&dir);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        exit(1);
    }

    analyze_directory(argv[1]);

    return 0;
}