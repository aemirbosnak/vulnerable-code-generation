//FormAI DATASET v1.0 Category: File Synchronizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

void sync_files(const char *src_dir, const char *dst_dir) {
    DIR *dir;
    struct dirent *ent;

    dir = opendir(src_dir);

    if(dir == NULL) {
        printf("Unable to open source directory\n");
        return;
    }

    while ((ent = readdir(dir)) != NULL) {
        if(strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
            continue;
        }

        char src_path[1024], dst_path[1024];
        sprintf(src_path, "%s/%s", src_dir, ent->d_name);
        sprintf(dst_path, "%s/%s", dst_dir, ent->d_name);

        struct stat src_stat, dst_stat;

        if(stat(src_path, &src_stat) != 0) {
            printf("Unable to get stats for %s\n", src_path);
            continue;
        }

        if(stat(dst_path, &dst_stat) == 0) {
            if(dst_stat.st_mtime >= src_stat.st_mtime) {
                continue;
            }

            printf("Updating file: %s\n", dst_path);
        } else {
            printf("Creating file: %s\n", dst_path);
        }

        int src_fd = open(src_path, O_RDONLY);
        int dst_fd = open(dst_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);

        if(src_fd < 0 || dst_fd < 0) {
            printf("Unable to open files for copying\n");
            continue;
        }

        char buffer[BUFFER_SIZE];
        ssize_t nread;

        while ((nread = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
            write(dst_fd, buffer, nread);
        }

        close(src_fd);
        close(dst_fd);
    }

    closedir(dir);
}

int main(int argc, char **argv) {
    if(argc != 3) {
        printf("Usage: %s [source directory] [destination directory]\n", argv[0]);
        return 1;
    }

    sync_files(argv[1], argv[2]);

    return 0;
}