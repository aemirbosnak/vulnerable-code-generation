//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

// Define the maximum number of processes to display
#define MAX_PROCESSES 100

// Define the structure of a process
typedef struct process {
    pid_t pid;
    char name[256];
    char state;
    unsigned long int mem_usage;
    char* path;
} process_t;

// Compare two processes by their memory usage
int compare_processes(const void* a, const void* b) {
    const process_t* process_a = (const process_t*) a;
    const process_t* process_b = (const process_t*) b;
    return (int) (process_b->mem_usage - process_a->mem_usage);
}

// Get the list of processes
int get_processes(process_t processes[], int* num_processes) {
    DIR* proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        perror("Error opening /proc directory");
        return -1;
    }

    struct dirent* entry;
    int i = 0;
    while ((entry = readdir(proc_dir)) != NULL && i < MAX_PROCESSES) {
        // Skip non-numeric directories
        if (!isdigit(entry->d_name[0])) {
            continue;
        }

        // Get the process ID
        processes[i].pid = atoi(entry->d_name);

        // Get the process name
        char path[256];
        snprintf(path, sizeof(path), "/proc/%d/cmdline", processes[i].pid);
        FILE* cmdline_file = fopen(path, "r");
        if (cmdline_file == NULL) {
            perror("Error opening cmdline file");
            closedir(proc_dir);
            return -1;
        }
        fgets(processes[i].name, sizeof(processes[i].name), cmdline_file);
        fclose(cmdline_file);

        // Get the process state
        path[256];
        snprintf(path, sizeof(path), "/proc/%d/stat", processes[i].pid);
        FILE* stat_file = fopen(path, "r");
        if (stat_file == NULL) {
            perror("Error opening stat file");
            closedir(proc_dir);
            return -1;
        }
        fscanf(stat_file, "%*d %*s %c %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*ld %*ld %*ld %*ld %*ld %lu", &processes[i].state, &processes[i].mem_usage);
        fclose(stat_file);

        // Get the process path
        path[259];
        snprintf(path, sizeof(path), "/proc/%d/cwd", processes[i].pid);
        processes[i].path = realpath(path, NULL);

        i++;
    }

    closedir(proc_dir);

    *num_processes = i;

    return 0;
}

// Print the list of processes
void print_processes(const process_t processes[], int num_processes) {
    printf("%-7s %-20s %-5s %-10s %-10s\n", "PID", "Name", "State", "MemUsage", "Path");
    for (int i = 0; i < num_processes; i++) {
        printf("%-7ld %-20s %-5c %-10lu %-10s\n", processes[i].pid, processes[i].name, processes[i].state, processes[i].mem_usage, processes[i].path);
    }
}

int main() {
    // Get the list of processes
    process_t processes[MAX_PROCESSES];
    int num_processes;
    if (get_processes(processes, &num_processes) != 0) {
        return EXIT_FAILURE;
    }

    // Sort the processes by their memory usage
    qsort(processes, num_processes, sizeof(process_t), compare_processes);

    // Print the list of processes
    print_processes(processes, num_processes);

    return EXIT_SUCCESS;
}