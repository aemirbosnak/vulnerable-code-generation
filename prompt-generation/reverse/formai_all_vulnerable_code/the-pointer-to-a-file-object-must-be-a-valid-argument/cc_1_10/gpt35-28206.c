//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/*
* This is a simple CPU usage monitor program written in C using Linux proc file system
* It displays the current CPU usage percentage for all installed CPUs
* The program is interactive, it displays the current usage every second until user presses 'q' to quit
*/

int NUM_OF_CPUS = 0; // global variable to hold number of installed CPUs

// function to calculate the CPU usage percentage
float get_cpu_usage(unsigned long long *prev_idle, unsigned long long *prev_total)
{
    unsigned long long idle, total, diff_idle, diff_total;
    FILE *fp = fopen("/proc/stat", "r");
    char cpu_line[100];

    while(fgets(cpu_line, sizeof(cpu_line), fp))
    {
        if(!strncmp(cpu_line, "cpu ", 4))
        {
            sscanf(cpu_line+5, "%llu %llu %*llu %*llu %*llu %*llu %*llu %*llu", &total, &idle);
            diff_idle = idle - *prev_idle;
            diff_total = total - *prev_total;
            *prev_idle = idle;
            *prev_total = total;
            return 100.0 * (1.0 - ((float) diff_idle) / ((float) diff_total));
        }
    }
    return 0;
}

int main()
{
    FILE *fp = fopen("/proc/cpuinfo", "r");
    char cpu_line[100];
    unsigned long long prev_idle[NUM_OF_CPUS], prev_total[NUM_OF_CPUS];
    float cpu_usage;

    // count number of installed CPUs
    while(fgets(cpu_line, sizeof(cpu_line), fp))
    {
        if(!strncmp(cpu_line, "processor", 9))
        {
            NUM_OF_CPUS++;
        }
    }

    // allocate memory for holding previous values of idle and total CPU cycles for all CPUs
    unsigned long long *prev_idle_arr = malloc(NUM_OF_CPUS * sizeof(unsigned long long));
    unsigned long long *prev_total_arr = malloc(NUM_OF_CPUS * sizeof(unsigned long long));

    // initialize previous values to zero
    for(int i=0; i<NUM_OF_CPUS; i++)
    {
        prev_idle_arr[i] = 0;
        prev_total_arr[i] = 0;
    }

    printf("Total installed CPUs: %d\n", NUM_OF_CPUS);

    while(getchar() != 'q')
    {
        system("clear"); // clear the terminal screen
        printf("CPU Usage (%%) for all CPUs:\n\n");

        for(int i=0; i<NUM_OF_CPUS; i++)
        {
            cpu_usage = get_cpu_usage(&prev_idle_arr[i], &prev_total_arr[i]);
            printf("CPU %d - %.1f %%\n", i, cpu_usage);
        }

        sleep(1); // wait for 1 second
    }

    free(prev_idle_arr);
    free(prev_total_arr);

    return 0;
}