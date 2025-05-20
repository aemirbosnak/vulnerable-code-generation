//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>
#include <string.h>
#include <ctype.h>

#define MAX_DIR_NAME_LEN 1024
#define MAX_FILE_NAME_LEN 1024
#define MAX_FILE_SIZE_LEN 32

typedef struct {
    char dir_name[MAX_DIR_NAME_LEN];
    char file_name[MAX_FILE_NAME_LEN];
    long long file_size;
} FileInfo;

void read_directory(const char* path, int level) {
    DIR* dir = opendir(path);

    if (dir == NULL) {
        fprintf(stderr, "Error: failed to open directory '%s'\n", path);
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dir))!= NULL) {
        char full_path[MAX_DIR_NAME_LEN + MAX_FILE_NAME_LEN + 2];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        struct statvfs statvfs_buf;
        if (statvfs(full_path, &statvfs_buf) == 0) {
            long long total_size = statvfs_buf.f_blocks * statvfs_buf.f_frsize;
            long long free_size = statvfs_buf.f_bavail * statvfs_buf.f_frsize;

            printf("%*s %s (%lld bytes)\n", level * 2, "", full_path, total_size);
        } else {
            printf("%*s %s (error)\n", level * 2, "", full_path);
        }

        if (entry->d_type == DT_DIR) {
            read_directory(full_path, level + 1);
        }
    }

    closedir(dir);
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    char path[MAX_DIR_NAME_LEN + MAX_FILE_NAME_LEN + 2];
    snprintf(path, sizeof(path), "%s", argv[1]);

    read_directory(path, 0);

    return 0;
}