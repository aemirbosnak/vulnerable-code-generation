//FormAI DATASET v1.0 Category: System process viewer ; Style: Alan Touring
// A System Process Viewer Program in C
// written in Alan Turing style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_NUM_PROCESSES 1024
#define PROCESS_NAME_LEN 20
#define STATUS_LEN 256
#define CMDLINE_LEN 512

typedef struct {
    char name[PROCESS_NAME_LEN];
    int pid;
    long unsigned int vsize; // virtual memory size
    char status[STATUS_LEN];
    char cmdline[CMDLINE_LEN];
} process_info_t;

process_info_t processes[MAX_NUM_PROCESSES];

int num_processes = 0;

// Function to read process info from /proc/[pid]
void read_process_info(char* pid_str) {
    // Create filename for process info
    char filename[100];
    sprintf(filename, "/proc/%s/status", pid_str);

    // Open the file
    FILE* file = fopen(filename, "r");

    // Initialize buffer to store file line by line
    char line_buf[256];

    // Initialize flags to indicate when to read name and status
    int name_found = 0;
    int status_found = 0;

    // Read file line by line
    while (fgets(line_buf, sizeof(line_buf), file)) {
        // Remove trailing newline from line
        char* pos;
        if ((pos=strchr(line_buf, '\n')) != NULL) {
            *pos = '\0';
        }

        // Find name of process
        if (!name_found && sscanf(line_buf, "Name: %s", processes[num_processes].name)) {
            name_found = 1;
        }

        // Find process status
        if (!status_found && sscanf(line_buf, "State: %s", processes[num_processes].status)) {
            status_found = 1;
        }
    }

    // Close file
    fclose(file);

    // Create filename for process cmdline
    sprintf(filename, "/proc/%s/cmdline", pid_str);

    // Open the file
    file = fopen(filename, "r");

    // Read the cmdline
    fgets(processes[num_processes].cmdline, sizeof(processes[num_processes].cmdline), file);

    // Close file
    fclose(file);

    // Create filename for process meminfo
    sprintf(filename, "/proc/%s/statm", pid_str);

    // Open the file
    file = fopen(filename, "r");

    // Read the virtual memory size
    fscanf(file, "%ld", &processes[num_processes].vsize);

    // Close file
    fclose(file);

    // Set the pid
    processes[num_processes].pid = atoi(pid_str);

    // Increment number of processes
    num_processes++;
}

// Function to list all processes and their info
void list_processes() {
    // Open the /proc directory
    DIR* dir = opendir("/proc");

    // If directory cannot be opened, return error
    if (!dir) {
        printf("Error opening /proc directory\n");
        return;
    }

    // Initialize buffer for directory entry
    struct dirent* entry;

    // Loop through the directory
    while ((entry = readdir(dir)) != NULL) {
        // Check if the directory entry is a directory and its name contains only digits
        if (entry->d_type == DT_DIR && isdigit(entry->d_name[0])) {
            // Read process info for this process
            read_process_info(entry->d_name);
        }
    }

    // Close the directory
    closedir(dir);

    // Print the process info
    printf("PID\t\tNAME\t\tSTATUS\t\tVSIZE(KB)\tCMDLINE\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t\t%s\t\t%s\t\t%lu\t\t%s\n", processes[i].pid, processes[i].name, processes[i].status, processes[i].vsize, processes[i].cmdline);
    }
}

int main() {
    list_processes();

    return 0;
}