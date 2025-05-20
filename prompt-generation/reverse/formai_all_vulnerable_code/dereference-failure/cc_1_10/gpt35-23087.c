//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

struct file_info {
    char name[256];
    long long size;
};

typedef struct file_info file_info;

file_info* get_files(char* dir_name, int* num_files);
void sort_files(file_info* files, int num_files);
void print_files(file_info* files, int num_files);

int main() {
    char* dir_name = "/mnt/c/";
    int num_files = 0;
    file_info* files = get_files(dir_name, &num_files);
    sort_files(files, num_files);
    print_files(files, num_files);
    free(files);

    return 0;
}

file_info* get_files(char* dir_name, int* num_files) {
    DIR* dir;
    struct dirent* entry;
    struct stat file_stat;
    char file_path[512];
    file_info* files = malloc(sizeof(file_info) * 10000);
    int file_index = 0;

    dir = opendir(dir_name);
    if (dir == NULL) {
        printf("Error: unable to open directory %s\n", dir_name);
        exit(1);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            sprintf(file_path, "%s/%s", dir_name, entry->d_name);
            if (stat(file_path, &file_stat) == 0) {
                if (S_ISREG(file_stat.st_mode)) {
                    strcpy(files[file_index].name, entry->d_name);
                    files[file_index].size = file_stat.st_size;
                    file_index++;
                }
            }
        }
    }

    closedir(dir);
    *num_files = file_index;

    return files;
}

void sort_files(file_info* files, int num_files) {
    int i, j;
    file_info temp;

    for (i = 0; i < num_files; i++) {
        for (j = i + 1; j < num_files; j++) {
            if (files[i].size < files[j].size) {
                temp = files[i];
                files[i] = files[j];
                files[j] = temp;
            }
        }
    }
}

void print_files(file_info* files, int num_files) {
    int i;
    long long total_size = 0;
    printf("%-20s%-20s\n", "File Name", "File Size");
    for (i = 0; i < num_files; i++) {
        printf("%-20s%-20lld\n", files[i].name, files[i].size);
        total_size += files[i].size;
    }
    printf("Total size: %lld bytes\n", total_size);
}