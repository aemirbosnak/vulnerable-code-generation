//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/statvfs.h>
#include <unistd.h>
#include <fcntl.h>

#define MEMORY_LIMIT (1024 * 1024) // 1MB

struct statvfs vfs_stat;

void check_memory() {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("/proc/self/statm", "r");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }

    read = getline(&line, &len, fp);
    if (read <= 0) {
        perror("getline");
        exit(1);
    }

    fclose(fp);

    int size = atoi(line) * 4096;

    if (size > MEMORY_LIMIT) {
        printf("WARNING: The application is using too much memory (%d bytes).\n", size);
    } else {
        printf("The application is using %d bytes of memory.\n", size);
    }
}

void check_disk_space() {
    if (statvfs("/", &vfs_stat) == -1) {
        perror("statvfs");
        exit(1);
    }

    int free_space = vfs_stat.f_bavail * vfs_stat.f_frsize;

    if (free_space < (int)MEMORY_LIMIT) {
        printf("WARNING: The system has less than 1MB of free disk space.\n");
    } else {
        printf("The system has %d bytes of free disk space.\n", free_space);
    }
}

int main() {
    check_memory();
    check_disk_space();

    return 0;
}