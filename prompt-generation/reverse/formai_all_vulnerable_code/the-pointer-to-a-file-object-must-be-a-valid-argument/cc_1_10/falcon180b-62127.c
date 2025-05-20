//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/statvfs.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

// Function to get the current RAM usage
long get_ram_usage() {
    FILE* file = fopen("/proc/meminfo", "r");
    char line[64];
    long ram_usage = 0;

    while (fgets(line, sizeof(line), file)!= NULL) {
        if (strncmp(line, "MemTotal:", 9) == 0) {
            char* token = strtok(line, " ");
            while (token!= NULL) {
                ram_usage += atoi(token);
                token = strtok(NULL, " ");
            }
        }
    }

    fclose(file);
    return ram_usage;
}

// Function to get the current disk usage
long get_disk_usage() {
    struct statvfs buf;
    if (statvfs("/", &buf) == 0) {
        return buf.f_blocks * buf.f_frsize;
    }
    return 0;
}

// Function to get the current CPU usage
long get_cpu_usage() {
    FILE* file = fopen("/proc/stat", "r");
    char line[64];
    long cpu_usage = 0;

    while (fgets(line, sizeof(line), file)!= NULL) {
        if (strncmp(line, "cpu ", 4) == 0) {
            char* token = strtok(line, " ");
            while (token!= NULL) {
                cpu_usage += atoi(token);
                token = strtok(NULL, " ");
            }
        }
    }

    fclose(file);
    return cpu_usage;
}

// Function to print the system information
void print_system_info() {
    printf("RAM Usage: %ld KB\n", get_ram_usage() / 1024);
    printf("Disk Usage: %ld KB\n", get_disk_usage() / 1024);
    printf("CPU Usage: %ld %%\n", get_cpu_usage() / (get_cpu_usage() + (long)sysconf(_SC_CLK_TCK)) * 100);
}

// Main function
int main() {
    print_system_info();
    return 0;
}