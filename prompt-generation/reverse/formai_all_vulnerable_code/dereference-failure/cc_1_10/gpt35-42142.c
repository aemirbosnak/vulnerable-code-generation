//FormAI DATASET v1.0 Category: System process viewer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>

#define MAX_BUFF 1024
#define STATE_BUF_LEN 32
#define COMMAND_BUF_LEN 128

// Struct to hold process information
typedef struct {
    int pid;
    char state[STATE_BUF_LEN];
    char command[COMMAND_BUF_LEN];
} process_info_t;

// Function to check if a directory is a valid process directory
int is_process_dir(const char *dir) {
    // Check if directory is a number
    for (int i = 0; i < strlen(dir); i++) {
        if (!isdigit(dir[i])) {
            return 0;
        }
    }

    // Check if process directory exists
    char path[MAX_BUFF];
    sprintf(path, "/proc/%s", dir);

    DIR *proc_dir = opendir(path);
    if (!proc_dir) {
        return 0;
    }

    closedir(proc_dir);
    return 1;
}

// Function to get the command line arguments of a process
char *get_process_command(const char *dir) {    
    char path[MAX_BUFF];
    sprintf(path, "/proc/%s/cmdline", dir);
    
    FILE *cmd_file = fopen(path, "r");
    if (!cmd_file) {
        return NULL;
    }
    
    // Read the command line arguments
    char *command = (char*) malloc(sizeof(char) * COMMAND_BUF_LEN);
    fgets(command, COMMAND_BUF_LEN, cmd_file);
    fclose(cmd_file);
    
    return command;
}

// Function to get the state of a process
char *get_process_state(const char *dir) {
    char path[MAX_BUFF];
    sprintf(path, "/proc/%s/status", dir);
    
    FILE *status_file = fopen(path, "r");
    if (!status_file) {
        return NULL;
    }
    
    // Read the state from the status file
    char *line = NULL;
    size_t len = 0;
    ssize_t read = 0;
    while ((read = getline(&line, &len, status_file)) != -1) {
        if (strncmp(line, "State:", 6) == 0) {
            char *state = strchr(line, ':') + 2;
            state[strlen(state) - 1] = '\0';
            fclose(status_file);
            return state;
        }
    }
    
    fclose(status_file);
    return NULL;
}

int main() {
    printf("****** WELCOME TO C PROCESS VIEWER ******\n\n");

    printf("----- PROCESS LIST -----\n");

    DIR *dir = opendir("/proc");
    if (!dir) {
        printf("Error: Can't open /proc directory\n");
        return 1;
    }
    
    struct dirent *entry;
    process_info_t process_info;
    while ((entry = readdir(dir)) != NULL) {
        if (is_process_dir(entry->d_name)) {
            process_info.pid = atoi(entry->d_name);
            strcpy(process_info.command, get_process_command(entry->d_name));
            strcpy(process_info.state, get_process_state(entry->d_name));
            printf("PID: %d | State: %s | Command: %s\n", process_info.pid, process_info.state, process_info.command);
        }
    }
    
    printf("\n****** END OF PROCESS VIEWER ******\n");

    return 0;
}