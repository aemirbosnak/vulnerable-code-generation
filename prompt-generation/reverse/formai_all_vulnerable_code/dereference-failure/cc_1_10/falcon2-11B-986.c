//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void copy_file(const char* src_file, const char* dest_file) {
    FILE* src_fp = fopen(src_file, "rb");
    FILE* dest_fp = fopen(dest_file, "wb");
    if (src_fp == NULL || dest_fp == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }
    fseek(src_fp, 0, SEEK_END);
    long src_size = ftell(src_fp);
    fseek(src_fp, 0, SEEK_SET);
    char* buffer = malloc(src_size);
    if (buffer == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    size_t bytes_read = fread(buffer, 1, src_size, src_fp);
    if (bytes_read!= src_size) {
        perror("Failed to read file");
        exit(EXIT_FAILURE);
    }
    fclose(src_fp);
    fclose(dest_fp);
    int bytes_written = fwrite(buffer, 1, src_size, dest_fp);
    if (bytes_written!= src_size) {
        perror("Failed to write file");
        exit(EXIT_FAILURE);
    }
    fclose(dest_fp);
    free(buffer);
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <source_dir> <destination_dir>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    const char* src_dir = argv[1];
    const char* dest_dir = argv[2];
    DIR* src_dir_fp = opendir(src_dir);
    if (src_dir_fp == NULL) {
        perror("Failed to open source directory");
        exit(EXIT_FAILURE);
    }
    DIR* dest_dir_fp = opendir(dest_dir);
    if (dest_dir_fp == NULL) {
        perror("Failed to open destination directory");
        exit(EXIT_FAILURE);
    }
    struct dirent* src_entry;
    struct stat src_stat;
    while ((src_entry = readdir(src_dir_fp))!= NULL) {
        if (strcmp(src_entry->d_name, ".")!= 0 && strcmp(src_entry->d_name, "..")!= 0) {
            char src_file[1024];
            sprintf(src_file, "%s/%s", src_dir, src_entry->d_name);
            if (stat(src_file, &src_stat) == -1) {
                perror("Failed to stat source file");
                exit(EXIT_FAILURE);
            }
            char dest_file[1024];
            sprintf(dest_file, "%s/%s", dest_dir, src_entry->d_name);
            copy_file(src_file, dest_file);
        }
    }
    closedir(src_dir_fp);
    closedir(dest_dir_fp);
    return 0;
}