//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// Data structure to store information about a process
typedef struct process_info {
    pid_t pid;
    char name[32];
    int state;
    int ppid;
    int threads;
    int vsize;
    int rss;
    char user[32];
    char start_time[32];
} process_info;

// Function to get the process information
int get_process_info(pid_t pid, process_info *info)
{
    char path[64];
    int fd;
    char buf[4096];
    char *p;

    // Open the process status file
    snprintf(path, sizeof(path), "/proc/%d/status", pid);
    fd = open(path, O_RDONLY);
    if (fd < 0) {
        return -1;
    }

    // Read the status file
    int n = read(fd, buf, sizeof(buf));
    close(fd);
    if (n < 0) {
        return -1;
    }

    // Parse the status file
    info->pid = pid;
    p = strstr(buf, "Name:");
    if (p) {
        sscanf(p, "Name: %s", info->name);
    }
    p = strstr(buf, "State:");
    if (p) {
        sscanf(p, "State: %c", &info->state);
    }
    p = strstr(buf, "PPid:");
    if (p) {
        sscanf(p, "PPid: %d", &info->ppid);
    }
    p = strstr(buf, "Threads:");
    if (p) {
        sscanf(p, "Threads: %d", &info->threads);
    }
    p = strstr(buf, "VmSize:");
    if (p) {
        sscanf(p, "VmSize: %d kB", &info->vsize);
    }
    p = strstr(buf, "VmRSS:");
    if (p) {
        sscanf(p, "VmRSS: %d kB", &info->rss);
    }
    p = strstr(buf, "User:");
    if (p) {
        sscanf(p, "User: %s", info->user);
    }
    p = strstr(buf, "StartTime:");
    if (p) {
        sscanf(p, "StartTime: %s", info->start_time);
    }

    return 0;
}

// Function to print the process information
void print_process_info(process_info *info)
{
    printf("PID: %d\n", info->pid);
    printf("Name: %s\n", info->name);
    printf("State: %c\n", info->state);
    printf("PPid: %d\n", info->ppid);
    printf("Threads: %d\n", info->threads);
    printf("Vsize: %d kB\n", info->vsize);
    printf("RSS: %d kB\n", info->rss);
    printf("User: %s\n", info->user);
    printf("Start Time: %s\n", info->start_time);
    printf("\n");
}

// Main function
int main(int argc, char *argv[])
{
    pid_t pid;
    process_info info;

    // Get the process ID
    if (argc > 1) {
        pid = atoi(argv[1]);
    } else {
        pid = getpid();
    }

    // Get the process information
    if (get_process_info(pid, &info) < 0) {
        perror("get_process_info");
        return 1;
    }

    // Print the process information
    print_process_info(&info);

    return 0;
}