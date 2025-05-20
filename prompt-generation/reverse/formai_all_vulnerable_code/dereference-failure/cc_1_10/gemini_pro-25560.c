//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s src dst\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *src = argv[1];
    char *dst = argv[2];

    DIR *src_dir = opendir(src);
    if (src_dir == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    struct dirent *src_dirent;
    while ((src_dirent = readdir(src_dir)) != NULL) {
        char *src_path = malloc(strlen(src) + strlen(src_dirent->d_name) + 2);
        strcpy(src_path, src);
        strcat(src_path, "/");
        strcat(src_path, src_dirent->d_name);

        struct stat src_stat;
        if (stat(src_path, &src_stat) == -1) {
            perror("stat");
            free(src_path);
            continue;
        }

        if (S_ISDIR(src_stat.st_mode)) {
            char *dst_path = malloc(strlen(dst) + strlen(src_dirent->d_name) + 2);
            strcpy(dst_path, dst);
            strcat(dst_path, "/");
            strcat(dst_path, src_dirent->d_name);

            mkdir(dst_path, src_stat.st_mode);
            free(dst_path);
            continue;
        }

        int src_fd = open(src_path, O_RDONLY);
        if (src_fd == -1) {
            perror("open");
            free(src_path);
            continue;
        }

        char *dst_path = malloc(strlen(dst) + strlen(src_dirent->d_name) + 2);
        strcpy(dst_path, dst);
        strcat(dst_path, "/");
        strcat(dst_path, src_dirent->d_name);

        int dst_fd = open(dst_path, O_WRONLY | O_CREAT | O_TRUNC, src_stat.st_mode);
        if (dst_fd == -1) {
            perror("open");
            free(src_path);
            free(dst_path);
            close(src_fd);
            continue;
        }

        char buf[4096];
        int n;
        while ((n = read(src_fd, buf, sizeof(buf))) > 0) {
            write(dst_fd, buf, n);
        }

        close(src_fd);
        close(dst_fd);
        free(src_path);
        free(dst_path);
    }

    closedir(src_dir);
    return EXIT_SUCCESS;
}