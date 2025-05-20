//FormAI DATASET v1.0 Category: System process viewer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

// define maximum number of processes to display
#define MAX_PROCESSES 100

// define structure to hold process information
struct Process {
    int pid;
    char name[50];
    char state;
    int priority;
    int parent_pid;
};

// function to read process information
void readProcessInfo(struct Process p[], int *num_processes) {
    // open the /proc directory
    DIR *dir = opendir("/proc");
    if (dir == NULL) {
        perror("Failed to open /proc");
        exit(1);
    }

    // loop through each entry in the directory
    struct dirent *entry;
    *num_processes = 0;
    while ((entry = readdir(dir)) != NULL && *num_processes < MAX_PROCESSES) {
        // check if the entry is a directory (i.e. a process)
        if (entry->d_type == DT_DIR) {
            // check if the name of the directory can be converted to an integer
            int pid = atoi(entry->d_name);
            if (pid > 0) {
                // read the process information from the /proc/PID/stat file
                char stat_file[100];
                sprintf(stat_file, "/proc/%d/stat", pid);
                FILE *file = fopen(stat_file, "r");
                if (file == NULL) continue;
                int ppid;
                fscanf(file, "%d %s %c %d %d", &pid, p[*num_processes].name, &p[*num_processes].state, &ppid, &p[*num_processes].priority);
                p[*num_processes].pid = pid;
                p[*num_processes].parent_pid = ppid;
                (*num_processes)++;
                fclose(file);
            }
        }
    }

    closedir(dir);
}

// function to print process information
void printProcessInfo(struct Process p[], int num_processes) {
    printf("%5s %20s %5s %5s %10s\n", "PID", "NAME", "STATE", "PPID", "PRIORITY");
    for (int i = 0; i < num_processes; i++) {
        printf("%5d %20s %5c %5d %10d\n", p[i].pid, p[i].name, p[i].state, p[i].parent_pid, p[i].priority);
    }
}

int main() {
    // declare the array to store process information
    struct Process processes[MAX_PROCESSES];

    // read the process information
    int num_processes;
    readProcessInfo(processes, &num_processes);

    // print the process information
    printProcessInfo(processes, num_processes);

    return 0;
}