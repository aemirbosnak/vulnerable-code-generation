//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define MAX_PATH 1024

// Function to get disk space usage of a directory
void get_disk_space_usage(const char *path, char *dir_name, float *total_space, float *used_space, float *free_space) {
    struct statvfs buf;
    if (statvfs(path, &buf)!= 0) {
        perror("statvfs");
        exit(EXIT_FAILURE);
    }

    *total_space = (float) buf.f_blocks * (float) buf.f_frsize;
    *used_space = *total_space - (float) buf.f_bavail * (float) buf.f_frsize;
    *free_space = (float) buf.f_bavail * (float) buf.f_frsize;

    strcpy(dir_name, path);
}

// Function to print disk space usage of a directory
void print_disk_space_usage(const char *dir_name, float total_space, float used_space, float free_space) {
    printf("Directory: %s\n", dir_name);
    printf("Total space: %.2f GB\n", total_space / (1024 * 1024 * 1024));
    printf("Used space: %.2f GB\n", used_space / (1024 * 1024 * 1024));
    printf("Free space: %.2f GB\n", free_space / (1024 * 1024 * 1024));
    printf("\n");
}

// Function to traverse a directory and print disk space usage of all subdirectories
void traverse_directory(const char *path, int depth) {
    DIR *dir;
    struct dirent *ent;
    char dir_name[MAX_PATH];
    float total_space, used_space, free_space;

    if ((dir = opendir(path))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR) {
                snprintf(dir_name, MAX_PATH, "%s/%s", path, ent->d_name);
                get_disk_space_usage(dir_name, dir_name, &total_space, &used_space, &free_space);
                print_disk_space_usage(dir_name, total_space, used_space, free_space);
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

    traverse_directory(argv[1], 0);

    return 0;
}