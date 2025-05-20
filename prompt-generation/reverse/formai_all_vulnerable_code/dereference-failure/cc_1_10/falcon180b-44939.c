//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define MAX_PATHLEN 1024

// Function to calculate total disk space in human readable format
void disk_space(char *path, struct statvfs *buf) {
    double total_space = buf->f_blocks * buf->f_bsize;
    double used_space = (double)buf->f_blocks - buf->f_bfree;
    double free_space = buf->f_bavail * buf->f_bsize;

    printf("Total space: %.2f GB\n", total_space / (1024 * 1024 * 1024));
    printf("Used space: %.2f GB\n", used_space / (1024 * 1024 * 1024));
    printf("Free space: %.2f GB\n", free_space / (1024 * 1024 * 1024));
}

// Function to recursively calculate directory sizes
void dir_size(char *path, struct statvfs *buf) {
    DIR *dir;
    struct dirent *ent;
    char subpath[MAX_PATHLEN];

    if ((dir = opendir(path))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR) {
                snprintf(subpath, MAX_PATHLEN, "%s/%s", path, ent->d_name);
                if (statvfs(subpath, &buf) == 0) {
                    disk_space(subpath, buf);
                }
            }
        }
        closedir(dir);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    char path[MAX_PATHLEN];
    snprintf(path, MAX_PATHLEN, "%s", argv[1]);

    struct statvfs buf;
    if (statvfs(path, &buf)!= 0) {
        perror("statvfs");
        return 1;
    }

    printf("Disk space for '%s':\n", path);
    disk_space(path, &buf);

    dir_size(path, &buf);

    return 0;
}