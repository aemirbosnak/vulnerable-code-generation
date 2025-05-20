//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>
#include <string.h>

typedef struct {
    char path[1024];
    unsigned long long size;
} FileInfo;

void get_file_info(const char* path, FileInfo* file_info) {
    struct statvfs buf;
    if (statvfs(path, &buf) == 0) {
        file_info->size = buf.f_blocks * buf.f_frsize;
        strcpy(file_info->path, path);
    }
}

int compare_file_info(const void* a, const void* b) {
    const FileInfo* file_info_a = (const FileInfo*)a;
    const FileInfo* file_info_b = (const FileInfo*)b;

    return (int)(file_info_a->size - file_info_b->size);
}

void print_file_info(const FileInfo* file_info) {
    printf("%-40s %10llu\n", file_info->path, file_info->size);
}

int main() {
    DIR* dir;
    struct dirent* ent;
    FileInfo* file_info = NULL;
    unsigned int num_files = 0;

    if ((dir = opendir("."))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR) {
                char path[1024];
                sprintf(path, "%s/%s", ".", ent->d_name);
                get_file_info(path, file_info);
                num_files++;
            }
        }
        closedir(dir);
    }

    qsort(file_info, num_files, sizeof(FileInfo), compare_file_info);

    for (unsigned int i = 0; i < num_files; i++) {
        print_file_info(&file_info[i]);
    }

    return 0;
}