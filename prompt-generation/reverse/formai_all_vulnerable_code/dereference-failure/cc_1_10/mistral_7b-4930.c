//MISTRAL-7B DATASET v1.0 Category: Disk space analyzer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

typedef struct FileInfo_tag {
    char name[256];
    off_t size;
} FileInfo;

void processDirectory(DIR *dir, char *path) {
    struct stat info;
    struct dirent *entry;
    FileInfo fileInfo;

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(fileInfo.name, sizeof(fileInfo.name), "%s/%s", path, entry->d_name);
        if (lstat(fileInfo.name, &info) == -1) {
            fprintf(stderr, "Error accessing %s\n", fileInfo.name);
            continue;
        }

        if (S_ISDIR(info.st_mode)) {
            processDirectory(opendir(fileInfo.name), fileInfo.name);
            closedir(opendir(fileInfo.name));
        } else {
            fileInfo.size = info.st_size;
            printf("%-40s %10llu bytes\n", fileInfo.name, fileInfo.size);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    if (chdir(argv[1]) != 0) {
        perror("Error changing directory");
        return 1;
    }

    processDirectory(opendir("."), ".");

    return 0;
}