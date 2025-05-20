//FormAI DATASET v1.0 Category: System process viewer ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUF_SIZE 1024

void printColumnHeader() {
    printf("%-10s %-20s %-10s %-10s\n", "PID", "Name", "Status", "Memory");
}

int main() {
    DIR *dir;
    struct dirent *entry;
    char path[BUF_SIZE], buf[BUF_SIZE], state;
    pid_t pid;
    int fd, n, vmsize;
    long hertz = sysconf(_SC_CLK_TCK);

    printColumnHeader();

    dir = opendir("/proc");
    if (!dir) {
        perror("opendir(/proc)");
        return 1;
    }

    while ((entry = readdir(dir))) {
        if (!isdigit(*entry->d_name)) {
            continue;
        }

        pid = atoi(entry->d_name);
        sprintf(path, "/proc/%d/stat", pid);
        fd = open(path, O_RDONLY);
        if (fd == -1) {
            perror(path);
            continue;
        }

        n = read(fd, buf, BUF_SIZE);
        if (n <= 0) {
            perror(path);
            close(fd);
            continue;
        }
        close(fd);

        buf[n] = '\0';
        sscanf(buf, "%*d %*s %c", &state);

        sprintf(path, "/proc/%d/statm", pid);
        fd = open(path, O_RDONLY);
        if (fd == -1) {
            perror(path);
            continue;
        }

        n = read(fd, buf, BUF_SIZE);
        if (n <= 0) {
            perror(path);
            close(fd);
            continue;
        }
        close(fd);

        buf[n] = '\0';
        sscanf(buf, "%d", &vmsize);

        printf("%-10d %-20s %-10c %-10ld\n", pid, entry->d_name, state, (vmsize * 1024) / hertz);
    }

    closedir(dir);
    return 0;
}