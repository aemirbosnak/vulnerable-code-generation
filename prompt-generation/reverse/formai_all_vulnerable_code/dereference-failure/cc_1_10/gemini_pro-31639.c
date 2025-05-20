//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

typedef struct {
    char *name;
    size_t size;
} FileInfo;

int compareFiles(const void *a, const void *b) {
    const FileInfo *fa = (const FileInfo *)a;
    const FileInfo *fb = (const FileInfo *)b;
    return fb->size - fa->size;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *directory = argv[1];

    DIR *dir = opendir(directory);
    if (dir == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    size_t fileCount = 0;
    size_t totalSize = 0;

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..")) {
            continue;
        }

        char *path = malloc(strlen(directory) + strlen(entry->d_name) + 2);
        if (path == NULL) {
            perror("malloc");
            closedir(dir);
            return EXIT_FAILURE;
        }

        sprintf(path, "%s/%s", directory, entry->d_name);

        struct stat statbuf;
        if (stat(path, &statbuf) == -1) {
            perror("stat");
            closedir(dir);
            return EXIT_FAILURE;
        }

        if (S_ISREG(statbuf.st_mode)) {
            fileCount++;
            totalSize += statbuf.st_size;
        }

        free(path);
    }

    closedir(dir);

    FileInfo *files = malloc(fileCount * sizeof(FileInfo));
    if (files == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    rewinddir(dir);
    size_t i = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..")) {
            continue;
        }

        char *path = malloc(strlen(directory) + strlen(entry->d_name) + 2);
        if (path == NULL) {
            perror("malloc");
            closedir(dir);
            free(files);
            return EXIT_FAILURE;
        }

        sprintf(path, "%s/%s", directory, entry->d_name);

        struct stat statbuf;
        if (stat(path, &statbuf) == -1) {
            perror("stat");
            closedir(dir);
            free(files);
            return EXIT_FAILURE;
        }

        if (S_ISREG(statbuf.st_mode)) {
            files[i].name = strdup(entry->d_name);
            files[i].size = statbuf.st_size;
            i++;
        }

        free(path);
    }

    closedir(dir);

    qsort(files, fileCount, sizeof(FileInfo), compareFiles);

    printf("Total files: %zu\n", fileCount);
    printf("Total size: %zu bytes\n", totalSize);
    printf("Top 10 largest files:\n");
    for (i = 0; i < 10 && i < fileCount; i++) {
        printf("%s\t%zu bytes\n", files[i].name, files[i].size);
    }

    for (i = 0; i < fileCount; i++) {
        free(files[i].name);
    }

    free(files);

    return EXIT_SUCCESS;
}