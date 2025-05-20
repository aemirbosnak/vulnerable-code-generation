//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define MAX_PATH 256
#define MAX_FILES 1000

typedef struct {
    char path[MAX_PATH];
    size_t size;
} File;

void add_file(File **files, int *count, const char *path, size_t size) {
    if (*count >= MAX_FILES) {
        return;
    }
    File *file = malloc(sizeof(File));
    strcpy(file->path, path);
    file->size = size;
    (*files)[*count] = *file;
    (*count)++;
}

void print_files(File *files, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s - %zu bytes\n", files[i].path, files[i].size);
    }
}

void analyze_directory(const char *path) {
    DIR *dir = opendir(path);
    if (!dir) {
        printf("Error opening directory: %s\n", path);
        return;
    }

    File files[MAX_FILES] = {0};
    int count = 0;

    struct dirent *ent;
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type!= DT_DIR) {
            char full_path[MAX_PATH];
            snprintf(full_path, MAX_PATH, "%s/%s", path, ent->d_name);

            struct statvfs statvfs_buf;
            if (statvfs(full_path, &statvfs_buf) == -1) {
                printf("Error getting file size: %s\n", full_path);
                continue;
            }

            add_file(&files, &count, full_path, statvfs_buf.f_bsize * statvfs_buf.f_blocks);
        }
    }

    closedir(dir);

    print_files(files, count);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    analyze_directory(argv[1]);

    return 0;
}