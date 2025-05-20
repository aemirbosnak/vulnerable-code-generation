//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define SAMPLE_INTERVAL 1 // seconds
#define MAX_SAMPLES 10

void print_memory_usage() {
    struct sysinfo memInfo;
    sysinfo(&memInfo);

    long totalRAM = memInfo.totalram / (1024 * 1024);
    long freeRAM = memInfo.freeram / (1024 * 1024);
    long usedRAM = totalRAM - freeRAM;

    printf("Total RAM: %ld MB\n", totalRAM);
    printf("Used RAM: %ld MB\n", usedRAM);
    printf("Free RAM: %ld MB\n\n", freeRAM);
}

void display_usage_graph(long usedRAM, long totalRAM) {
    int percentage = (usedRAM * 100) / totalRAM;
    int barWidth = 50;
    int pos = (barWidth * percentage) / 100;

    printf("[");
    for (int i = 0; i < barWidth; i++) {
        if (i < pos) {
            printf("=");
        } else {
            printf(" ");
        }
    }
    printf("] %d%% used\n", percentage);
}

void record_memory_usage(long *usedRAMs, int *index) {
    struct sysinfo memInfo;
    sysinfo(&memInfo);
    
    long totalRAM = memInfo.totalram / (1024 * 1024);
    long usedRAM = (memInfo.totalram - memInfo.freeram) / (1024 * 1024);

    if (*index < MAX_SAMPLES) {
        usedRAMs[*index] = usedRAM;
        (*index)++;
    } else {
        // Shift sample array to make space for new sample
        for (int i = 1; i < MAX_SAMPLES; i++) {
            usedRAMs[i - 1] = usedRAMs[i];
        }
        usedRAMs[MAX_SAMPLES - 1] = usedRAM;
    }
}

void print_average_memory(long *usedRAMs, int count) {
    long totalUsage = 0;
    for (int i = 0; i < count; i++) {
        totalUsage += usedRAMs[i];
    }
    long averageUsage = totalUsage / count;
    printf("Average Used RAM over last %d samples: %ld MB\n", count, averageUsage);
}

int main() {
    long usedRAMs[MAX_SAMPLES] = {0};
    int index = 0;

    printf("RAM Usage Monitor\n");
    printf("==================\n");

    for (int i = 0; i < MAX_SAMPLES; i++) {
        print_memory_usage();
        
        sleep(SAMPLE_INTERVAL);
        
        record_memory_usage(usedRAMs, &index);
        
        if (index == MAX_SAMPLES) {
            print_average_memory(usedRAMs, MAX_SAMPLES);
        }
        
        long totalRAM = 0;
        struct sysinfo memInfo;
        sysinfo(&memInfo);
        totalRAM = memInfo.totalram / (1024 * 1024);
        display_usage_graph(usedRAMs[(index - 1) % MAX_SAMPLES], totalRAM);
    }

    return 0;
}