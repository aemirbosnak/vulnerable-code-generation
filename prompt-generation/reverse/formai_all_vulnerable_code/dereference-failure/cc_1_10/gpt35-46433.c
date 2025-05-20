//FormAI DATASET v1.0 Category: System process viewer ; Style: Machiavellien
// Machiavellien-style System Process Viewer Program

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>

// Define the struct to store information about each process
struct Process {
    int pid;
    char name[100];
    char state;
    int priority;
    long unsigned int memory_usage;
};

// Define function to print process information
void print_process_info(struct Process p) {
    printf("%d\t%s\t%c\t%d\t%lu KB\n", p.pid, p.name, p.state, p.priority, p.memory_usage / 1024);
}

int main() {
    // Open the directory containing information about all processes
    DIR* proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        perror("Error opening /proc directory");
        exit(1);
    }

    // Print the header for the process information table
    printf("PID\tProcess Name\tState\tPriority\tMemory Usage\n");

    // Loop through each directory in /proc to find information about each process
    struct dirent* entry;
    while ((entry = readdir(proc_dir))) {
        char* name = entry->d_name;
        // Check if the directory name is a number (i.e. a process ID)
        if (name[0] >= '0' && name[0] <= '9') {
            // Create the path to the process status file
            char status_path[100];
            snprintf(status_path, sizeof(status_path), "/proc/%s/status", name);
            // Open the status file for the process
            FILE* status_file = fopen(status_path, "r");
            if (status_file != NULL) {
                // Read in the necessary information from the status file
                struct Process p;
                p.pid = atoi(name);
                while (fgets(status_path, sizeof(status_path), status_file)) {
                    char* colon = strchr(status_path, ':');
                    if (colon != NULL) {
                        if (strncmp(status_path, "Name", 4) == 0) {
                            // Copy the process name into the struct
                            sscanf(colon + 2, "%s", p.name);
                        } else if (strncmp(status_path, "State", 5) == 0) {
                            // Copy the process state into the struct
                            sscanf(colon + 2, "%c", &p.state);
                        } else if (strncmp(status_path, "Priority", 8) == 0) {
                            // Copy the process priority into the struct
                            sscanf(colon + 2, "%d", &p.priority);
                        } else if (strncmp(status_path, "VmRSS", 5) == 0) {
                            // Copy the process memory usage into the struct
                            sscanf(colon + 2, "%lu", &p.memory_usage);
                        }
                    }
                }
                // Close the status file for the process
                fclose(status_file);
                // Print the information about the process
                print_process_info(p);
            }
        }
    }

    // Close the directory containing information about all processes
    closedir(proc_dir);

    return 0;
}