//FormAI DATASET v1.0 Category: File Synchronizer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>

#define MAX_FILE_PATH 1024
#define MAX_THREADS 10

int copyFile(const char *src, const char *dst) {
    int fd_src, fd_dst;
    ssize_t rcount, wcount;
    char buffer[4096];

    fd_src = open(src, O_RDONLY);
    if (fd_src == -1) {
        printf("Unable to open source file '%s'\n", src);
        return 1;
    }
    fd_dst = open(dst, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd_dst == -1) {
        printf("Unable to create destination file '%s'\n", dst);
        return 1;
    }
    while ((rcount = read(fd_src, buffer, sizeof(buffer))) != 0) {
        if (rcount == -1) {
            printf("Error reading from file '%s'\n", src);
            close(fd_src);
            close(fd_dst);
            return 1;
        }
        wcount = write(fd_dst, buffer, rcount);
        if (wcount != rcount) {
            printf("Error writing to file '%s'\n", dst);
            close(fd_src);
            close(fd_dst);
            return 1;
        }
    }
    if (close(fd_src) == -1) {
        printf("Error closing source file '%s'\n", src);
        return 1;
    }
    if (close(fd_dst) == -1) {
        printf("Error closing destination file '%s'\n", dst);
        return 1;
    }
    return 0;
}

void *syncDirectory(void *arg) {
    char *dir_path = (char *) arg;
    struct dirent *entry;
    struct stat src_stat, dst_stat;
    DIR *dir = opendir(dir_path);
    int ret;
    char src_path[MAX_FILE_PATH], dst_path[MAX_FILE_PATH];

    if (dir == NULL) {
        printf("Unable to access directory '%s'\n", dir_path);
        return NULL;
    }
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;
        snprintf(src_path, MAX_FILE_PATH, "%s/%s", dir_path, entry->d_name);
        snprintf(dst_path, MAX_FILE_PATH, "%s/%s", "./backup", entry->d_name);
        ret = stat(src_path, &src_stat);
        if (ret == -1) {
            printf("Unable to get stat for file '%s': %s\n", src_path, strerror(errno));
            continue;
        }
        if (S_ISDIR(src_stat.st_mode)) {
            syncDirectory(src_path);
            continue;
        }
        ret = stat(dst_path, &dst_stat);
        if (ret == -1) {
            if (errno == ENOENT) {
                // destination file does not exist, copy source to destination
                printf("Creating new file '%s'\n", dst_path);
                copyFile(src_path, dst_path);
            } else {
                // unknown error, print error and continue
                printf("Unable to get stat for file '%s': %s\n", dst_path, strerror(errno));
            }
            continue;
        }
        if (src_stat.st_mtime == dst_stat.st_mtime && src_stat.st_size == dst_stat.st_size) {
            // file has not been modified, no need to copy
            continue;
        }
        printf("Copying file '%s' to '%s'\n", src_path, dst_path);
        copyFile(src_path, dst_path);
    }
    closedir(dir);
    return NULL;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    pthread_t threads[MAX_THREADS];
    int num_threads = 0;

    for (int i = 1; i < argc; i++) {
        if (num_threads >= MAX_THREADS) {
            printf("Maximum number of threads reached, skipping directory '%s'\n", argv[i]);
            continue;
        }
        pthread_create(&threads[num_threads], NULL, syncDirectory, argv[i]);
        num_threads++;
    }
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}