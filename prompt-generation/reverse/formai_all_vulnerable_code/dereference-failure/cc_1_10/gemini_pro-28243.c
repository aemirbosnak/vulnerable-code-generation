//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

int main() {
    // Open the /proc/stat file
    int fd = open("/proc/stat", O_RDONLY);
    if (fd == -1) {
        perror("open failed");
        return EXIT_FAILURE;
    }

    // Read the first line of the file
    char buf[1024];
    ssize_t bytes_read = read(fd, buf, sizeof(buf));
    if (bytes_read == -1) {
        perror("read failed");
        close(fd);
        return EXIT_FAILURE;
    }

    // Close the file
    close(fd);

    // Parse the first line of the file
    char *ptr = buf;
    char *endptr;
    unsigned long long user, nice, system, idle, iowait, irq, softirq;

    errno = 0;
    user = strtoull(ptr, &endptr, 10);
    if (errno != 0) {
        perror("strtoull failed");
        return EXIT_FAILURE;
    }
    ptr = endptr;

    errno = 0;
    nice = strtoull(ptr, &endptr, 10);
    if (errno != 0) {
        perror("strtoull failed");
        return EXIT_FAILURE;
    }
    ptr = endptr;

    errno = 0;
    system = strtoull(ptr, &endptr, 10);
    if (errno != 0) {
        perror("strtoull failed");
        return EXIT_FAILURE;
    }
    ptr = endptr;

    errno = 0;
    idle = strtoull(ptr, &endptr, 10);
    if (errno != 0) {
        perror("strtoull failed");
        return EXIT_FAILURE;
    }
    ptr = endptr;

    errno = 0;
    iowait = strtoull(ptr, &endptr, 10);
    if (errno != 0) {
        perror("strtoull failed");
        return EXIT_FAILURE;
    }
    ptr = endptr;

    errno = 0;
    irq = strtoull(ptr, &endptr, 10);
    if (errno != 0) {
        perror("strtoull failed");
        return EXIT_FAILURE;
    }
    ptr = endptr;

    errno = 0;
    softirq = strtoull(ptr, &endptr, 10);
    if (errno != 0) {
        perror("strtoull failed");
        return EXIT_FAILURE;
    }

    // Calculate the total CPU usage
    unsigned long long total_cpu_usage = user + nice + system + idle + iowait + irq + softirq;

    // Calculate the idle CPU usage
    unsigned long long idle_cpu_usage = idle;

    // Calculate the CPU usage percentage
    double cpu_usage_percentage = 100.0 * (total_cpu_usage - idle_cpu_usage) / total_cpu_usage;

    // Print the CPU usage percentage
    printf("CPU usage: %.2f%%\n", cpu_usage_percentage);

    return EXIT_SUCCESS;
}