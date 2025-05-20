//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define MAX_PATH 256

typedef struct {
    char path[MAX_PATH];
    size_t size;
} FileInfo;

void get_files(const char* path, void (*process_file)(const char*, size_t)) {
    DIR* dir = opendir(path);
    if (!dir) {
        printf("Error: cannot open directory '%s'\n", path);
        return;
    }

    struct dirent* ent;
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_REG) {
            char file_path[MAX_PATH];
            snprintf(file_path, MAX_PATH, "%s/%s", path, ent->d_name);

            struct statvfs fs;
            if (statvfs(file_path, &fs) == 0) {
                size_t file_size = fs.f_blocks * fs.f_frsize;
                process_file(file_path, file_size);
            }
        }
    }

    closedir(dir);
}

void print_files(const char* path, size_t size) {
    printf("%s (%zu bytes)\n", path, size);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    char path[MAX_PATH];
    snprintf(path, MAX_PATH, "%s", argv[1]);

    get_files(path, print_files);

    return 0;
}