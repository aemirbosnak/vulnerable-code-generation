//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

long long int dir_size(const char *path);

int main(int argc, char *argv[]) {
    const char *dirname;
    if(argc == 2){
        dirname = argv[1];
    } else {
        dirname = ".";
    }

    long long int total_size = dir_size(dirname);

    printf("Total Size of directory '%s': ", dirname);
    if(total_size < 1024LL){
        printf("%lld B\n", total_size);
    } else if(total_size < 1024LL * 1024LL){
        printf("%.2f KB\n", (double)total_size / 1024);
    } else if(total_size < 1024LL * 1024LL * 1024LL){
        printf("%.2f MB\n", (double)total_size / (1024 * 1024));
    } else {
        printf("%.2f GB\n", (double)total_size / (1024 * 1024 * 1024));
    }

    return 0;
}

long long int dir_size(const char *path) {
    DIR *dir = opendir(path);
    if (!dir) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    long long int total_size = 0LL;
    struct dirent *entry;

    while ((entry = readdir(dir))) {
        if (entry->d_type == DT_DIR) { // directory
            char pathbuf[1024] = "";
            strcat(pathbuf, path);
            strcat(pathbuf, "/");
            strcat(pathbuf, entry->d_name);

            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            total_size += dir_size(pathbuf);
        } else { // file
            char pathbuf[1024] = "";
            strcat(pathbuf, path);
            strcat(pathbuf, "/");
            strcat(pathbuf, entry->d_name);

            struct stat statbuf;
            if(stat(pathbuf, &statbuf) == -1){
                perror("stat");
                exit(EXIT_FAILURE);
            }
            total_size += statbuf.st_size;
        }
    }
    closedir(dir);

    return total_size;
}