//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

#define MIN_CPU_USAGE 0
#define MAX_CPU_USAGE 100
#define BUFFER_SIZE 256
#define MAX_WAIT_TIME 5

volatile sig_atomic_t is_running = 1;

void sigint_handler(int signal)
{
    is_running = 0;
}

int main()
{
    char buffer[BUFFER_SIZE];
    pid_t pid = getpid();
    snprintf(buffer, BUFFER_SIZE, "/proc/%d/stat", pid);
    int file_descriptor = open(buffer, O_RDONLY);
    if (file_descriptor == -1)
    {
        fprintf(stderr, "Failed to open file: %s", strerror(errno));
        return EXIT_FAILURE;
    }
    double cpu_usage = MIN_CPU_USAGE;
    time_t start_time = time(NULL);
    while (is_running)
    {
        lseek(file_descriptor, 0, SEEK_SET);
        if (read(file_descriptor, buffer, BUFFER_SIZE) == -1)
        {
            fprintf(stderr, "Failed to read file: %s", strerror(errno));
            exit(EXIT_FAILURE);
        }
        char* token = strtok(buffer, " ");
        int token_count = 1;
        while (token != NULL)
        {
            if (token_count == 14 || token_count == 15 || token_count == 16 || token_count == 17)
            {
                cpu_usage += atof(token);
            }
            token = strtok(NULL, " ");
            token_count++;
        }
        double time_difference = difftime(time(NULL), start_time);
        cpu_usage /= time_difference;
        cpu_usage /= sysconf(_SC_NPROCESSORS_ONLN);
        cpu_usage *= MAX_CPU_USAGE;
        printf("Current CPU Usage: %.1f%%\n", cpu_usage);
        cpu_usage = MIN_CPU_USAGE;
        sleep(MAX_WAIT_TIME);
    }
    close(file_descriptor);
    return EXIT_SUCCESS;
}