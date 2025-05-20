//Gemma-7B DATASET v1.0 Category: CPU usage monitor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/sysinfo.h>
#include <string.h>
#include <time.h>

int main()
{
    char filename[] = "/proc/stat";
    FILE *fp;
    char line[256];
    int i, j, k, l, m, n, cpu_user, cpu_system, cpu_idle, cpu_wait, cpu_total;
    time_t t, t_start, t_end;
    long int cpu_usage;

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    t_start = time(NULL);

    while (1)
    {
        fgets(line, 256, fp);
        if (feof(fp))
            break;

        for (i = 0; i < 10; i++)
        {
            cpu_user = atoi(strtok(line, ":"));
            cpu_system = atoi(strtok(NULL, ":"));
            cpu_idle = atoi(strtok(NULL, ":"));
            cpu_wait = atoi(strtok(NULL, ":"));

            cpu_total = cpu_user + cpu_system + cpu_idle + cpu_wait;

            n = (cpu_total * 100) / cpu_total;

            printf("%d%% CPU usage, ", n);
        }

        printf("\n");

        t_end = time(NULL);
        cpu_usage = (t_end - t_start) * 100 / 2;
        printf("Total CPU usage: %.2f%% for %.2f seconds\n", cpu_usage, t_end - t_start);

        t_start = t_end;

        sleep(1);
    }

    fclose(fp);

    return 0;
}