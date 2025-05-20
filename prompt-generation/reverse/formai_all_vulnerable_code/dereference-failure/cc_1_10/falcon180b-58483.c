//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024

typedef struct {
    char name[MAX_PATH];
    size_t size;
} FileInfo;

void print_file_info(FileInfo* file_info) {
    printf("%s %zu bytes\n", file_info->name, file_info->size);
}

void get_file_info(const char* path, FileInfo* file_info) {
    struct stat stat_buf;
    stat(path, &stat_buf);
    file_info->size = stat_buf.st_size;
    strncpy(file_info->name, path, MAX_PATH);
    file_info->name[MAX_PATH - 1] = '\0';
}

void get_dir_info(const char* path, size_t* total_size, size_t* num_files) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        return;
    }

    struct dirent* dirent;
    while ((dirent = readdir(dir))!= NULL) {
        if (dirent->d_type == DT_REG) {
            FileInfo file_info;
            char* full_path = malloc(MAX_PATH);
            sprintf(full_path, "%s/%s", path, dirent->d_name);
            get_file_info(full_path, &file_info);
            print_file_info(&file_info);
            *total_size += file_info.size;
            (*num_files)++;
        }
    }

    closedir(dir);
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    char path[MAX_PATH];
    strcpy(path, argv[1]);

    size_t total_size = 0;
    size_t num_files = 0;

    get_dir_info(path, &total_size, &num_files);

    printf("Total size: %zu bytes\n", total_size);
    printf("Number of files: %zu\n", num_files);

    return 0;
}