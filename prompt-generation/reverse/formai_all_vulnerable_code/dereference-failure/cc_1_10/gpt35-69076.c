//FormAI DATASET v1.0 Category: File Synchronizer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024

int copy_file(char *src, char *dest) {
    FILE *fp1, *fp2;
    char buf[BUF_SIZE];
    size_t bytes_read;
    fp1 = fopen(src, "rb");
    if (fp1 == NULL) {
        return 1;
    }
    fp2 = fopen(dest, "wb");
    if (fp2 == NULL) {
        return 1;
    }
    while ((bytes_read = fread(buf, 1, BUF_SIZE, fp1)) > 0) {
        fwrite(buf, 1, bytes_read, fp2);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}

void sync_files(char *src_path, char *dest_path) {
    DIR *dir;
    struct dirent *dp;
    char src_file[BUF_SIZE], dest_file[BUF_SIZE];
    dir = opendir(src_path);
    if (dir == NULL) {
        perror("opendir");
        return;
    }
    while ((dp = readdir(dir)) != NULL) {
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) {
            continue;
        }
        sprintf(src_file, "%s/%s", src_path, dp->d_name);
        sprintf(dest_file, "%s/%s", dest_path, dp->d_name);
        struct stat st;
        lstat(src_file, &st);
        if (S_ISDIR(st.st_mode)) {
            sync_files(src_file, dest_file);
        } else {
            struct stat st_dest;
            if (lstat(dest_file, &st_dest) < 0) {
                if (errno != ENOENT) {
                    perror("lstat error");
                    closedir(dir);
                    return;
                }
            } else {
                if (st.st_size == st_dest.st_size
                        && st.st_mtim.tv_sec <= st_dest.st_mtim.tv_sec) {
                    continue;
                }
            }
            int ret = copy_file(src_file, dest_file);
            if (ret != 0) {
                printf("Error copying file %s\n", src_file);
            } else {
                printf("Copied file %s to %s\n", src_file, dest_file);
            }
        }
    }
    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return 1;
    }
    sync_files(argv[1], argv[2]);
    return 0;
}