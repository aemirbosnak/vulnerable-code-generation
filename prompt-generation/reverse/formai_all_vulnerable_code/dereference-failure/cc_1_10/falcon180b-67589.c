//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_FILE_NAME_LENGTH 1024
#define TOTAL_SPACE_IN_BYTES (1024*1024*1024)

struct FileInfo {
    char name[MAX_FILE_NAME_LENGTH];
    long int size;
};

void print_usage() {
    printf("Usage:./program <directory_path>\n");
}

void print_file_info(struct FileInfo file_info) {
    printf("%s - %ld bytes\n", file_info.name, file_info.size);
}

void print_total_space_info(long int total_space_in_bytes) {
    printf("\nTotal space in directory: %ld bytes\n", total_space_in_bytes);
}

int main(int argc, char** argv) {
    if(argc!= 2) {
        print_usage();
        return 1;
    }

    DIR* dir = opendir(argv[1]);
    if(dir == NULL) {
        printf("Error: Invalid directory path\n");
        return 1;
    }

    struct dirent* entry;
    long int total_space_in_bytes = 0;

    while((entry = readdir(dir))!= NULL) {
        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char file_path[MAX_FILE_NAME_LENGTH];
        sprintf(file_path, "%s/%s", argv[1], entry->d_name);

        struct stat stat_buf;
        if(stat(file_path, &stat_buf) == -1) {
            printf("Error: Could not get file info for %s\n", entry->d_name);
            continue;
        }

        struct FileInfo file_info;
        strcpy(file_info.name, entry->d_name);
        file_info.size = stat_buf.st_size;

        print_file_info(file_info);
        total_space_in_bytes += file_info.size;
    }

    print_total_space_info(total_space_in_bytes);

    closedir(dir);
    return 0;
}