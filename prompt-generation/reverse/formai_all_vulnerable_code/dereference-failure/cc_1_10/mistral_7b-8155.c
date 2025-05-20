//MISTRAL-7B DATASET v1.0 Category: Disk space analyzer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_DEPTH 10
#define BUF_SIZE 4096

struct DirInfo {
    char name[256];
    off_t size;
};

void traverse_dir(const char *path, int depth, struct DirInfo *parent, off_t *total) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;
    struct DirInfo dir_info, file_info;

    if (!(dir = opendir(path))) {
        return;
    }

    while ((entry = readdir(dir))) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(dir_info.name, sizeof(dir_info.name), "%s/%s", path, entry->d_name);

        if (depth < MAX_DEPTH) {
            traverse_dir(dir_info.name, depth + 1, &dir_info, total);
        }

        snprintf(file_info.name, sizeof(file_info.name), "%s/%s", path, entry->d_name);
        if (lstat(file_info.name, &file_stat) < 0) {
            continue;
        }

        if (S_ISDIR(file_stat.st_mode)) {
            dir_info.size += file_stat.st_blocks * file_stat.st_blksize;
            traverse_dir(file_info.name, depth + 1, &dir_info, total);
        } else {
            file_info.size = file_stat.st_size;
            *total += file_info.size;
            printf("%-20s %10llu bytes\n", file_info.name, (long unsigned int)file_info.size);
        }
    }

    closedir(dir);

    if (depth > 0) {
        parent->size += dir_info.size;
        strcpy(parent->name, dir_info.name);
    }
}

int main() {
    char root_path[256];
    getcwd(root_path, sizeof(root_path));
    struct DirInfo root;
    off_t total = 0;

    printf("Disk usage analysis for %s:\n\n", root_path);
    traverse_dir(root_path, 0, &root, &total);
    printf("\nTotal disk usage: %llu bytes\n", (long unsigned int)total);

    return 0;
}