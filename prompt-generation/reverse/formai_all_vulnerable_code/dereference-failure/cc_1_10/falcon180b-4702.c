//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_DIRS 1000
#define MAX_FILES 10000

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    unsigned long long size;
    time_t modified_time;
    int is_dir;
} FileInfo;

typedef struct {
    char dir_path[MAX_FILE_NAME_LENGTH];
    int num_files;
    int num_dirs;
    unsigned long long total_size;
} DirInfo;

void read_dir(const char* path, DirInfo* dir_info) {
    DIR* dir = opendir(path);

    if (dir == NULL) {
        printf("Error: failed to open directory %s\n", path);
        return;
    }

    struct dirent* entry;

    while ((entry = readdir(dir))!= NULL) {
        if (entry->d_type == DT_DIR) {
            dir_info->num_dirs++;
        } else if (entry->d_type == DT_REG) {
            dir_info->num_files++;
            FileInfo file_info;
            strcpy(file_info.name, entry->d_name);
            struct stat stat_buf;
            stat(entry->d_name, &stat_buf);
            file_info.size = stat_buf.st_size;
            file_info.modified_time = stat_buf.st_mtime;
            file_info.is_dir = 0;
            dir_info->total_size += file_info.size;
        }
    }

    closedir(dir);
}

void print_dir_info(DirInfo* dir_info) {
    printf("Directory: %s\n", dir_info->dir_path);
    printf("Number of files: %d\n", dir_info->num_files);
    printf("Number of directories: %d\n", dir_info->num_dirs);
    printf("Total size: %llu bytes\n", dir_info->total_size);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return 1;
    }

    DirInfo dir_info;
    strcpy(dir_info.dir_path, argv[1]);

    read_dir(argv[1], &dir_info);
    print_dir_info(&dir_info);

    return 0;
}