//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_CPU_COUNT 64

struct cpu_info {
    long long user;
    long long nice;
    long long system;
    long long idle;
    long long iowait;
    long long irq;
    long long softirq;
};

struct cpu_data {
    struct cpu_info prev;
    struct cpu_info current;
};

struct cpu_percentage {
    double user;
    double nice;
    double system;
    double idle;
    double iowait;
    double irq;
    double softirq;
};

int get_cpu_count() {
    FILE* fp = fopen("/proc/cpuinfo", "r");
    int count = 0;
    char line[1024];
    while (fgets(line, 1024, fp)) {
        if (strstr(line, "processor")) count++;
    }
    fclose(fp);
    return count;
}

void read_cpu_data(struct cpu_data* cpus, int cpu_count) {
    FILE* fp = fopen("/proc/stat", "r");
    char line[1024];
    int i = 0;
    while (i < cpu_count) {
        if (!fgets(line, 1024, fp)) break;
        if (strncmp(line, "cpu", 3)) break;
        sscanf(line + 5, "%lld %lld %lld %lld %lld %lld %lld",
                &cpus[i].current.user,
                &cpus[i].current.nice,
                &cpus[i].current.system,
                &cpus[i].current.idle,
                &cpus[i].current.iowait,
                &cpus[i].current.irq,
                &cpus[i].current.softirq);
        i++;
    }
    fclose(fp);
}

void calculate_cpu_percentage(struct cpu_percentage* percentage, struct cpu_data* cpus, int cpu_count) {
    struct cpu_info diff;
    int i;
    for (i = 0; i < cpu_count; i++) {
        diff.user = cpus[i].current.user - cpus[i].prev.user;
        diff.nice = cpus[i].current.nice - cpus[i].prev.nice;
        diff.system = cpus[i].current.system - cpus[i].prev.system;
        diff.idle = cpus[i].current.idle - cpus[i].prev.idle;
        diff.iowait = cpus[i].current.iowait - cpus[i].prev.iowait;
        diff.irq = cpus[i].current.irq - cpus[i].prev.irq;
        diff.softirq = cpus[i].current.softirq - cpus[i].prev.softirq;

        double total_idle = diff.idle + diff.iowait;
        double total_non_idle = diff.user + diff.nice + diff.system + diff.irq + diff.softirq;

        percentage[i].user = (diff.user * 100.0) / (total_idle + total_non_idle);
        percentage[i].nice = (diff.nice * 100.0) / (total_idle + total_non_idle);
        percentage[i].system = (diff.system * 100.0) / (total_idle + total_non_idle);
        percentage[i].idle = (diff.idle * 100.0) / (total_idle + total_non_idle);
        percentage[i].iowait = (diff.iowait * 100.0) / (total_idle + total_non_idle);
        percentage[i].irq = (diff.irq * 100.0) / (total_idle + total_non_idle);
        percentage[i].softirq = (diff.softirq * 100.0) / (total_idle + total_non_idle);
    }
}

void print_cpu_percentage(struct cpu_percentage* percentage, int cpu_count) {
    printf("CPU      User   Nice System   Idle Iowait    IRQ SoftIRQ\n");
    int i;
    for (i = 0; i < cpu_count; i++) {
        printf("CPU %d %5.2f%% %5.2f%% %5.2f%% %5.2f%% %5.2f%% %5.2f%%\n",
                i,
                percentage[i].user,
                percentage[i].nice,
                percentage[i].system,
                percentage[i].idle,
                percentage[i].iowait,
                percentage[i].irq,
                percentage[i].softirq);
    }
}

int main() {
    int cpu_count = get_cpu_count();
    struct cpu_data* cpus = (struct cpu_data*)malloc(cpu_count * sizeof(struct cpu_data));
    struct cpu_percentage* percentage = (struct cpu_percentage*)malloc(cpu_count * sizeof(struct cpu_percentage));
    memset(cpus, 0, cpu_count * sizeof(struct cpu_data));
    read_cpu_data(cpus, cpu_count);
    usleep(1000000);
    read_cpu_data(cpus, cpu_count);
    calculate_cpu_percentage(percentage, cpus, cpu_count);
    print_cpu_percentage(percentage, cpu_count);
    free(cpus);
    free(percentage);
    return 0;
}