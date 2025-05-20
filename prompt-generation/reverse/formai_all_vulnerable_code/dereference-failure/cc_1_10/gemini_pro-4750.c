//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

typedef struct {
    char *name;
    long size;
} file_info;

int compare_files(const void *a, const void *b) {
    file_info *fa = (file_info *)a;
    file_info *fb = (file_info *)b;
    return fb->size - fa->size;
}

int main() {
    DIR *dir = opendir(".");
    if (dir == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    struct dirent *dirent;
    long total_size = 0;
    int num_files = 0;

    while ((dirent = readdir(dir)) != NULL) {
        if (strcmp(dirent->d_name, ".") == 0 || strcmp(dirent->d_name, "..") == 0) {
            continue;
        }

        struct stat statbuf;
        if (stat(dirent->d_name, &statbuf) == -1) {
            perror("stat");
            continue;
        }

        num_files++;
        total_size += statbuf.st_size;
    }

    rewinddir(dir);

    file_info *files = malloc(sizeof(file_info) * num_files);
    if (files == NULL) {
        perror("malloc");
        closedir(dir);
        return EXIT_FAILURE;
    }

    int i = 0;
    while ((dirent = readdir(dir)) != NULL) {
        if (strcmp(dirent->d_name, ".") == 0 || strcmp(dirent->d_name, "..") == 0) {
            continue;
        }

        struct stat statbuf;
        if (stat(dirent->d_name, &statbuf) == -1) {
            perror("stat");
            continue;
        }

        files[i].name = strdup(dirent->d_name);
        files[i].size = statbuf.st_size;
        i++;
    }

    closedir(dir);

    qsort(files, num_files, sizeof(file_info), compare_files);

    printf("Total size: %ld\n", total_size);

    for (i = 0; i < num_files; i++) {
        printf("%s: %ld\n", files[i].name, files[i].size);
        free(files[i].name);
    }

    free(files);

    return EXIT_SUCCESS;
}