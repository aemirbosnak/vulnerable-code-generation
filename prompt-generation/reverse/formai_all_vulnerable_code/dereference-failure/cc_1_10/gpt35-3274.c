//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

// function to calculate the size of a directory
long long calculate_size(char *);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s directory\n", argv[0]);
        return 1;
    }
    
    long long size = calculate_size(argv[1]);
    
    printf("Size of %s: %lld bytes\n", argv[1], size);
    
    return 0;
}

long long calculate_size(char *path) {
    struct stat st;
    
    if (stat(path, &st) == -1) {
        printf("Error: %s\n", strerror(errno));
        exit(1);
    }

    if (S_ISDIR(st.st_mode)) {
        long long size = 0;
        DIR *dir = opendir(path);
        struct dirent *entry;

        while ((entry = readdir(dir)) != NULL) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            char *new_path = malloc(strlen(path) + strlen(entry->d_name) + 2);
            sprintf(new_path, "%s/%s", path, entry->d_name);
            size += calculate_size(new_path);
            free(new_path);
        }

        closedir(dir);

        return size;
    } else if (S_ISREG(st.st_mode)) {
        return st.st_size;
    } else {
        return 0;
    }
}