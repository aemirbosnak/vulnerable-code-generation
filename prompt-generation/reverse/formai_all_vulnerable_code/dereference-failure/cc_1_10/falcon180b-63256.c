//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define MAX_FILE_NAME 100
#define MAX_PATH 1024

typedef struct {
    char name[MAX_FILE_NAME];
    long size;
} FileInfo;

void get_files(const char* path, FileInfo* files, int count) {
    DIR *dir = opendir(path);
    struct dirent *ent;

    int i = 0;
    while ((ent = readdir(dir))!= NULL && i < count) {
        if (ent->d_type == DT_REG) {
            strncpy(files[i].name, ent->d_name, MAX_FILE_NAME - 1);
            files[i].size = ent->d_reclen;
            i++;
        }
    }

    closedir(dir);
}

void print_files(FileInfo* files, int count) {
    printf("File name\tFile size\n");
    for (int i = 0; i < count; i++) {
        printf("%-40s %10ld\n", files[i].name, files[i].size);
    }
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    char path[MAX_PATH];
    strcpy(path, argv[1]);
    strcat(path, "/");

    FileInfo files[100];
    int count = 0;

    get_files(path, files, 100);
    print_files(files, count);

    return 0;
}