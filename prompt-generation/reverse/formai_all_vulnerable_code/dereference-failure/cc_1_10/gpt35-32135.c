//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 100
#define MAX_LINE_SIZE 1024

double get_cpu_usage() {
    int fd;
    char buffer[BUFFER_SIZE];
    char cpu[BUFFER_SIZE];
    double user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
    double total_idle, total_non_idle;
    double total, percentage;

    fd = open("/proc/stat", O_RDONLY);
    read(fd, buffer, BUFFER_SIZE);

    sscanf(buffer, "%s %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", cpu, &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);

    close(fd);

    total_idle = idle + iowait;
    total_non_idle = user + nice + system + irq + softirq + steal;
    total = total_idle + total_non_idle;

    percentage = 100 * ((total - total_idle) / total);

    return percentage;
}

int main(int argc, char *argv[]) {
    int seconds = 5;
    int i;

    if (argc > 1) {
        seconds = atoi(argv[1]);
    }

    printf("Monitoring CPU usage every %d seconds...\n", seconds);

    for (i = 0; i < 10; i++) {
        printf("-");

        fflush(stdout);

        sleep(seconds);

        double cpu_usage = get_cpu_usage();

        printf("\r| CPU Usage: %.2f %% |", cpu_usage);

        fflush(stdout);
    }

    printf("\n");

    return 0;
}