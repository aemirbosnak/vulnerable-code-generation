//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// function to calculate the size of a directory or file
unsigned long long get_size(const char *path) {
    struct stat sb;
    if (lstat(path, &sb) == -1) {
        fprintf(stderr, "Error: cannot stat path %s\n", path);
        exit(EXIT_FAILURE);
    }
    if (!S_ISDIR(sb.st_mode)) { // this is a file
        return sb.st_size;
    }
    DIR *dir = opendir(path);
    if (dir == NULL) { // cannot access the directory
        return 0;
    }
    unsigned long long size = 0;
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // skip ".", "..", and hidden files/directories
        if (entry->d_name[0] == '.') {
            continue;
        }
        char *subpath = malloc(strlen(path) + strlen(entry->d_name) + 2);
        sprintf(subpath, "%s/%s", path, entry->d_name);
        size += get_size(subpath);
        free(subpath);
    }
    closedir(dir);
    return size;
}

int main(int argc, char *argv[]) {
    char *path;
    if (argc < 2) {
        path = ".";
    } else {
        path = argv[1];
    }
    unsigned long long size = get_size(path);
    if (size >> 30) {
        printf("Total size: %.2f GB\n", size / 1e9);
    } else if (size >> 20) {
        printf("Total size: %.2f MB\n", size / 1e6);
    } else if (size >> 10) {
        printf("Total size: %.2f KB\n", size / 1e3);
    } else {
        printf("Total size: %llu B\n", size);
    }
    return 0;
}