//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
    int cpu_usage, time_interval;
    printf("Enter the time interval (in seconds): ");
    scanf("%d", &time_interval);
    printf("\nCPU usage monitor started...\n");

    while(1){
        FILE* fp1 = fopen("/proc/stat", "r");
        char buff1[256];
        fgets(buff1, sizeof(buff1), fp1);

        sleep(time_interval); // Wait for given time interval

        FILE* fp2 = fopen("/proc/stat", "r");
        char buff2[256];
        fgets(buff2, sizeof(buff2), fp2);

        char* token1 = strtok(buff1, " "), *token2, *token3, *token4, *token5, *token6, *token7;
        token1 = strtok(NULL, " "), token2 = strtok(NULL, " "), token3 = strtok(NULL, " "), 
        token4 = strtok(NULL, " "), token5 = strtok(NULL, " "), token6 = strtok(NULL, " "), 
        token7 = strtok(NULL, " "); // Extracting the CPU usage information from /proc/stat file

        int user1 = atoi(token1), nice1 = atoi(token2), system1 = atoi(token3), 
        idle1 = atoi(token4), iowait1 = atoi(token5), irq1 = atoi(token6), 
        softirq1 = atoi(token7); // Converting text data into integers

        token1 = strtok(buff2, " "), token2 = strtok(NULL, " "), token3 = strtok(NULL, " "), 
        token4 = strtok(NULL, " "), token5 = strtok(NULL, " "), token6 = strtok(NULL, " "), 
        token7 = strtok(NULL, " ");

        int user2 = atoi(token1), nice2 = atoi(token2), system2 = atoi(token3), 
        idle2 = atoi(token4), iowait2 = atoi(token5), irq2 = atoi(token6), 
        softirq2 = atoi(token7); // Converting text data into integers

        int prev_idle = idle1 + iowait1;
        int idle = idle2 + iowait2;
        int prev_non_idle = user1 + nice1 + system1 + irq1 + softirq1;
        int non_idle = user2 + nice2 + system2 + irq2 + softirq2;
        int prev_total = prev_idle + prev_non_idle;
        int total = idle + non_idle;

        int total_diff = total - prev_total;
        int idle_diff = idle - prev_idle;

        cpu_usage = (total_diff - idle_diff) * 100 / total_diff; // Calculating the percentage of CPU usage

        printf("\n===================================\n");
        printf("            CPU USAGE               \n");
        printf("===================================\n");
        printf("               %d%%                  \n", cpu_usage); // Displaying the CPU usage

        fclose(fp1);
        fclose(fp2);
    }

    return 0;
}