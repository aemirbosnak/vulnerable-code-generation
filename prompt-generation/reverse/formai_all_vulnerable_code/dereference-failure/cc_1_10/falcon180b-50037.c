//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUF_SIZE 1024

typedef struct {
    char name[BUF_SIZE];
    off_t size;
    int is_dir;
} FileInfo;

void get_dir_info(const char* path, FileInfo* dir_info) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        printf("Failed to open directory %s\n", path);
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dir))!= NULL) {
        char fullpath[BUF_SIZE];
        snprintf(fullpath, BUF_SIZE, "%s/%s", path, entry->d_name);

        struct stat statbuf;
        if (stat(fullpath, &statbuf) == 0) {
            FileInfo file_info;
            strncpy(file_info.name, entry->d_name, BUF_SIZE - 1);
            file_info.name[BUF_SIZE - 1] = '\0';
            file_info.size = statbuf.st_size;
            file_info.is_dir = S_ISDIR(statbuf.st_mode);

            if (file_info.is_dir) {
                get_dir_info(fullpath, &file_info);
            }

            dir_info->size += file_info.size;
        }
    }

    closedir(dir);
}

void print_dir_info(FileInfo* dir_info) {
    printf("Directory: %s\n", dir_info->name);
    printf("Total size: %ld bytes\n", dir_info->size);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return 1;
    }

    char path[BUF_SIZE];
    snprintf(path, BUF_SIZE, "%s", argv[1]);

    FileInfo dir_info;
    get_dir_info(path, &dir_info);
    print_dir_info(&dir_info);

    return 0;
}