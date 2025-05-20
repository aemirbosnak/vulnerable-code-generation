//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define BUF_SIZE 1024

typedef struct {
    char name[BUF_SIZE];
    long size;
} FileInfo;

void get_file_info(const char *path, FileInfo *file_info) {
    struct statvfs fs_info;
    if (statvfs(path, &fs_info) == 0) {
        file_info->size = fs_info.f_blocks * fs_info.f_frsize;
    }
}

void print_file_info(const FileInfo *file_info) {
    printf("%s: %ld bytes\n", file_info->name, file_info->size);
}

int compare_file_info(const void *a, const void *b) {
    const FileInfo *file_info_a = (const FileInfo *)a;
    const FileInfo *file_info_b = (const FileInfo *)b;

    return strcmp(file_info_a->name, file_info_b->name);
}

void print_directory_info(const char *path) {
    DIR *dir;
    struct dirent *ent;
    FileInfo *file_info;
    int count = 0;

    if ((dir = opendir(path))!= NULL) {
        file_info = (FileInfo *)malloc(sizeof(FileInfo) * BUF_SIZE);

        while ((ent = readdir(dir))!= NULL) {
            if (count >= BUF_SIZE) {
                printf("Directory is too large.\n");
                break;
            }

            strcpy(file_info[count].name, ent->d_name);
            get_file_info(ent->d_name, &file_info[count]);
            count++;
        }

        closedir(dir);
        qsort(file_info, count, sizeof(FileInfo), compare_file_info);

        for (int i = 0; i < count; i++) {
            print_file_info(&file_info[i]);
        }

        free(file_info);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    print_directory_info(argv[1]);

    return 0;
}