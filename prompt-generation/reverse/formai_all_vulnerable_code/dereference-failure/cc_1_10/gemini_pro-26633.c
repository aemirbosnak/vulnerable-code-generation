//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

// Get the size of a file in bytes
long get_file_size(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fclose(fp);
    return size;
}

// Get the size of a directory in bytes
long get_dir_size(const char *dirname) {
    DIR *dir = opendir(dirname);
    if (dir == NULL) {
        perror("opendir");
        return -1;
    }
    long size = 0;
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        char path[PATH_MAX];
        snprintf(path, sizeof(path), "%s/%s", dirname, entry->d_name);
        if (entry->d_type == DT_DIR) {
            size += get_dir_size(path);
        } else {
            size += get_file_size(path);
        }
    }
    closedir(dir);
    return size;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    long size = get_dir_size(argv[1]);
    if (size == -1) {
        perror("get_dir_size");
        return EXIT_FAILURE;
    }

    printf("The total size of the directory '%s' is %ld bytes.\n", argv[1], size);
    return EXIT_SUCCESS;
}