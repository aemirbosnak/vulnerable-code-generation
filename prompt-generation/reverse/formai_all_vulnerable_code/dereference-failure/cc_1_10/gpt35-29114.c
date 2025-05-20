//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include <sys/stat.h>

#define BLOCK_SIZE 512

typedef struct {
    char *name;
    long size;
} File;

void print_human_readable_size(long bytes) {
    const char *suffixes[] = {"B", "KB", "MB", "GB", "TB"};
    int i = 0;

    while (bytes >= 1024 && i < 4) {
        bytes /= 1024;
        i++;
    }

    printf("%ld %s\n", bytes, suffixes[i]);
}

void print_disk_space_usage(char *path) {
    DIR *dp;
    struct dirent *entry;
    struct stat filestat;
    char *filepath;
    long total_size = 0;
    int file_count = 0;

    dp = opendir(path);
    if (dp == NULL) {
        fprintf(stderr, "Cannot open directory: %s\n", path);
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_name[0] == '.') continue; // skip hidden files and directories

        filepath = (char*)malloc(sizeof(char) * (strlen(path) + strlen(entry->d_name) + 2));
        sprintf(filepath, "%s/%s", path, entry->d_name);

        if (stat(filepath, &filestat)) {
            fprintf(stderr, "Cannot stat file: %s\n", filepath);
            free(filepath);
            continue;
        }

        if (S_ISDIR(filestat.st_mode)) {
            print_disk_space_usage(filepath);
        } else if (S_ISREG(filestat.st_mode)) {
            total_size += filestat.st_size;
            file_count++;
        }

        free(filepath);
    }

    closedir(dp);

    if (file_count > 0) {
        printf("Total size of %d files in %s: ", file_count, path);
        print_human_readable_size(total_size);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    print_disk_space_usage(argv[1]);

    return 0;
}