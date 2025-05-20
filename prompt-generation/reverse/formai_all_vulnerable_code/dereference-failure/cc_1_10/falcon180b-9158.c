//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024

typedef struct {
    char path[MAX_PATH];
    long long size;
} FileInfo;

void addFile(char* path, long long size, FileInfo* files, int* count) {
    if (*count >= MAX_PATH) {
        printf("Error: Too many files.\n");
        exit(1);
    }

    strcpy(files[*count].path, path);
    files[*count].size = size;
    (*count)++;
}

int compareSize(const void* a, const void* b) {
    FileInfo* fileA = (FileInfo*)a;
    FileInfo* fileB = (FileInfo*)b;

    if (fileA->size > fileB->size) {
        return -1;
    } else if (fileA->size < fileB->size) {
        return 1;
    } else {
        return 0;
    }
}

void printFiles(FileInfo* files, int count) {
    qsort(files, count, sizeof(FileInfo), compareSize);

    for (int i = 0; i < count; i++) {
        printf("%s (%lld bytes)\n", files[i].path, files[i].size);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s [directory]\n", argv[0]);
        return 1;
    }

    DIR* dir = opendir(argv[1]);
    if (dir == NULL) {
        printf("Error: Could not open directory.\n");
        return 1;
    }

    FileInfo files[MAX_PATH];
    int count = 0;

    struct dirent* ent;
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_REG || ent->d_type == DT_LNK) {
            char path[MAX_PATH];
            snprintf(path, MAX_PATH, "%s/%s", argv[1], ent->d_name);

            struct stat st;
            if (stat(path, &st) == 0) {
                addFile(path, st.st_size, files, &count);
            }
        }
    }

    closedir(dir);

    if (count == 0) {
        printf("Directory is empty.\n");
    } else {
        printFiles(files, count);
    }

    return 0;
}