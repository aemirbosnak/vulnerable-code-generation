//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define KB (1024)
#define MB (KB * 1024)
#define GB (MB * 1024)

// Function to calculate the size of a directory in bytes
off_t dir_size(const char *path) {
    struct dirent *dirent;
    DIR *dir = opendir(path);
    off_t size = 0;

    if (dir!= NULL) {
        while ((dirent = readdir(dir))!= NULL) {
            if (dirent->d_type == DT_REG) {
                size += dirent->d_off;
            } else if (dirent->d_type == DT_DIR) {
                char *subpath = malloc(strlen(path) + strlen(dirent->d_name) + 2);
                strcpy(subpath, path);
                strcat(subpath, "/");
                strcat(subpath, dirent->d_name);
                size += dir_size(subpath);
                free(subpath);
            }
        }
        closedir(dir);
    }

    return size;
}

// Function to print the disk usage of a directory
void print_disk_usage(const char *path, off_t size) {
    struct statvfs buf;
    if (statvfs(path, &buf) == 0) {
        double used_percent = (double)size / (double)buf.f_blocks * 100.0;
        printf("Disk usage for %s:\n", path);
        printf("Total size: %lld bytes\n", size);
        printf("Used space: %lld bytes (%d%%)\n", size, (int)used_percent);
        printf("Free space: %lld bytes (%d%%)\n", (buf.f_blocks - size) * buf.f_frsize, (int)(100.0 - used_percent));
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    char *path = argv[1];
    off_t size = dir_size(path);
    print_disk_usage(path, size);

    return 0;
}