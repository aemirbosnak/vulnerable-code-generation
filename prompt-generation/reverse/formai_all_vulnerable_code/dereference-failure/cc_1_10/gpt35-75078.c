//FormAI DATASET v1.0 Category: System process viewer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

// Function to convert a process ID to a process name
char* pidToName(int pid) {
    char* name = malloc(50 * sizeof(char));
    char path[50];
    sprintf(path, "/proc/%d/status", pid);
    FILE* file = fopen(path, "r");
    if (file != NULL) {
        char line[100];
        while (fgets(line, sizeof(line), file) != NULL) {
            if (strncmp(line, "Name:", 5) == 0) {
                sscanf(line, "Name:\t%s", name);
                break;
            }
        }
        fclose(file);
    }
    return name;
}

// Function to print process statistics
void printProcStats(int pid) {
    char path[50];
    sprintf(path, "/proc/%d/stat", pid);
    FILE* file = fopen(path, "r");
    if (file != NULL) {
        char state;
        char name[50];
        int ppid, pgid, sid;
        fscanf(file, "%d %s %c %d %d %d", &pid, name, &state, &ppid, &pgid, &sid);
        printf("%-8d %-10s %c\t%-8d %-8d %-8d\n", pid, name, state, ppid, pgid, sid);
        fclose(file);
    }
}

int main() {
    // Print header row for process list
    printf("%-8s %-10s %-4s %-8s %-8s %-8s\n", "PID", "NAME", "STAT", "PPID", "PGID", "SID");
    
    // Open the directory containing process folders in /proc
    DIR* procDir = opendir("/proc");
    if (procDir == NULL) {
        perror("Error opening /proc directory");
        return 1;
    }
    
    // Loop through process folders
    struct dirent* procEnt;
    while ((procEnt = readdir(procDir)) != NULL) {
        if (procEnt->d_type == DT_DIR) {
            char* nameEndptr;
            int pid = strtol(procEnt->d_name, &nameEndptr, 10);
            if (*nameEndptr == '\0') { // If directory name is a valid PID
                char* name = pidToName(pid);
                if (strcmp(name, "") != 0) { // If process name is not an empty string
                    printProcStats(pid);
                }
                free(name);
            }
        }
    }
    
    closedir(procDir);
    return 0;
}