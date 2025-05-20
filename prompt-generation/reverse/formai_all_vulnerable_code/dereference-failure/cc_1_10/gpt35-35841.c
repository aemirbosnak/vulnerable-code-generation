//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

// Define constant for sleep time
#define SLEEP_TIME 1

int main(int argc, char **argv) {

    // Declare variables
    struct rusage cpu_before, cpu_after;
    struct timeval utime_before, utime_after, stime_before, stime_after;
    double user_secs, sys_secs;
    int is_first = 1;

    // Loop to monitor CPU usage
    while(1) {

        // Record CPU usage before sleep
        if(getrusage(RUSAGE_SELF, &cpu_before) != 0) {
            fprintf(stderr, "Error: Unable to get CPU usage before. %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
        utime_before = cpu_before.ru_utime;
        stime_before = cpu_before.ru_stime;

        // Sleep for specified time
        sleep(SLEEP_TIME);

        // Record CPU usage after sleep
        if(getrusage(RUSAGE_SELF, &cpu_after) != 0) {
            fprintf(stderr, "Error: Unable to get CPU usage after. %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
        utime_after = cpu_after.ru_utime;
        stime_after = cpu_after.ru_stime;

        // Calculate CPU usage
        user_secs = ((double)utime_after.tv_sec + (double)utime_after.tv_usec/1e6) - 
                    ((double)utime_before.tv_sec + (double)utime_before.tv_usec/1e6);
        sys_secs = ((double)stime_after.tv_sec + (double)stime_after.tv_usec/1e6) - 
                   ((double)stime_before.tv_sec + (double)stime_before.tv_usec/1e6);

        // Print CPU usage if not the first iteration
        if(!is_first) {
            printf("User CPU usage: %f seconds\n", user_secs);
            printf("System CPU usage: %f seconds\n", sys_secs);
        } else {
            is_first = 0;
        }
    }

    return 0;
}