//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_LEN 1024

/* Function to display the CPU usage */
void display_cpu_usage(double cpu_usage) {
    printf("CPU Usage: %.2f%%\n", cpu_usage);
}

/* Function to read the CPU usage from /proc/stat */
double get_cpu_usage() {
    FILE *fp;
    char buf[BUF_LEN];
    double idle, total;
    int i, j;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error: Unable to open /proc/stat\n");
        return -1;
    }

    while (fgets(buf, BUF_LEN, fp)!= NULL) {
        if (strncmp(buf, "cpu ", 4) == 0) {
            sscanf(buf, "cpu %d %d %d %d", &i, &j, &idle, &total);
            break;
        }
    }

    fclose(fp);

    return (100 - ((idle + j) / total) * 100);
}

/* Main function */
int main(int argc, char *argv[]) {
    double cpu_usage;
    int interval;

    if (argc!= 3) {
        printf("Usage: %s <interval> <cpu_usage_threshold>\n", argv[0]);
        return 1;
    }

    interval = atoi(argv[1]);
    if (interval <= 0) {
        printf("Error: Invalid interval\n");
        return 1;
    }

    while (1) {
        cpu_usage = get_cpu_usage();
        if (cpu_usage < atoi(argv[2])) {
            printf("CPU usage is below threshold. Exiting...\n");
            break;
        }

        display_cpu_usage(cpu_usage);
        sleep(interval);
    }

    return 0;
}