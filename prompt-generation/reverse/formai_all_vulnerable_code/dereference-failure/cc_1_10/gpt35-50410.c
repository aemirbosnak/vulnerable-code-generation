//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <unistd.h>

// function to get CPU usage in percentage
float CalculateCPUPercentage(unsigned long long idle_ticks, unsigned long long total_ticks)
{
    static unsigned long long _previous_total_ticks = 0;
    static unsigned long long _previous_idle_ticks = 0;

    unsigned long long total_ticks_since_last_time = total_ticks - _previous_total_ticks;
    unsigned long long idle_ticks_since_last_time = idle_ticks - _previous_idle_ticks;

    float percent = 1.0f - ((float)idle_ticks_since_last_time) / ((float)total_ticks_since_last_time);

    _previous_total_ticks = total_ticks;
    _previous_idle_ticks = idle_ticks;

    return percent * 100.0f;
}

int main()
{
    // get the number of CPUs on the machine
    const int num_cpus = get_nprocs();

    printf("Number of CPUs: %d\n", num_cpus);

    // allocate memory to store CPU usage statistics for each CPU
    unsigned long long** cpu_stats = malloc(sizeof(unsigned long long*) * num_cpus);

    for(int i = 0; i < num_cpus; ++i)
    {
        cpu_stats[i] = malloc(sizeof(unsigned long long) * 10);
    }

    // infinite loop to monitor CPU usage
    while(1)
    {
        // get CPU statistics for each CPU
        for(int i = 0; i < num_cpus; ++i)
        {
            FILE* file = fopen("/proc/stat", "r");

            char line[255];
            char* token;
            
            // read through file until we find the statistics for this particular CPU
            do
            {
                fgets(line, sizeof(line), file);
                token = strtok(line, " ");
            } while(token != NULL && strncmp(token, "cpu", 3) != 0);

            // read in CPU statistics
            for(int j = 0; j < 10; ++j)
            {
                token = strtok(NULL, " ");
                cpu_stats[i][j] = strtoull(token, NULL, 10);
            }

            fclose(file);
        }

        usleep(1000000);

        // calculate CPU usage for each CPU and print results
        printf("CPU Usage:\n");

        for(int i = 0; i < num_cpus; ++i)
        {
            unsigned long long idle_ticks = cpu_stats[i][3] + cpu_stats[i][4];
            unsigned long long total_ticks = idle_ticks + cpu_stats[i][0] + cpu_stats[i][1] + cpu_stats[i][2] + cpu_stats[i][5] + cpu_stats[i][6] + cpu_stats[i][7];

            float cpu_usage = CalculateCPUPercentage(idle_ticks, total_ticks);

            printf("CPU %d: %.2f% \n", i, cpu_usage);
        }
    }

    // free memory used to store CPU statistics
    for(int i = 0; i < num_cpus; ++i)
    {
        free(cpu_stats[i]);
    }

    free(cpu_stats);

    return 0;
}