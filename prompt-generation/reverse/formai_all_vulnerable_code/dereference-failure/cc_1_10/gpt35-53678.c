//FormAI DATASET v1.0 Category: System process viewer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <dirent.h>
#include <ctype.h>

// Define constants
#define MAX_PATH 4096
#define MAX_PID_LENGTH 16

// Define struct to hold information about process
typedef struct {
    char pid[MAX_PID_LENGTH];
    char comm[MAX_PATH];
    char state;
} Process;

// Define function to check if a string is a number
bool is_number(const char *s) {
    for (int i = 0; i < strlen(s); i++) {
        if (!isdigit(s[i])) {
            return false;
        }
    }
    return true;
}

// Define function to get list of processes
int get_processes(Process *processes) {
    DIR *dir = opendir("/proc");
    struct dirent *entry;
    int process_count = 0;
    while ((entry = readdir(dir)) != NULL) {
        // Check if entry is a directory and its name is a number
        if (entry->d_type == DT_DIR && is_number(entry->d_name)) {
            // Open process status file and read process information
            char status_file_path[MAX_PATH];
            snprintf(status_file_path, sizeof(status_file_path), "/proc/%s/status", entry->d_name);
            FILE *status_file = fopen(status_file_path, "r");
            if (status_file != NULL) {
                char line[MAX_PATH];
                while (fgets(line, sizeof(line), status_file)) {
                    // Check for process name and status
                    if (strncmp(line, "Name:", 5) == 0) {
                        sscanf(line + 6, "%s", processes[process_count].comm);
                    } else if (strncmp(line, "State:", 6) == 0) {
                        sscanf(line + 7, "%c", &processes[process_count].state);
                    }
                }
                // Close process status file
                fclose(status_file);
                // Copy pid to process struct
                strncpy(processes[process_count].pid, entry->d_name, sizeof(processes[process_count].pid));
                // Increment process count
                process_count++;
            }
        }
    }
    // Close directory stream
    closedir(dir);
    // Return process count
    return process_count;
}

// Define function to print processes
void print_processes(Process *processes, int process_count) {
    printf("PID\tSTATE\tNAME\n");
    for (int i = 0; i < process_count; i++) {
        printf("%s", processes[i].pid);
        printf("\t%c", processes[i].state);
        printf("\t%s", processes[i].comm);
    }
}

// Define main function
int main(int argc, char *argv[]) {
    // Create array to hold processes
    Process processes[1000];
    // Get list of processes
    int process_count = get_processes(processes);
    // Print processes
    print_processes(processes, process_count);
    // Exit program
    return 0;
}