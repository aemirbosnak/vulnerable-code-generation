//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 256

typedef struct {
    unsigned long utime; /* CPU time spent in user mode */
    unsigned long stime; /* CPU time spent in kernel mode */
} cpu_usage_t;

static double calculate_cpu_usage(cpu_usage_t *old, cpu_usage_t *new) {
    unsigned long total_time = (new->utime + new->stime) - (old->utime + old->stime);
    unsigned long cpu_time = new->stime - old->stime;

    return ((cpu_time * 100.0) / total_time);
}

static void parse_proc_stat(cpu_usage_t *usage) {
    FILE *fp;
    char buffer[BUFFER_SIZE], *p;
    int count = 0;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    fgets(buffer, sizeof(buffer), fp);

    fclose(fp);

    p = strtok(buffer, " ");
    while (p != NULL) {
        p = strtok(NULL, " ");
        count++;

        switch(count) {
            case 1:
                break;
            case 2:
                usage->utime = strtoul(p, NULL, 10);
                break;
            case 3:
                usage->stime = strtoul(p, NULL, 10);
                break;
            default:
                return;
        }
    }
}

int main(int argc, char *argv[]) {
    cpu_usage_t old_usage, new_usage;
    double usage;
    int duration;

    if (argc < 2) {
        printf("Usage: %s [duration]\n", argv[0]);
        return EXIT_FAILURE;
    }

    duration = atoi(argv[1]);

    if (duration <= 0) {
        printf("Duration must be a positive integer.\n");
        return EXIT_FAILURE;
    }

    memset(&old_usage, 0, sizeof(cpu_usage_t));
    parse_proc_stat(&old_usage);

    while (duration--) {
        sleep(1);
        memset(&new_usage, 0, sizeof(cpu_usage_t));
        parse_proc_stat(&new_usage);
        usage = calculate_cpu_usage(&old_usage, &new_usage);
        printf("CPU usage: %.2f%%\n", usage);
        old_usage = new_usage;
    }

    return EXIT_SUCCESS;
}