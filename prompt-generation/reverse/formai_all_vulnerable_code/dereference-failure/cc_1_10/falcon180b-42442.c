//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>
#include <string.h>

#define S_ISDIR(m) (((m) & S_IFMT) == S_IFDIR)

typedef struct {
    char path[1024];
    size_t size;
} FileInfo;

void get_files(const char *path, void (*callback)(const FileInfo *)) {
    DIR *dir = opendir(path);
    if (!dir) {
        perror("opendir");
        return;
    }

    struct dirent *ent;
    while ((ent = readdir(dir))!= NULL) {
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
            continue;
        }

        char file_path[1024];
        snprintf(file_path, sizeof(file_path), "%s/%s", path, ent->d_name);

        struct statvfs statvfs_buf;
        if (statvfs(file_path, &statvfs_buf) == -1) {
            perror("statvfs");
            continue;
        }

        FileInfo file_info = { 0 };
        strncpy(file_info.path, file_path, sizeof(file_info.path));
        file_info.size = statvfs_buf.f_bsize * statvfs_buf.f_blocks;

        callback(&file_info);
    }

    closedir(dir);
}

void print_file_info(const FileInfo *file_info) {
    printf("%-40s %10zu bytes\n", file_info->path, file_info->size);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    get_files(argv[1], print_file_info);

    return 0;
}