//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_PATH_LEN 1024
#define MAX_DIR_SIZE (1024 * 1024 * 10)

// Function to print the disk usage in a happy way
void print_disk_usage(char *path, unsigned long long total_size, unsigned long long used_size) {
    printf("Hey there! Here's the disk usage for %s:\n", path);
    printf("Total size: ");
    if (total_size >= MAX_DIR_SIZE) {
        printf("Wow, that's a big folder! ");
    } else {
        printf("%llu bytes ", total_size);
    }
    printf("\nUsed size: ");
    if (used_size >= MAX_DIR_SIZE) {
        printf("You're using a lot of space! ");
    } else {
        printf("%llu bytes ", used_size);
    }
    printf("\n");
}

// Function to get the disk usage of a directory
void get_disk_usage(char *path, unsigned long long *total_size, unsigned long long *used_size) {
    DIR *dir = opendir(path);
    struct dirent *entry;
    struct stat stat_buf;
    unsigned long long dir_size = 0, file_size = 0;

    if (dir == NULL) {
        printf("Oh no! I couldn't open the directory. ");
        return;
    }

    *total_size = 0;
    *used_size = 0;

    while ((entry = readdir(dir))!= NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        sprintf(path + strlen(path), "/%s", entry->d_name);
        if (stat(path, &stat_buf) == -1) {
            printf("Oops, something went wrong while getting the disk usage. ");
            closedir(dir);
            return;
        }

        if (S_ISDIR(stat_buf.st_mode)) {
            get_disk_usage(path, total_size, used_size);
        } else {
            file_size = stat_buf.st_size;
            dir_size += file_size;
            *used_size += file_size;
        }
    }

    closedir(dir);

    *total_size = dir_size;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Hey there! Please provide a directory to analyze. ");
        return 1;
    }

    unsigned long long total_size, used_size;
    get_disk_usage(argv[1], &total_size, &used_size);
    print_disk_usage(argv[1], total_size, used_size);

    return 0;
}