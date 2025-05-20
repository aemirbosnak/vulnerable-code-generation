//FormAI DATASET v1.0 Category: System process viewer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

// Define the maximum length of a process name
#define MAX_NAME_LENGTH 50

// Define a struct to hold process information
typedef struct {
    int pid; // Process ID
    char name[MAX_NAME_LENGTH]; // Process name
    int priority; // Process priority
} Process;

// Define a function to get the process name given a PID
void get_process_name(int pid, char* name) {
    // Open the file that contains the process name
    char filename[20];
    sprintf(filename, "/proc/%d/comm", pid);
    FILE* f = fopen(filename, "r");

    // Read the process name from the file
    fgets(name, MAX_NAME_LENGTH, f);

    // Remove the newline character from the end of the process name
    name[strlen(name) - 1] = '\0';

    // Close the file
    fclose(f);
}

// Define a function to check if a character is a digit
int is_digit(char c) {
    return (isdigit(c) != 0);
}

// Define a function to parse an integer from a string
int parse_integer(char* str) {
    int result = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (is_digit(str[i])) {
            result = result * 10 + (str[i] - '0');
        }
        i++;
    }
    return result;
}

int main() {
    // Open the directory that contains information about all processes
    DIR* directory = opendir("/proc");
    if (directory == NULL) {
        fprintf(stderr, "Error: Could not open /proc directory.\n");
        exit(EXIT_FAILURE);
    }

    // Initialize an array to hold information about all processes
    Process* processes = malloc(sizeof(Process) * 100);
    int num_processes = 0;

    // Read information about each process from the /proc directory
    struct dirent* entry;
    while ((entry = readdir(directory)) != NULL) {
        // Check if the directory entry is a directory (i.e. a process)
        if (entry->d_type == DT_DIR) {
            // Check if the directory name is a number (i.e. a PID)
            if (is_digit(entry->d_name[0])) {
                int pid = parse_integer(entry->d_name);

                // Get the process name and priority
                char name[MAX_NAME_LENGTH];
                get_process_name(pid, name);
                char filename[20];
                sprintf(filename, "/proc/%d/stat", pid);
                FILE* f = fopen(filename, "r");
                char stat_str[500];
                fgets(stat_str, 500, f);
                fclose(f);
                char* ptr = strtok(stat_str, " ");
                int i = 0;
                int priority = 0;
                while (ptr != NULL && i < 17) {
                    if (i == 17) {
                        priority = atoi(ptr);
                    }
                    ptr = strtok(NULL, " ");
                    i++;
                }

                // Add the process to the array
                processes[num_processes].pid = pid;
                strncpy(processes[num_processes].name, name, MAX_NAME_LENGTH);
                processes[num_processes].priority = priority;
                num_processes++;
            }
        }
    }

    // Close the /proc directory
    closedir(directory);

    // Sort the processes by priority (highest to lowest)
    for (int i = 0; i < num_processes - 1; i++) {
        for (int j = i + 1; j < num_processes; j++) {
            if (processes[i].priority < processes[j].priority) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    // Print information about each process
    for (int i = 0; i < num_processes; i++) {
        printf("PID: %d, Name: %s, Priority: %d\n",
               processes[i].pid, processes[i].name, processes[i].priority);
    }

    // Free the array of processes
    free(processes);

    return 0;
}