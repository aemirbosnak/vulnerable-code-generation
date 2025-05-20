//Gemma-7B DATASET v1.0 Category: CPU usage monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_PROC 10

int main()
{
    int i, j, k;
    char proc_name[256];
    int cpu_usage[MAX_PROC] = {0};
    FILE *fp;

    system("clear");

    // Open a file to store process names
    fp = fopen("process.txt", "w");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    // Loop to gather CPU usage for each process
    for (i = 0; i < MAX_PROC; i++)
    {
        // Get the process name
        sprintf(proc_name, "proc%d", i + 1);

        // Get the CPU usage for the process
        cpu_usage[i] = get_cpu_usage(proc_name);

        // Write the process name to the file
        fprintf(fp, "%s\n", proc_name);
    }

    fclose(fp);

    // Print the CPU usage for each process
    system("clear");
    printf("Process Name\t\tCPU Usage (%)\n");
    printf("---------------------------------------\n");

    for (i = 0; i < MAX_PROC; i++)
    {
        printf("%s\t\t\t%d\n", cpu_usage[i], proc_name[i]);
    }

    return 0;
}

int get_cpu_usage(char *proc_name)
{
    FILE *fp;
    char line[256];
    int cpu_usage = 0;

    // Open a file to get the CPU usage for the process
    fp = fopen("/proc/stat", "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    // Read the line of text containing the process's CPU usage
    fgets(line, 256, fp);

    // Extract the CPU usage from the line of text
    cpu_usage = atoi(strtok(line, "%"));

    fclose(fp);

    return cpu_usage;
}