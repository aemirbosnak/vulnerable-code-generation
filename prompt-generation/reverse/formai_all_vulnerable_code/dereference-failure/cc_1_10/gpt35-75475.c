//FormAI DATASET v1.0 Category: System process viewer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUF_SIZE 512

int main(int argc, char **argv) {
    DIR *proc;
    struct dirent *dir;
    char path[BUF_SIZE];
    char line[BUF_SIZE];
    pid_t pid;
    int uid, gid, ppid;

    printf("%-8s%-20s%-10s%-10s%-20s%-10s\n", "PID", "COMMAND", "UID", "GID", "PPID", "STATE");

    proc = opendir("/proc");

    if (!proc) {
        fprintf(stderr, "Failed to open /proc directory\n");
        exit(1);
    }

    while ((dir = readdir(proc)) != NULL) {
        if (!isdigit(*(dir->d_name)))
            continue;

        snprintf(path, BUF_SIZE, "/proc/%s/status", dir->d_name);

        int fd = open(path, O_RDONLY);
        if (fd == -1) {
            continue;
        }

        read(fd, line, BUF_SIZE);

        sscanf(line, "Uid:\t%d", &uid);

        read(fd, line, BUF_SIZE);

        sscanf(line, "Gid:\t%d", &gid);

        read(fd, line, BUF_SIZE);

        sscanf(line, "PPid:\t%d", &ppid);

        snprintf(path, BUF_SIZE, "/proc/%s/cmdline", dir->d_name);

        char buf[BUF_SIZE];
        int rfd = open(path, O_RDONLY);
        if (rfd == -1) {
            continue;
        }

        int r = read(rfd, buf, BUF_SIZE);
        for (int i = 0; i < r; i++) {
            if (buf[i] == '\0')
                buf[i] = ' ';
        }

        snprintf(line, BUF_SIZE, "/proc/%s/stat", dir->d_name);

        FILE *fp = fopen(line, "r");

        if (!fp) {
            continue;
        }

        fgets(line, BUF_SIZE, fp);
        fclose(fp);

        char *state = strchr(line, ')');
        state += 2;

        sscanf(line, "%d", &pid);
        printf("%-8d%-20s%-10d%-10d%-20d%-10s\n",
                pid, buf, uid, gid, ppid, state);
    }

    closedir(proc);
    return 0;
}