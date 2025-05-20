//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>

#define MAX_PATH_LENGTH 1024

typedef struct {
    char *path;
    long long size;
} FileInfo;

int compareFileInfo(const void *a, const void *b) {
    const FileInfo *fa = (const FileInfo *)a;
    const FileInfo *fb = (const FileInfo *)b;
    return fb->size - fa->size;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    DIR *dir = opendir(argv[1]);
    if (dir == NULL) {
        fprintf(stderr, "Error opening directory: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    int numFiles = 0;
    FileInfo *files = NULL;

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char path[MAX_PATH_LENGTH];
        snprintf(path, MAX_PATH_LENGTH, "%s/%s", argv[1], entry->d_name);

        struct stat statbuf;
        if (stat(path, &statbuf) == -1) {
            fprintf(stderr, "Error getting file stats: %s\n", strerror(errno));
            continue;
        }

        if (!S_ISREG(statbuf.st_mode)) {
            continue;
        }

        FileInfo *file = malloc(sizeof(FileInfo));
        file->path = strdup(path);
        file->size = statbuf.st_size;

        files = realloc(files, (numFiles + 1) * sizeof(FileInfo));
        files[numFiles++] = *file;
    }

    closedir(dir);

    qsort(files, numFiles, sizeof(FileInfo), compareFileInfo);

    for (int i = 0; i < numFiles; i++) {
        printf("%lld %s\n", files[i].size, files[i].path);
        free(files[i].path);
    }
    free(files);

    return EXIT_SUCCESS;
}