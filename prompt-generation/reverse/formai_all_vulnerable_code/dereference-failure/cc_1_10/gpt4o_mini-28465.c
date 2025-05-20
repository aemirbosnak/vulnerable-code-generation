//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define LOG_FILE "/var/log/system_monitor.log"
#define CPU_INFO_FILE "/proc/stat"
#define MEM_INFO_FILE "/proc/meminfo"
#define DISK_INFO_FILE "/proc/diskstats"
#define INTERVAL 5

void log_event(const char *message) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if(!log_file) {
        perror("Failed to open log file");
        exit(EXIT_FAILURE);
    }
    time_t now = time(NULL);
    fprintf(log_file, "[%s] %s\n", ctime(&now), message);
    fclose(log_file);
}

void monitor_cpu() {
    FILE *cpu_file = fopen(CPU_INFO_FILE, "r");
    if(!cpu_file) {
        perror("Failed to open CPU info file");
        return;
    }
    char buffer[256];
    if(fgets(buffer, sizeof(buffer), cpu_file) != NULL) {
        log_event(buffer);
    }
    fclose(cpu_file);
}

void monitor_memory() {
    FILE *mem_file = fopen(MEM_INFO_FILE, "r");
    if(!mem_file) {
        perror("Failed to open memory info file");
        return;
    }
    char buffer[256];
    while(fgets(buffer, sizeof(buffer), mem_file) != NULL) {
        log_event(buffer);
    }
    fclose(mem_file);
}

void monitor_disk() {
    FILE *disk_file = fopen(DISK_INFO_FILE, "r");
    if(!disk_file) {
        perror("Failed to open disk info file");
        return;
    }
    char buffer[256];
    while(fgets(buffer, sizeof(buffer), disk_file) != NULL) {
        log_event(buffer);
    }
    fclose(disk_file);
}

void usage() {
    printf("System Monitor\n");
    printf("Usage: system_monitor\n");
    printf("This program will log CPU, Memory, and Disk usage information.\n");
    printf("Logs are saved to %s\n", LOG_FILE);
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        usage();
        return EXIT_FAILURE;
    }

    // Continuous monitoring every INTERVAL seconds
    while (1) {
        monitor_cpu();
        monitor_memory();
        monitor_disk();
        sleep(INTERVAL);
    }

    return EXIT_SUCCESS;
}