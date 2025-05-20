//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

typedef struct {
    char *path;
    long size;
} FileInfo;

int compareFileInfo(const void *a, const void *b) {
    FileInfo *fa = (FileInfo *)a;
    FileInfo *fb = (FileInfo *)b;
    return fb->size - fa->size;
}

long getDirectorySize(const char *path) {
    long size = 0;
    DIR *dir = opendir(path);
    if (dir == NULL) {
        return 0;
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        char *fullPath = malloc(strlen(path) + strlen(entry->d_name) + 2);
        sprintf(fullPath, "%s/%s", path, entry->d_name);
        struct stat st;
        if (lstat(fullPath, &st) == 0) {
            if (S_ISREG(st.st_mode)) {
                size += st.st_size;
            } else if (S_ISDIR(st.st_mode)) {
                size += getDirectorySize(fullPath);
            }
        }
        free(fullPath);
    }
    closedir(dir);
    return size;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    long totalSize = getDirectorySize(argv[1]);

    FileInfo *files = malloc(sizeof(FileInfo) * 100);
    int numFiles = 0;

    DIR *dir = opendir(argv[1]);
    if (dir == NULL) {
        return 1;
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        char *fullPath = malloc(strlen(argv[1]) + strlen(entry->d_name) + 2);
        sprintf(fullPath, "%s/%s", argv[1], entry->d_name);
        struct stat st;
        if (lstat(fullPath, &st) == 0) {
            if (S_ISREG(st.st_mode)) {
                files[numFiles].path = fullPath;
                files[numFiles].size = st.st_size;
                numFiles++;
            }
        }
        free(fullPath);
    }
    closedir(dir);

    qsort(files, numFiles, sizeof(FileInfo), compareFileInfo);

    printf("Total size: %ld bytes\n", totalSize);
    printf("Top 100 largest files:\n");
    for (int i = 0; i < numFiles && i < 100; i++) {
        printf("%d. %s (%ld bytes)\n", i + 1, files[i].path, files[i].size);
    }

    for (int i = 0; i < numFiles; i++) {
        free(files[i].path);
    }
    free(files);

    return 0;
}