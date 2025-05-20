//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 256

// Function prototype declarations
void print_cpu_usage();
void read_resource_file(FILE *file);
void process_file(const char *filepath);

int main() {
    while (1) {
        print_cpu_usage();
        sleep(2); // Delay for 2 seconds before the next read
    }
    return 0;
}

void print_cpu_usage() {
    const char *proc_stat_file = "/proc/stat";
    process_file(proc_stat_file);
}

void process_file(const char *filepath) {
    FILE *file = fopen(filepath, "r");
    if (!file) {
        perror("Could not open the file");
        return;
    }
    read_resource_file(file);
    fclose(file);
}

void read_resource_file(FILE *file) {
    char line[MAX_LINE_LENGTH];
    long user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
    
    if (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, " ");
        // Skip the first token which is "cpu"
        token = strtok(NULL, " ");
        
        // Read CPU usage values
        user = strtol(token, NULL, 10);
        token = strtok(NULL, " ");
        nice = strtol(token, NULL, 10);
        token = strtok(NULL, " ");
        system = strtol(token, NULL, 10);
        token = strtok(NULL, " ");
        idle = strtol(token, NULL, 10);
        token = strtok(NULL, " ");
        iowait = strtol(token, NULL, 10);
        token = strtok(NULL, " ");
        irq = strtol(token, NULL, 10);
        token = strtok(NULL, " ");
        softirq = strtol(token, NULL, 10);
        token = strtok(NULL, " ");
        steal = strtol(token, NULL, 10);
        token = strtok(NULL, " ");
        guest = strtol(token, NULL, 10);
        token = strtok(NULL, " ");
        guest_nice = strtol(token, NULL, 10);

        // Calculate total CPU time
        long total_cpu = user + nice + system + idle + iowait + irq + softirq + steal;
        long total_idle = idle + iowait;

        // Calculate usage percentage
        float usage = ((total_cpu - total_idle) / (float)total_cpu) * 100;

        // Display the CPU usage
        printf("CPU Usage: %.2f%%\n", usage);
        
        // Recursive call for continuous monitoring
        read_resource_file(file);
    }
}