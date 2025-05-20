//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define MAXCPU 4 // Max number of CPUs to monitor
#define INTERVAL 1 // Sampling Interval in seconds

int main()
{
    // Setting up variables
    FILE* fp;
    char buff[256];
    int system_cpu[MAXCPU], user_cpu[MAXCPU], idle_cpu[MAXCPU];
    int system_cpu_diff[MAXCPU], user_cpu_diff[MAXCPU], idle_cpu_diff[MAXCPU];
    char cpu_model[256];
    char* ptr;
    int ncpus, i;
    double sys_cpu_perc[MAXCPU], user_cpu_perc[MAXCPU], idle_cpu_perc[MAXCPU];
    struct timespec ts;

    // Get the CPU model
    fp = fopen("/proc/cpuinfo", "r");
    while(fgets(buff, 256, fp)) {
        if(!strncmp(buff, "model name", 10)) {
            ptr = strchr(buff, ':');
            strcpy(cpu_model, ptr + 2);
            cpu_model[strlen(cpu_model) - 1] = '\0';
            break;
        }
    }
    fclose(fp);

    // Get the number of CPUs
    ncpus = sysconf(_SC_NPROCESSORS_ONLN);

    // Starting the loop
    while(1) {

        // Open the /proc/stat file
        fp = fopen("/proc/stat", "r");

        // Read the CPU usage of each CPU
        for(i = 0; i < ncpus; i++) {
            fgets(buff, 256, fp);
            sscanf(buff, "cpu%d %d %d %d", &i, &user_cpu[i], &system_cpu[i], &idle_cpu[i]);
        }

        // Close the file
        fclose(fp);

        // Sleep for the sampling interval
        ts.tv_sec = INTERVAL;
        ts.tv_nsec = 0;
        nanosleep(&ts, NULL);

        // Open the /proc/stat file again
        fp = fopen("/proc/stat", "r");

        // Read the CPU usage of each CPU again
        for(i = 0; i < ncpus; i++) {
            fgets(buff, 256, fp);
            sscanf(buff, "cpu%d %d %d %d", &i, &user_cpu_diff[i], &system_cpu_diff[i], &idle_cpu_diff[i]);
        }

        // Close the file again
        fclose(fp);

        // Calculate the CPU usage percentage of each CPU
        for(i = 0; i < ncpus; i++) {
            sys_cpu_perc[i] = (double)(system_cpu_diff[i] - system_cpu[i]) * 100 / (system_cpu_diff[i] - system_cpu[i] + user_cpu_diff[i] - user_cpu[i] + idle_cpu_diff[i] - idle_cpu[i]);
            user_cpu_perc[i] = (double)(user_cpu_diff[i] - user_cpu[i]) * 100 / (system_cpu_diff[i] - system_cpu[i] + user_cpu_diff[i] - user_cpu[i] + idle_cpu_diff[i] - idle_cpu[i]);
            idle_cpu_perc[i] = (double)(idle_cpu_diff[i] - idle_cpu[i]) * 100 / (system_cpu_diff[i] - system_cpu[i] + user_cpu_diff[i] - user_cpu[i] + idle_cpu_diff[i] - idle_cpu[i]);
        }

        // Printing the CPU usage of each CPU
        printf("CPU Usage (%s):\n", cpu_model);
        for(i = 0; i < ncpus; i++) {
            printf("CPU %d:\n", i);
            printf("\tSystem CPU Usage: %.2f %%\n", sys_cpu_perc[i]);
            printf("\tUser CPU Usage: %.2f %%\n", user_cpu_perc[i]);
            printf("\tIdle CPU Usage: %.2f %%\n", idle_cpu_perc[i]);
        }
    }

    return 0;
}