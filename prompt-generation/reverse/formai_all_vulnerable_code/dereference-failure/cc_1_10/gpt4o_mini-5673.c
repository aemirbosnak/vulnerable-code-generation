//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/statvfs.h>

#define MAX_PATH_LENGTH 1024
#define DEFAULT_PATH "/"

void display_disk_usage(const char *path) {
    struct statvfs stat;

    if (statvfs(path, &stat) != 0) { 
        perror("Could not get file system statistics");
        return;
    }

    unsigned long total_space = stat.f_blocks * stat.f_frsize;
    unsigned long free_space = stat.f_bfree * stat.f_frsize;
    unsigned long used_space = total_space - free_space;

    printf("Disk usage for path: %s\n", path);
    printf("Total space: %.2f GB\n", total_space / (1024.0 * 1024 * 1024));
    printf("Free space: %.2f GB\n", free_space / (1024.0 * 1024 * 1024));
    printf("Used space: %.2f GB\n", used_space / (1024.0 * 1024 * 1024));
}

void parse_arguments(int argc, char *argv[], char *path) {
    if (argc > 1) {
        strncpy(path, argv[1], MAX_PATH_LENGTH - 1);
        path[MAX_PATH_LENGTH - 1] = '\0'; // Ensure string is null-terminated
    } else {
        strncpy(path, DEFAULT_PATH, MAX_PATH_LENGTH - 1);
        path[MAX_PATH_LENGTH - 1] = '\0';
    }
}

void print_help_message() {
    printf("Disk Space Analyzer\n");
    printf("Usage: disk_analyzer [path]\n");
    printf("If no path is provided, it defaults to the root directory.\n");
}

int main(int argc, char *argv[]) {
    char path[MAX_PATH_LENGTH];

    parse_arguments(argc, argv, path);

    if (strcmp(path, "--help") == 0 || strcmp(path, "-h") == 0) {
        print_help_message();
        return 0;
    }

    display_disk_usage(path);
    return 0;
}