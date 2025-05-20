//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define BLOCK_SIZE 1024
#define MAX_PATH_LEN 1024

typedef struct dirent dirent;

typedef struct {
    int num_files;
    int num_directories;
    int total_size;
} DirectoryInfo;

void count_directory_size(const char* path, DirectoryInfo* info) {
    dirent* dir;
    DIR* d = opendir(path);

    if (d) {
        while ((dir = readdir(d))!= NULL) {
            if (dir->d_type == DT_REG) {
                info->num_files++;
            } else if (dir->d_type == DT_DIR) {
                info->num_directories++;
            }
        }
        closedir(d);
    }
}

void get_directory_size(const char* path, DirectoryInfo* info) {
    struct statvfs buf;
    if (statvfs(path, &buf) == 0) {
        info->total_size = buf.f_blocks * buf.f_frsize;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    DirectoryInfo info = {0};
    count_directory_size(argv[1], &info);
    get_directory_size(argv[1], &info);

    printf("Directory: %s\n", argv[1]);
    printf("Number of files: %d\n", info.num_files);
    printf("Number of directories: %d\n", info.num_directories);
    printf("Total size: %d bytes\n", info.total_size);

    return 0;
}