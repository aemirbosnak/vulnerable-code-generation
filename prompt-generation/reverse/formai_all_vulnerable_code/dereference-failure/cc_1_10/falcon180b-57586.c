//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define MAX_PATH_LEN 1024

typedef struct {
    char path[MAX_PATH_LEN];
    size_t size;
} FileSize;

void get_files_in_dir(const char* path, void (*callback)(const char*, size_t)) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        printf("Error opening directory: %s\n", path);
        return;
    }

    struct dirent* ent;
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_DIR) {
            char subpath[MAX_PATH_LEN];
            snprintf(subpath, MAX_PATH_LEN, "%s/%s", path, ent->d_name);
            get_files_in_dir(subpath, callback);
        } else {
            FileSize file;
            snprintf(file.path, MAX_PATH_LEN, "%s/%s", path, ent->d_name);
            struct statvfs statvfs_buf;
            if (statvfs(file.path, &statvfs_buf) == 0) {
                file.size = statvfs_buf.f_blocks * statvfs_buf.f_frsize;
            } else {
                file.size = 0;
            }
            callback(file.path, file.size);
        }
    }

    closedir(dir);
}

void print_file_sizes(const char* path, size_t size) {
    printf("%s (%zu bytes)\n", path, size);
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    get_files_in_dir(argv[1], print_file_sizes);

    return 0;
}