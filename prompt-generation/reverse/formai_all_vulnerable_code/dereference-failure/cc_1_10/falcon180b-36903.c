//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define BUFFER_SIZE 4096

// Function to print the total, used and free space in a human readable format
void print_space(double total, double used, double free) {
    printf("Total: %.2f MB\n", total);
    printf("Used: %.2f MB\n", used);
    printf("Free: %.2f MB\n", free);
}

// Function to recursively scan a directory and print the space used by each file and directory
void scan_directory(char* path, double* total_space, double* used_space) {
    DIR* dir = opendir(path);
    struct dirent* entry;
    while ((entry = readdir(dir))!= NULL) {
        char* full_path = malloc(strlen(path) + strlen(entry->d_name) + 2);
        sprintf(full_path, "%s/%s", path, entry->d_name);

        struct statvfs stat;
        if (statvfs(full_path, &stat) == 0) {
            double space_used = (double)stat.f_blocks * stat.f_frsize / (1024 * 1024);
            *total_space += space_used;
            *used_space += space_used;
        } else {
            printf("Error getting space for %s\n", full_path);
        }

        if (entry->d_type == DT_DIR) {
            scan_directory(full_path, total_space, used_space);
        }

        free(full_path);
    }
    closedir(dir);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s [directory]\n", argv[0]);
        return 1;
    }

    char* path = argv[1];
    double total_space = 0;
    double used_space = 0;

    scan_directory(path, &total_space, &used_space);

    print_space(total_space, used_space, total_space - used_space);

    return 0;
}