//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: single-threaded
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define PROC_MEMINFO "/proc/meminfo"

// function to read memory information from procfs
void read_memory_info(long *total_memory, long *free_memory)
{
    FILE *fp;
    char line[128];

    fp = fopen(PROC_MEMINFO, "r");

    // loop through each line until the end of file is reached
    while (fgets(line, 128, fp) != NULL) {

        // get total memory
        if (strncmp(line, "MemTotal:", 9) == 0) {
            sscanf(line + 9, "%ld", total_memory);
        }

        // get free memory
        if (strncmp(line, "MemFree:", 8) == 0) {
            sscanf(line + 8, "%ld", free_memory);
        }
    }

    fclose(fp);
}

int main()
{
    long total_memory;
    long free_memory;

    while (1) {

        // read memory information
        read_memory_info(&total_memory, &free_memory);

        // calculate used memory percentage
        float used_memory_percentage = 100 - ((float)free_memory / total_memory) * 100;

        // print memory usage stats
        printf("Total Memory: %ld kB\n", total_memory);
        printf("Free Memory: %ld kB\n", free_memory);
        printf("Used Memory: %.2f%%\n", used_memory_percentage);

        // wait for 1 second
        sleep(1);
    }

    return 0;
}