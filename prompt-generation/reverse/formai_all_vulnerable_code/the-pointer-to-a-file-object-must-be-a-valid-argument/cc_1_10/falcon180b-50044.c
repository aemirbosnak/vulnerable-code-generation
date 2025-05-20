//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RAM_USAGE_FILE "/proc/meminfo"
#define MEMORY_UNIT "kB"

/* Function to get the total amount of RAM in the system */
unsigned long long get_total_ram() {
    FILE *fp = fopen(RAM_USAGE_FILE, "r");
    char line[1024];
    unsigned long long total_ram = 0;

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (strncmp(line, "MemTotal:", 9) == 0) {
            total_ram = strtoull(line + 9, NULL, 10);
            break;
        }
    }

    fclose(fp);
    return total_ram;
}

/* Function to get the current RAM usage */
unsigned long long get_current_ram_usage() {
    FILE *fp = fopen(RAM_USAGE_FILE, "r");
    char line[1024];
    unsigned long long current_ram_usage = 0;

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (strncmp(line, "MemAvailable:", 12) == 0) {
            current_ram_usage = strtoull(line + 12, NULL, 10);
            break;
        }
    }

    fclose(fp);
    return current_ram_usage;
}

/* Function to get the percentage of RAM usage */
double get_ram_usage_percentage(unsigned long long total_ram, unsigned long long current_ram_usage) {
    return ((double) current_ram_usage / (double) total_ram) * 100.0;
}

int main() {
    unsigned long long total_ram = get_total_ram();
    unsigned long long current_ram_usage = get_current_ram_usage();
    double ram_usage_percentage = get_ram_usage_percentage(total_ram, current_ram_usage);

    printf("Current RAM usage: %llu %s\n", current_ram_usage, MEMORY_UNIT);
    printf("Total RAM in the system: %llu %s\n", total_ram, MEMORY_UNIT);
    printf("RAM usage percentage: %.2f%%\n", ram_usage_percentage);

    return 0;
}