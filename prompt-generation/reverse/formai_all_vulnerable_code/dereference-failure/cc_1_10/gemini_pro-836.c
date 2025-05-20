//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

// Structure to store process information
typedef struct Process {
    pid_t pid;
    char name[256];
    char state;
    unsigned long ppid;
    unsigned long utime;
    unsigned long stime;
} Process;

// Function to compare two processes based on their PID
int compare_processes(const void *a, const void *b) {
    const Process *p1 = (const Process *)a;
    const Process *p2 = (const Process *)b;
    return p1->pid - p2->pid;
}

int main() {
    // Open the /proc directory
    DIR *procdir = opendir("/proc");
    if (procdir == NULL) {
        perror("Error opening /proc directory");
        return EXIT_FAILURE;
    }

    // Allocate memory for an array of Process structures
    Process *processes = malloc(sizeof(Process) * 1024);
    if (processes == NULL) {
        perror("Error allocating memory for processes");
        closedir(procdir);
        return EXIT_FAILURE;
    }

    // Initialize the number of processes found to 0
    int num_processes = 0;

    // Iterate over the /proc directory
    struct dirent *dirent;
    while ((dirent = readdir(procdir)) != NULL) {
        // Skip entries that are not directories
        if (!strcmp(dirent->d_name, ".") || !strcmp(dirent->d_name, "..")) {
            continue;
        }

        // Get the PID from the directory name
        pid_t pid = atoi(dirent->d_name);

        // Read the /proc/[PID]/stat file
        char stat_file[256];
        snprintf(stat_file, sizeof(stat_file), "/proc/%d/stat", pid);
        FILE *statfp = fopen(stat_file, "r");
        if (statfp == NULL) {
            perror("Error opening stat file");
            continue;
        }

        // Parse the stat file
        char line[1024];
        if (fgets(line, sizeof(line), statfp) == NULL) {
            perror("Error reading stat file");
            fclose(statfp);
            continue;
        }

        // Store the process information in the Process structure
        Process process;
        process.pid = pid;
        sscanf(line, "%*d %s %c %*d %*d %*d %*d %*d %*d %lu %lu", process.name, &process.state, &process.ppid, &process.utime, &process.stime);

        // Add the process to the array
        processes[num_processes] = process;
        num_processes++;

        // Close the stat file
        fclose(statfp);
    }

    // Close the /proc directory
    closedir(procdir);

    // Sort the processes by their PID
    qsort(processes, num_processes, sizeof(Process), compare_processes);

    // Print the process information
    printf("%-5s %-16s %-2s %-6s %-8s %-8s\n", "PID", "Name", "State", "PPID", "UTime", "STime");
    for (int i = 0; i < num_processes; i++) {
        printf("%-5d %-16s %-2c %-6lu %-8lu %-8lu\n", processes[i].pid, processes[i].name, processes[i].state, processes[i].ppid, 
processes[i].utime, processes[i].stime);
    }

    // Free the memory allocated for the array of Process structures
    free(processes);

    return EXIT_SUCCESS;
}