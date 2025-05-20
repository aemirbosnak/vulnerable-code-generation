//FormAI DATASET v1.0 Category: File Synchronizer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void sync_files(const char *src_path, const char *dst_path)
{
    DIR *dir = opendir(src_path);
    struct dirent *entry;
    char *src_filename, *dst_filename, *src_pathname, *dst_pathname, *cmd;

    while ((entry = readdir(dir)) != NULL) {
        if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..")) {
            continue;
        }

        src_filename = entry->d_name;
        dst_filename = src_filename;
        asprintf(&src_pathname, "%s/%s", src_path, src_filename);
        asprintf(&dst_pathname, "%s/%s", dst_path, dst_filename);

        struct stat src_stat, dst_stat;
        if (stat(src_pathname, &src_stat) == -1) {
            perror(src_pathname);
            free(src_pathname);
            free(dst_pathname);
            continue;
        }

        if (stat(dst_pathname, &dst_stat) == 0) {
            if (src_stat.st_mtime > dst_stat.st_mtime) {
                asprintf(&cmd, "cp %s %s", src_pathname, dst_pathname);
                system(cmd);
                free(cmd);
            }
        } else {
            asprintf(&cmd, "cp %s %s", src_pathname, dst_pathname);
            system(cmd);
            free(cmd);
        }

        sync_files(src_pathname, dst_pathname);

        free(src_pathname);
        free(dst_pathname);
    }

    closedir(dir);
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        printf("Usage: %s SRC_PATH DST_PATH\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sync_files(argv[1], argv[2]);

    return 0;
}