//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define BLOCK_SIZE 1024
#define MAX_FILES 10000

typedef struct {
    char name[256];
    unsigned long long size;
    unsigned long long blocks;
} file_t;

void read_dir(const char* path, file_t* files, unsigned int* num_files) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        printf("Error: could not open directory '%s'\n", path);
        exit(1);
    }

    struct dirent* entry;
    while ((entry = readdir(dir))!= NULL) {
        if (*num_files >= MAX_FILES) {
            printf("Error: too many files in directory '%s'\n", path);
            exit(1);
        }

        strcpy(files[*num_files].name, entry->d_name);
        files[*num_files].size = entry->d_off;
        files[*num_files].blocks = entry->d_off / BLOCK_SIZE;
        (*num_files)++;
    }

    closedir(dir);
}

void print_files(file_t* files, unsigned int num_files) {
    printf("Name\tSize\tBlocks\n");
    for (unsigned int i = 0; i < num_files; i++) {
        printf("%-256s\t%10llu\t%10llu\n", files[i].name, files[i].size, files[i].blocks);
    }
}

void print_total(file_t* files, unsigned int num_files) {
    unsigned long long total_size = 0;
    unsigned long long total_blocks = 0;

    for (unsigned int i = 0; i < num_files; i++) {
        total_size += files[i].size;
        total_blocks += files[i].blocks;
    }

    printf("\nTotal:\t%10llu\t%10llu\n", total_size, total_blocks);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Error: no directory specified\n");
        exit(1);
    }

    char path[1024];
    strcpy(path, argv[1]);

    file_t files[MAX_FILES];
    unsigned int num_files = 0;

    read_dir(path, files, &num_files);
    print_files(files, num_files);
    print_total(files, num_files);

    return 0;
}