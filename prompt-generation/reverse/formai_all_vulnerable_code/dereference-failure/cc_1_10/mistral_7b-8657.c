//MISTRAL-7B DATASET v1.0 Category: Disk space analyzer ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

typedef struct {
    char name[100];
    int size;
} FileOrDir;

void processDirectory(char *path, FileOrDir *files, int *numFiles, int *totalSize) {
    DIR *dir;
    struct dirent *entry;
    struct stat info;

    if (!(dir = opendir(path))) return;

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) continue;

        char fullPath[200];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);
        if (lstat(fullPath, &info) == -1) continue;

        if (S_ISDIR(info.st_mode)) {
            if (*numFiles < 1000) {
                FileOrDir dir;
                strcpy(dir.name, entry->d_name);
                processDirectory(fullPath, files, numFiles, totalSize);
                *numFiles += 1;
                *totalSize += totalSize[*numFiles - 1];
            }
            continue;
        }

        if (*numFiles < 1000) {
            FileOrDir file;
            strcpy(file.name, entry->d_name);
            file.size = info.st_size;
            files[*numFiles] = file;
            *numFiles += 1;
            *totalSize += file.size;
        }
    }

    closedir(dir);
}

int main() {
    FileOrDir files[10000];
    int numFiles = 0;
    int totalSize[10000] = {0};

    processDirectory("/", files, &numFiles, totalSize);

    printf("Directory of C:\\\n");
    printf("--------------------\n");
    printf("Name                Size(bytes)\n");
    printf("--------------------\n");

    for (int i = 0; i < numFiles; i++) {
        printf("%-20s   %10d\n", files[i].name, files[i].size);
    }

    return 0;
}