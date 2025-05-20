//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>

#define MAX_LINE_LENGTH 256
#define PROC_DIRECTORY "/proc"

void print_process_info(pid_t pid) {
    char path[MAX_LINE_LENGTH];
    FILE *status_file;
    char line[MAX_LINE_LENGTH];
    
    // Construct the status file path
    snprintf(path, sizeof(path), "%s/%d/status", PROC_DIRECTORY, pid);
    
    // Open the status file
    status_file = fopen(path, "r");
    if (status_file == NULL) {
        return; // Process might have terminated
    }
    
    char name[MAX_LINE_LENGTH] = {0};
    char state[MAX_LINE_LENGTH] = {0};
    char uid[MAX_LINE_LENGTH] = {0};
    
    // Read the status file to get relevant information
    while (fgets(line, sizeof(line), status_file)) {
        if (sscanf(line, "Name:\t%s", name) == 1) {
            continue;
        }
        if (sscanf(line, "State:\t%s", state) == 1) {
            continue;
        }
        if (sscanf(line, "Uid:\t%s", uid) == 1) {
            continue;
        }
    }
    
    fclose(status_file);
    
    // Print the process information
    printf("PID: %d | Name: %s | State: %s | UID: %s\n", pid, name, state, uid);
}

void list_processes() {
    DIR *proc_dir;
    struct dirent *entry;
    
    proc_dir = opendir(PROC_DIRECTORY);
    if (proc_dir == NULL) {
        perror("Failed to open /proc directory");
        exit(EXIT_FAILURE);
    }
    
    printf("Current running processes:\n");
    printf("=====================================\n");
    printf("PID   | Name                     | State          | UID\n");
    printf("=====================================\n");
    
    // Iterate through the entries in the /proc directory
    while ((entry = readdir(proc_dir)) != NULL) {
        // Check if the entry is a PID directory (which should be digits)
        if (isdigit(entry->d_name[0])) {
            pid_t pid = atoi(entry->d_name);
            print_process_info(pid);
        }
    }
    
    closedir(proc_dir);
}

int main() {
    // Continuously refresh the process list every 2 seconds
    while (1) {
        system("clear"); // Clear the screen to refresh output
        list_processes();
        sleep(2); // Wait for 2 seconds before refreshing
    }
    
    return 0;
}