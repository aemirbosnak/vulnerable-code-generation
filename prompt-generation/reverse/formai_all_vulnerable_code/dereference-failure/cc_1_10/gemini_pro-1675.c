//GEMINI-pro DATASET v1.0 Category: System administration ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_PATH_LENGTH 1024

void print_file_info(const char *path) {
    struct stat statbuf;
    if (stat(path, &statbuf) != 0) {
        perror("stat");
        return;
    }

    printf("File: %s\n", path);
    printf("Size: %ld bytes\n", statbuf.st_size);
    printf("Type: ");
    switch (statbuf.st_mode & S_IFMT) {
        case S_IFREG:
            printf("regular file\n");
            break;
        case S_IFDIR:
            printf("directory\n");
            break;
        case S_IFLNK:
            printf("symbolic link\n");
            break;
        case S_IFIFO:
            printf("FIFO\n");
            break;
        case S_IFBLK:
            printf("block device\n");
            break;
        case S_IFCHR:
            printf("character device\n");
            break;
        default:
            printf("unknown type\n");
            break;
    }
    printf("Mode: %o\n", statbuf.st_mode);
    printf("Owner: %s\n", getpwuid(statbuf.st_uid)->pw_name);
    printf("Group: %s\n", getgrgid(statbuf.st_gid)->gr_name);
    printf("Access time: %s", ctime(&statbuf.st_atime));
    printf("Modification time: %s", ctime(&statbuf.st_mtime));
    printf("Change time: %s", ctime(&statbuf.st_ctime));
}

void print_directory_contents(const char *path) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char full_path[MAX_PATH_LENGTH];
        snprintf(full_path, MAX_PATH_LENGTH, "%s/%s", path, entry->d_name);
        print_file_info(full_path);
    }

    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *path = argv[1];

    struct stat statbuf;
    if (stat(path, &statbuf) != 0) {
        perror("stat");
        return EXIT_FAILURE;
    }

    if (S_ISDIR(statbuf.st_mode)) {
        print_directory_contents(path);
    } else {
        print_file_info(path);
    }

    return EXIT_SUCCESS;
}