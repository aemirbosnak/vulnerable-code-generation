//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

typedef struct {
    char *path;
    long long size;
} FileInfo;

int compareFileInfo(const void *a, const void *b) {
    FileInfo *fa = (FileInfo *)a;
    FileInfo *fb = (FileInfo *)b;
    return fb->size - fa->size;
}

long long computeDirectorySize(char *path) {
    long long size = 0;
    DIR *dir = opendir(path);
    if (!dir) {
        return -1;
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        char *fullpath = malloc(strlen(path) + strlen(entry->d_name) + 2);
        strcpy(fullpath, path);
        strcat(fullpath, "/");
        strcat(fullpath, entry->d_name);
        struct stat st;
        if (stat(fullpath, &st) == 0) {
            if (S_ISDIR(st.st_mode)) {
                size += computeDirectorySize(fullpath);
            } else {
                size += st.st_size;
            }
        }
        free(fullpath);
    }
    closedir(dir);
    return size;
}

void printDiskSpaceUsage(char *path) {
    long long size = computeDirectorySize(path);
    if (size < 0) {
        printf("Error: could not compute directory size\n");
        return;
    }
    printf("Directory '%s' uses %lld bytes\n", path, size);
    const int MAX_FILES = 100;
    FileInfo files[MAX_FILES];
    int numFiles = 0;
    DIR *dir = opendir(path);
    if (!dir) {
        printf("Error: could not open directory\n");
        return;
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        char *fullpath = malloc(strlen(path) + strlen(entry->d_name) + 2);
        strcpy(fullpath, path);
        strcat(fullpath, "/");
        strcat(fullpath, entry->d_name);
        struct stat st;
        if (stat(fullpath, &st) == 0) {
            if (!S_ISDIR(st.st_mode)) {
                if (numFiles < MAX_FILES) {
                    files[numFiles].path = malloc(strlen(fullpath) + 1);
                    strcpy(files[numFiles].path, fullpath);
                    files[numFiles].size = st.st_size;
                    numFiles++;
                }
            }
        }
        free(fullpath);
    }
    closedir(dir);
    qsort(files, numFiles, sizeof(FileInfo), compareFileInfo);
    printf("Top %d largest files:\n", numFiles);
    for (int i = 0; i < numFiles; i++) {
        printf("%2d. %s (%lld bytes)\n", i + 1, files[i].path, files[i].size);
        free(files[i].path);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: disk_analyzer <path>\n");
        return 1;
    }
    printDiskSpaceUsage(argv[1]);
    return 0;
}