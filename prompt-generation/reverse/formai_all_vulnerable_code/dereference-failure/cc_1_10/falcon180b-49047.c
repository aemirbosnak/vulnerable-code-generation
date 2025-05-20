//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_SIZE 1024
#define MAX_PATH_SIZE 4096

typedef struct {
    char *path;
    size_t size;
} FileInfo;

typedef struct {
    char *path;
    size_t total_size;
    size_t num_files;
    FileInfo *files;
} DirectoryInfo;

static void print_file_info(FileInfo *file_info) {
    printf("Path: %s\n", file_info->path);
    printf("Size: %zu bytes\n", file_info->size);
    printf("\n");
}

static void print_directory_info(DirectoryInfo *dir_info) {
    printf("Total size: %zu bytes\n", dir_info->total_size);
    printf("Number of files: %zu\n", dir_info->num_files);
    printf("\n");

    for (size_t i = 0; i < dir_info->num_files; i++) {
        print_file_info(&dir_info->files[i]);
    }
}

static void add_file_info(DirectoryInfo *dir_info, const char *path, size_t size) {
    if (dir_info->num_files >= MAX_FILE_SIZE) {
        printf("Error: Too many files in directory.\n");
        return;
    }

    FileInfo *file_info = &dir_info->files[dir_info->num_files];
    file_info->path = strdup(path);
    file_info->size = size;

    dir_info->num_files++;
    dir_info->total_size += size;
}

static void analyze_directory(const char *path, DirectoryInfo *dir_info) {
    DIR *dir = opendir(path);

    if (dir == NULL) {
        printf("Error: Could not open directory.\n");
        return;
    }

    struct dirent *dent;
    while ((dent = readdir(dir))!= NULL) {
        if (dent->d_type!= DT_REG) {
            continue;
        }

        char file_path[MAX_PATH_SIZE];
        snprintf(file_path, MAX_PATH_SIZE, "%s/%s", path, dent->d_name);

        struct statvfs fs_info;
        if (statvfs(file_path, &fs_info)!= 0) {
            printf("Error: Could not get file system info for file.\n");
            continue;
        }

        add_file_info(dir_info, file_path, fs_info.f_bsize * fs_info.f_blocks);
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    DirectoryInfo dir_info = {0};
    analyze_directory(argv[1], &dir_info);
    print_directory_info(&dir_info);

    return 0;
}