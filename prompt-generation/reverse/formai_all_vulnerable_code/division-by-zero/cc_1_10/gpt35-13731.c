//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void print_cpu_usage() {
    FILE *file_pointer;
    char buffer[1024];
    char line[256];
    char *cpu;
    int user, nice, sys, idle, iowait, irq, softirq, steal, guest, guest_nice;
    int prev_idle = 0, prev_total = 0;
    int idle_difference, total_difference, percentage_cpu_usage;

    file_pointer = fopen("/proc/stat", "r");
    if (file_pointer == NULL) {
        printf("Error: Unable to open /proc/stat\n");
        exit(EXIT_FAILURE);
    }

    fgets(buffer, sizeof(buffer), file_pointer); // Read in first line of file
    cpu = strtok(buffer, " ");
    user = atoi(strtok(NULL, " "));
    nice = atoi(strtok(NULL, " "));
    sys = atoi(strtok(NULL, " "));
    idle = atoi(strtok(NULL, " "));
    iowait = atoi(strtok(NULL, " "));
    irq = atoi(strtok(NULL, " "));
    softirq = atoi(strtok(NULL, " "));
    steal = atoi(strtok(NULL, " "));
    guest = atoi(strtok(NULL, " "));
    guest_nice = atoi(strtok(NULL, " "));

    int total = user + nice + sys + idle + iowait + irq + softirq + steal;

    idle_difference = idle - prev_idle;
    total_difference = total - prev_total;

    percentage_cpu_usage = 100 * (total_difference - idle_difference) / total_difference;

    printf("CPU Usage: %d %%\n", percentage_cpu_usage);

    prev_idle = idle;
    prev_total = total;

    fclose(file_pointer);
}

int main() {
    printf("CPU Usage Monitor\n");
    while (1) {
        print_cpu_usage();
        sleep(1);
    }
    return 0;
}