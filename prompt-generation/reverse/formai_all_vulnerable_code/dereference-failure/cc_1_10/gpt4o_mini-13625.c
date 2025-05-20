//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024

typedef struct {
    char path[MAX_PATH];
    long total_size;
} Directory;

void analyze_directory(Directory dir) {
    struct dirent *entry;
    struct stat info;
    long dir_size = 0;
    DIR *d = opendir(dir.path);

    if (d == NULL) {
        perror("Failed to open directory");
        return;
    }

    while ((entry = readdir(d)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char path[MAX_PATH];
        snprintf(path, sizeof(path), "%s/%s", dir.path, entry->d_name);
        
        if (stat(path, &info) == 0) {
            if (S_ISDIR(info.st_mode)) {
                Directory subdir;
                strncpy(subdir.path, path, MAX_PATH);
                analyze_directory(subdir);
            } else {
                dir_size += info.st_size;
            }
        }
    }

    closedir(d);
    dir.total_size = dir_size;
    printf("Directory: %s\nTotal Size: %ld bytes\n", dir.path, dir.total_size);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Directory initial_dir;
    strncpy(initial_dir.path, argv[1], MAX_PATH);
    analyze_directory(initial_dir);
    return EXIT_SUCCESS;
}