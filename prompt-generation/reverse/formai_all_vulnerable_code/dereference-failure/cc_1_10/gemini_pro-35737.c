//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>

// Define the maximum number of processes to display
#define MAX_PROCESSES 100

// Define the structure of a process
typedef struct {
    pid_t pid;
    char name[256];
    char state;
    unsigned long int memory;
    unsigned long int cpu;
} process_t;

// Compare two processes by their memory usage
int compare_processes_by_memory(const void *a, const void *b) {
    process_t *process_a = (process_t *)a;
    process_t *process_b = (process_t *)b;

    return process_b->memory - process_a->memory;
}

// Compare two processes by their CPU usage
int compare_processes_by_cpu(const void *a, const void *b) {
    process_t *process_a = (process_t *)a;
    process_t *process_b = (process_t *)b;

    return process_b->cpu - process_a->cpu;
}

// Get the list of processes
int get_processes(process_t *processes) {
    DIR *proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        perror("opendir");
        return -1;
    }

    int num_processes = 0;
    struct dirent *entry;
    while ((entry = readdir(proc_dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            pid_t pid = atoi(entry->d_name);
            if (pid > 0) {
                processes[num_processes].pid = pid;

                // Get the process name
                char proc_name_path[256];
                snprintf(proc_name_path, sizeof(proc_name_path), "/proc/%d/comm", pid);
                int proc_name_fd = open(proc_name_path, O_RDONLY);
                if (proc_name_fd == -1) {
                    perror("open");
                    continue;
                }

                char proc_name[256];
                read(proc_name_fd, proc_name, sizeof(proc_name));
                close(proc_name_fd);

                strcpy(processes[num_processes].name, proc_name);

                // Get the process state
                char proc_state_path[256];
                snprintf(proc_state_path, sizeof(proc_state_path), "/proc/%d/stat", pid);
                int proc_state_fd = open(proc_state_path, O_RDONLY);
                if (proc_state_fd == -1) {
                    perror("open");
                    continue;
                }

                char proc_state[256];
                read(proc_state_fd, proc_state, sizeof(proc_state));
                close(proc_state_fd);

                processes[num_processes].state = proc_state[2];

                // Get the process memory usage
                char proc_memory_path[256];
                snprintf(proc_memory_path, sizeof(proc_memory_path), "/proc/%d/statm", pid);
                int proc_memory_fd = open(proc_memory_path, O_RDONLY);
                if (proc_memory_fd == -1) {
                    perror("open");
                    continue;
                }

                char proc_memory[256];
                read(proc_memory_fd, proc_memory, sizeof(proc_memory));
                close(proc_memory_fd);

                char *proc_memory_tokens = strtok(proc_memory, " ");
                processes[num_processes].memory = atol(proc_memory_tokens);

                // Get the process CPU usage
                char proc_cpu_path[256];
                snprintf(proc_cpu_path, sizeof(proc_cpu_path), "/proc/%d/stat", pid);
                int proc_cpu_fd = open(proc_cpu_path, O_RDONLY);
                if (proc_cpu_fd == -1) {
                    perror("open");
                    continue;
                }

                char proc_cpu[256];
                read(proc_cpu_fd, proc_cpu, sizeof(proc_cpu));
                close(proc_cpu_fd);

                char *proc_cpu_tokens = strtok(proc_cpu, " ");
                for (int i = 0; i < 14; i++) {
                    proc_cpu_tokens = strtok(NULL, " ");
                }

                processes[num_processes].cpu = atol(proc_cpu_tokens);

                num_processes++;
            }
        }
    }

    closedir(proc_dir);

    return num_processes;
}

// Print the list of processes
void print_processes(process_t *processes, int num_processes) {
    // Sort the processes by memory usage
    qsort(processes, num_processes, sizeof(process_t), compare_processes_by_memory);

    // Print the header
    printf("%-5s %-24s %-5s %-10lu %-10lu\n", "PID", "Name", "State", "Memory", "CPU");

    // Print the processes
    for (int i = 0; i < num_processes; i++) {
        printf("%-5d %-24s %-5c %-10lu %-10lu\n", 
            processes[i].pid, 
            processes[i].name, 
            processes[i].state, 
            processes[i].memory, 
            processes[i].cpu);
    }
}

int main() {
    process_t processes[MAX_PROCESSES];
    int num_processes = get_processes(processes);
    if (num_processes == -1) {
        return EXIT_FAILURE;
    }

    print_processes(processes, num_processes);

    return EXIT_SUCCESS;
}