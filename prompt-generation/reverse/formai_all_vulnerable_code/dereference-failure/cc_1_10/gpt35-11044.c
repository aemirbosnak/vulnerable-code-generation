//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <signal.h>

#define BUFFER_SIZE 256

int counter = 1;

void signal_handler(int signal_number) {
    counter++;
}

double calculate_cpu_usage(int pid) {
    struct timeval start, end;
    char cmd[BUFFER_SIZE];
    char buffer[BUFFER_SIZE];
    char* token;
    FILE* file;
    double time_difference;
    double cpu_usage;

    sprintf(cmd, "ps -p %d -o utime=", pid);

    file = popen(cmd, "r");
    if (!file) {
        return -1;
    }

    fgets(buffer, BUFFER_SIZE, file);

    token = strtok(buffer, "\n");

    if (!token) {
        return -1;
    }

    time_difference = atof(token) - counter;

    gettimeofday(&start, NULL);

    sleep(1);

    gettimeofday(&end, NULL);

    cpu_usage = (time_difference / (end.tv_sec - start.tv_sec)) * 100;

    pclose(file);

    return cpu_usage;
}

void monitor_cpu_usage(int pid) {
    double cpu_usage;

    signal(SIGINT, signal_handler);

    while (1) {
        cpu_usage = calculate_cpu_usage(pid);

        if (cpu_usage < 0) {
            printf("Error: Could not retrieve CPU usage.\n");
        } else {
            printf("CPU usage: %.2lf%%\n", cpu_usage);
        }

        sleep(1);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Please provide a valid PID.\n");
        exit(1);
    }

    int pid = atoi(argv[1]);

    if (pid <= 0) {
        printf("Please provide a valid PID.\n");
        exit(1);
    }

    monitor_cpu_usage(pid);

    return 0;
}