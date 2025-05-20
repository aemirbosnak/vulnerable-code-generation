//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define MAX_THREADS 10

// Global variables
int total_cpus;
int idle_cpus;
float cpu_usage;

// Function prototypes
void* calculate_cpu_usage(void* arg);

int main(int argc, char** argv) {
    // Get the number of CPUs
    total_cpus = sysconf(_SC_NPROCESSORS_ONLN);
    printf("Total CPUs: %d\n", total_cpus);

    // Create an array of threads
    pthread_t threads[MAX_THREADS];

    // Create a thread for each CPU
    for (int i = 0; i < total_cpus; i++) {
        pthread_create(&threads[i], NULL, calculate_cpu_usage, (void*) i);
    }

    // Join all threads
    for (int i = 0; i < total_cpus; i++) {
        pthread_join(threads[i], NULL);
    }

    // Display CPU usage
    printf("CPU Usage: %.2f%%\n", cpu_usage);

    return 0;
}

void* calculate_cpu_usage(void* arg) {
    int cpu_id = (int) arg;

    char str[50];
    sprintf(str, "/proc/stat");

    // Open the stat file for the current CPU
    FILE* fp = fopen(str, "r");

    // Read the first line of the file
    char* line = NULL;
    size_t len = 0;
    ssize_t read = getline(&line, &len, fp);

    // Close the file
    fclose(fp);

    // Parse the first line of the file
    char* token = strtok(line, " ");
    token = strtok(NULL, " ");
    int user = atoi(token);
    token = strtok(NULL, " ");
    int nice = atoi(token);
    token = strtok(NULL, " ");
    int sys = atoi(token);
    token = strtok(NULL, " ");
    int idle = atoi(token);

    // Calculate the CPU usage
    while (1) {
        // Sleep for 1 second
        sleep(1);

        // Open the stat file again
        FILE* fp = fopen(str, "r");

        // Read the first line of the file again
        char* line = NULL;
        size_t len = 0;
        ssize_t read = getline(&line, &len, fp);

        // Close the file
        fclose(fp);

        // Parse the first line of the file again
        char* token = strtok(line, " ");
        token = strtok(NULL, " ");
        int new_user = atoi(token);
        token = strtok(NULL, " ");
        int new_nice = atoi(token);
        token = strtok(NULL, " ");
        int new_sys = atoi(token);
        token = strtok(NULL, " ");
        int new_idle = atoi(token);

        // Calculate the CPU usage percentage
        int diff_idle = new_idle - idle;
        int diff_total = (new_user + new_nice + new_sys + new_idle) - (user + nice + sys + idle);
        float cpu_usage_percentage = ((float) (diff_total - diff_idle) / diff_total) * 100;

        // Update global variables
        idle_cpus += diff_idle;
        cpu_usage += cpu_usage_percentage;

        // Update idle value
        idle = new_idle;
    }

    return NULL;
}