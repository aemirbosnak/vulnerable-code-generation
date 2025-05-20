//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define CPU_USAGE_FILE "/proc/stat"

typedef struct {
    int user;
    int nice;
    int system;
    int idle;
} cpu_stats_t;

int main(int argc, char *argv[]) {
    FILE *fp = NULL;
    char line[256];
    cpu_stats_t cpu_stats = {0};
    int total_cpu_usage = 0;
    int prev_total_cpu_usage = 0;
    int sleep_time = 1;

    if (argc!= 2) {
        printf("Usage: %s <sleep_time_in_seconds>\n", argv[0]);
        exit(1);
    }

    sleep_time = atoi(argv[1]);

    fp = fopen(CPU_USAGE_FILE, "r");
    if (fp == NULL) {
        printf("Error opening %s\n", CPU_USAGE_FILE);
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (strncmp(line, "cpu", 3) == 0) {
            sscanf(line, "cpu%*s%d%*s%d%*s%d%*s%d",
                   &cpu_stats.user, &cpu_stats.nice,
                   &cpu_stats.system, &cpu_stats.idle);
            total_cpu_usage = cpu_stats.user + cpu_stats.nice + cpu_stats.system + cpu_stats.idle;
            if (prev_total_cpu_usage > 0) {
                printf("CPU Usage: %.2f%%\n", (float)((total_cpu_usage - prev_total_cpu_usage) * 100.0) / sleep_time);
            }
            prev_total_cpu_usage = total_cpu_usage;
        }
    }

    fclose(fp);

    return 0;
}