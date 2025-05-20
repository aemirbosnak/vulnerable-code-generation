//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>

#define MAX_PROCESSES 1024

// The noble structure to represent the realm of processes
typedef struct {
    int pid; // The noble process identifier
    char name[256]; // The name of the noble process
    char state[16]; // The noble state (running, sleeping, etc.)
} NobleProcess;

// A wise function to gather the processes
int gather_processes(NobleProcess *nobleProcesses) {
    char path[256];
    int count = 0;

    DIR *dir = opendir("/proc");
    struct dirent *entry;

    if (dir == NULL) {
        perror("The gates of the process directory could not be opened");
        return -1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            int pid = atoi(entry->d_name);
            if (pid > 0) {
                // Gather process information from the realm
                snprintf(path, sizeof(path), "/proc/%s/stat", entry->d_name);
                FILE *file = fopen(path, "r");
                if (file) {
                    NobleProcess noble;
                    noble.pid = pid;
                    fscanf(file, "%d %s %s", &noble.pid, noble.name, noble.state);
                    // Make sure to only keep the process name without parentheses
                    noble.name[strcspn(noble.name, ")]")] = '\0'; 
                    strcpy(nobleProcesses[count].name, noble.name);
                    nobleProcesses[count].pid = pid;
                    strcpy(nobleProcesses[count].state, noble.state);
                    count++;
                    fclose(file);
                }
            }
        }
        // Limit the number of processes surveyed, lest we tire from the journey
        if (count >= MAX_PROCESSES) break;
    }

    closedir(dir);
    return count;
}

// A gallant function to print the noble processes
void display_processes(NobleProcess *nobleProcesses, int count) {
    printf("***************************\n");
    printf("   The List of Noble Processes\n");
    printf("***************************\n");
    printf("| PID |      Name      |   State   |\n");
    printf("-------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("| %3d | %-14s | %-9s |\n", 
               nobleProcesses[i].pid, 
               nobleProcesses[i].name, 
               nobleProcesses[i].state);
    }

    printf("-------------------------------\n");
}

// The critical role of a gallant knight who oversees the process realm
int main() {
    NobleProcess nobleProcesses[MAX_PROCESSES];
    int processCount = gather_processes(nobleProcesses);

    if (processCount < 0) {
        return 1; // Exit with a noble mark of failure
    }

    display_processes(nobleProcesses, processCount);
    printf("All noble processes have been duly surveyed!\n");
    
    return 0; // Return from the gallant adventure accomplished
}