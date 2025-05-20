//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_PATH 1024

typedef struct {
    char path[MAX_PATH];
    unsigned long long size;
} FileInfo;

void get_file_info(const char* path, FileInfo* file_info) {
    struct stat stat_buf;
    stat(path, &stat_buf);
    file_info->size = stat_buf.st_size;
    strcpy(file_info->path, path);
}

int compare_file_info(const void* a, const void* b) {
    const FileInfo* file_info_a = (const FileInfo*)a;
    const FileInfo* file_info_b = (const FileInfo*)b;
    return (int)(file_info_a->size - file_info_b->size);
}

void print_file_info(const FileInfo* file_info) {
    printf("%s (%llu bytes)\n", file_info->path, file_info->size);
}

void analyze_disk_space(const char* path) {
    DIR* dir;
    struct dirent* dirent;
    FileInfo* file_info_array = NULL;
    unsigned int file_count = 0;

    dir = opendir(path);
    if (dir == NULL) {
        fprintf(stderr, "Error opening directory: %s\n", path);
        exit(1);
    }

    while ((dirent = readdir(dir))!= NULL) {
        if (dirent->d_type == DT_REG) {
            FileInfo* file_info = realloc(file_info_array, sizeof(FileInfo) * ++file_count);
            get_file_info(dirent->d_name, file_info);
        }
    }

    closedir(dir);

    qsort(file_info_array, file_count, sizeof(FileInfo), compare_file_info);

    for (unsigned int i = 0; i < file_count; ++i) {
        print_file_info(&file_info_array[i]);
    }

    free(file_info_array);
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        exit(1);
    }

    analyze_disk_space(argv[1]);

    return 0;
}