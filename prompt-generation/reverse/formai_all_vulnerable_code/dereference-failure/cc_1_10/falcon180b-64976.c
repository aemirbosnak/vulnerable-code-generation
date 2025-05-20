//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define MAX_PATH 1024

// Function to list all files in a directory
void list_files(const char* path) {
    DIR* dir = opendir(path);
    struct dirent* ent;

    while ((ent = readdir(dir))!= NULL) {
        printf("%s\n", ent->d_name);
    }

    closedir(dir);
}

// Function to calculate disk space usage
void disk_usage(const char* path) {
    struct statvfs buf;

    if (statvfs(path, &buf) == -1) {
        perror("statvfs");
        exit(1);
    }

    printf("Total space: %ld bytes\n", buf.f_bsize * buf.f_blocks);
    printf("Available space: %ld bytes\n", buf.f_bsize * buf.f_bavail);
    printf("Used space: %ld bytes\n", buf.f_bsize * (buf.f_blocks - buf.f_bavail));
}

// Function to traverse directories and calculate disk space usage
void traverse_dir(const char* path) {
    char next_path[MAX_PATH];

    strcpy(next_path, path);
    strcat(next_path, "/");

    DIR* dir = opendir(path);
    struct dirent* ent;

    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_DIR) {
            strcat(next_path, ent->d_name);
            traverse_dir(next_path);
        }
    }

    disk_usage(path);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s directory\n", argv[0]);
        return 1;
    }

    traverse_dir(argv[1]);

    return 0;
}