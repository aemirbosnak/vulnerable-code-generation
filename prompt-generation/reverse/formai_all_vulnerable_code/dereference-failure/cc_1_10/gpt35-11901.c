//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

#define REFRESH_RATE 1 //Refresh rate in seconds

void print_cpu_usage() {
    FILE* file;
    double cpu_usage = 0.0;
    char buffer[1024];

    file = fopen("/proc/stat", "r");

    if (!file) {
        printf("Error was encountered while opening /proc/stat");
        return;
    }

    fgets(buffer, sizeof(buffer), file);

    char* token = strtok(buffer, " ");
    double user = atoi(strtok(NULL, " "));
    double nice = atoi(strtok(NULL, " "));
    double system = atoi(strtok(NULL, " "));
    double idle = atoi(strtok(NULL, " "));
    double iowait = atoi(strtok(NULL, " "));
    double irq = atoi(strtok(NULL, " "));
    double softirq = atoi(strtok(NULL, " "));
    double steal = atoi(strtok(NULL, " "));

    fclose(file);

    double prev_idle = 0.0;
    double prev_total = 0.0;
    static int initialized = 0;

    if (initialized) {
        prev_idle = idle - prev_idle;
        prev_total = (user + nice + system + idle + iowait + irq + softirq + steal) - prev_total;

        cpu_usage = (prev_total - prev_idle) / prev_total * 100;
    }

    prev_idle = idle;
    prev_total = user + nice + system + idle + iowait + irq + softirq + steal;
    initialized = 1;

    printf("CPU usage: %.2f%%\n", cpu_usage);
}

int main() {
    while (1) {
        print_cpu_usage();
        sleep(REFRESH_RATE);
    }

    return 0;
}