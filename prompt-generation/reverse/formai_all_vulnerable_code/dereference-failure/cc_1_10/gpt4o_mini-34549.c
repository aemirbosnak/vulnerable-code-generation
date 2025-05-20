//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define BUFFER_SIZE 256

// Struct to hold process information
typedef struct {
    char pid[BUFFER_SIZE];
    char name[BUFFER_SIZE];
} Process;

// Function to read the contents of a file
void readFile(const char *path, char *dest, size_t size) {
    FILE *file = fopen(path, "r");
    if (file) {
        fread(dest, sizeof(char), size, file);
        fclose(file);
    }
}

// Function to filter out numeric entries
int isNumeric(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) return 0;
    }
    return 1;
}

// Function to retrieve process information
int getProcessList(Process *processes) {
    DIR *dir;
    struct dirent *entry;
    int count = 0;

    dir = opendir("/proc");
    if (dir == NULL) {
        perror("Error opening /proc directory");
        return -1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (isNumeric(entry->d_name)) {
            // Found a directory with PID
            strcpy(processes[count].pid, entry->d_name);
            char path[BUFFER_SIZE];
            snprintf(path, sizeof(path), "/proc/%s/comm", entry->d_name);

            // Read the command name of the process
            readFile(path, processes[count].name, BUFFER_SIZE);
            // Remove newline character from the command
            processes[count].name[strcspn(processes[count].name, "\n")] = '\0';

            count++;
        }
    }
    closedir(dir);
    return count;
}

// Function to sort processes by name
void sortProcesses(Process *processes, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(processes[j].name, processes[j + 1].name) > 0) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

// Function to print the list of processes
void printProcesses(Process *processes, int count) {
    printf("%-10s %-50s\n", "PID", "Name");
    printf("--------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-10s %-50s\n", processes[i].pid, processes[i].name);
    }
}

int main() {
    Process processes[BUFFER_SIZE];
    int processCount;

    // Gathering all processes
    processCount = getProcessList(processes);
    if (processCount < 0) {
        return EXIT_FAILURE;
    }

    // Sorting the processes
    sortProcesses(processes, processCount);

    // Viewing the process list
    printProcesses(processes, processCount);
    
    return EXIT_SUCCESS;
}