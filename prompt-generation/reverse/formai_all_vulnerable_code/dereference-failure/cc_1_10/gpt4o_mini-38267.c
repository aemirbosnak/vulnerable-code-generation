//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

#define MAX_PROCESSES 1024
#define NAME_LENGTH 256

typedef struct {
    pid_t pid;
    char name[NAME_LENGTH];
    char state[20];
} Process;

// Function to retrieve the list of processes
int gather_processes(Process *processes) {
    DIR *dir;
    struct dirent *entry;
    int count = 0;

    // Open the directory of process IDs
    dir = opendir("/proc");
    if (!dir) {
        perror("A wretched error has occurred whilst opening the process directory");
        return -1;
    }

    // Iterate through each entry in the directory
    while ((entry = readdir(dir)) != NULL) {
        // Check if the entry is a number which represents a PID
        if (entry->d_type == DT_DIR && atoi(entry->d_name) > 0) {
            pid_t pid = atoi(entry->d_name);
            char path[NAME_LENGTH], line[NAME_LENGTH];
            FILE *file;

            // Construct the path for the status file
            snprintf(path, sizeof(path), "/proc/%d/status", pid);
            file = fopen(path, "r");
            if (!file) {
                continue;
            }

            // Read the name and state from the status file
            snprintf(processes[count].name, sizeof(processes[count].name), "Unknown");
            snprintf(processes[count].state, sizeof(processes[count].state), "Unknown");

            // Parse the status file for Process name and state
            while (fgets(line, sizeof(line), file)) {
                if (sscanf(line, "Name:\t%s", processes[count].name) == 1) {
                    // Successfully retrieved name
                }
                if (sscanf(line, "State:\t%s", processes[count].state) == 1) {
                    // Successfully retrieved state
                }
            }
            fclose(file);

            // Populate the process struct
            processes[count].pid = pid;
            count++;
        }
    }
    closedir(dir);
    return count;
}

// Function to display the processes in a medieval style
void display_processes(Process *processes, int count) {
    printf("Hark! Behold the list of noble processes in the realm of thine computer!\n");
    printf("PID\tName\t\t\tState\n");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-5d %-20s %-15s\n", processes[i].pid, processes[i].name, processes[i].state);
    }
}

// Main function that serves as the gatekeeper to the assembly
int main() {
    Process processes[MAX_PROCESSES];
    int count;

    // Summon the spirits to gather processes
    count = gather_processes(processes);
    if (count < 0) {
        return EXIT_FAILURE;
    }

    // Display the gathered processes
    display_processes(processes, count);

    // A fitting farewell to the user of this program
    printf("Thus, the viewing of the processes hath concluded.\n");
    return EXIT_SUCCESS;
}