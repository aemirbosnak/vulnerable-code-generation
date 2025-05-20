//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/statvfs.h>

#define MEGABYTE (1024 * 1024)

void get_memory_usage(double *total, double *free) {
    struct statvfs stat;
    statvfs("/", &stat);
    *total = (double)stat.f_blocks * stat.f_frsize;
    *free = (double)stat.f_bavail * stat.f_frsize;
}

void get_cpu_usage(double *user, double *system, double *idle) {
    FILE *fp;
    char line[100];
    fp = fopen("/proc/stat", "r");
    fgets(line, 100, fp);
    sscanf(line, "%*s %*s %*s %*s %*s %*s %lu %lu %lu", &user, &system, &idle);
    fclose(fp);
}

void get_network_usage(double *tx, double *rx) {
    FILE *fp;
    char line[100];
    fp = fopen("/proc/net/dev", "r");
    while (fgets(line, 100, fp)) {
        sscanf(line, "%*s %*s %*s %*s %*s %*s %*s %*s %*s %lu %lu", &tx, &rx);
        break;
    }
    fclose(fp);
}

int main() {
    double total, free, user, system, idle, tx, rx;
    int i;
    for (i = 0; i < 10; i++) {
        get_memory_usage(&total, &free);
        get_cpu_usage(&user, &system, &idle);
        get_network_usage(&tx, &rx);
        printf("Total memory: %.2f MB\n", total / MEGABYTE);
        printf("Free memory: %.2f MB\n", free / MEGABYTE);
        printf("CPU usage: user: %.2f%, system: %.2f%, idle: %.2f%\n", user * 100, system * 100, idle * 100);
        printf("Network usage: TX: %.2f KB, RX: %.2f KB\n\n", tx / 1024, rx / 1024);
        sleep(1);
    }
    return 0;
}