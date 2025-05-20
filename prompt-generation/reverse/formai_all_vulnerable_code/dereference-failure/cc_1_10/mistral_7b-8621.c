//MISTRAL-7B DATASET v1.0 Category: Disk space analyzer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_DEPTH 3
#define BUF_SIZE 1024

typedef struct {
    char name[256];
    off_t size;
} file_t;

void print_files_in_dir(DIR *dir, int depth) {
    struct dirent *entry;
    file_t files[100];
    int num_files = 0;
    struct stat info;

    while ((entry = readdir(dir)) != NULL) {
        if (depth > MAX_DEPTH || S_ISDIR(entry->d_type)) {
            continue;
        }

        if (stat(entry->d_name, &info) < 0) {
            printf("Error reading %s\n", entry->d_name);
            continue;
        }

        if (S_ISREG(entry->d_type)) {
            strcpy(files[num_files].name, entry->d_name);
            files[num_files].size = info.st_size;
            num_files++;
        }
    }

    for (int i = 0; i < num_files; i++) {
        printf("%*s%s: %lld bytes\n", depth * 4, "", files[i].name, files[i].size);
    }
}

int main(int argc, char *argv[]) {
    DIR *dir;
    struct stat root_stats;

    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    if (stat(argv[1], &root_stats) < 0) {
        printf("Error reading %s\n", argv[1]);
        return 1;
    }

    if (!S_ISDIR(root_stats.st_mode)) {
        printf("%s is not a directory\n", argv[1]);
        return 1;
    }

    dir = opendir(argv[1]);

    if (dir == NULL) {
        printf("Error opening %s\n", argv[1]);
        return 1;
    }

    print_files_in_dir(dir, 0);

    closedir(dir);
    return 0;
}