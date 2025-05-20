//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage: %s <pid>\n", argv[0]);
        return 1;
    }

    int pid = atoi(argv[1]);
    char fd_path[256];
    snprintf(fd_path, 256, "/proc/%d/stat", pid);

    int fd = open(fd_path, O_RDONLY);
    if (fd < 0) {
        printf("Failed to open %s: %s\n", fd_path, strerror(errno));
        return 1;
    }

    char buffer[1024];
    ssize_t bytes_read;

    while (1) {
        bytes_read = read(fd, buffer, 1024);
        if (bytes_read <= 0) break;

        buffer[bytes_read] = '\0';
        char *p = strchr(buffer, ')');
        if (p == NULL) break;

        p++;
        char *q = strchr(p, ' ');
        if (q == NULL) break;

        q++;
        char *r = strchr(q, ' ');
        if (r == NULL) break;

        r++;
        double utime = atof(q) / sysconf(_SC_CLK_TCK);
        double stime = atof(r) / sysconf(_SC_CLK_TCK);
        printf("CPU Usage: %.2lf%%\n", (utime + stime) * 100);
        sleep(1);
    }

    close(fd);
    return 0;
}