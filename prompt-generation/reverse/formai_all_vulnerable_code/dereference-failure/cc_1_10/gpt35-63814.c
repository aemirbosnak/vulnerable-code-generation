//FormAI DATASET v1.0 Category: File Synchronizer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define MAX_PATH 1024

int sync_files(char *src_path, char *dst_path);
int sync_directory(char *src_path, char *dst_path);

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s [source directory] [destination directory]\n", argv[0]);
        exit(1);
    }
    char *src_path = argv[1];
    char *dst_path = argv[2];
    sync_files(src_path, dst_path);
    return 0;
}

int sync_files(char *src_path, char *dst_path) {
    struct stat st = {0};
    if (stat(dst_path, &st) == -1) {
        // create the destination directory if it doesn't exist
        if (mkdir(dst_path, 0700) != 0) {
            printf("Failed to create directory: %s\n", dst_path);
            return errno;
        }
    }
    DIR *dir = opendir(src_path);
    if (!dir) {
        printf("Failed to open directory: %s\n", src_path);
        return errno;
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            // skip directories . and ..
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            char src_subdir[MAX_PATH];
            snprintf(src_subdir, MAX_PATH, "%s/%s", src_path, entry->d_name);
            char dst_subdir[MAX_PATH];
            snprintf(dst_subdir, MAX_PATH, "%s/%s", dst_path, entry->d_name);
            if (sync_directory(src_subdir, dst_subdir) != 0) {
                closedir(dir);
                return errno;
            }
        }
        else {
            // copy the file to the destination directory
            char src_file[MAX_PATH];
            snprintf(src_file, MAX_PATH, "%s/%s", src_path, entry->d_name);
            char dst_file[MAX_PATH];
            snprintf(dst_file, MAX_PATH, "%s/%s", dst_path, entry->d_name);
            if (access(dst_file, F_OK) == -1) {
                // file doesn't exist in the destination directory
                if (link(src_file, dst_file) != 0) {
                    printf("Failed to link file: %s -> %s\n", src_file, dst_file);
                    closedir(dir);
                    return errno;
                }
            }
            else {
                // file exists in the destination directory
                struct stat src_stat;
                stat(src_file, &src_stat);
                struct stat dst_stat;
                stat(dst_file, &dst_stat);
                if (src_stat.st_mtime > dst_stat.st_mtime) {
                    // source file is newer than the destination file
                    if (unlink(dst_file) != 0) {
                        printf("Failed to unlink file: %s\n", dst_file);
                        closedir(dir);
                        return errno;
                    }
                    if (link(src_file, dst_file) != 0) {
                        printf("Failed to link file: %s -> %s\n", src_file, dst_file);
                        closedir(dir);
                        return errno;
                    }
                }
            }
        }
    }
    closedir(dir);
    return 0;
}

int sync_directory(char *src_path, char *dst_path) {
    struct stat st = {0};
    if (stat(dst_path, &st) == -1) {
        // create the destination directory if it doesn't exist
        if (mkdir(dst_path, 0700) != 0) {
            printf("Failed to create directory: %s\n", dst_path);
            return errno;
        }
    }
    if (sync_files(src_path, dst_path) != 0) {
        return errno;
    }
    return 0;
}