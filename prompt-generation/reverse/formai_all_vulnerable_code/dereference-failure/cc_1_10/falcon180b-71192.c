//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define MAX_DIR_DEPTH 1000

typedef struct {
    char path[MAX_DIR_DEPTH];
    size_t size;
    size_t files;
    size_t dirs;
} dir_info_t;

void get_dir_info(const char *path, dir_info_t *info) {
    DIR *d;
    struct dirent *dir;
    d = opendir(path);

    if (d) {
        info->size = 0;
        info->files = 0;
        info->dirs = 0;

        while ((dir = readdir(d))!= NULL) {
            if (dir->d_type == DT_DIR) {
                if (strcmp(dir->d_name, ".")!= 0 && strcmp(dir->d_name, "..")!= 0) {
                    info->dirs++;
                    snprintf(info->path + strlen(info->path), MAX_DIR_DEPTH - strlen(info->path), "/%s", dir->d_name);
                    get_dir_info(info->path, info);
                }
            } else {
                info->files++;
                info->size += dir->d_off;
            }
        }

        closedir(d);
    }
}

void print_dir_info(const char *path, dir_info_t *info) {
    printf("Path: %s\n", path);
    printf("Total size: %zu bytes\n", info->size);
    printf("Number of files: %zu\n", info->files);
    printf("Number of directories: %zu\n", info->dirs);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    dir_info_t info;
    info.size = 0;
    info.files = 0;
    info.dirs = 0;

    snprintf(info.path, MAX_DIR_DEPTH, "%s", argv[1]);
    get_dir_info(info.path, &info);

    print_dir_info(argv[1], &info);

    return 0;
}