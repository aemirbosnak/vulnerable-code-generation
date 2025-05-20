//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define PATH_MAX 4096
#define BUFFER_SIZE 256

typedef struct {
    char name[PATH_MAX];
    long total_size;
} DirectoryInfo;

void calculate_directory_size(const char *path, DirectoryInfo *dir_info) {
    struct dirent *entry;
    struct stat statbuf;
    DIR *dp = opendir(path);

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        char fullpath[PATH_MAX];
        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);

        if (stat(fullpath, &statbuf) == -1) {
            perror("stat");
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                calculate_directory_size(fullpath, dir_info); // Recursion for subdirectories
            }
        } else {
            dir_info->total_size += statbuf.st_size; // Add file size to total
        }
    }

    closedir(dp);
}

void print_directory_info(const DirectoryInfo *dir_info, const char *base_path) {
    printf("Directory: %s\n", base_path);
    printf("Total size: %ld bytes\n", dir_info->total_size);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    DirectoryInfo dir_info;
    strncpy(dir_info.name, argv[1], sizeof(dir_info.name) - 1);
    dir_info.name[sizeof(dir_info.name) - 1] = '\0'; // Null-terminate the string
    dir_info.total_size = 0;

    calculate_directory_size(argv[1], &dir_info);
    print_directory_info(&dir_info, dir_info.name);

    return EXIT_SUCCESS;
}