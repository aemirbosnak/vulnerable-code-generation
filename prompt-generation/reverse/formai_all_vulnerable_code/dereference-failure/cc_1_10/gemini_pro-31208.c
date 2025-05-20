//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: irregular
// C program to analyze disk space usage.
// warning: this is a very simple example and may not be suitable for all cases.

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

typedef struct {
    long long size;
    char *name;
} file_info;

int compare(const void *a, const void *b) {
    file_info *fa = (file_info *)a;
    file_info *fb = (file_info *)b;
    return fb->size - fa->size;
}

int main() {
    DIR *dir;
    struct dirent *ent;
    char *path = ".";
    long long total_size = 0;
    int num_files = 0;
    int num_dirs = 0;
    int num_other = 0;

    dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    while ((ent = readdir(dir)) != NULL) {
        struct stat buf;
        char *full_path = malloc(strlen(path) + strlen(ent->d_name) + 2);
        strcpy(full_path, path);
        strcat(full_path, "/");
        strcat(full_path, ent->d_name);

        if (lstat(full_path, &buf) == -1) {
            perror("lstat");
            free(full_path);
            continue;
        }

        if (S_ISREG(buf.st_mode)) {
            total_size += buf.st_size;
            num_files++;
        } else if (S_ISDIR(buf.st_mode)) {
            num_dirs++;
        } else {
            num_other++;
        }

        free(full_path);
    }

    closedir(dir);

    printf("Total size: %lld bytes\n", total_size);
    printf("Number of files: %d\n", num_files);
    printf("Number of directories: %d\n", num_dirs);
    printf("Number of other: %d\n", num_other);

    return EXIT_SUCCESS;
}