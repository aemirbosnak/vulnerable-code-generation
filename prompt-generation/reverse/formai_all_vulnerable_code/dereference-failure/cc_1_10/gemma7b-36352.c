//Gemma-7B DATASET v1.0 Category: CPU usage monitor ; Style: secure
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>

#define MAX_PROC_NUM 10

int main()
{
    FILE *fp;
    char filename[256];
    char line[256];
    int i, j, k, pid, cpu_usage;
    int process_num = 0;
    char **processes = NULL;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    processes = malloc(MAX_PROC_NUM * sizeof(char *));
    if (processes == NULL)
    {
        perror("Error allocating memory");
        return 1;
    }

    while (fgets(line, 256, fp) != NULL)
    {
        if (line[0] == 'p' && process_num < MAX_PROC_NUM)
        {
            processes[process_num] = strdup(line);
            process_num++;
        }
    }

    fclose(fp);

    for (i = 0; i < process_num; i++)
    {
        printf("Process: %s\n", processes[i]);

        cpu_usage = 0;
        for (j = 0; j < 3; j++)
        {
            k = atoi(processes[i][j]) * 2;
            cpu_usage += k;
        }

        printf("CPU usage: %d%%\n", cpu_usage);
    }

    free(processes);

    return 0;
}