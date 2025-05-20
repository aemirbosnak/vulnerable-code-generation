//FormAI DATASET v1.0 Category: File Synchronizer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <unistd.h>

bool is_directory(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}

bool sync_file(const char *src_path, const char *dest_path) {
    FILE *src_file = fopen(src_path, "r");
    if (!src_file) {
        printf("Error opening file: %s\n", src_path);
        return false;
    }

    FILE *dest_file = fopen(dest_path, "w");
    if (!dest_file) {
        printf("Error creating file: %s\n", dest_path);
        fclose(src_file);
        return false;
    }

    char buffer[BUFSIZ];
    size_t size_read;
    while ((size_read = fread(buffer, 1, BUFSIZ, src_file)) > 0){
        fwrite(buffer, 1, size_read, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);
    return true;
}

bool sync_directory(const char *src_path, const char *dest_path) {
    DIR *src_dir = opendir(src_path);
    if (!src_dir) {
        printf("Error opening directory: %s\n", src_path);
        return false;
    }

    DIR *dest_dir = opendir(dest_path);
    if (!dest_dir) {
        printf("Error opening directory: %s\n", dest_path);
        closedir(src_dir);
        return false;
    }

    struct dirent *entry;
    while ((entry = readdir(src_dir))) {
        const char *name = entry->d_name;
        if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0) continue;

        char src_file_path[PATH_MAX];
        snprintf(src_file_path, sizeof(src_file_path), "%s/%s", src_path, name);

        char dest_file_path[PATH_MAX];
        snprintf(dest_file_path, sizeof(dest_file_path), "%s/%s", dest_path, name);

        if (is_directory(src_file_path)) {
            if (!is_directory(dest_file_path)) {
                if (mkdir(dest_file_path, 0777) < 0) {
                    printf("Error creating directory: %s\n", dest_file_path);
                    closedir(src_dir);
                    closedir(dest_dir);
                    return false;
                }
            }

            if (!sync_directory(src_file_path, dest_file_path)) {
                closedir(src_dir);
                closedir(dest_dir);
                return false;
            }
        } else {
            if (!sync_file(src_file_path, dest_file_path)) {
                closedir(src_dir);
                closedir(dest_dir);
                return false;
            }
        }
    }

    closedir(src_dir);
    closedir(dest_dir);
    return true;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        exit(1);
    }

    if (!is_directory(argv[1])) {
        printf("Error: First argument must be a directory: %s\n", argv[1]);
        exit(1);
    }

    if (!is_directory(argv[2])) {
        printf("Error: Second argument must be a directory: %s\n", argv[2]);
        exit(1);
    }

    if (!sync_directory(argv[1], argv[2])) {
        exit(1);
    }

    printf("Directory synchronization successful.\n");
    exit(0);
}