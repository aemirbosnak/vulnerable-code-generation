//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: peaceful
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/statvfs.h>

#define MAX_FILE_NAME_LENGTH 1024
#define MAX_FILES 1000

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    unsigned long long size;
} File;

unsigned long long get_directory_size(const char* path) {
    unsigned long long size = 0;
    DIR* dir = opendir(path);
    struct dirent* ent;

    if (dir!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_REG) {
                File file;
                strncpy(file.name, ent->d_name, MAX_FILE_NAME_LENGTH);
                file.size = ent->d_reclen;
                size += file.size;
            }
        }
        closedir(dir);
    }

    return size;
}

unsigned long long get_file_size(const char* path) {
    struct statvfs buf;
    statvfs(path, &buf);
    return buf.f_blocks * buf.f_frsize;
}

int compare_files(const void* a, const void* b) {
    const File* file1 = (const File*)a;
    const File* file2 = (const File*)b;

    return strcmp(file1->name, file2->name);
}

void print_files(File* files, int count) {
    qsort(files, count, sizeof(File), compare_files);

    for (int i = 0; i < count; i++) {
        printf("%s %llu bytes\n", files[i].name, files[i].size);
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    char path[MAX_FILE_NAME_LENGTH];
    strcpy(path, argv[1]);
    unsigned long long directory_size = get_directory_size(path);
    unsigned long long file_size = get_file_size(path);

    File files[MAX_FILES];
    int count = 0;
    DIR* dir = opendir(path);
    struct dirent* ent;

    if (dir!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_REG) {
                File file;
                strncpy(file.name, ent->d_name, MAX_FILE_NAME_LENGTH);
                file.size = ent->d_reclen;
                files[count++] = file;
            }
        }
        closedir(dir);
    }

    print_files(files, count);

    printf("Total directory size: %llu bytes\n", directory_size);
    printf("Total file size: %llu bytes\n", file_size);

    return 0;
}