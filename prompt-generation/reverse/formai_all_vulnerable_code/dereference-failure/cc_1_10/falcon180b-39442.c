//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>
#include<unistd.h>

#define BUFFER_SIZE 1024

typedef struct dirent dirent;

int count_files_and_dirs(char* path) {
    int count = 0;
    DIR* dir = opendir(path);
    if (dir!= NULL) {
        dirent* de;
        while ((de = readdir(dir))!= NULL) {
            if (de->d_type == DT_DIR) {
                count++;
            }
        }
        closedir(dir);
    }
    return count;
}

int count_files(char* path, int* file_count, long long* total_size) {
    DIR* dir = opendir(path);
    if (dir!= NULL) {
        dirent* de;
        while ((de = readdir(dir))!= NULL) {
            if (de->d_type == DT_REG) {
                (*file_count)++;
                struct stat file_stat;
                stat(de->d_name, &file_stat);
                (*total_size) += file_stat.st_size;
            }
        }
        closedir(dir);
    }
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    char path[BUFFER_SIZE];
    strcpy(path, argv[1]);

    int file_count = 0;
    long long total_size = 0;

    count_files(path, &file_count, &total_size);

    printf("Total files: %d\n", file_count);
    printf("Total size: %lld bytes\n", total_size);

    return 0;
}