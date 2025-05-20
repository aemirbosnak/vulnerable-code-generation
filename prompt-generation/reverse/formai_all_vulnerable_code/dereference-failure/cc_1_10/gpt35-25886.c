//FormAI DATASET v1.0 Category: System process viewer ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>

// Define some constants
#define MAX_CMD_LENGTH 512 
#define MAX_PID_LENGTH 10
#define MAX_PROC_PATH_LENGTH 512 

// Define a function to check if a given string is a valid integer
int is_integer(const char *str) {
    while (*str) {
        if (!isdigit(*str))
            return 0;
        str++;
    }
    return 1;
}

// Define a function to get the command for a process
char* get_command(int pid) {
    char proc_path[MAX_PROC_PATH_LENGTH];
    sprintf(proc_path, "/proc/%d/cmdline", pid);
    FILE *cmd_file = fopen(proc_path, "r");
    if (cmd_file == NULL) {
        printf("Failed to open cmdline file for process %d\n", pid);
        return NULL;
    }
    static char cmd[MAX_CMD_LENGTH];
    memset(cmd, 0, sizeof(cmd));
    if (fgets(cmd, sizeof(cmd), cmd_file) == NULL) {
        printf("Failed to read cmdline file for process %d\n", pid);
        fclose(cmd_file);
        return NULL;    
    }
    fclose(cmd_file);
    return cmd;
}

// Define a function to get the process information
void get_process_info(struct dirent *entry) {
    char *name = entry->d_name;
    if (!is_integer(name)) return;
    int pid = atoi(name);
    char *cmd = get_command(pid);
    if (cmd == NULL) return;
    printf("%s (%d) - %s\n", cmd, pid, name);
}

// Define the main function
int main() {
    DIR *proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        printf("Failed to open /proc directory\n");
        return 1;
    }
    struct dirent *entry;
    while ((entry = readdir(proc_dir)) != NULL) {
        get_process_info(entry);
    }
    closedir(proc_dir);
    return 0;
}