//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/statvfs.h>

#define BUF_SIZE 1024

typedef struct {
    char *name;
    long size;
} FileInfo;

void get_file_info(const char *path, FileInfo *file_info) {
    struct statvfs fs;
    statvfs(path, &fs);

    file_info->size = fs.f_blocks * fs.f_frsize;
    strcpy(file_info->name, path);
}

void print_file_info(const FileInfo *file_info) {
    printf("%-40s %10ld\n", file_info->name, file_info->size);
}

void print_disk_info(const char *path) {
    DIR *dir;
    struct dirent *ent;
    int count = 0;
    FileInfo files[100];

    dir = opendir(path);
    if (dir == NULL) {
        printf("Cannot open directory: %s\n", path);
        return;
    }

    while ((ent = readdir(dir))!= NULL) {
        if (count >= 100) {
            printf("Too many files in directory.\n");
            break;
        }

        char file_path[BUF_SIZE];
        sprintf(file_path, "%s/%s", path, ent->d_name);

        get_file_info(file_path, &files[count]);
        count++;
    }

    closedir(dir);

    printf("File Name\t\tSize\n");
    printf("--------------------------------\n");

    for (int i = 0; i < count; i++) {
        print_file_info(&files[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [directory]\n", argv[0]);
        return 1;
    }

    print_disk_info(argv[1]);

    return 0;
}