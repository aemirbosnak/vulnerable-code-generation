//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>

struct FileInfo {
    char *name;
    long long size;
    time_t last_modified;
};

void print_file_info(struct FileInfo *file) {
    printf("File: %s\n", file->name);
    printf("Size: %lld bytes\n", file->size);
    printf("Last modified: %s", ctime(&file->last_modified));
    printf("\n");
}

void free_file_info(struct FileInfo *file) {
    free(file->name);
    free(file);
}

void analyze_directory(const char *path, long long *total_size) {
    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;

    dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char *full_path = malloc(strlen(path) + strlen(entry->d_name) + 2);
        sprintf(full_path, "%s/%s", path, entry->d_name);

        if (stat(full_path, &statbuf) == -1) {
            perror("stat");
            free(full_path);
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            analyze_directory(full_path, total_size);
        } else {
            struct FileInfo *file = malloc(sizeof(struct FileInfo));
            file->name = full_path;
            file->size = statbuf.st_size;
            file->last_modified = statbuf.st_mtime;

            *total_size += file->size;
            print_file_info(file);
            free_file_info(file);
        }
    }

    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }

    long long total_size = 0;
    analyze_directory(argv[1], &total_size);

    printf("Total size: %lld bytes\n", total_size);
    return 0;
}