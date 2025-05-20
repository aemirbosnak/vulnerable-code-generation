//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>

void print_error(char *function_name) {
    printf("Error in function %s: %s\n", function_name, strerror(errno));
    exit(1);
}

int is_directory(struct dirent *entry) {
    struct stat statbuf;

    if (stat(entry->d_name, &statbuf) == -1) {
        print_error("is_directory");
    }

    return S_ISDIR(statbuf.st_mode);
}

void print_size(double size) {
    char *suffix = "B";

    if (size > 1024) {
        suffix = "KB";
        size /= 1024;
    }

    if (size > 1024) {
        suffix = "MB";
        size /= 1024;
    }

    if (size > 1024) {
        suffix = "GB";
        size /= 1024;
    }

    printf("%.1f %s\n", size, suffix);
}

double get_directory_size(char *path) {
    DIR *directory = opendir(path);
    struct dirent *entry;
    double total_size = 0;

    if (directory == NULL) {
        print_error("get_directory_size");
    }

    while ((entry = readdir(directory)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char entry_path[1024];
        snprintf(entry_path, sizeof(entry_path), "%s/%s", path, entry->d_name);

        if (is_directory(entry)) {
            total_size += get_directory_size(entry_path);
        } else {
            struct stat statbuf;

            if (stat(entry_path, &statbuf) == -1) {
                print_error("get_directory_size");
            }

            total_size += statbuf.st_size;
        }
    }

    if (closedir(directory) == -1) {
        print_error("get_directory_size");
    }

    return total_size;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s [path]\n", argv[0]);
        exit(1);
    }

    double total_size = get_directory_size(argv[1]);

    printf("Total size of directory %s: ", argv[1]);
    print_size(total_size);

    return 0;
}