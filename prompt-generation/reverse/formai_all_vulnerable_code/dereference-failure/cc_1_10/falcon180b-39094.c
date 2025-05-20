//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/statvfs.h>

#define BUF_SIZE 1024

typedef struct {
    char name[BUF_SIZE];
    unsigned long long size;
} File;

void read_dir(const char* path, File* files, int* count) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        printf("Error: Could not open directory '%s'\n", path);
        exit(1);
    }

    struct dirent* entry;
    while ((entry = readdir(dir))!= NULL) {
        if (entry->d_type == DT_REG) {
            if (*count >= sizeof(files) / sizeof(File)) {
                printf("Warning: Reached maximum number of files\n");
                break;
            }

            strcpy(files[*count].name, entry->d_name);
            files[*count].size = entry->d_off;
            (*count)++;
        }
    }

    closedir(dir);
}

void sort_files(File* files, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (files[j].size > files[i].size) {
                File temp = files[i];
                files[i] = files[j];
                files[j] = temp;
            }
        }
    }
}

void print_files(File* files, int count) {
    printf("File\tSize\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%llu bytes\n", files[i].name, files[i].size);
    }
}

unsigned long long get_folder_size(const char* path) {
    unsigned long long size = 0;
    struct statvfs buf;

    if (statvfs(path, &buf) == -1) {
        printf("Error: Could not get folder size for '%s'\n", path);
        exit(1);
    }

    size = (unsigned long long)buf.f_blocks * (unsigned long long)buf.f_frsize;

    return size;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s [folder]\n", argv[0]);
        exit(1);
    }

    const char* path = argv[1];
    File files[1000];
    int count = 0;

    read_dir(path, files, &count);
    sort_files(files, count);
    print_files(files, count);

    return 0;
}