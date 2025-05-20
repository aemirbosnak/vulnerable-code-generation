//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_FILES 1000
#define MAX_FILE_NAME_LENGTH 256
#define MAX_PATH_LENGTH 1024

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    int size;
} File;

void addFile(File *files, int numFiles, const char *path) {
    DIR *dir = opendir(path);
    struct dirent *ent;

    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_REG) {
            char fullPath[MAX_PATH_LENGTH];
            sprintf(fullPath, "%s/%s", path, ent->d_name);

            struct stat fileStat;
            stat(fullPath, &fileStat);

            if (numFiles >= MAX_FILES) {
                printf("Warning: Maximum number of files reached.\n");
                break;
            }

            files[numFiles].size = fileStat.st_size;
            strncpy(files[numFiles].name, ent->d_name, MAX_FILE_NAME_LENGTH - 1);
            files[numFiles].name[MAX_FILE_NAME_LENGTH - 1] = '\0';

            numFiles++;
        }
    }

    closedir(dir);
}

void sortFiles(File *files, int numFiles) {
    for (int i = 0; i < numFiles - 1; i++) {
        for (int j = i + 1; j < numFiles; j++) {
            if (files[j].size > files[i].size) {
                File temp = files[i];
                files[i] = files[j];
                files[j] = temp;
            }
        }
    }
}

void printFiles(File *files, int numFiles) {
    for (int i = 0; i < numFiles; i++) {
        printf("%s (%d bytes)\n", files[i].name, files[i].size);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    File files[MAX_FILES];
    int numFiles = 0;

    addFile(files, numFiles, argv[1]);
    sortFiles(files, numFiles);
    printFiles(files, numFiles);

    return 0;
}