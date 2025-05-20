//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

long long count_size(char* path); // function prototype

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }
    char* path = argv[1];
    long long size = count_size(path); // call count_size function
    printf("Total size of '%s' directory: %lld bytes\n", path, size);
    return 0;
}

long long count_size(char* path) {
    struct stat st;
    if (stat(path, &st) != 0) { // check if file exists
        fprintf(stderr, "Error: cannot access '%s'\n", path);
        return 0;
    }
    if (S_ISREG(st.st_mode)) { // check if file is regular file
        return st.st_size;
    }
    if (!S_ISDIR(st.st_mode)) { // check if file is directory
        fprintf(stderr, "Error: '%s' is not a directory\n", path);
        return 0;
    }
    DIR* dir = opendir(path);
    if (dir == NULL) { // check if directory can be opened
        fprintf(stderr, "Error: cannot open directory '%s'\n", path);
        return 0;
    }
    long long size = 0;
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) { // loop through directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // ignore . and .. directories
        }
        char* new_path = malloc(strlen(path) + strlen(entry->d_name) + 2); // allocate memory for new path
        sprintf(new_path, "%s/%s", path, entry->d_name); // create new path
        long long entry_size;
        if (entry->d_type == DT_DIR) { // recursive case: directory
            entry_size = count_size(new_path); // call count_size recursively
        } else if (entry->d_type == DT_REG) { // base case: regular file
            if (stat(new_path, &st) == 0) {
                entry_size = st.st_size;
            } else {
                fprintf(stderr, "Error: cannot access file '%s'\n", new_path);
                entry_size = 0;
            }
        } else { // ignore symbolic links, sockets, etc.
            entry_size = 0;
        }
        size += entry_size; // accumulate size
        free(new_path); // free memory
    }
    closedir(dir); // close directory
    return size;
}