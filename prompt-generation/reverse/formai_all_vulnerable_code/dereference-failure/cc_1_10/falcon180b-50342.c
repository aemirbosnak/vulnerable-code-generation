//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/statvfs.h>

#define MAX_PATH 1024

typedef struct {
    char path[MAX_PATH];
    struct statvfs stat;
    unsigned long long total_size;
    unsigned long long used_size;
    unsigned long long free_size;
} disk_info_t;

void get_disk_info(char *path, disk_info_t *info) {
    struct statvfs st;
    if (statvfs(path, &st) == -1) {
        printf("Error getting disk info for %s\n", path);
        exit(1);
    }

    info->stat = st;

    info->total_size = st.f_blocks * st.f_frsize;
    info->used_size = (st.f_blocks - st.f_bfree) * st.f_frsize;
    info->free_size = st.f_bfree * st.f_frsize;
}

void print_disk_info(disk_info_t *info) {
    printf("Path: %s\n", info->path);
    printf("Total size: %llu bytes\n", info->total_size);
    printf("Used size: %llu bytes\n", info->used_size);
    printf("Free size: %llu bytes\n", info->free_size);
    printf("\n");
}

void scan_directory(char *path, void (*callback)(disk_info_t *)) {
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir(path))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            char full_path[MAX_PATH];
            sprintf(full_path, "%s/%s", path, ent->d_name);

            if (ent->d_type == DT_DIR) {
                if (strcmp(ent->d_name, ".")!= 0 && strcmp(ent->d_name, "..")!= 0) {
                    scan_directory(full_path, callback);
                }
            } else {
                disk_info_t info;
                get_disk_info(full_path, &info);
                callback(&info);
            }
        }
        closedir(dir);
    }
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    scan_directory(argv[1], print_disk_info);

    return 0;
}