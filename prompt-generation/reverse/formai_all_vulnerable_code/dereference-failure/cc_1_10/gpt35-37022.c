//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LINE_LENGTH 1024

int get_cpu_usage() {
    int fd;
    unsigned long long idle_ticks, total_ticks;
    unsigned long long prev_idle_ticks = 0, prev_total_ticks = 0;
    unsigned long long diff_idle_ticks, diff_total_ticks;
    char line[MAX_LINE_LENGTH + 1];
    char *endptr;

    fd = open("/proc/stat", O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Failed to open /proc/stat\n");
        exit(EXIT_FAILURE);
    }

    if (read(fd, line, MAX_LINE_LENGTH) == -1) {
        fprintf(stderr, "Failed to read /proc/stat\n");
        exit(EXIT_FAILURE);
    }

    close(fd);

    if (strncmp(line, "cpu ", 4) != 0) {
        fprintf(stderr, "Failed to find cpu line in /proc/stat\n");
        exit(EXIT_FAILURE);
    }

    endptr = line + 4;
    while (*endptr == ' ') {
        endptr++;
    }

    total_ticks = strtoull(endptr, &endptr, 10);
    endptr++;
    idle_ticks = strtoull(endptr, &endptr, 10);
    endptr++;
    prev_idle_ticks = idle_ticks;
    prev_total_ticks = total_ticks;

    sleep(1);

    fd = open("/proc/stat", O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Failed to open /proc/stat\n");
        exit(EXIT_FAILURE);
    }

    if (read(fd, line, MAX_LINE_LENGTH) == -1) {
        fprintf(stderr, "Failed to read /proc/stat\n");
        exit(EXIT_FAILURE);
    }

    close(fd);

    if (strncmp(line, "cpu ", 4) != 0) {
        fprintf(stderr, "Failed to find cpu line in /proc/stat\n");
        exit(EXIT_FAILURE);
    }

    endptr = line + 4;
    while (*endptr == ' ') {
        endptr++;
    }

    total_ticks = strtoull(endptr, &endptr, 10);
    endptr++;
    idle_ticks = strtoull(endptr, &endptr, 10);

    diff_idle_ticks = idle_ticks - prev_idle_ticks;
    diff_total_ticks = total_ticks - prev_total_ticks;

    return (int) (100 * (1.0 - ((double) diff_idle_ticks) / diff_total_ticks));
}

int main() {
    int cpu_usage = get_cpu_usage();
    printf("CPU usage: %d%%\n", cpu_usage);
    return 0;
}