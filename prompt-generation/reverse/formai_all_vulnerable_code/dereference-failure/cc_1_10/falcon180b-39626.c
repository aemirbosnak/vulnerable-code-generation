//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_DEPTH 100

typedef struct {
    char path[1024];
    size_t size;
    struct dirent *dirent;
} FileInfo;

void print_file_info(FileInfo *file_info, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("%s (%zu bytes)\n", file_info->path, file_info->size);
}

void scan_directory(const char *path, int depth) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        exit(1);
    }

    struct dirent *dirent = NULL;
    while ((dirent = readdir(dir))!= NULL) {
        if (dirent->d_type == DT_DIR && depth < MAX_DEPTH) {
            char new_path[1024];
            snprintf(new_path, sizeof(new_path), "%s/%s", path, dirent->d_name);
            scan_directory(new_path, depth + 1);
        } else if (dirent->d_type == DT_REG) {
            FileInfo file_info = {0};
            snprintf(file_info.path, sizeof(file_info.path), "%s/%s", path, dirent->d_name);
            struct stat stat_buf;
            if (stat(file_info.path, &stat_buf) == 0) {
                file_info.size = stat_buf.st_size;
                print_file_info(&file_info, depth);
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    char path[1024];
    snprintf(path, sizeof(path), "%s", argv[1]);

    scan_directory(path, 0);

    return 0;
}