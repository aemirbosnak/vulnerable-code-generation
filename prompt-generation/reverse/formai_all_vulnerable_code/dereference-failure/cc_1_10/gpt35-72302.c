//FormAI DATASET v1.0 Category: System process viewer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAX_PATH_LEN 1024
#define MAX_BUF_SIZE 2048

int isdigit_str(const char *str) {
    int len = strlen(str);
    int i;
    for (i = 0; i < len; i++) {
        if (!(str[i] >= '0' && str[i] <= '9')) {
            return 0;
        }
    }
    return 1;
}

void read_cmdline(int pid, char *cmdline, int len) {
    char path[MAX_PATH_LEN] = {0};
    snprintf(path, MAX_PATH_LEN, "/proc/%d/cmdline", pid);
    int fd = open(path, O_RDONLY);
    if (fd != -1) {
        ssize_t nread = read(fd, cmdline, len - 1);
        if (nread > 0) {
            cmdline[nread] = '\0';
        }
        close(fd);
    }
}

void read_stat(int pid, char *stat) {
    char path[MAX_PATH_LEN] = {0};
    snprintf(path, MAX_PATH_LEN, "/proc/%d/stat", pid);
    int fd = open(path, O_RDONLY);
    if (fd != -1) {
        ssize_t nread = read(fd, stat, MAX_BUF_SIZE - 1);
        if (nread > 0) {
            stat[nread] = '\0';
        }
        close(fd);
    }
}

int main(int argc, char *argv[]) {
    DIR *dir = opendir("/proc");
    struct dirent *ent;
    while ((ent = readdir(dir)) != NULL) {
        if (isdigit_str(ent->d_name)) {
            int pid = atoi(ent->d_name);
            char cmdline[MAX_BUF_SIZE] = {0};
            char stat[MAX_BUF_SIZE] = {0};
            read_cmdline(pid, cmdline, MAX_BUF_SIZE);
            read_stat(pid, stat);
            printf("PID: %d, CMD: %s, STAT: %s\n", pid, cmdline, stat);
        }
     }
     closedir(dir);
     return 0;
}