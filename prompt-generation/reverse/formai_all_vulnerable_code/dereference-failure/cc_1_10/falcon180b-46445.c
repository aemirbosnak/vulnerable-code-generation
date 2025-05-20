//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>
#include <string.h>

#define MAX_PATH 1024

typedef struct {
    char path[MAX_PATH];
    unsigned long long size;
} FileInfo;

void getFilesInDir(const char* dir, FileInfo* files, int* numFiles) {
    DIR* d = opendir(dir);
    struct dirent* entry;
    while ((entry = readdir(d))!= NULL) {
        if (entry->d_type == DT_REG || entry->d_type == DT_LNK) {
            if (*numFiles >= MAX_PATH - 1) {
                printf("Error: Too many files in directory.\n");
                exit(1);
            }
            strcpy(files[*numFiles].path, dir);
            strcat(files[*numFiles].path, "/");
            strcat(files[*numFiles].path, entry->d_name);
            files[*numFiles].size = 0;
            (*numFiles)++;
        }
    }
    closedir(d);
}

unsigned long long getDirSize(const char* path) {
    struct statvfs buf;
    if (statvfs(path, &buf) == -1) {
        perror("statvfs");
        exit(1);
    }
    return buf.f_blocks * buf.f_frsize;
}

void printFileInfo(FileInfo* files, int numFiles) {
    printf("File\tSize\n");
    for (int i = 0; i < numFiles; i++) {
        files[i].size = getDirSize(files[i].path);
        printf("%s\t%llu bytes\n", files[i].path, files[i].size);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        exit(1);
    }
    FileInfo files[MAX_PATH];
    int numFiles = 0;
    getFilesInDir(argv[1], files, &numFiles);
    printFileInfo(files, numFiles);
    return 0;
}