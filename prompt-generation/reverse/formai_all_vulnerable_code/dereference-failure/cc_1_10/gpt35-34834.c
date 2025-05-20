//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

typedef struct {
    char name[100];
    long size;
} File;

void analyzeDir(char *path, File *files, int *count) {
    DIR *dir;
    struct dirent *entry;
    struct stat fileStat;
    dir = opendir(path);
    if (dir == NULL) {
        return;
    }
    while ((entry = readdir(dir)) != NULL) {
        if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..")) continue;
        char filePath[1000];
        snprintf(filePath, 1000, "%s/%s", path, entry->d_name);
        if (lstat(filePath, &fileStat) < 0) continue;
        if (S_ISDIR(fileStat.st_mode)) {
            analyzeDir(filePath, files, count);
        } else {
            int i;
            for (i = 0; i < *count; i++) {
                if (!strcmp(files[i].name, entry->d_name)) {
                    files[i].size += fileStat.st_size;
                    break;
                }
            }
            if (i == *count) {
                strncpy(files[*count].name, entry->d_name, sizeof(files[*count].name));
                files[*count].size = fileStat.st_size;
                (*count)++;
            }
        }
    }
    closedir(dir);
}

int compare(const void *a, const void *b) {
    return ((File*)b)->size - ((File*)a)->size;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./disk-analyzer /path/to/analyze\n");
        return EXIT_FAILURE;
    }
    char *path = argv[1];
    File files[1000];
    int count = 0;
    analyzeDir(path, files, &count);
    qsort(files, count, sizeof(File), compare);
    printf("%-30s %s\n", "Name", "Size");
    int i;
    for (i = 0; i < count; i++) {
        printf("%-30s %ld bytes\n", files[i].name, files[i].size);
    }
    return EXIT_SUCCESS;
}