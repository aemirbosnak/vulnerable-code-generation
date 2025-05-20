//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define MEGABYTE (1024 * 1024)

typedef struct {
    char path[4096];
    long long total_space;
    long long used_space;
    long long free_space;
    double percentage_used;
} DiskSpaceInfo;

void disk_space_analyzer(char* directory, DiskSpaceInfo* info) {
    DIR* dir = opendir(directory);
    if (dir == NULL) {
        printf("Error: could not open directory %s\n", directory);
        exit(1);
    }

    struct statvfs statvfs_buf;
    if (statvfs(directory, &statvfs_buf) == -1) {
        printf("Error: could not retrieve disk space information for %s\n", directory);
        exit(1);
    }

    info->total_space = statvfs_buf.f_blocks * statvfs_buf.f_frsize;
    info->used_space = statvfs_buf.f_blocks - statvfs_buf.f_bavail;
    info->free_space = statvfs_buf.f_bavail * statvfs_buf.f_frsize;
    info->percentage_used = (double)info->used_space / info->total_space * 100;

    struct dirent* dent;
    while ((dent = readdir(dir))!= NULL) {
        if (dent->d_type == DT_DIR) {
            char child_dir[4096];
            sprintf(child_dir, "%s/%s", directory, dent->d_name);
            disk_space_analyzer(child_dir, info);
        }
    }

    closedir(dir);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    char directory[4096];
    sprintf(directory, "%s", argv[1]);

    DiskSpaceInfo info;
    disk_space_analyzer(directory, &info);

    printf("Directory: %s\n", directory);
    printf("Total space: %.2f GB\n", info.total_space / MEGABYTE);
    printf("Used space: %.2f GB\n", info.used_space / MEGABYTE);
    printf("Free space: %.2f GB\n", info.free_space / MEGABYTE);
    printf("Percentage used: %.2f%%\n", info.percentage_used);

    return 0;
}