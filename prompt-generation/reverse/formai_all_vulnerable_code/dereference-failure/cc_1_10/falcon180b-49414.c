//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

#define MAX_PROCESSES 1024

int main() {
    int num_processes = 0;
    struct rusage usage;
    pid_t *process_list;

    // Get the number of processes running
    if (getrusage(RUSAGE_SELF, &usage) == -1) {
        perror("Error getting rusage");
        exit(1);
    }
    num_processes = usage.ru_maxrss;

    // Allocate memory for the process list
    process_list = (pid_t *) malloc(num_processes * sizeof(pid_t));
    if (process_list == NULL) {
        perror("Error allocating memory");
        exit(1);
    }

    // Get the list of running processes
    if (getrusage(RUSAGE_CHILDREN, &usage) == -1) {
        perror("Error getting rusage");
        exit(1);
    }

    num_processes = usage.ru_maxrss;

    // Get the list of running processes
    if (getrusage(RUSAGE_CHILDREN, &usage) == -1) {
        perror("Error getting rusage");
        exit(1);
    }

    for (int i = 0; i < num_processes; i++) {
        process_list[i] = usage.ru_idrss;
    }

    // Print the list of running processes and their CPU usage
    printf("Process ID | CPU Usage\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d | %d\n", i, process_list[i]);
    }

    free(process_list);
    return 0;
}