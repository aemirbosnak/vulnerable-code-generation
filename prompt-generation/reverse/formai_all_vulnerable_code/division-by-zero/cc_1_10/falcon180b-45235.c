//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <string.h>

#define CPU_USAGE_INTERVAL 5 // in seconds
#define BUFFER_SIZE 1024

struct rusage cpu_usage;
int fd;
char buffer[BUFFER_SIZE];

void get_cpu_usage() {
    if (getrusage(RUSAGE_SELF, &cpu_usage)!= 0) {
        printf("Error getting CPU usage.\n");
        exit(1);
    }
}

void read_file(const char* filename) {
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_read = read(fd, buffer, BUFFER_SIZE);

        if (bytes_read == 0) {
            printf("\nEnd of file reached.\n");
            break;
        } else if (bytes_read == -1) {
            printf("Error reading file: %s\n", filename);
            exit(1);
        }

        printf("%s", buffer);
    }

    close(fd);
}

int main() {
    printf("Starting CPU usage monitor...\n");

    while (1) {
        get_cpu_usage();
        printf("CPU usage: %ld%%\n", cpu_usage.ru_maxrss * 100 / getpagesize());

        read_file("/proc/cpuinfo");
        sleep(CPU_USAGE_INTERVAL);
    }

    return 0;
}