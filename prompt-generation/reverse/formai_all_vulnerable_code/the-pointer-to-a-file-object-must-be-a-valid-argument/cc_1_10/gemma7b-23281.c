//Gemma-7B DATASET v1.0 Category: CPU usage monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int cpu_usage = 0;
    char cmd[128];
    FILE *fp;
    long int total_ticks = 0;
    long int current_ticks = 0;
    long int prev_ticks = 0;
    long int time_elapsed = 0;
    long int avg_usage = 0;
    long int i = 0;

    // Open a pipe to get the output of the ps command
    fp = popen("ps -eo %CPU", "r");

    // Read the output of the ps command line by line
    while (fgets(cmd, 128, fp) != NULL)
    {
        // Extract the CPU usage from the line
        cpu_usage = atoi(cmd);

        // Add the CPU usage to the total ticks
        total_ticks += cpu_usage;

        // Increment the current ticks
        current_ticks++;

        // Calculate the time elapsed
        time_elapsed = current_ticks - prev_ticks;

        // Calculate the average CPU usage
        avg_usage = (total_ticks - prev_ticks) * 100 / time_elapsed;

        // Print the average CPU usage
        printf("Average CPU usage: %.2f%%\n", avg_usage);

        // Update the previous ticks
        prev_ticks = current_ticks;
    }

    // Close the pipe
    pclose(fp);

    // Calculate the average CPU usage over time
    avg_usage = (total_ticks - prev_ticks) * 100 / time_elapsed;

    // Print the average CPU usage
    printf("Average CPU usage over time: %.2f%%\n", avg_usage);

    return 0;
}