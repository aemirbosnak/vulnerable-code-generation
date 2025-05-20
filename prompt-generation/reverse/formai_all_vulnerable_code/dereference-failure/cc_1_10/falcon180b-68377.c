//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_FILE_NAME_LEN 1024
#define MAX_DIR_PATH_LEN 2048

typedef struct {
    char file_name[MAX_FILE_NAME_LEN];
    unsigned long long file_size;
    unsigned long long dir_size;
} FileSizeInfo;

void get_file_info(const char* file_path, FileSizeInfo* file_info) {
    struct stat stat_buf;
    stat(file_path, &stat_buf);

    strncpy(file_info->file_name, file_path, MAX_FILE_NAME_LEN - 1);
    file_info->file_name[MAX_FILE_NAME_LEN - 1] = '\0';

    file_info->file_size = stat_buf.st_size;
}

void get_dir_info(const char* dir_path, FileSizeInfo* dir_info) {
    DIR* dir = opendir(dir_path);
    if (dir == NULL) {
        dir_info->dir_size = 0;
        return;
    }

    struct dirent* dirent;
    while ((dirent = readdir(dir))!= NULL) {
        if (strcmp(dirent->d_name, ".") == 0 || strcmp(dirent->d_name, "..") == 0) {
            continue;
        }

        char file_path[MAX_DIR_PATH_LEN];
        snprintf(file_path, MAX_DIR_PATH_LEN, "%s/%s", dir_path, dirent->d_name);

        FileSizeInfo file_info;
        get_file_info(file_path, &file_info);

        dir_info->dir_size += file_info.file_size;
    }

    closedir(dir);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    char dir_path[MAX_DIR_PATH_LEN];
    snprintf(dir_path, MAX_DIR_PATH_LEN, "%s", argv[1]);

    FileSizeInfo dir_info;
    get_dir_info(dir_path, &dir_info);

    printf("Directory: %s\n", dir_path);
    printf("Total size of all files: %llu bytes\n", dir_info.dir_size);

    return 0;
}