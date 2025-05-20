//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256

typedef struct {
    long user;
    long nice;
    long system;
    long idle;
    long iowait;
    long irq;
    long softirq;
    long steal;
    long guest;
    long guest_nice;
} CpuInfo;

void getCpuInfo(CpuInfo *cpuInfo) {
    FILE *file = fopen("/proc/stat", "r");
    if (!file) {
        perror("Could not open /proc/stat");
        exit(EXIT_FAILURE);
    }
    
    char buffer[BUFFER_SIZE];
    if (fgets(buffer, BUFFER_SIZE, file) == NULL) {
        perror("Could not read CPU info");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    sscanf(buffer, "cpu %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld",
           &cpuInfo->user, 
           &cpuInfo->nice, 
           &cpuInfo->system, 
           &cpuInfo->idle, 
           &cpuInfo->iowait, 
           &cpuInfo->irq, 
           &cpuInfo->softirq,
           &cpuInfo->steal,
           &cpuInfo->guest,
           &cpuInfo->guest_nice);

    fclose(file);
}

void calculateCpuUsage(CpuInfo *previous, CpuInfo *current, double *usage) {
    long totalPrev = previous->user + previous->nice + previous->system + previous->idle + 
                    previous->iowait + previous->irq + previous->softirq + 
                    previous->steal;

    long totalCurr = current->user + current->nice + current->system + current->idle + 
                     current->iowait + current->irq + current->softirq + 
                     current->steal;

    long idlePrev = previous->idle;
    long idleCurr = current->idle;

    long totalDifference = totalCurr - totalPrev;
    long idleDifference = idleCurr - idlePrev;

    *usage = 100.0 * (1.0 - (double)idleDifference / (double)totalDifference);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interval in seconds>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int interval = atoi(argv[1]);
    if (interval <= 0) {
        fprintf(stderr, "Invalid interval: must be greater than 0\n");
        exit(EXIT_FAILURE);
    }

    CpuInfo previousCpuInfo, currentCpuInfo;

    // Get the initial CPU information
    getCpuInfo(&previousCpuInfo);

    while (1) {
        sleep(interval);  // Wait for the specified interval
        getCpuInfo(&currentCpuInfo);

        double cpuUsage;
        calculateCpuUsage(&previousCpuInfo, &currentCpuInfo, &cpuUsage);
        
        printf("CPU Usage: %.2f%%\n", cpuUsage);

        // Update previous CPU info for the next iteration
        previousCpuInfo = currentCpuInfo;
    }

    return 0;
}