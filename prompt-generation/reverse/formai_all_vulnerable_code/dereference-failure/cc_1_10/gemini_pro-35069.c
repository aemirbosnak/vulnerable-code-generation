//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_PATH_LEN 1024

typedef struct {
    char *path;
    long size;
} file_t;

int comp_files(const void *a, const void *b) {
    file_t *fa = (file_t *)a;
    file_t *fb = (file_t *)b;
    return fb->size - fa->size;
}

long get_file_size(const char *path) {
    struct stat statbuf;
    if (lstat(path, &statbuf) == -1) {
        return -1;
    }
    return statbuf.st_size;
}

void print_file(file_t *file) {
    printf("%s\t%ld\n", file->path, file->size);
}

int main(int argc, char *argv[]) {
    char path[MAX_PATH_LEN] = ".";
    if (argc > 1) {
        strcpy(path, argv[1]);
    }

    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    file_t *files = NULL;
    int num_files = 0;

    struct dirent *dirent;
    while ((dirent = readdir(dir)) != NULL) {
        if (strcmp(dirent->d_name, ".") == 0 || strcmp(dirent->d_name, "..") == 0) {
            continue;
        }

        char subpath[MAX_PATH_LEN];
        snprintf(subpath, MAX_PATH_LEN, "%s/%s", path, dirent->d_name);

        long size = get_file_size(subpath);
        if (size == -1) {
            continue;
        }

        files = realloc(files, (num_files + 1) * sizeof(file_t));
        files[num_files].path = strdup(subpath);
        files[num_files].size = size;
        num_files++;
    }

    closedir(dir);

    qsort(files, num_files, sizeof(file_t), comp_files);

    for (int i = 0; i < num_files; i++) {
        print_file(&files[i]);
    }

    for (int i = 0; i < num_files; i++) {
        free(files[i].path);
    }
    free(files);

    return 0;
}