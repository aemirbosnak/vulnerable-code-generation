//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

#define INTERVAL 1 // Time interval in seconds

int main() {
    int i, j, num_processors;
    struct rusage usage;
    double cpu_usage[10]; // For 10 processors
    char *process_name[10]; // For 10 processors

    // Get the number of processors
    num_processors = sysconf(_SC_NPROCESSORS_ONLN);

    // Get the name of the processes
    for (i = 0; i < num_processors; i++) {
        process_name[i] = malloc(20);
        sprintf(process_name[i], "PID %d", i);
    }

    // Initialize CPU usage to 0
    for (i = 0; i < num_processors; i++) {
        cpu_usage[i] = 0;
    }

    while (1) {
        for (i = 0; i < num_processors; i++) {
            // Get the process ID
            j = fork();

            if (j == 0) {
                // Child process
                execlp("ps", "ps", "-p", process_name[i], "-o", "cpu=", NULL);
                exit(0);
            } else if (j < 0) {
                // Error forking
                perror("fork");
                exit(1);
            } else {
                // Parent process
                waitpid(j, NULL, 0);

                // Get the CPU usage
                if (getrusage(RUSAGE_SELF, &usage) == -1) {
                    perror("getrusage");
                    exit(1);
                }

                cpu_usage[i] = usage.ru_utime.tv_sec + usage.ru_stime.tv_sec;
            }
        }

        // Print the CPU usage
        for (i = 0; i < num_processors; i++) {
            printf("CPU usage for %s: %.2f%%\n", process_name[i], cpu_usage[i] * 100.0 / INTERVAL);
        }

        // Sleep for a second
        sleep(1);
    }

    return 0;
}