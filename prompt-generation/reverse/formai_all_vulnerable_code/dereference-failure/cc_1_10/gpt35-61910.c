//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

#define MAX_LENGTH 50 // Maximum length of process name

int main(int argc, char *argv[]) {
    char process_name[MAX_LENGTH];
    int interval = 1; // default sampling interval is 1 second
    int counter = 0;
    int pid;

    if (argc < 2) {
        printf("Usage: cpu_monitor [process name] [sampling interval]\n");
        printf("Default sampling interval is 1 second\n");
        exit(1);
    }

    // Get process name and sampling interval from command line arguments
    strncpy(process_name, argv[1], MAX_LENGTH);
    if (argc >= 3) {
        interval = atoi(argv[2]);
    }
    
    // Get process ID by name
    FILE *fp = popen("pidof -s -x -o %PPID", "r");
    if (fp == NULL) {
        perror("popen failed");
        exit(1);
    }
    fscanf(fp, "%d", &pid);
    pclose(fp);
    
    while (1) {
        // Get CPU usage for process by ID
        struct rusage usage;
        getrusage(RUSAGE_SELF, &usage);
        double cpu_time_seconds = (double)usage.ru_utime.tv_sec + ((double)usage.ru_utime.tv_usec / 1000000);
        double cpu_usage = cpu_time_seconds / interval * 100;

        // Print CPU usage
        printf("CPU usage for process '%s' over the last %d seconds is %.2f%%\n",
            process_name,
            interval,
            cpu_usage
        );
        
        // Check if process is still running
        int kill_result = kill(pid, 0);
        if (kill_result == -1) {
            printf("Process '%s' with ID %d is no longer running.\n", process_name, pid);
            exit(0);
        }
        
        // Wait for interval seconds before taking another sample
        counter++;
        sleep(interval);
    }
    
    return 0;
}