//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>

#define BUFFER_SIZE 4096

double get_cpu_usage(int pid);
void mem_error(char *msg);

int main(int argc, char **argv) {
    pid_t pid;
    double cpu_usage;

    if (argc != 2) {
        printf("Please provide the PID of the process to monitor\n");
        exit(EXIT_FAILURE);
    }

    pid = atoi(argv[1]);

    if (pid <= 0) {
        printf("Invalid PID: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    printf("Starting CPU usage monitor for process with PID %d...\n", pid);

    while (1) {
        cpu_usage = get_cpu_usage(pid);
        printf("CPU usage: %.1f%%\n", cpu_usage);
        sleep(1);
    }

    return 0;
}


double get_cpu_usage(int pid) {
    char stat_file[100];
    char buffer[BUFFER_SIZE];
    int fd, read_bytes;
    char *stat;
    double uptime, user_time, system_time, start_time;
    double cpu_usage;

    sprintf(stat_file, "/proc/%d/stat", pid);

    fd = open(stat_file, O_RDONLY);

    if (fd == -1) {
        printf("Could not open %s: %s\n", stat_file, strerror(errno));
        exit(EXIT_FAILURE);
    }

    read_bytes = read(fd, buffer, BUFFER_SIZE);

    if (read_bytes == -1) {
        printf("Could not read from %s: %s\n", stat_file, strerror(errno));
        exit(EXIT_FAILURE);
    }

    close(fd);

    buffer[read_bytes] = '\0';

    stat = strtok(buffer, " ");

    int i = 0;
    while (stat != NULL) {
        switch (i) {
            case 13:
                user_time = atof(stat);
                break;
            case 14:
                system_time = atof(stat);
                break;
            case 21:
                start_time = atof(stat);
                break;
        }

        i++;
        stat = strtok(NULL, " ");
    }

    fd = open("/proc/uptime", O_RDONLY);

    if (fd == -1) {
        printf("Could not open /proc/uptime: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    read_bytes = read(fd, buffer, BUFFER_SIZE);

    if (read_bytes == -1) {
        printf("Could not read from /proc/uptime: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    close(fd);

    buffer[read_bytes] = '\0';

    uptime = atof(strtok(buffer, " "));

    cpu_usage = 100.0 * (
            ((user_time + system_time) / sysconf(_SC_CLK_TCK)) /
            ((uptime * sysconf(_SC_CLK_TCK)) - start_time)
    );

    return cpu_usage;
}