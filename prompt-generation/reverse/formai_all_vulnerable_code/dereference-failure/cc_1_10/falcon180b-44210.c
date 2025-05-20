//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>
#include <sys/stat.h>

#define MAX_PATH 1024

/* Function to print the disk usage statistics */
void print_disk_usage(char *path, struct statvfs *disk_stats) {
    printf("Path: %s\n", path);
    printf("Total space: %ld bytes\n", disk_stats->f_bsize * disk_stats->f_blocks);
    printf("Used space: %ld bytes\n", disk_stats->f_bsize * disk_stats->f_blocks - disk_stats->f_bfree * disk_stats->f_bsize);
    printf("Free space: %ld bytes\n", disk_stats->f_bfree * disk_stats->f_bsize);
    printf("Available space: %ld bytes\n", disk_stats->f_bavail * disk_stats->f_bsize);
    printf("\n");
}

/* Function to get the disk usage statistics for a given path */
void get_disk_usage(char *path) {
    struct statvfs disk_stats;
    if (statvfs(path, &disk_stats) == -1) {
        printf("Error getting disk usage statistics for %s\n", path);
        return;
    }
    print_disk_usage(path, &disk_stats);
}

/* Function to traverse the directory tree and print the disk usage statistics for each directory */
void traverse_dir(char *path) {
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(path))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            char subpath[MAX_PATH];
            strcpy(subpath, path);
            strcat(subpath, "/");
            strcat(subpath, ent->d_name);
            if (ent->d_type == DT_DIR) {
                get_disk_usage(subpath);
                traverse_dir(subpath);
            }
        }
        closedir(dir);
    }
}

/* Main function */
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }
    traverse_dir(argv[1]);
    return 0;
}