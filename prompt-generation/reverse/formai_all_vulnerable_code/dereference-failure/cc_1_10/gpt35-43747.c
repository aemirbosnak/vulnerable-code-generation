//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RUNCMD "ps -p %d -o %%cpu,rss"

/**
 * A function that returns the current RAM usage of a process specified by PID.
 * This function uses the system command 'ps' to retrieve the RAM usage.
 */
double get_ram_usage(int pid) {
    char cmd[256];
    char buffer[1024];
    double cpu_usage, ram_usage;
    int err;
 
    // Generate the command to retrieve RAM usage for the specified PID
    sprintf(cmd, RUNCMD, pid);

    // Open the command and read the output
    FILE* fp = popen(cmd, "r");
    if (fp == NULL) {
        printf("Failed to execute command: %s\n", cmd);
        return -1;
    }
    if (fgets(buffer, sizeof(buffer), fp) == NULL) {
        printf("Failed to read output of command: %s\n", cmd);
        pclose(fp);
        return -1;
    }

    // Parse the output for RAM usage
    err = sscanf(buffer, "%lf %lf", &cpu_usage, &ram_usage);
    if (err != 2) {
        printf("Failed to parse output of command: %s\n", cmd);
        pclose(fp);
        return -1;
    }

    // Close the command and return the RAM usage
    pclose(fp);
    return ram_usage;
}

/**
 * A function that recursively monitors the RAM usage of a specified process.
 * The function runs until the process is terminated or the user interrupts the program.
 * The function prints the current RAM usage every second.
 */
void monitor_ram_usage(int pid) {
    double ram_usage;

    // Get the initial RAM usage for the process
    ram_usage = get_ram_usage(pid);
    if (ram_usage == -1) {
        printf("Failed to retrieve RAM usage for process %d\n", pid);
        return;
    }
    printf("RAM usage for process %d: %lf MB\n", pid, ram_usage / 1024.0);

    // Wait for 1 second and check RAM usage again
    sleep(1);
    ram_usage = get_ram_usage(pid);
    while (ram_usage != -1) {
        printf("RAM usage for process %d: %lf MB\n", pid, ram_usage / 1024.0);

        // Recursively call this function to check RAM usage again
        monitor_ram_usage(pid);

        // Wait for 1 second and check RAM usage again
        sleep(1);
        ram_usage = get_ram_usage(pid);
    }
}

int main(int argc, char** argv) {
    int pid;

    // Get the PID of the process to monitor
    if (argc != 2) {
        printf("Usage: %s <pid>\n", argv[0]);
        return -1;
    }
    pid = atoi(argv[1]);
    if (pid <= 0) {
        printf("Invalid PID specified\n");
        return -1;
    }

    // Monitor the RAM usage of the specified process recursively
    monitor_ram_usage(pid);

    return 0;
}