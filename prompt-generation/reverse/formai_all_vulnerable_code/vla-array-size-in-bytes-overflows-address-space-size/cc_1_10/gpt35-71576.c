//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

// Global Variables
static volatile sig_atomic_t keep_running = 1;
char *proc_pid_stat = "/proc/stat";
int max_cpus = 0;

// Function declarations
void print_cpu_usage(int *previous_total_idle, int *previous_total, int *total_idle, int *total);
void signal_handler(int sig);

int main(int argc, char **argv)
{
    printf("Welcome to CPU usage monitor program!\n");

    // Get number of CPU cores
    max_cpus = sysconf(_SC_NPROCESSORS_ONLN);
    printf("Number of CPU cores detected: %d \n", max_cpus);

    // Set signal handler for SIGINT and SIGTERM
    if(signal(SIGINT, signal_handler) == SIG_ERR) 
    {
        printf("\ncan't catch SIGINT\n");
    }
    if(signal(SIGTERM, signal_handler) == SIG_ERR) 
    {
        printf("\ncan't catch SIGTERM\n");
    }

    // Initialize variables for CPU usage calculation
    int previous_total_idle[max_cpus+1], previous_total[max_cpus+1];
    int total_idle[max_cpus+1], total[max_cpus+1];
    for (int i = 0; i <= max_cpus; i++)
    {
        previous_total_idle[i] = 0;
        previous_total[i] = 0;
        total_idle[i] = 0;
        total[i] = 0;
    }

    // Start monitoring CPU usage
    while (keep_running) 
    {
        print_cpu_usage(previous_total_idle, previous_total, total_idle, total);

        // Wait for 1 second before checking again
        sleep(1);
    }

    printf("\nExiting CPU usage monitor program.\n");

    return 0;
}

// Function to calculate and print CPU usage
void print_cpu_usage(int *previous_total_idle, int *previous_total, int *total_idle, int *total)
{
    // Open /proc/stat file
    int fd = open(proc_pid_stat, O_RDONLY, 0);
    if (fd < 0)
    {
        printf("Error opening /proc/stat file: %s\n", strerror(errno));
        return;
    }

    // Read /proc/stat file
    char buffer[1024];
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer)-1);
    if (bytes_read == -1)
    {
        printf("Error reading /proc/stat file: %s\n", strerror(errno));
        close(fd);
        return;
    }

    // Parse /proc/stat file
    buffer[bytes_read] = '\0';
    char *line = strtok(buffer, "\n");
    while (line != NULL)
    {
        if (strstr(line, "cpu") != NULL)
        {
            int cpuidx;
            sscanf(line, "cpu%d ", &cpuidx);

            // Calculate total CPU ticks
            int user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
            sscanf(line+4, "%d %d %d %d %d %d %d %d %d %d", &user, &nice, &system, &idle, 
                &iowait, &irq, &softirq, &steal, &guest, &guest_nice);
            total[cpuidx] = user + nice + system + idle + iowait + irq + softirq + steal;
            total_idle[cpuidx] = idle + iowait;

            // Calculate CPU usage percentage
            if (previous_total[cpuidx] != 0)
            {
                float cpu_usage = 100.0 * (1.0 - (float)(total_idle[cpuidx] - previous_total_idle[cpuidx]) / 
                    (float)(total[cpuidx] - previous_total[cpuidx]));
                printf("CPU %d Usage: %.2f%%\n", cpuidx, cpu_usage);
            }

            // Update previous CPU ticks
            previous_total_idle[cpuidx] = total_idle[cpuidx];
            previous_total[cpuidx] = total[cpuidx];
        }
        line = strtok(NULL, "\n");
    }

    close(fd);
}

// Signal handler for SIGINT and SIGTERM
void signal_handler(int sig)
{
    printf("\nReceived signal %d\n", sig);
    keep_running = 0;
}