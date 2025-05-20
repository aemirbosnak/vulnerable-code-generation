//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

#define MAX_PROC_NAME 1024

int main(int argc, char *argv[]) {
    char proc_name[MAX_PROC_NAME];
    double user_time, sys_time, cpu_usage;

    // Check if process name is given as argument
    if (argc == 2) {
        strncpy(proc_name, argv[1], MAX_PROC_NAME);
    } else {
        // Get process name of this program
        int pid = getpid();
        sprintf(proc_name, "/proc/%d/stat", pid);
    }

    struct rusage usage;
    struct timeval timeval_start, timeval_end;
    double start_time, end_time;

    // Get starting CPU time
    if (gettimeofday(&timeval_start, NULL) == -1) {
        perror("gettimeofday");
        exit(1);
    }
    start_time = timeval_start.tv_sec + timeval_start.tv_usec/1000000.0;

    // Do some heavy computation to monitor CPU usage
    int i, j, k;
    for (i = 0; i < 100; i++) {
        for (j = 0; j < 100000; j++) {
            k = i*j;
        }
    }

    // Get ending CPU time
    if (gettimeofday(&timeval_end, NULL) == -1) {
        perror("gettimeofday");
        exit(1);
    }
    end_time = timeval_end.tv_sec + timeval_end.tv_usec/1000000.0;

    // Get resource usage
    if (getrusage(RUSAGE_SELF, &usage) == -1) {
        perror("getrusage");
        exit(1);
    }
    user_time = usage.ru_utime.tv_sec + usage.ru_utime.tv_usec/1000000.0;
    sys_time = usage.ru_stime.tv_sec + usage.ru_stime.tv_usec/1000000.0;

    // Calculate CPU usage
    cpu_usage = 100.0*(user_time + sys_time)/(end_time - start_time);

    // Print results
    printf("Process name: %s\n", proc_name);
    printf("User time: %f s\n", user_time);
    printf("System time: %f s\n", sys_time);
    printf("CPU usage: %f%%\n", cpu_usage);

    return 0;
}