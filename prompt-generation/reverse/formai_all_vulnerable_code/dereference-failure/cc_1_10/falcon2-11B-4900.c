//Falcon2-11B DATASET v1.0 Category: Disk space analyzer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>

struct disk_t {
    long long total;
    long long used;
};

struct disk_t* analyzeDiskSpace(const char* path) {
    struct stat st;
    DIR* dir;
    struct dirent* entry;
    struct disk_t* disk;

    if (stat(path, &st) < 0) {
        printf("Error: Failed to access the file system.\n");
        return NULL;
    }

    disk = malloc(sizeof(struct disk_t));
    if (disk == NULL) {
        printf("Error: Failed to allocate memory.\n");
        return NULL;
    }

    disk->total = st.st_blocks * st.st_blksize;
    disk->used = 0;

    dir = opendir(path);
    if (dir == NULL) {
        printf("Error: Failed to open the directory.\n");
        return NULL;
    }

    while ((entry = readdir(dir))!= NULL) {
        if (entry->d_type == DT_DIR) {
            struct stat st_entry;
            char path_entry[PATH_MAX];

            if (stat(path_entry, &st_entry) < 0) {
                printf("Error: Failed to access the file system.\n");
                return NULL;
            }

            disk->used += st_entry.st_blocks * st_entry.st_blksize;
        }
    }

    closedir(dir);

    return disk;
}

int main() {
    struct disk_t* disk;
    const char* path = "/";

    disk = analyzeDiskSpace(path);
    if (disk!= NULL) {
        printf("Total Disk Space: %lld bytes\n", disk->total);
        printf("Used Disk Space: %lld bytes\n", disk->used);
        free(disk);
    } else {
        printf("Error: Failed to analyze the disk space.\n");
    }

    return 0;
}