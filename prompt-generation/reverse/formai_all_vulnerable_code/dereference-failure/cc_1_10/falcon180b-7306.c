//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define BUF_SIZE 1024

#define TOTAL_CPU "cpu"
#define TOTAL_MEM "memory"

void get_cpu_usage(double *usage) {
    FILE *fp;
    char buf[BUF_SIZE];
    int n;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open /proc/stat: %s\n", strerror(errno));
        exit(1);
    }

    while ((n = fread(buf, sizeof(char), BUF_SIZE, fp)) > 0) {
        char *p = strstr(buf, TOTAL_CPU);
        if (p!= NULL) {
            p += strlen(TOTAL_CPU);
            n = sscanf(p, "%lf", usage);
            break;
        }
    }

    fclose(fp);
}

void get_mem_usage(double *usage) {
    FILE *fp;
    char buf[BUF_SIZE];
    int n;

    fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open /proc/meminfo: %s\n", strerror(errno));
        exit(1);
    }

    while ((n = fread(buf, sizeof(char), BUF_SIZE, fp)) > 0) {
        char *p = strstr(buf, TOTAL_MEM);
        if (p!= NULL) {
            p += strlen(TOTAL_MEM);
            n = sscanf(p, "%lf", usage);
            break;
        }
    }

    fclose(fp);
}

int main(int argc, char **argv) {
    double cpu_usage, mem_usage;

    get_cpu_usage(&cpu_usage);
    get_mem_usage(&mem_usage);

    printf("CPU Usage: %.2f%%\n", cpu_usage);
    printf("Memory Usage: %.2f%%\n", mem_usage);

    return 0;
}