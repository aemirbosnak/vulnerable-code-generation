//FormAI DATASET v1.0 Category: System process viewer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define BUF_LEN 256

int is_numeric(const char *str) {
    for (size_t i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    DIR *dp;
    struct dirent *dirp;
    char path[BUF_LEN];
    char stat_path[BUF_LEN];
    char buf[BUF_LEN];
    char comm[BUF_LEN];
    int pid = -1;
    int ppid = -1;
    int pgrp = -1;
    int sid = -1;
    int tty = -1;
    int uid = -1;
    int euid = -1;
    int gid = -1;
    int egid = -1;
    int state = -1;
    int pcpu = -1;
    int rss = -1;
    int vsize = -1;
    int fd = -1;
    int max_fd = -1;
    int c = 0;

    printf("PID\tPPID\tPGRP\tSID\tTTY\tUID\tEUID\tGID\tEGID\tSTATE\tCPU\tRSS\tVSIZE\n");

    dp = opendir("/proc");

    if (!dp) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((dirp = readdir(dp))) {
        if (is_numeric(dirp->d_name)) {
            sprintf(path, "/proc/%s/stat", dirp->d_name);
            sprintf(stat_path, "/proc/%s/fd", dirp->d_name);
            FILE *fp = fopen(path, "r");

            if (!fp) {
                continue;
            }

            memset(buf, 0, BUF_LEN);
            fread(buf, BUF_LEN, 1, fp);
            fclose(fp);

            sscanf(buf,
                   "%d "
                   "%s "
                   "%c "
                   "%d %d %d %d "
                   "%d "
                   "%u "
                   "%lu "
                   "%lu "
                   "%d %d "
                   "%d "
                   "%d "
                   "%*d "
                   "%*d "
                   "%d "
                   "%u "
                   "%lu "
                   "%ld",
                   &pid, comm, &state, &ppid, &pgrp, &sid, &tty, &uid, &gid, &pcpu, &rss, &vsize, &egid);

            DIR *fd_dir = opendir(stat_path);

                while ((dirp = readdir(fd_dir))) {
                    if (is_numeric(dirp->d_name)) {
                        fd++;
                    }
                }

            if (fd > max_fd) {
                max_fd = fd;
            }

            closedir(fd_dir);

            printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%c\t%d\t%d\t%d\n",
                   pid, ppid, pgrp, sid, tty, uid, euid, gid, egid, state, pcpu, rss, vsize);
        }
    }

    closedir(dp);

    printf("\nMax file descriptors: %d\n", max_fd);

    return 0;
}