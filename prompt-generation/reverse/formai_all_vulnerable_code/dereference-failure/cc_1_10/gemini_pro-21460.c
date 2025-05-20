//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

// Get the current CPU usage as a percentage
int get_cpu_usage() {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Error opening /proc/stat");
        return -1;
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        if (strstr(line, "cpu")) {
            // The first number after "cpu" is the total CPU usage
            char *token = strtok(line, " ");
            token = strtok(NULL, " ");
            return atoi(token);
        }
    }

    fclose(fp);
    free(line);
    return -1;
}

// Print a progress bar representing the CPU usage
void print_progress_bar(int usage) {
    printf("[");
    for (int i = 0; i < usage / 2; i++) {
        printf("#");
    }
    for (int i = usage / 2; i < 50; i++) {
        printf(".");
    }
    printf("] %d%%\n", usage);
}

int main() {
    // Get the initial CPU usage
    int usage = get_cpu_usage();

    // Keep track of the maximum CPU usage
    int max_usage = usage;

    // Loop forever, printing the CPU usage every second
    while (1) {
        // Get the current CPU usage
        usage = get_cpu_usage();

        // Update the maximum CPU usage if necessary
        if (usage > max_usage) {
            max_usage = usage;
        }

        // Print the progress bar
        print_progress_bar(usage);

        // Sleep for one second
        sleep(1);
    }

    return 0;
}