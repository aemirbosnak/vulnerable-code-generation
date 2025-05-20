//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/statvfs.h>
#include <sys/stat.h>

#define MAX_DIR_LEN 1024
#define MAX_FILE_LEN 256
#define MB (1024*1024)

typedef struct {
    char name[MAX_FILE_LEN];
    off_t size;
} FileInfo;

typedef struct {
    char name[MAX_DIR_LEN];
    size_t total_size;
    size_t num_files;
} DirInfo;

void get_dir_info(const char *path, DirInfo *info) {
    info->total_size = 0;
    info->num_files = 0;
    DIR *dir = opendir(path);
    if (dir == NULL) {
        return;
    }
    struct dirent *ent;
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_DIR) {
            char subpath[MAX_DIR_LEN];
            strcpy(subpath, path);
            strcat(subpath, "/");
            strcat(subpath, ent->d_name);
            get_dir_info(subpath, info);
        } else {
            FileInfo file_info;
            strcpy(file_info.name, ent->d_name);
            file_info.size = ent->d_reclen;
            info->total_size += file_info.size;
            info->num_files++;
        }
    }
    closedir(dir);
}

void print_dir_info(const DirInfo *info, int indent) {
    for (int i = 0; i < indent; i++) {
        printf("  ");
    }
    printf("%s (%zu bytes)\n", info->name, info->total_size);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }
    char path[MAX_DIR_LEN];
    strcpy(path, argv[1]);
    DirInfo info;
    get_dir_info(path, &info);
    print_dir_info(&info, 0);
    return 0;
}