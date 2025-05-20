//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void get_cpu_usage() {
    FILE *file;
    char buffer[256];

    file = fopen("/proc/stat", "r");
    if (file == NULL) {
        perror("Failed to open /proc/stat");
        return;
    }
    
    fgets(buffer, sizeof(buffer), file);
    fclose(file);

    unsigned long user, nice, system, idle;
    sscanf(buffer, "cpu %lu %lu %lu %lu", &user, &nice, &system, &idle);
    
    unsigned long total = user + nice + system + idle;
    unsigned long cpu_usage = (100 * (total - idle)) / total;

    printf("CPU Usage: %lu%%\n", cpu_usage);
}

void get_memory_usage() {
    FILE *file;
    char buffer[256];
    unsigned long total_memory, free_memory;
    
    file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        perror("Failed to open /proc/meminfo");
        return;
    }

    fgets(buffer, sizeof(buffer), file);
    sscanf(buffer, "MemTotal: %lu kB", &total_memory);
    fgets(buffer, sizeof(buffer), file);
    sscanf(buffer, "MemFree: %lu kB", &free_memory);
    fclose(file);

    unsigned long used_memory = total_memory - free_memory;
    printf("Memory Usage: %lu kB used (%.2f%%)\n", used_memory, (used_memory * 100.0) / total_memory);
}

void get_disk_usage() {
    FILE *file;
    char buffer[256];

    file = popen("df -h --total | tail -n 1", "r");
    if (file == NULL) {
        perror("Failed to run df command");
        return;
    }

    fgets(buffer, sizeof(buffer), file);
    pclose(file);

    char size[20], used[20], avail[20], use_percent[20];
    sscanf(buffer, "%*s %s %s %s %s", size, used, avail, use_percent);

    printf("Disk Usage: Total Size: %s, Used: %s, Available: %s, Usage: %s\n", size, used, avail, use_percent);
}

void get_uptime() {
    FILE *file;
    double uptime;

    file = fopen("/proc/uptime", "r");
    if (file == NULL) {
        perror("Failed to open /proc/uptime");
        return;
    }

    fscanf(file, "%lf", &uptime);
    fclose(file);

    int days = uptime / (24 * 3600);
    uptime -= days * (24 * 3600);
    int hours = uptime / 3600;
    uptime -= hours * 3600;
    int minutes = uptime / 60;

    printf("System Uptime: %d days, %d hours, %d minutes\n", days, hours, minutes);
}

int main() {
    printf("System Monitoring Tool\n");
    printf("=======================\n");
    
    get_cpu_usage();
    get_memory_usage();
    get_disk_usage();
    get_uptime();
    
    return 0;
}