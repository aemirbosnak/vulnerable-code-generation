//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_FILE_NAME_LEN 256
#define MAX_DIR_NAME_LEN 256

typedef struct {
    char dir_name[MAX_DIR_NAME_LEN];
    size_t total_size;
    size_t num_files;
} DirectoryInfo;

void get_directory_info(const char* directory_path, DirectoryInfo* info) {
    DIR* dir = opendir(directory_path);
    if (dir == NULL) {
        printf("Error opening directory: %s\n", directory_path);
        exit(1);
    }

    struct dirent* dir_entry;
    while ((dir_entry = readdir(dir))!= NULL) {
        if (dir_entry->d_type == DT_DIR) {
            if (strcmp(dir_entry->d_name, ".")!= 0 && strcmp(dir_entry->d_name, "..")!= 0) {
                char sub_dir_path[MAX_DIR_NAME_LEN];
                sprintf(sub_dir_path, "%s/%s", directory_path, dir_entry->d_name);
                get_directory_info(sub_dir_path, info);
            }
        } else {
            char file_path[MAX_FILE_NAME_LEN];
            sprintf(file_path, "%s/%s", directory_path, dir_entry->d_name);
            struct stat file_stat;
            stat(file_path, &file_stat);
            info->total_size += file_stat.st_size;
            info->num_files++;
        }
    }

    closedir(dir);
}

void print_directory_info(const DirectoryInfo* info) {
    printf("Total size: %zu bytes\n", info->total_size);
    printf("Number of files: %zu\n", info->num_files);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return 1;
    }

    char directory_path[MAX_DIR_NAME_LEN];
    sprintf(directory_path, "%s", argv[1]);

    DirectoryInfo info;
    get_directory_info(directory_path, &info);
    print_directory_info(&info);

    return 0;
}