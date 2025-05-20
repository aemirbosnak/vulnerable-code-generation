//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define MAX_FILES 1000000

typedef struct {
    char* name;
    int size;
} File;

void read_directory(char* path, File files[MAX_FILES]) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        printf("Error: Unable to open directory '%s'\n", path);
        return;
    }

    struct dirent* entry;
    int count = 0;
    while ((entry = readdir(dir))!= NULL) {
        if (count >= MAX_FILES) {
            printf("Error: Too many files in directory '%s'\n", path);
            closedir(dir);
            return;
        }

        File file;
        strcpy(file.name, entry->d_name);
        file.size = 0;
        files[count++] = file;
    }

    closedir(dir);
}

void get_file_size(char* path, File* file) {
    struct statvfs stat;
    if (statvfs(path, &stat)!= 0) {
        printf("Error: Unable to get file size for '%s'\n", path);
        return;
    }

    file->size = stat.f_blocks * stat.f_bsize;
}

void print_files(File files[MAX_FILES], int count) {
    printf("Files:\n");
    for (int i = 0; i < count; i++) {
        printf("%s - %d bytes\n", files[i].name, files[i].size);
    }
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        printf("Usage: %s directory\n", argv[0]);
        return 1;
    }

    char path[1024];
    strcpy(path, argv[1]);
    if (path[strlen(path) - 1]!= '/') {
        strcat(path, "/");
    }

    File files[MAX_FILES];
    int count = 0;
    read_directory(path, files);

    for (int i = 0; i < count; i++) {
        get_file_size(files[i].name, &files[i]);
    }

    print_files(files, count);

    return 0;
}