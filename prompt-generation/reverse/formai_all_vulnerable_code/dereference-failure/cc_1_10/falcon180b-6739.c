//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_FILE_NAME_LENGTH 1024

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    unsigned long long file_size;
} FileInfo;

void print_file_info(FileInfo *file_info) {
    printf("File name: %s\n", file_info->file_name);
    printf("File size: %llu bytes\n\n", file_info->file_size);
}

long long get_directory_size(const char *path) {
    long long size = 0;
    DIR *dir = opendir(path);

    if (dir!= NULL) {
        struct dirent *ent;
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_REG) {
                char file_path[MAX_FILE_NAME_LENGTH];
                sprintf(file_path, "%s/%s", path, ent->d_name);
                struct stat file_stat;
                stat(file_path, &file_stat);
                size += file_stat.st_size;
            }
        }
        closedir(dir);
    }

    return size;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return 1;
    }

    char directory_path[MAX_FILE_NAME_LENGTH];
    strcpy(directory_path, argv[1]);

    long long directory_size = get_directory_size(directory_path);

    printf("Directory size: %llu bytes\n", directory_size);

    return 0;
}