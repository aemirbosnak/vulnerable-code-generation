//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>

// Custom data structure to store process information
typedef struct {
    pid_t pid;
    char name[256];
    char state;
    int ppid;
    int mem_usage;
    int cpu_usage;
} ProcessInfo;

// Function to compare ProcessInfo structures by PID
int compare_processes(const void *a, const void *b) {
    const ProcessInfo *p1 = (const ProcessInfo *)a;
    const ProcessInfo *p2 = (const ProcessInfo *)b;
    return p1->pid - p2->pid;
}

// Function to get process information from /proc/[pid]
int get_process_info(pid_t pid, ProcessInfo *info) {
    char path[256];
    int fd;
    char buf[1024];
    int n;

    // Open /proc/[pid]/status
    snprintf(path, sizeof(path), "/proc/%d/status", pid);
    fd = open(path, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return -1;
    }

    // Read the contents of /proc/[pid]/status into a buffer
    n = read(fd, buf, sizeof(buf) - 1);
    if (n == -1) {
        perror("read");
        close(fd);
        return -1;
    }
    buf[n] = '\0';

    // Parse the buffer to extract process information
    info->pid = pid;
    if (sscanf(buf, "Name:\t%s", info->name) != 1) {
        info->name[0] = '\0';
    }
    if (sscanf(buf, "State:\t%c", &info->state) != 1) {
        info->state = '?';
    }
    if (sscanf(buf, "PPid:\t%d", &info->ppid) != 1) {
        info->ppid = 0;
    }
    if (sscanf(buf, "VmSize:\t%d kB", &info->mem_usage) != 1) {
        info->mem_usage = 0;
    }
    if (sscanf(buf, "CpuTime:\t%d", &info->cpu_usage) != 1) {
        info->cpu_usage = 0;
    }

    // Close the file descriptor
    close(fd);

    return 0;
}

// Function to display process information
void print_process_info(const ProcessInfo *info) {
    printf("%-5d %-16s %-1c %-5d %-6d %-6d\n",
           info->pid, info->name, info->state, info->ppid,
           info->mem_usage, info->cpu_usage);
}

// Main function
int main(int argc, char *argv[]) {
    DIR *procdir;
    struct dirent *ent;
    int nprocs;
    ProcessInfo *procs;
    int i;

    // Open /proc directory
    procdir = opendir("/proc");
    if (procdir == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    // Count the number of processes
    nprocs = 0;
    while ((ent = readdir(procdir)) != NULL) {
        if (ent->d_type == DT_DIR) {
            nprocs++;
        }
    }
    rewinddir(procdir);

    // Allocate memory for the process information
    procs = malloc(sizeof(ProcessInfo) * nprocs);
    if (procs == NULL) {
        perror("malloc");
        closedir(procdir);
        return EXIT_FAILURE;
    }

    // Read process information from /proc/[pid]
    i = 0;
    while ((ent = readdir(procdir)) != NULL) {
        if (ent->d_type == DT_DIR) {
            int pid = atoi(ent->d_name);
            if (pid > 0) {
                if (get_process_info(pid, &procs[i]) == 0) {
                    i++;
                }
            }
        }
    }
    closedir(procdir);

    // Sort the process information by PID
    qsort(procs, nprocs, sizeof(ProcessInfo), compare_processes);

    // Print the process information
    printf("%-5s %-16s %-1c %-5s %-6s %-6s\n", "PID", "NAME", "STATE", "PPID", "MEM", "CPU");
    for (i = 0; i < nprocs; i++) {
        print_process_info(&procs[i]);
    }

    // Free the allocated memory
    free(procs);

    return EXIT_SUCCESS;
}