//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define MAX_PATH 1024

typedef struct {
    char path[MAX_PATH];
    unsigned long long size;
} FileInfo;

void get_file_info(const char* path, FileInfo* file_info) {
    struct statvfs buf;
    if (statvfs(path, &buf) == 0) {
        file_info->size = buf.f_blocks * buf.f_frsize;
    } else {
        file_info->size = 0;
    }
    strncpy(file_info->path, path, MAX_PATH - 1);
}

int compare_file_info(const void* a, const void* b) {
    const FileInfo* file_info_a = (const FileInfo*)a;
    const FileInfo* file_info_b = (const FileInfo*)b;
    return (int)(file_info_b->size - file_info_a->size);
}

void print_file_info(const FileInfo* file_info) {
    printf("%-40s %10llu\n", file_info->path, file_info->size);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    DIR* dir = opendir(argv[1]);
    if (dir == NULL) {
        printf("Error: Could not open directory '%s'.\n", argv[1]);
        return 1;
    }

    FileInfo files[1000];
    int num_files = 0;

    struct dirent* ent;
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_DIR) {
            char path[MAX_PATH];
            snprintf(path, MAX_PATH, "%s/%s", argv[1], ent->d_name);
            get_file_info(path, &files[num_files]);
            num_files++;
        }
    }

    closedir(dir);

    qsort(files, num_files, sizeof(FileInfo), compare_file_info);

    for (int i = 0; i < num_files; i++) {
        print_file_info(&files[i]);
    }

    return 0;
}