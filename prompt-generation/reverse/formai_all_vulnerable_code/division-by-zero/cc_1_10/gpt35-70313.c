//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

#define BUFFER_SIZE 1024

/**
 * This program monitors the usage of C RAM in real time.
 */

int main() {
    unsigned long long total_mem, free_mem, used_mem, buff_mem, cache_mem;
    struct sysinfo mem_info;
    char buffer[BUFFER_SIZE];
    char *indicator = "/-\\|";
    int i = 0;

    // Get initial information on memory usage
    sysinfo(&mem_info);
    total_mem = (unsigned long long)mem_info.totalram * mem_info.mem_unit;
    free_mem = (unsigned long long)mem_info.freeram * mem_info.mem_unit;
    buff_mem = (unsigned long long)mem_info.bufferram * mem_info.mem_unit;
    cache_mem = (unsigned long long)mem_info.sharedram * mem_info.mem_unit;

    printf("Initial Memory Usage: Total:%lld Free:%lld Used:%lld Buff:%lld Cache:%lld\n", total_mem, free_mem, used_mem, buff_mem, cache_mem);

    while(1) {
        // Clear screen and start from the beginning
        printf("\033[H\033[J");
        printf("Monitoring Memory Usage...\n");

        // Get new information on memory usage
        sysinfo(&mem_info);
        total_mem = (unsigned long long)mem_info.totalram * mem_info.mem_unit;
        free_mem = (unsigned long long)mem_info.freeram * mem_info.mem_unit;
        used_mem = total_mem - free_mem;
        buff_mem = (unsigned long long)mem_info.bufferram * mem_info.mem_unit;
        cache_mem = (unsigned long long)mem_info.sharedram * mem_info.mem_unit;

        // Display memory usage statistics
        printf("Total Memory: %lld\n", total_mem);
        printf("Used Memory: %lld\n", used_mem);
        printf("Free Memory: %lld\n", free_mem);
        printf("Buffer Memory: %lld\n", buff_mem);
        printf("Cache Memory: %lld\n", cache_mem);

        // Display graphical representation of memory usage
        int j = (int)(used_mem * 10 / total_mem);
        memset(buffer, ' ', BUFFER_SIZE - 1);
        buffer[BUFFER_SIZE - 1] = '\0';
        for(int i = 0; i < j; i++) {
            buffer[i] = '-';
        }
        printf("Memory Usage [ %s ] %d%%\n", buffer, (int)(used_mem * 100 / total_mem));

        // Display loading animation while memory usage is being monitored
        printf("Scanning... %c\r", indicator[i % 4]);
        i++;
        fflush(stdout);
        sleep(1);
    }

    return 0;
}