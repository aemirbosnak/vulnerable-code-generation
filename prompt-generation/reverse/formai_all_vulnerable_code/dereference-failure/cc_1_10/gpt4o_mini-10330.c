//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 256

void print_process_info(const char *pid) {
    char path[BUFFER_SIZE];
    char line[BUFFER_SIZE];
    FILE *status_file;
    
    // Construct the path to the status file for the given PID
    snprintf(path, sizeof(path), "/proc/%s/status", pid);
    
    status_file = fopen(path, "r");
    if (status_file == NULL) {
        return; // Could not open status file, possibly the process has finished
    }

    char user[BUFFER_SIZE] = {0};
    char state[BUFFER_SIZE] = {0};
    char command[BUFFER_SIZE] = {0};

    // Read the status file
    while (fgets(line, sizeof(line), status_file)) {
        if (strncmp(line, "Uid:", 4) == 0) {
            sscanf(line, "Uid:\t%d", (int*)&user);
            snprintf(user, sizeof(user), "%d", atoi(user));
        } else if (strncmp(line, "State:", 6) == 0) {
            sscanf(line, "State:\t%s", state);
        }
    }
    
    // Construct command path
    snprintf(path, sizeof(path), "/proc/%s/comm", pid);
    FILE *comm_file = fopen(path, "r");
    if (comm_file) {
        fgets(command, sizeof(command), comm_file);
        fclose(comm_file);
        // Remove the newline character at the end
        command[strcspn(command, "\n")] = 0;
    }
    
    printf("PID: %s, User: %s, State: %s, Command: %s\n", pid, user, state, command);
    
    fclose(status_file);
}

void list_processes() {
    DIR *proc_dir;
    struct dirent *entry;
    
    // Open the /proc directory
    proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        perror("Unable to open /proc directory");
        exit(EXIT_FAILURE);
    }

    // Iterate through the directory entries
    while ((entry = readdir(proc_dir)) != NULL) {
        // Check if the entry is a numeric directory (PID)
        if (entry->d_type == DT_DIR && atoi(entry->d_name) > 0) {
            print_process_info(entry->d_name);
        }
    }

    closedir(proc_dir);
}

int main() {
    printf("Simple Process Viewer\n");
    printf("=====================\n");
    list_processes();
    printf("=====================\n");
    
    return 0;
}