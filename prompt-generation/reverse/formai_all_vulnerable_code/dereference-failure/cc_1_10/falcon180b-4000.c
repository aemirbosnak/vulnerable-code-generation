//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

#define BUFFER_SIZE 1024

// Function to read the contents of a file into a buffer
int read_file(const char* filename, char* buffer) {
    int file_descriptor = open(filename, O_RDONLY);
    if (file_descriptor == -1) {
        perror("Error opening file");
        return 1;
    }

    ssize_t bytes_read = read(file_descriptor, buffer, BUFFER_SIZE);
    if (bytes_read == -1) {
        perror("Error reading file");
        close(file_descriptor);
        return 1;
    }

    close(file_descriptor);
    return 0;
}

// Function to print the CPU usage statistics
void print_cpu_usage(struct rusage usage) {
    double cpu_percentage = (double)usage.ru_utime.tv_sec + (double)usage.ru_utime.tv_usec / 1000000.0;
    cpu_percentage /= (double)usage.ru_stime.tv_sec + (double)usage.ru_stime.tv_usec / 1000000.0;

    printf("CPU usage: %.2f%%\n", cpu_percentage * 100.0);
}

// Function to monitor the CPU usage
void monitor_cpu_usage(int interval_seconds) {
    struct rusage usage;

    while (1) {
        int result = getrusage(RUSAGE_SELF, &usage);
        if (result == -1) {
            perror("Error getting resource usage");
            break;
        }

        print_cpu_usage(usage);

        sleep(interval_seconds);
    }
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <interval_seconds>\n", argv[0]);
        return 1;
    }

    int interval_seconds = atoi(argv[1]);

    if (interval_seconds <= 0) {
        fprintf(stderr, "Invalid interval\n");
        return 1;
    }

    monitor_cpu_usage(interval_seconds);

    return 0;
}