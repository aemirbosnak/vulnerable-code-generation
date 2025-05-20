//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/time.h>

// Global variables
int user_id;
double prev_total_time;
double prev_idle_time;

// Function to get the current user's ID
int get_user_id() {
    struct passwd *pw = getpwuid(getuid());
    return pw->pw_uid;
}

// Function to get the CPU usage in percentage
double get_cpu_usage() {
    FILE *fh = fopen("/proc/stat", "r");
    if (fh == NULL) {
        perror("Error opening /proc/stat");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fh) != NULL) {
        if (strncmp(buffer, "cpu ", 4) == 0) {
            // Parse the CPU usage information
            long long user_time, nice_time, system_time, idle_time, iowait_time, irq_time, softirq_time, total_time;
            sscanf(buffer, "cpu  %lld %lld %lld %lld %lld %lld %lld %lld", &user_time, &nice_time, &system_time, &idle_time, &iowait_time, &irq_time, &softirq_time, &total_time);

            // Calculate the CPU usage in percentage
            double cpu_usage = (total_time - idle_time - (prev_total_time - prev_idle_time)) * 100.0 / (total_time - prev_total_time);

            // Update the previous total time and idle time
            prev_total_time = total_time;
            prev_idle_time = idle_time;

            fclose(fh);
            return cpu_usage;
        }
    }

    fclose(fh);
    return -1.0;
}

// Function to print the CPU usage in a lively style
void print_cpu_usage(double cpu_usage) {
    // Get the current user's name
    struct passwd *pw = getpwuid(user_id);
    char *username = pw->pw_name;

    // Print the CPU usage
    printf("Hi %s, your CPU usage is: %.2f%%\n", username, cpu_usage);

    // Print a lively message based on the CPU usage
    if (cpu_usage < 20.0) {
        printf("Your CPU is taking a siesta!\n");
    } else if (cpu_usage < 50.0) {
        printf("Your CPU is working hard, but not too hard.\n");
    } else if (cpu_usage < 80.0) {
        printf("Your CPU is sweating a bit!\n");
    } else if (cpu_usage < 90.0) {
        printf("Your CPU is on fire! Please cool it down.\n");
    } else {
        printf("Your CPU is melting! Time to upgrade your computer.\n");
    }
}

// Main function
int main() {
    // Get the current user's ID
    user_id = get_user_id();

    // Infinite loop to continuously monitor the CPU usage
    while (1) {
        // Get the CPU usage in percentage
        double cpu_usage = get_cpu_usage();

        // Print the CPU usage in a lively style
        print_cpu_usage(cpu_usage);

        // Sleep for 1 second
        sleep(1);
    }

    return 0;
}