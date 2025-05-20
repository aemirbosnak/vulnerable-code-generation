//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_PATH_LEN 256

typedef struct FileInfo {
    char path[MAX_PATH_LEN];
    long size;
} FileInfo;

int compareFileInfo(const void *a, const void *b) {
    FileInfo *fa = (FileInfo *) a;
    FileInfo *fb = (FileInfo *) b;
    return fb->size - fa->size;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    char *dir_path = argv[1];

    DIR *dir = opendir(dir_path);
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    int file_count = 0;
    long total_size = 0;

    FileInfo *files = malloc(sizeof(FileInfo) * 100);
    if (files == NULL) {
        perror("malloc");
        closedir(dir);
        return 1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char file_path[MAX_PATH_LEN];
        snprintf(file_path, MAX_PATH_LEN, "%s/%s", dir_path, entry->d_name);

        struct stat statbuf;
        if (lstat(file_path, &statbuf) != 0) {
            perror("lstat");
            continue;
        }

        if (S_ISREG(statbuf.st_mode)) {
            files[file_count].size = statbuf.st_size;
            strcpy(files[file_count].path, file_path);
            file_count++;
        }
    }

    closedir(dir);

    qsort(files, file_count, sizeof(FileInfo), compareFileInfo);

    printf("Directory: %s\n", dir_path);
    printf("Total files: %d\n", file_count);
    for (int i = 0; i < file_count; i++) {
        printf("%5ld %s\n", files[i].size, files[i].path);
    }

    free(files);

    return 0;
}