//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 256
#define PROC_DIRECTORY "/proc"

// Function to check if a string is a number
int is_number(const char *str) {
    while (*str) {
        if (!isdigit(*str)) return 0;
        str++;
    }
    return 1;
}

// Function to get process details
void get_process_details(const char *pid) {
    char path[BUFFER_SIZE], line[BUFFER_SIZE];
    FILE *status_file;
    char comm[BUFFER_SIZE], state[BUFFER_SIZE];
    int ppid, vm_size;

    snprintf(path, sizeof(path), PROC_DIRECTORY "/%s/status", pid);
    status_file = fopen(path, "r");
    if (status_file == NULL) return;

    // Initialize default values
    strcpy(comm, "N/A");
    strcpy(state, "N/A");
    ppid = -1;
    vm_size = -1;

    // Read the process status
    while (fgets(line, sizeof(line), status_file)) {
        if (sscanf(line, "Name:\t%[^\n]", comm) == 1) continue;
        if (sscanf(line, "State:\t%[^\n]", state) == 1) continue;
        if (sscanf(line, "Pid:\t%d", &ppid) == 1) continue;
        if (sscanf(line, "VmSize:\t%d", &vm_size) == 1) continue;
    }

    fclose(status_file);

    // Display process details in a nice format
    printf("| PID: %-6s | State: %9s | Comm: %-15s | VMSize: %-6d | \n", pid, state, comm, vm_size / 1024);
}

// The main function to list processes
int main() {
    DIR *proc_dir;
    struct dirent *entry;

    printf("***********************************************\n");
    printf("*               Process Viewer                *\n");
    printf("***********************************************\n");
    printf("| PID:      | State:     | Comm:            | VMSize:  |\n");
    printf("---------------------------------------------------------\n");

    // Open the proc directory
    proc_dir = opendir(PROC_DIRECTORY);
    if (proc_dir == NULL) {
        perror("Failed to open /proc directory");
        return 1;
    }

    // Iterate through the entries in the /proc directory
    while ((entry = readdir(proc_dir)) != NULL) {
        if (is_number(entry->d_name)) {
            get_process_details(entry->d_name);
        }
    }

    closedir(proc_dir);
    printf("---------------------------------------------------------\n");
    printf("* End of Process List                                 *\n");
    printf("***********************************************\n");

    return 0;
}