//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/sysinfo.h>

#define TOTAL_MEM (get_phys_pages() * getpagesize())

// Function to parse /proc/meminfo and retrieve memory usage stats
void get_mem_stats(uint64_t *total_mem, uint64_t *free_mem, uint64_t *cached_mem) {
    FILE *fp = fopen("/proc/meminfo", "rb");
    char line[1024];
    *total_mem = *free_mem = *cached_mem = 0;
    while (fgets(line, sizeof(line), fp)) {
        uint64_t val;
        if (sscanf(line, "MemTotal: %lu", &val) == 1) {
            *total_mem = val * 1024;
        } else if (sscanf(line, "MemFree: %lu", &val) == 1) {
            *free_mem = val * 1024;
        } else if (sscanf(line, "Cached: %lu", &val) == 1) {
            *cached_mem = val * 1024;
        }
    }
    fclose(fp);
}

// Function to calculate amount of memory used by process
uint64_t get_proc_mem_usage(void) {
    uint64_t mem_usage = 0;
    FILE *fp = fopen("/proc/self/statm", "rb");
    if (fp) {
        char buf[1024] = { 0 };
        fread(buf, sizeof(buf), 1, fp);
        fclose(fp);
        sscanf(buf, "%*ld %lu", &mem_usage);
        mem_usage *= getpagesize();
    }
    return mem_usage;
}

int main(void) {
    uint64_t total_mem, free_mem, cached_mem;
    get_mem_stats(&total_mem, &free_mem, &cached_mem);
    printf("Total memory: %lu\n", TOTAL_MEM);
    printf("Free memory: %lu\n", free_mem + cached_mem);
    printf("Used memory: %lu\n", TOTAL_MEM - (free_mem + cached_mem));
    printf("Process memory usage: %lu\n", get_proc_mem_usage());
    return 0;
}