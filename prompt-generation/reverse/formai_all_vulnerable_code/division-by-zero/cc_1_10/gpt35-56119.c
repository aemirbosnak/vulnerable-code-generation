//FormAI DATASET v1.0 Category: System process viewer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 255

// Define the structure to hold process information
typedef struct process {
    int pid;
    char name[MAX_NAME_LEN];
    int cpu_percentage;
} process_t;

// Function to calculate CPU usage percentage for a process
int get_cpu_percentage(int pid) {
    char pid_str[10];
    sprintf(pid_str, "%d", pid);

    // Open the process stat file
    char stat_path[100];
    sprintf(stat_path, "/proc/%s/stat", pid_str);

    FILE* stat_file = fopen(stat_path, "r");

    if (!stat_file) {
        return -1;
    }

    char line[1024];
    fgets(line, 1024, stat_file);

    fclose(stat_file);

    // Extract the required values from process stat file
    int process_time = 0;
    int system_time = 0;
    int utime = 0;
    int stime = 0;

    sscanf(line, "%*d %*s %*c %*d %*d %*d %*d %*d %*u %*lu %*lu %*lu "
    "%*lu %*lu %*lu %*ld %*ld %*ld %*ld %*ld %*ld %d %d %*ld %*ld %*ld %*ld "
    "%*ld %*ld %*ld %*ld %*ld %*ld %*ld %d %d", &utime, &stime, &process_time, &system_time);

    // Calculate the total time spent by the process
    int total_time = utime + stime;
    int cpu_percentage = total_time * 100 / (process_time + system_time);

    return cpu_percentage;
}

// Function to retrieve the name of a process using its PID
char* get_process_name_by_pid(int pid) {
    char pid_str[10];
    sprintf(pid_str, "%d", pid);

    // Open the process comm file
    char comm_path[100];
    sprintf(comm_path, "/proc/%s/comm", pid_str);

    FILE* comm_file = fopen(comm_path, "r");

    if (!comm_file) {
        return NULL;
    }

    // Read the process name from comm file
    char* process_name = (char*) malloc(MAX_NAME_LEN);

    fgets(process_name, MAX_NAME_LEN, comm_file);

    // Remove newline character from the end of process name
    int len = strlen(process_name);

    if (len > 0 && process_name[len-1] == '\n') {
        process_name[len-1] = '\0';
    }

    fclose(comm_file);

    return process_name;
}

// Function to print process information
void print_process_info(process_t process) {
    printf("%-10d %-20s %d%%\n", process.pid, process.name, process.cpu_percentage);
}

// Function to sort processes by CPU percentage
int compare_processes(const void* a, const void* b) {
    process_t* process_a = (process_t*) a;
    process_t* process_b = (process_t*) b;

    return process_b->cpu_percentage - process_a->cpu_percentage;
}

int main() {
    // Open the /proc directory
    DIR* proc_dir = opendir("/proc");

    if (!proc_dir) {
        printf("Failed to open /proc directory\n");
        exit(1);
    }

    // Read the directory contents to find process directories
    struct dirent* entry;

    process_t processes[1000];
    int num_processes = 0;

    while ((entry = readdir(proc_dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            // Found a process directory

            int pid = atoi(entry->d_name);

            char* process_name = get_process_name_by_pid(pid);

            int cpu_percentage = get_cpu_percentage(pid);

            if (process_name && cpu_percentage >= 0) {
                process_t process;
                process.pid = pid;
                strcpy(process.name, process_name);
                process.cpu_percentage = cpu_percentage;

                processes[num_processes++] = process;
            }

            free(process_name);
        }
    }

    closedir(proc_dir);

    // Sort the processes by CPU percentage
    qsort(processes, num_processes, sizeof(process_t), compare_processes);

    // Print the process information
    printf("%-10s %-20s %s\n", "PID", "Name", "CPU%");
    printf("---------------------------------\n");

    for (int i = 0; i < num_processes; i++) {
        print_process_info(processes[i]);
    }

    return 0;
}