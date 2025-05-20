//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define MAX_CPUS 64
#define CPUSTATS_FILE "/proc/stat"

typedef struct {
    long total;
    long idle;
    long iowait;
} cpu_stats;

static cpu_stats prev_cpu_stats[MAX_CPUS];
static cpu_stats curr_cpu_stats[MAX_CPUS];
static int num_cpus;

void read_cpu_stats(cpu_stats *stats) {
    FILE *fp;
    char buf[1024];
    long user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;

    fp = fopen(CPUSTATS_FILE, "r");
    if(fp == NULL) {
        fprintf(stderr, "Error opening file %s: %s\n", CPUSTATS_FILE, strerror(errno));
        exit(EXIT_FAILURE);
    }

    /* read first line */
    fgets(buf, sizeof(buf), fp);
    sscanf(buf, "cpu %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld", 
           &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);

    stats->total = user + nice + system + idle + iowait + irq + softirq + steal + guest + guest_nice;
    stats->idle = idle;
    stats->iowait = iowait;

    /* read subsequent lines */
    int i = 0;
    while(fgets(buf, sizeof(buf), fp) != NULL && i < num_cpus) {
        sscanf(buf, "cpu%d %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld",
               &i, &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest);

        curr_cpu_stats[i].total = user + nice + system + idle + iowait + irq + softirq + steal + guest;
        curr_cpu_stats[i].idle = idle;
        curr_cpu_stats[i].iowait = iowait;
    }

    fclose(fp);
}

void print_cpu_stats() {
    for(int i = 0; i < num_cpus; i++) {
        long prev_used = prev_cpu_stats[i].total - prev_cpu_stats[i].idle - prev_cpu_stats[i].iowait;
        long curr_used = curr_cpu_stats[i].total - curr_cpu_stats[i].idle - curr_cpu_stats[i].iowait;

        float usage = ((float)(curr_used - prev_used) / (float)(curr_cpu_stats[i].total - prev_cpu_stats[i].total)) * 100;

        printf("CPU%d Usage: %.2f%%\n", i, usage);
    }
}

int main() {
    FILE *fp;
    char buf[1024];

    /* determine number of CPUs */
    fp = fopen(CPUSTATS_FILE, "r");
    if(fp == NULL) {
        fprintf(stderr, "Error opening file %s: %s\n", CPUSTATS_FILE, strerror(errno));
        exit(EXIT_FAILURE);
    }

    fgets(buf, sizeof(buf), fp);
    while(fgets(buf, sizeof(buf), fp) != NULL && num_cpus < MAX_CPUS) {
        num_cpus++;
    }

    fclose(fp);

    while(1) {
        read_cpu_stats(prev_cpu_stats);
        sleep(1);
        read_cpu_stats(curr_cpu_stats);
        print_cpu_stats();
        memcpy(prev_cpu_stats, curr_cpu_stats, sizeof(curr_cpu_stats));
    }

    return 0;
}