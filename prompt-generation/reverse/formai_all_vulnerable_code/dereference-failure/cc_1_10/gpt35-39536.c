//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printHeader()
{
    printf("\n---------------------------------\n");
    printf("|        CPU Usage Monitor      |\n");
    printf("---------------------------------\n\n");
}

void printUsage()
{
    printf("Usage: cpu_monitor [interval] [count]\n\n");
    printf("interval: The time interval between each CPU usage check (in seconds)\n");
    printf("count: The total number of times to check CPU usage\n");
}

float calculateCPUUsage()
{
    FILE* file = fopen("/proc/stat", "r");
    char buffer[1024];
    fgets(buffer, sizeof(buffer), file);
    fclose(file);

    char* token = strtok(buffer, " ");
    float total = 0, idle = 0;
    for (int i = 0; i < 9; i++)
    {
        token = strtok(NULL, " ");
        if (i == 3) idle = atoi(token);
        total += atoi(token);
    }

    return 100.0 * (1.0 - idle / total);
}

int main(int argc, char *argv[])
{
    // Check if enough arguments are passed
    if(argc != 3)
    {
        printHeader();
        printUsage();
        return 1;
    }

    // Get arguments
    int interval = atoi(argv[1]);
    int count = atoi(argv[2]);

    // Validate arguments
    if(interval <= 0 || count <= 0)
    {
        printHeader();
        printf("Invalid arguments. Interval and count must be greater than 0.\n");
        return 1;
    }

    // Start monitoring CPU usage
    printHeader();
    for(int i = 0; i < count; i++)
    {
        float usage = calculateCPUUsage();
        printf("CPU usage: %.2f%%\n", usage);
        sleep(interval);
    }

    return 0;
}