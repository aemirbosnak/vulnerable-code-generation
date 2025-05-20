//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CPUS 8

typedef struct CPUstat {
    int user;
    int nice;
    int system;
    int idle;
    int iowait;
    int irq;
    int softirq;
    int steal;
} CPUstat;

// Function to parse stat file for a particular CPU
void getCPUstat(CPUstat *cpu, int id) {
    char line[256];
    char *tok;
    char *statFile = "/proc/stat";
    FILE *fp = fopen(statFile, "r");
    
    // Skip first line of the file
    fgets(line, sizeof(line), fp);
    
    // Find the line for the specified CPU
    for (int i = 0; i < id + 1; i++) {
        fgets(line, sizeof(line), fp);
    }
    
    // Parse the line and populate the CPUstat struct
    tok = strtok(line, " ");
    for (int i = 0; i < 7; i++) {
        tok = strtok(NULL, " ");
        switch (i) {
            case 0:
                cpu->user = atoi(tok);
                break;
            case 1:
                cpu->nice = atoi(tok);
                break;
            case 2:
                cpu->system = atoi(tok);
                break;
            case 3:
                cpu->idle = atoi(tok);
                break;
            case 4:
                cpu->iowait = atoi(tok);
                break;
            case 5:
                cpu->irq = atoi(tok);
                break;
            case 6:
                cpu->softirq = atoi(tok);
                break;
        }
    }
    
    fclose(fp);
}

int main() {
    // Allocate an array of CPUstat structs to store previous CPU stats
    CPUstat prevStats[MAX_CPUS];
    memset(prevStats, 0, sizeof(CPUstat) * MAX_CPUS);
    
    // Loop infinitely to monitor CPU usage
    while (1) {
        // Iterate through each CPU and calculate its usage percentage
        for (int i = 0; i < MAX_CPUS; i++) {
            CPUstat currStats;
            getCPUstat(&currStats, i);
            
            int prevTotal = prevStats[i].user + prevStats[i].nice + prevStats[i].system +
                prevStats[i].idle + prevStats[i].iowait + prevStats[i].irq + prevStats[i].softirq;
            int currTotal = currStats.user + currStats.nice + currStats.system +
                currStats.idle + currStats.iowait + currStats.irq + currStats.softirq;
            int deltaTotal = currTotal - prevTotal;
            float usage = ((float) deltaTotal / (float) currTotal) * 100.0;
            
            printf("CPU %d usage: %.2f%%\n", i, usage);
            
            // Store current stats as previous stats for the next iteration
            memcpy(&prevStats[i], &currStats, sizeof(CPUstat));
        }
        
        // Sleep for one second before repeating the loop
        sleep(1);
    }
    
    return 0;
}