//FormAI DATASET v1.0 Category: File Synchronizer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void copy_file(const char* src, const char* dst) {
    FILE* src_ptr = fopen(src, "rb");
    FILE* dst_ptr = fopen(dst, "wb");
    if (src_ptr == NULL || dst_ptr == NULL) {
        printf("Error: Unable to open file\n");
        return;
    }
    char buffer[BUFSIZ];
    size_t size_read;
    while ((size_read = fread(buffer, 1, BUFSIZ, src_ptr)) > 0) {
        fwrite(buffer, 1, size_read, dst_ptr);
    }
    fclose(src_ptr);
    fclose(dst_ptr);
}

void copy_dir(const char* src, const char* dst) {
    int path_len = strlen(dst) + strlen(src) + 2;
    char* new_dir = (char*)malloc(sizeof(char) * path_len);
    snprintf(new_dir, path_len, "%s/%s", dst, basename(src));
    mkdir(new_dir, 0700);
    DIR* dir = opendir(src);
    struct dirent* entry;

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        int new_path_len = strlen(new_dir) + strlen(entry->d_name) + 2;
        char* new_path = (char*)malloc(sizeof(char) * new_path_len);
        snprintf(new_path, new_path_len, "%s/%s", new_dir, entry->d_name);
        if (entry->d_type == DT_DIR) {
            copy_dir(entry->d_name, new_dir);
        } else {
            copy_file(entry->d_name, new_dir);
        }
        free(new_path);
    }
    closedir(dir);
    free(new_dir);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Error: Incorrect number of arguments\n");
        printf("Please enter the source and destination directory paths\n");
        return 1;
    }

    struct stat src_stat, dst_stat;
    if (stat(argv[1], &src_stat) == -1) {
        printf("Error: Unable to stat source directory\n");
        return 1;
    }

    if (stat(argv[2], &dst_stat) == -1) {
        printf("Error: Unable to stat destination directory\n");
        return 1;
    }

    if (!S_ISDIR(src_stat.st_mode)) {
        printf("Error: Source is not a directory\n");
        return 1;
    }

    if (!S_ISDIR(dst_stat.st_mode)) {
        printf("Error: Destination is not a directory\n");
        return 1;
    }

    copy_dir(argv[1], argv[2]);
    return 0;
}