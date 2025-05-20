//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define CPU_FILE "/proc/stat"

int main() {
    char line[256];
    FILE* cpu_file = fopen(CPU_FILE, "r");

    if (cpu_file == NULL)
        perror("Could not open file!"), exit(EXIT_FAILURE);

    unsigned long int user_time = 0, nice_time = 0, system_time = 0, idle_time = 0, iowait_time = 0, irq_time = 0, softirq_time = 0, steal_time = 0, guest_time = 0, guest_nice_time = 0;
    unsigned long int prev_user_time = 0, prev_nice_time = 0, prev_system_time = 0, prev_idle_time = 0, prev_iowait_time = 0, prev_irq_time = 0, prev_softirq_time = 0, prev_steal_time = 0, prev_guest_time = 0, prev_guest_nice_time = 0;

    if (fgets(line, sizeof(line), cpu_file) == NULL)
        perror("Could not read file!"), exit(EXIT_FAILURE);

    if (strstr(line, "cpu") == NULL)
        perror("Could not parse file!"), exit(EXIT_FAILURE);

    sscanf(line, "%*s %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu", &prev_user_time, &prev_nice_time, &prev_system_time, &prev_idle_time, &prev_iowait_time, &prev_irq_time, &prev_softirq_time, &prev_steal_time, &prev_guest_time, &prev_guest_nice_time);

    fclose(cpu_file);

    while (1) {
        cpu_file = fopen(CPU_FILE, "r");

        if (cpu_file == NULL) 
            perror("Could not open file!"), exit(EXIT_FAILURE);

        if (fgets(line, sizeof(line), cpu_file) == NULL)
            perror("Could not read file!"), exit(EXIT_FAILURE);

        if (strstr(line, "cpu") == NULL)
            perror("Could not parse file!"), exit(EXIT_FAILURE);

        sscanf(line, "%*s %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu", &user_time, &nice_time, &system_time, &idle_time, &iowait_time, &irq_time, &softirq_time, &steal_time, &guest_time, &guest_nice_time);

        unsigned long int prev_total = prev_user_time + prev_nice_time + prev_system_time + prev_idle_time + prev_iowait_time + prev_irq_time + prev_softirq_time + prev_steal_time + prev_guest_time + prev_guest_nice_time;
        unsigned long int total = user_time + nice_time + system_time + idle_time + iowait_time + irq_time + softirq_time + steal_time + guest_time + guest_nice_time;

        unsigned long int diff_idle = idle_time - prev_idle_time;
        unsigned long int diff_total = total - prev_total;

        float usage = (100.0f * (diff_total - diff_idle)) / diff_total;

        printf("CPU usage: %.2f%%\n", usage);

        prev_user_time = user_time;
        prev_nice_time = nice_time;
        prev_system_time = system_time;
        prev_idle_time = idle_time;
        prev_iowait_time = iowait_time;
        prev_irq_time = irq_time;
        prev_softirq_time = softirq_time;
        prev_steal_time = steal_time;
        prev_guest_time = guest_time;
        prev_guest_nice_time = guest_nice_time;

        fclose(cpu_file);

        sleep(1);
    } 

    return 0;
}