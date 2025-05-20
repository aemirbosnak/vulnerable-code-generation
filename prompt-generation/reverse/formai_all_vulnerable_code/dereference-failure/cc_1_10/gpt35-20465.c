//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>

void print_error(char *dir) {
    fprintf(stderr, "Could not open directory %s: %s\n", dir, strerror(errno));
    exit(EXIT_FAILURE);
}

int is_dot_or_dot_dot(char *name) {
    return strcmp(name, ".") == 0 || strcmp(name, "..") == 0;
}

unsigned long long get_size(char *dir_path) {
    unsigned long long size = 0;
    struct stat st;
    if (stat(dir_path, &st) == 0 && S_ISDIR(st.st_mode)) {
        DIR *dir = opendir(dir_path);
        if (dir == NULL) {
            print_error(dir_path);
        }
        struct dirent *entry = readdir(dir);
        while (entry != NULL) {
            if (!is_dot_or_dot_dot(entry->d_name)) {
                char *path = malloc(strlen(dir_path) + strlen(entry->d_name) + 2);
                if (path == NULL) {
                    fprintf(stderr, "Failed to allocate memory\n");
                    exit(EXIT_FAILURE);
                }
                sprintf(path, "%s/%s", dir_path, entry->d_name);
                size += get_size(path);
                free(path);
            }
            entry = readdir(dir);
        }
        closedir(dir);
    } else if (stat(dir_path, &st) == 0 && S_ISREG(st.st_mode)) {
        size += st.st_size;
    }
    return size;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    unsigned long long size = get_size(argv[1]);
    printf("Directory size: %llu bytes\n", size);
    return 0;
}