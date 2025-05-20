//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>
#include <string.h>
#include <math.h>

#define MAX_FILE_NAME_LENGTH 1024
#define MAX_DIR_NAME_LENGTH 1024

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    size_t size;
} File;

typedef struct {
    char name[MAX_DIR_NAME_LENGTH];
    size_t total_size;
    size_t num_files;
    File *files;
} Directory;

void add_file(Directory *dir, const char *name, size_t size) {
    File *file = realloc(dir->files, sizeof(File) * (dir->num_files + 1));
    if (file == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }
    dir->files = file;
    strcpy(file[dir->num_files].name, name);
    file[dir->num_files].size = size;
    dir->num_files++;
    dir->total_size += size;
}

void print_directory(const Directory *dir) {
    printf("Directory: %s\n", dir->name);
    printf("Total size: %zu bytes\n", dir->total_size);
    printf("Number of files: %zu\n", dir->num_files);
    for (size_t i = 0; i < dir->num_files; i++) {
        printf("%s: %zu bytes\n", dir->files[i].name, dir->files[i].size);
    }
}

void analyze_directory(const char *path) {
    DIR *d = opendir(path);
    if (d == NULL) {
        fprintf(stderr, "Failed to open directory: %s\n", path);
        exit(1);
    }
    Directory dir = {0};
    strcpy(dir.name, path);
    struct dirent *ent;
    while ((ent = readdir(d))!= NULL) {
        if (ent->d_type == DT_REG) {
            char file_path[MAX_DIR_NAME_LENGTH + MAX_FILE_NAME_LENGTH + 2];
            snprintf(file_path, sizeof(file_path), "%s/%s", path, ent->d_name);
            struct statvfs fs;
            if (statvfs(file_path, &fs)!= 0) {
                fprintf(stderr, "Failed to get file system information for file: %s\n", file_path);
                exit(1);
            }
            size_t file_size = fs.f_frsize * fs.f_blocks;
            add_file(&dir, ent->d_name, file_size);
        } else if (ent->d_type == DT_DIR) {
            char subdir_path[MAX_DIR_NAME_LENGTH + MAX_FILE_NAME_LENGTH + 2];
            snprintf(subdir_path, sizeof(subdir_path), "%s/%s", path, ent->d_name);
            analyze_directory(subdir_path);
        }
    }
    closedir(d);
    print_directory(&dir);
    free(dir.files);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s directory\n", argv[0]);
        return 1;
    }
    analyze_directory(argv[1]);
    return 0;
}