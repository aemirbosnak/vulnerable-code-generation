//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define MAX_PATH 1024

typedef struct {
    char path[MAX_PATH];
    unsigned long long size;
} Directory;

typedef struct {
    Directory *directories;
    unsigned int count;
    unsigned long long total_size;
} DiskSpaceAnalyzer;

void addDirectory(DiskSpaceAnalyzer *analyzer, const char *path) {
    Directory *directory = (Directory *)malloc(sizeof(Directory));
    strncpy(directory->path, path, MAX_PATH - 1);
    directory->size = 0;
    analyzer->directories = (Directory *)realloc(analyzer->directories, (analyzer->count + 1) * sizeof(Directory));
    analyzer->directories[analyzer->count] = *directory;
    analyzer->count++;
}

void analyzeDirectory(DiskSpaceAnalyzer *analyzer, const char *path) {
    DIR *d;
    struct dirent *dir;
    d = opendir(path);

    if (d) {
        while ((dir = readdir(d))!= NULL) {
            char childPath[MAX_PATH];
            snprintf(childPath, MAX_PATH, "%s/%s", path, dir->d_name);

            struct statvfs sv;
            if (statvfs(childPath, &sv) == 0) {
                unsigned long long size = sv.f_blocks * sv.f_frsize;
                addDirectory(analyzer, childPath);
                analyzer->total_size += size;
            }
        }
        closedir(d);
    }
}

void printDirectories(DiskSpaceAnalyzer *analyzer) {
    printf("Directory\tSize\n");
    for (unsigned int i = 0; i < analyzer->count; i++) {
        printf("%s\t%llu\n", analyzer->directories[i].path, analyzer->directories[i].size);
    }
}

void printTotalSize(DiskSpaceAnalyzer *analyzer) {
    printf("\nTotal size: %llu\n", analyzer->total_size);
}

int main(int argc, char **argv) {
    DiskSpaceAnalyzer analyzer = {0};

    if (argc < 2) {
        printf("Usage: %s [path]\n", argv[0]);
        return 1;
    }

    addDirectory(&analyzer, argv[1]);
    analyzeDirectory(&analyzer, argv[1]);

    printDirectories(&analyzer);
    printTotalSize(&analyzer);

    return 0;
}