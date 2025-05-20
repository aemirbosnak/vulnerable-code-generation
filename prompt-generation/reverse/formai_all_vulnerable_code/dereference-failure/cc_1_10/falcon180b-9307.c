//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024
#define MAX_FILES 1000

// Function to read directory and list files
void read_dir(char *dir, char *files[]) {
    DIR *dp;
    struct dirent *dirp;
    int count = 0;

    dp = opendir(dir);

    if (dp!= NULL) {
        while ((dirp = readdir(dp))!= NULL) {
            if (count < MAX_FILES) {
                files[count] = (char *) malloc(strlen(dirp->d_name) + 1);
                strcpy(files[count], dirp->d_name);
                count++;
            }
        }
        closedir(dp);
    }
}

// Function to get file size in bytes
long get_file_size(char *filename) {
    struct stat statbuf;
    stat(filename, &statbuf);
    return statbuf.st_size;
}

// Function to calculate disk space used by files in directory
long calc_disk_space(char *dir, char *files[], int num_files) {
    long total_size = 0;

    for (int i = 0; i < num_files; i++) {
        char filepath[MAX_PATH];
        sprintf(filepath, "%s/%s", dir, files[i]);
        total_size += get_file_size(filepath);
    }

    return total_size;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        exit(1);
    }

    char dir[MAX_PATH];
    strcpy(dir, argv[1]);
    char *files[MAX_FILES];

    read_dir(dir, files);
    long total_size = calc_disk_space(dir, files, strlen(files)/sizeof(files[0]));

    printf("Total disk space used in '%s': %ld bytes\n", dir, total_size);

    return 0;
}