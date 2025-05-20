//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define TRUE 1
#define FALSE 0
#define BUFFER_SIZE 1024

typedef struct file_info {
    char name[100];
    long long size;
    float percentage;
} FileInfo;

void get_file_info(char* path, FileInfo* file_info) {
    struct statvfs statvfs_data;
    statvfs(path, &statvfs_data);
    file_info->size = statvfs_data.f_blocks * statvfs_data.f_frsize;
    sprintf(file_info->name, "%s", path);
}

void print_file_info(FileInfo* file_info, int num_files) {
    printf("%-20s %-20s %-10s\n", "File Name", "File Size (Bytes)", "Percentage");
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < num_files; i++) {
        printf("%-20s %-20lld %-10.2f\n", file_info[i].name, file_info[i].size, ((float)file_info[i].size / (float)file_info[0].size) * 100);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Please provide a directory path.\n");
        return 1;
    }

    char path[BUFFER_SIZE];
    strcpy(path, argv[1]);
    DIR* dir = opendir(path);
    struct dirent* dirent;
    FileInfo file_info[100];
    int num_files = 0;

    while ((dirent = readdir(dir))!= NULL) {
        if (dirent->d_type == DT_REG) {
            char file_path[BUFFER_SIZE];
            sprintf(file_path, "%s/%s", path, dirent->d_name);
            get_file_info(file_path, &file_info[num_files]);
            num_files++;
        }
    }

    closedir(dir);
    print_file_info(file_info, num_files);

    return 0;
}