//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <math.h>

// Recursive function to calculate the size of a directory
long get_dir_size(char *path) {
    long size = 0;
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return -1;
    }
    struct dirent *ent;
    while ((ent = readdir(dir)) != NULL) {
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
            continue;
        }
        char *new_path = malloc(strlen(path) + strlen(ent->d_name) + 2);
        sprintf(new_path, "%s/%s", path, ent->d_name);
        struct stat sbuf;
        if (lstat(new_path, &sbuf) == -1) {
            perror("lstat");
            free(new_path);
            closedir(dir);
            return -1;
        }
        if (S_ISDIR(sbuf.st_mode)) {
            size += get_dir_size(new_path);
        } else {
            size += sbuf.st_size;
        }
        free(new_path);
    }
    closedir(dir);
    return size;
}

// Function to print the size of a directory in human-readable format
void print_dir_size(char *path) {
    long size = get_dir_size(path);
    if (size == -1) {
        perror("get_dir_size");
        return;
    }
    char *suffixes[] = {"B", "KB", "MB", "GB", "TB", "PB", "EB"};
    int i = 0;
    while (size >= 1024 && i < 6) {
        size /= 1024;
        i++;
    }
    printf("%ld %s\n", size, suffixes[i]);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return 1;
    }
    print_dir_size(argv[1]);
    return 0;
}