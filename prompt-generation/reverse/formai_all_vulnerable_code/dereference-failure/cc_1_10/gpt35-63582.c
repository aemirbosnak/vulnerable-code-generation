//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define TOTAL_RAM 4194304 // 4 GB in bytes

int main(int argc, char *argv[]) {
    char *mem_info_file = "/proc/meminfo"; // file containing memory information
    int refresh_rate = 1; // default refresh rate of 1 second
    
    // parse command line arguments for optional refresh rate value
    if (argc == 2) {
        refresh_rate = atoi(argv[1]);
    }
    
    // loop to continuously monitor RAM usage
    while (1) {
        FILE *mem_info = fopen(mem_info_file, "r");
        if (mem_info == NULL) {
            printf("Error opening file %s\n", mem_info_file);
            exit(1);
        }
        
        char line[256];
        int mem_free = 0, mem_available = 0;
        while (fgets(line, sizeof(line), mem_info)) {
            // extract free memory and available memory data from file
            if (strncmp(line, "MemFree:", 8) == 0) {
                mem_free = atoi(&line[8]) * 1024; // convert from kB to bytes
            } else if (strncmp(line, "MemAvailable:", 12) == 0) {
                mem_available = atoi(&line[12]) * 1024; // convert from kB to bytes
            }
            
            // break out of loop once both values are obtained
            if (mem_free > 0 && mem_available > 0) {
                break;
            }
        }
        fclose(mem_info);
        
        // calculate RAM usage percentage
        int mem_used = TOTAL_RAM - mem_available;
        float ram_percentage = 100.0 * ((float) mem_used / TOTAL_RAM);
        
        // print RAM usage information
        printf("RAM Usage: %.2f%%\tFree: %d MB\tAvailable: %d MB\n", ram_percentage, mem_free/1024/1024, mem_available/1024/1024);
        fflush(stdout);
        
        // wait before refreshing again
        sleep(refresh_rate);
    }
    
    return 0;
}