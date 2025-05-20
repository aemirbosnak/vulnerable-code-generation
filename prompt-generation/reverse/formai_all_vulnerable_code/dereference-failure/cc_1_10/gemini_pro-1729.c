//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH_LEN 256
#define MAX_FILES_PER_DIR 1024

struct file_info {
    char path[MAX_PATH_LEN];
    off_t size;
};

struct dir_info {
    char path[MAX_PATH_LEN];
    struct file_info files[MAX_FILES_PER_DIR];
    int num_files;
};

struct analyze_result {
    off_t total_size;
    off_t largest_file_size;
    char *largest_file_path;
};

struct analyze_result analyze_directory(const char *path) {
    struct analyze_result result = {0};
    DIR *dir = opendir(path);
    if (!dir) {
        perror("opendir");
        return result;
    }

    struct dirent *ent;
    while ((ent = readdir(dir))) {
        if (!strcmp(ent->d_name, ".") || !strcmp(ent->d_name, "..")) {
            continue;
        }

        char full_path[MAX_PATH_LEN];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, ent->d_name);

        struct stat st;
        if (lstat(full_path, &st) < 0) {
            perror("lstat");
            continue;
        }

        if (S_ISDIR(st.st_mode)) {
            struct analyze_result subdir_result = analyze_directory(full_path);
            result.total_size += subdir_result.total_size;
            if (subdir_result.largest_file_size > result.largest_file_size) {
                result.largest_file_size = subdir_result.largest_file_size;
                result.largest_file_path = subdir_result.largest_file_path;
            }
        } else {
            struct file_info file_info = {
                .path = full_path,
                .size = st.st_size,
            };
            result.total_size += file_info.size;
            if (file_info.size > result.largest_file_size) {
                result.largest_file_size = file_info.size;
                result.largest_file_path = file_info.path;
            }
        }
    }

    closedir(dir);
    return result;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct analyze_result result = analyze_directory(argv[1]);
    printf("Total size: %ld bytes\n", result.total_size);
    printf("Largest file: %s (%ld bytes)\n", result.largest_file_path, result.largest_file_size);
    return EXIT_SUCCESS;
}