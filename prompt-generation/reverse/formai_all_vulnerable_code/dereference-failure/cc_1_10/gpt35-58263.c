//FormAI DATASET v1.0 Category: System process viewer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>

// Define constants for array sizes
#define NAME_SIZE 1024
#define COMMAND_SIZE 4096

// Define struct to hold process information
struct ProcessInfo {
    int pid;
    char name[NAME_SIZE];
    char command[COMMAND_SIZE];
};

int countProcesses() {
    int count = 0;
    DIR* proc = opendir("/proc");
    struct dirent* entry = NULL;
    while ((entry = readdir(proc))) {
        // Check if entry is a directory and is named by a number
        if (entry->d_type == DT_DIR && isdigit(entry->d_name[0])) {
            count++;
        }
    }
    closedir(proc);
    return count;
}

void getProcessInfo(struct ProcessInfo* processes, int count) {
    DIR* proc = opendir("/proc");
    struct dirent* entry = NULL;
    int i = 0;
    while ((entry = readdir(proc))) {
        // Check if entry is a directory and is named by a number
        if (entry->d_type == DT_DIR && isdigit(entry->d_name[0])) {
            // Get the pid from the directory name
            int pid = atoi(entry->d_name);
            // Open the cmdline file for the process
            char path[NAME_SIZE];
            sprintf(path, "/proc/%d/cmdline", pid);
            FILE* cmd = fopen(path, "r");
            if (cmd != NULL) {
                // Read the command and store it in the struct
                char buffer[COMMAND_SIZE];
                fgets(buffer, COMMAND_SIZE, cmd);
                int len = strlen(buffer);
                if (len > 0 && buffer[len-1] == '\n') {
                    buffer[len-1] = '\0';
                }
                strcpy(processes[i].command, buffer);
                fclose(cmd);
            }
            // Open the stat file for the process
            sprintf(path, "/proc/%d/stat", pid);
            FILE* stat = fopen(path, "r");
            if (stat != NULL) {
                // Read the name and store it in the struct
                char buffer[COMMAND_SIZE];
                fgets(buffer, COMMAND_SIZE, stat);
                int len = strlen(buffer);
                if (len > 0 && buffer[len-1] == '\n') {
                    buffer[len-1] = '\0';
                }
                char* start = strchr(buffer, '(') + 1;
                char* end = strchr(start, ')');
                len = end - start;
                strncpy(processes[i].name, start, len);
                processes[i].name[len] = '\0';
                processes[i].pid = pid;
                fclose(stat);
                i++;
            }
            if (i == count) {
                break;
            }
        }
    }
    closedir(proc);
}

int main() {
    int count = countProcesses();
    struct ProcessInfo* processes = malloc(count * sizeof(struct ProcessInfo));
    getProcessInfo(processes, count);
    printf("%-6s %-20s %s\n", "PID", "NAME", "COMMAND");
    for (int i = 0; i < count; i++) {
        printf("%-6d %-20s %s\n", processes[i].pid, processes[i].name, processes[i].command);
    }
    free(processes);
    return 0;
}