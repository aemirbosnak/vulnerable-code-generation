//FormAI DATASET v1.0 Category: File Synchronizer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void copy_file(char* src_path, char* dest_path) {
    char buf[1024];
    int src_file, dest_file;
    ssize_t read_size, write_size;
    src_file = open(src_path, O_RDONLY);
    dest_file = open(dest_path, O_WRONLY|O_CREAT|O_TRUNC, 0644);
    while((read_size = read(src_file, buf, sizeof buf)) > 0) {
        write_size = write(dest_file, buf, read_size);
        if(write_size != read_size) {
            printf("Failed to copy file %s to %s\n", src_path, dest_path);
            exit(1);
        }
    }
    close(src_file);
    close(dest_file);
    printf("Copied %s to %s\n", src_path, dest_path);
}

void sync_files(char* src_dir, char* dest_dir) {
    DIR* src_dp, * dest_dp;
    struct dirent *entry;
    struct stat src_stat, dest_stat;
    char src_path[PATH_MAX], dest_path[PATH_MAX];
    src_dp = opendir(src_dir);
    if(!src_dp) {
        printf("Failed to open %s\n", src_dir);
        exit(1);
    }
    while((entry = readdir(src_dp)) != NULL) {
        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        sprintf(src_path, "%s/%s", src_dir, entry->d_name);
        sprintf(dest_path, "%s/%s", dest_dir, entry->d_name);
        stat(src_path, &src_stat);
        if(S_ISDIR(src_stat.st_mode)) {
            mkdir(dest_path, src_stat.st_mode);
            sync_files(src_path, dest_path);
        }
        else {
            if(stat(dest_path, &dest_stat) == -1 || src_stat.st_mtime > dest_stat.st_mtime) {
                copy_file(src_path, dest_path);
            }
        }
    }
    closedir(src_dp);
    dest_dp = opendir(dest_dir);
    if(!dest_dp) {
        printf("Failed to open %s\n", dest_dir);
        exit(1);
    }
    while((entry = readdir(dest_dp)) != NULL) {
        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        sprintf(src_path, "%s/%s", src_dir, entry->d_name);
        sprintf(dest_path, "%s/%s", dest_dir, entry->d_name);
        stat(dest_path, &dest_stat);
        if(S_ISDIR(dest_stat.st_mode)) {
            rmdir(dest_path);
        }
    }
    closedir(dest_dp);
    printf("Synchronized %s with %s\n", src_dir, dest_dir);
}

int main() {
    sync_files("/home/user/dir1", "/home/user/dir2");
    return 0;
}