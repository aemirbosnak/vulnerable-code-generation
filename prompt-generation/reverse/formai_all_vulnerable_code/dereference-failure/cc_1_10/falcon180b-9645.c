//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define MAX_DIR_LEN 1024
#define MAX_FILE_LEN 1024

typedef struct {
    char dir[MAX_DIR_LEN];
    char file[MAX_FILE_LEN];
    size_t size;
} file_t;

void print_file_info(file_t* file) {
    printf("%s/%s (%zu bytes)\n", file->dir, file->file, file->size);
}

void print_dir_info(const char* dir_path) {
    DIR* dir = opendir(dir_path);
    if (dir == NULL) {
        printf("Error: Could not open directory '%s'\n", dir_path);
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dir))!= NULL) {
        if (entry->d_type == DT_DIR) {
            char subdir_path[MAX_DIR_LEN];
            sprintf(subdir_path, "%s/%s", dir_path, entry->d_name);
            print_dir_info(subdir_path);
        } else {
            char file_path[MAX_DIR_LEN];
            sprintf(file_path, "%s/%s", dir_path, entry->d_name);
            struct statvfs fs_info;
            statvfs(file_path, &fs_info);

            file_t file = {
               .dir = dir_path,
               .file = entry->d_name,
               .size = fs_info.f_frsize * fs_info.f_blocks
            };
            print_file_info(&file);
        }
    }

    closedir(dir);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Error: Please provide a directory path as an argument.\n");
        return 1;
    }

    char dir_path[MAX_DIR_LEN];
    strcpy(dir_path, argv[1]);

    print_dir_info(dir_path);

    return 0;
}