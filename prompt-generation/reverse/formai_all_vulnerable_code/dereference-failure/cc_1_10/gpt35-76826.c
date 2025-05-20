//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *entry;
    char *path;

    if (argc == 2) {
        path = argv[1];
    }
    else {
        path = ".";
    }

    if ((dp = opendir(path)) == NULL) {
        fprintf(stderr, "Error opening directory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    long long int total_size = 0;
    long long int file_count = 0;
    long long int dir_count = 0;

    while ((entry = readdir(dp)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        char full_path[1024];
        snprintf(full_path, 1024, "%s/%s", path, entry->d_name);
        DIR *sub_dir = opendir(full_path);
        if (sub_dir != NULL) {
            closedir(sub_dir);
            dir_count++;
            long long int sub_dir_size = 0;
            char sub_dir_path[1024];
            snprintf(sub_dir_path, 1024, "%s/%s", path, entry->d_name);
            char *sub_dir_argv[] = {"./diskanalyzer", sub_dir_path, NULL};
            int sub_dir_argc = 2;
            int sub_dir_pid = fork();
            if (sub_dir_pid == 0) {
                execvp(sub_dir_argv[0], sub_dir_argv);
            }
            else {
                int status;
                waitpid(sub_dir_pid, &status, 0);
                sub_dir_size = WEXITSTATUS(status);
            }
            printf("%lld\t%s/\n", sub_dir_size, entry->d_name);
            total_size += sub_dir_size;
        }
        else {
            file_count++;
            long long int size = 0;
            FILE *fp;
            fp = fopen(full_path, "rb");
            if (fp) {
                fseek(fp, 0, SEEK_END);
                size = ftell(fp);
                fclose(fp);
            }
            total_size += size;
            printf("%lld\t%s\n", size, entry->d_name);
        }
    }
    printf("\n%lld file(s), %lld directory(s) total size: %lld bytes\n\n", file_count, dir_count, total_size);
    closedir(dp);
    return total_size;
}