//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define BUF_SIZE 1024
#define CPU_COUNT 8 // Number of CPU cores

// Function to read CPU usage from /proc/stat
double * read_cpu_usage() {
    double * usage = (double *) malloc(CPU_COUNT * sizeof(double));

    int fd = open("/proc/stat", O_RDONLY);
    if (fd == -1) {
        perror("open failed");
        exit(1);
    }

    char buffer[BUF_SIZE];
    if (read(fd, buffer, BUF_SIZE) <= 0) {
        perror("read failed");
        exit(1);
    }

    close(fd);

    char * line = strtok(buffer, "\n");
    int core = 0;
    while (line != NULL) {
        if (strncmp(line, "cpu", 3) == 0) {
            line += 3;

            unsigned long long fields[10];
            int i = 0;
            char * token = strtok(line, " ");
            while (token != NULL) {
                fields[i++] = strtoull(token, NULL, 10);
                token = strtok(NULL, " ");
            }

            unsigned long long total_time = fields[0] + fields[1] + fields[2] +
                                             fields[3] + fields[4] + fields[5] +
                                             fields[6] + fields[7] + fields[8] +
                                             fields[9];
            unsigned long long idle_time = fields[3];

            double percent = 1.0 - ((double)idle_time / (double)total_time);
            usage[core++] = percent;
        }

        line = strtok(NULL, "\n");
    }

    return usage;
}

int main() {
    double * prev = read_cpu_usage();

    while (1) {
        sleep(1);

        double * current = read_cpu_usage();

        printf("CPU Usage:\n");
        for (int i = 0; i < CPU_COUNT; i++) {
            printf("\tCore %d: %0.2f%%\n", i, (current[i] - prev[i]) * 100.0);
        }

        free(prev);
        prev = current;
    }

    return 0;
}