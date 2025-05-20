//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 1024

struct file_info {
    char name[MAX_FILE_NAME_LEN];
    long long size;
};

void get_file_info(const char* path, struct file_info* file_info) {
    struct statvfs statvfs_buf;
    if (statvfs(path, &statvfs_buf) == 0) {
        file_info->size = statvfs_buf.f_blocks * statvfs_buf.f_frsize;
    } else {
        perror("statvfs");
        exit(1);
    }
}

void get_dir_contents(const char* path, struct file_info* files, int* num_files) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        exit(1);
    }

    struct dirent* dirent = NULL;
    while ((dirent = readdir(dir))!= NULL) {
        if (*num_files >= MAX_FILE_NAME_LEN) {
            fprintf(stderr, "Too many files in directory.\n");
            exit(1);
        }

        strcpy(files[*num_files].name, dirent->d_name);
        get_file_info(dirent->d_name, &files[*num_files]);
        (*num_files)++;
    }

    closedir(dir);
}

void sort_files(struct file_info* files, int num_files) {
    for (int i = 0; i < num_files - 1; i++) {
        for (int j = i + 1; j < num_files; j++) {
            if (files[i].size < files[j].size) {
                struct file_info temp = files[i];
                files[i] = files[j];
                files[j] = temp;
            }
        }
    }
}

void print_files(struct file_info* files, int num_files) {
    printf("File name\t\tSize\n");
    for (int i = 0; i < num_files; i++) {
        printf("%s\t\t%lld\n", files[i].name, files[i].size);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s directory\n", argv[0]);
        return 1;
    }

    struct file_info files[MAX_FILE_NAME_LEN];
    int num_files = 0;

    get_dir_contents(argv[1], files, &num_files);
    sort_files(files, num_files);
    print_files(files, num_files);

    return 0;
}