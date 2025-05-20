//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>

#define MAX_FILES 100
#define MAX_NAME 256

typedef struct {
    char name[MAX_NAME];
    time_t mtime;
    long size;
} file_info;

file_info files[MAX_FILES];
int num_files;

void get_files(char *dir) {
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    int fd;

    if ((dp = opendir(dir)) == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_type == DT_REG) {
            sprintf(files[num_files].name, "%s/%s", dir, entry->d_name);
            if ((fd = open(files[num_files].name, O_RDONLY)) == -1) {
                perror("open");
                exit(EXIT_FAILURE);
            }
            if (fstat(fd, &statbuf) == -1) {
                perror("fstat");
                exit(EXIT_FAILURE);
            }
            close(fd);
            files[num_files].mtime = statbuf.st_mtime;
            files[num_files].size = statbuf.st_size;
            num_files++;
        }
    }

    closedir(dp);
}

int compare_files(const void *a, const void *b) {
    file_info *fa = (file_info *)a;
    file_info *fb = (file_info *)b;

    return strcmp(fa->name, fb->name);
}

int main(int argc, char *argv[]) {
    int i, j, k;
    char *src_dir, *dst_dir;
    int src_fd, dst_fd;
    char buf[BUFSIZ];
    int n;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s src_dir dst_dir\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    src_dir = argv[1];
    dst_dir = argv[2];

    get_files(src_dir);
    get_files(dst_dir);

    qsort(files, num_files, sizeof(file_info), compare_files);

    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, files[j].name) == 0) {
            if (files[i].mtime == files[j].mtime && files[i].size == files[j].size) {
                continue;
            }
        }

        if ((src_fd = open(files[i].name, O_RDONLY)) == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }

        if ((dst_fd = open(files[j].name, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }

        while ((n = read(src_fd, buf, BUFSIZ)) > 0) {
            if (write(dst_fd, buf, n) != n) {
                perror("write");
                exit(EXIT_FAILURE);
            }
        }

        if (n == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        close(src_fd);
        close(dst_fd);
    }

    return 0;
}