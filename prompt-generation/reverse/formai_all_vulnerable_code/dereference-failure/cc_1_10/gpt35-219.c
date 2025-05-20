//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROC_FILE_NAME_LEN 128
#define MAX_PROC_FILE_CONTENT_LEN 1024
#define CPU_STAT_FILE_NAME "/proc/stat"
#define PROC_PID_STAT_FILE_NAME "/proc/%d/stat"

/*
 * The program uses the /proc filesystem to monitor the CPU usage of the system and
 * individual processes. The program reads from the /proc/stat file to get the CPU usage
 * of the system, and from the /proc/[pid]/stat file to get the CPU usage of individual
 * processes.
 */

/*
 * Get the CPU usage of the system from the /proc/stat file.
 */
int get_system_cpu_usage(long *user, long *nice, long *system, long *idle)
{
    char *line = (char *)malloc(MAX_PROC_FILE_CONTENT_LEN);
    FILE *file = fopen(CPU_STAT_FILE_NAME, "r");
    int ret = 0;

    if (!file) {
        fprintf(stderr, "Failed to open %s\n", CPU_STAT_FILE_NAME);
        return -1;
    }

    fgets(line, MAX_PROC_FILE_CONTENT_LEN, file);

    if (strncmp(line, "cpu ", 4) != 0) {
        fprintf(stderr, "Error reading %s\n", CPU_STAT_FILE_NAME);
        ret = -1;
        goto free_mem;
    }

    sscanf(line, "cpu %ld %ld %ld %ld", user, nice, system, idle);

free_mem:
    free(line);
    fclose(file);

    return ret;
}

/*
 * Get the CPU usage of an individual process from the /proc/[pid]/stat file.
 */
int get_process_cpu_usage(pid_t pid, long *utime, long *stime) {
    char file_name[MAX_PROC_FILE_NAME_LEN];
    char *line = (char *)malloc(MAX_PROC_FILE_CONTENT_LEN);
    int fd = -1, ret = 0;

    snprintf(file_name, MAX_PROC_FILE_NAME_LEN, PROC_PID_STAT_FILE_NAME, pid);

    fd = open(file_name, O_RDONLY);

    if (fd < 0) {
        fprintf(stderr, "Failed to open %s\n", file_name);
        return -1;
    }

    if (read(fd, line, MAX_PROC_FILE_CONTENT_LEN) <= 0) {
        fprintf(stderr, "Failed to read from %s\n", file_name);
        ret = -1;
        goto free_mem;
    }

    sscanf(line, "%*d %*s %*c %*d %*d %*d %*d %*d %*u %*lu %*lu %*lu %*lu %ld %ld",
           utime, stime);

free_mem:
    free(line);
    close(fd);

    return ret;
}

int main(int argc, char *argv[])
{
    long prev_user = 0, prev_nice = 0, prev_system = 0, prev_idle = 0;
    long curr_user = 0, curr_nice = 0, curr_system = 0, curr_idle = 0;
    long delta_total = 0, delta_idle = 0;
    long utime = 0, stime = 0;
    pid_t pid = getpid();

    printf("Process ID: %d\n", pid);

    if (get_system_cpu_usage(&prev_user, &prev_nice, &prev_system, &prev_idle) != 0) {
        fprintf(stderr, "Failed to get system CPU usage\n");
        return -1;
    }

    printf("System CPU usage: user=%ld nice=%ld system=%ld idle=%ld\n",
           prev_user, prev_nice, prev_system, prev_idle);

    while (1) {
        if (get_process_cpu_usage(pid, &utime, &stime) != 0) {
            fprintf(stderr, "Failed to get process CPU usage\n");
            continue;
        }

        printf("\nProcess CPU time: utime=%ld stime=%ld\n", utime, stime);

        if (get_system_cpu_usage(&curr_user, &curr_nice, &curr_system, &curr_idle) != 0) {
            fprintf(stderr, "Failed to get system CPU usage\n");
            continue;
        }

        printf("System CPU usage: user=%ld nice=%ld system=%ld idle=%ld\n",
               curr_user, curr_nice, curr_system, curr_idle);

        delta_total = ((curr_user + curr_nice + curr_system) -
                       (prev_user + prev_nice + prev_system));
        delta_idle = (curr_idle - prev_idle);

        printf("Process CPU usage: %.2f%%\n", (((float)(utime + stime)) / delta_total) * 100);
        printf("System CPU usage: %.2f%%\n", (((float)(delta_total - delta_idle)) / delta_total) * 100);

        prev_user = curr_user;
        prev_nice = curr_nice;
        prev_system = curr_system;
        prev_idle = curr_idle;

        sleep(1);
    }

    return 0;
}