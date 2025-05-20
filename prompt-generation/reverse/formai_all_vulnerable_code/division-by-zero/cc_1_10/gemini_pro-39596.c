//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Get CPU usage
int get_cpu_usage() {
    // Open the proc/stat file
    FILE *fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    // Read the first line of the file
    char line[1024];
    if (fgets(line, sizeof(line), fp) == NULL) {
        perror("fgets");
        fclose(fp);
        return -1;
    }

    // Close the file
    fclose(fp);

    // Parse the line
    char *token;
    int user, nice, system, idle, iowait, irq, softirq, steal;
    token = strtok(line, " ");
    token = strtok(NULL, " ");
    user = atoi(token);
    token = strtok(NULL, " ");
    nice = atoi(token);
    token = strtok(NULL, " ");
    system = atoi(token);
    token = strtok(NULL, " ");
    idle = atoi(token);
    token = strtok(NULL, " ");
    iowait = atoi(token);
    token = strtok(NULL, " ");
    irq = atoi(token);
    token = strtok(NULL, " ");
    softirq = atoi(token);
    token = strtok(NULL, " ");
    steal = atoi(token);

    // Calculate the CPU usage
    int total = user + nice + system + idle + iowait + irq + softirq + steal;
    int idle_total = idle + iowait;
    int active_total = total - idle_total;
    int usage = (active_total * 100) / total;

    // Return the CPU usage
    return usage;
}

int main() {
    // Get the CPU usage
    int usage = get_cpu_usage();

    // Print the CPU usage
    printf("CPU usage: %d%%\n", usage);

    return 0;
}