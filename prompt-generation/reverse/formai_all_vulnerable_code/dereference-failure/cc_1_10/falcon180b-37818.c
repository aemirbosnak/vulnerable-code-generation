//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define BLOCK_SIZE 1024

typedef struct {
    char *path;
    long long size;
    int is_directory;
} FileInfo;

long long get_folder_size(const char *path) {
    long long size = 0;
    DIR *dir = opendir(path);
    struct dirent *ent;

    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_REG) {
            FileInfo file_info;
            file_info.path = ent->d_name;
            file_info.size = ent->d_reclen;
            file_info.is_directory = 0;

            size += file_info.size;
        } else if (ent->d_type == DT_DIR) {
            FileInfo file_info;
            file_info.path = ent->d_name;
            file_info.size = 0;
            file_info.is_directory = 1;

            long long dir_size = get_folder_size(file_info.path);
            size += dir_size;
        }
    }

    closedir(dir);
    return size;
}

int main() {
    char *path = ".";
    long long total_size = 0;
    long long free_size = 0;
    long long used_size = 0;

    struct statvfs buf;
    if (statvfs(path, &buf) == 0) {
        total_size = buf.f_blocks * BLOCK_SIZE;
        free_size = buf.f_bavail * BLOCK_SIZE;
        used_size = total_size - free_size;
    }

    printf("Total size: %lld bytes\n", total_size);
    printf("Used size: %lld bytes\n", used_size);
    printf("Free size: %lld bytes\n", free_size);

    get_folder_size(path);

    return 0;
}