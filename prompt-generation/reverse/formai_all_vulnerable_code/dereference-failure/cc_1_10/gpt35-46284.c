//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define GB_DIVISOR 1000000000
#define MB_DIVISOR 1000000
#define KB_DIVISOR 1000
#define BUFFER_SIZE 256

void print_size(long int size);
void analyze_dir(char* path);

int main(int argc, char *argv[]) {
    printf("C Disk Space Analyzer\n\n");

    if (argc < 2) {
        printf("Please specify a path.\n");
        return 1;
    }

    analyze_dir(argv[1]);

    return 0;
}

void analyze_dir(char* path) {
    DIR *dir;
    struct dirent *dir_entry;
    struct stat file_stat;

    long int size = 0;

    dir = opendir(path);

    if (dir) {
        while ((dir_entry = readdir(dir)) != NULL) {
            if (strcmp(dir_entry->d_name, ".") != 0 && strcmp(dir_entry->d_name, "..") != 0) {
                char full_path[BUFFER_SIZE];
                strcpy(full_path, path);
                strcat(full_path, "/");
                strcat(full_path, dir_entry->d_name);

                if (stat(full_path, &file_stat) != -1) {
                    if (S_ISDIR(file_stat.st_mode)) {
                        analyze_dir(full_path);
                    } else {
                        size += file_stat.st_size;
                    }
                }
            }
        }

        closedir(dir);
    }

    printf("%s ", path);
    print_size(size);
}

void print_size(long int size) {
    if (size > GB_DIVISOR) {
        printf("%.2f GB\n", (float) size / GB_DIVISOR);
    } else if (size > MB_DIVISOR) {
        printf("%.2f MB\n", (float) size / MB_DIVISOR);
    } else if (size > KB_DIVISOR) {
        printf("%.2f KB\n", (float) size / KB_DIVISOR);
    } else {
        printf("%ld B\n", size);
    }
}