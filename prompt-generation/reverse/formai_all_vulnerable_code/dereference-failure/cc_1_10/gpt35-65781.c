//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    printf("Welcome to the C RAM Usage Monitor!\n");
    printf("-----------------------------------\n");

    // determine total available memory
    char* meminfo = (char*) malloc(sizeof(char) * 100);
    FILE* meminfo_fp = fopen("/proc/meminfo", "r");
    if (meminfo_fp == NULL) {
        printf("Error: unable to open /proc/meminfo\n");
        return 1;
    }
    fgets(meminfo, 100, meminfo_fp);
    int total_mem = get_mem_val(meminfo);
    printf("Total memory: %d kB\n", total_mem);

    // monitor memory usage every second
    while (1) {
        sleep(1);

        // determine used memory
        char* memavail = (char*) malloc(sizeof(char) * 100);
        FILE* memavail_fp = fopen("/proc/meminfo", "r");
        if (memavail_fp == NULL) {
            printf("Error: unable to open /proc/meminfo\n");
            return 1;
        }
        fgets(memavail, 100, memavail_fp);
        int mem_used = total_mem - get_mem_val(memavail);
        printf("Memory used: %d kB\n", mem_used);

        // determine percentage of used memory
        float percent_used = (float) mem_used / total_mem * 100;
        printf("Percent used: %.2f%%\n", percent_used);
    }

    return 0;
}

// helper function to extract memory value from meminfo string
int get_mem_val(char* meminfo) {
    int val = 0;
    while (*meminfo && !isdigit(*meminfo)) {
        meminfo++;
    }
    while (*meminfo && isdigit(*meminfo)) {
        val = val * 10 + (*meminfo - '0');
        meminfo++;
    }
    return val;
}