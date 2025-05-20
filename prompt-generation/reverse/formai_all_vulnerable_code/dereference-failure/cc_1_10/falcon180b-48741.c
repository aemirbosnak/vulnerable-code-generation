//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUF_SIZE 1024

typedef struct {
    char *path;
    long size;
} FileInfo;

void print_file_info(FileInfo *file_info) {
    printf("%s: %ld bytes\n", file_info->path, file_info->size);
}

long get_directory_size(char *path) {
    long size = 0;
    DIR *dir = opendir(path);
    struct dirent *ent;

    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_REG) {
            char file_path[BUF_SIZE];
            snprintf(file_path, BUF_SIZE, "%s/%s", path, ent->d_name);
            struct stat file_stat;
            stat(file_path, &file_stat);
            size += file_stat.st_size;
        }
    }

    closedir(dir);
    return size;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    char *dir_path = argv[1];
    long dir_size = get_directory_size(dir_path);

    printf("Directory size for '%s': %ld bytes\n", dir_path, dir_size);

    return 0;
}