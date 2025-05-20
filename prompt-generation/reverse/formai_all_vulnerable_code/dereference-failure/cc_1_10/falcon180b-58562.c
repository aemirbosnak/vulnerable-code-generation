//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024

typedef struct _file_info {
    char path[MAX_PATH];
    unsigned long long size;
} FILE_INFO;

void print_usage(char* program_name) {
    printf("Usage: %s [directory]\n", program_name);
}

void print_file_info(FILE_INFO* file_info) {
    printf("Path: %s\n", file_info->path);
    printf("Size: %llu bytes\n\n", file_info->size);
}

int compare_file_info(const void* a, const void* b) {
    return (*(FILE_INFO*)a).size - (*(FILE_INFO*)b).size;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        print_usage(argv[0]);
        return 1;
    }

    char directory[MAX_PATH];
    strcpy(directory, argv[1]);
    strcat(directory, "/");

    DIR* dir = opendir(directory);
    if (dir == NULL) {
        printf("Error: Unable to open directory '%s'.\n", directory);
        return 1;
    }

    FILE_INFO files[10000];
    int num_files = 0;

    struct dirent* ent;
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_REG || ent->d_type == DT_LNK) {
            if (num_files >= 10000) {
                printf("Error: Too many files in directory.\n");
                closedir(dir);
                return 1;
            }

            char path[MAX_PATH];
            strcpy(path, directory);
            strcat(path, ent->d_name);

            struct stat file_stat;
            if (stat(path, &file_stat)!= 0) {
                printf("Error: Unable to get file info for '%s'.\n", path);
                closedir(dir);
                return 1;
            }

            FILE_INFO file_info;
            strcpy(file_info.path, path);
            file_info.size = file_stat.st_size;

            files[num_files++] = file_info;
        }
    }

    closedir(dir);

    qsort(files, num_files, sizeof(FILE_INFO), compare_file_info);

    for (int i = 0; i < num_files; i++) {
        print_file_info(&files[i]);
    }

    return 0;
}