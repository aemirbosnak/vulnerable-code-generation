//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>
#include <sys/stat.h>

#define MAX_DEPTH 1000
#define MAX_PATH 4096

typedef struct {
    char path[MAX_PATH];
    unsigned long long size;
} file_t;

static void add_file(file_t *files, int num_files, const char *path, unsigned long long size) {
    if (num_files >= MAX_DEPTH) {
        printf("Error: Maximum depth exceeded.\n");
        return;
    }

    strncpy(files[num_files].path, path, MAX_PATH - 1);
    files[num_files].size = size;
    num_files++;
}

static void print_files(file_t *files, int num_files) {
    for (int i = 0; i < num_files; i++) {
        printf("%-40s %10llu\n", files[i].path, files[i].size);
    }
}

static unsigned long long get_directory_size(const char *path) {
    unsigned long long size = 0;
    DIR *dir = opendir(path);

    if (dir == NULL) {
        return size;
    }

    struct dirent *ent;
    while ((ent = readdir(dir))!= NULL) {
        char full_path[MAX_PATH];
        snprintf(full_path, MAX_PATH, "%s/%s", path, ent->d_name);

        struct stat stat_buf;
        if (stat(full_path, &stat_buf) == 0) {
            if (S_ISDIR(stat_buf.st_mode)) {
                size += get_directory_size(full_path);
            } else {
                size += stat_buf.st_size;
            }
        }
    }

    closedir(dir);
    return size;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [directory]\n", argv[0]);
        return 1;
    }

    char path[MAX_PATH];
    strncpy(path, argv[1], MAX_PATH - 1);

    unsigned long long total_size = get_directory_size(path);

    file_t files[MAX_DEPTH];
    int num_files = 0;

    add_file(files, num_files, path, total_size);

    print_files(files, num_files);

    return 0;
}