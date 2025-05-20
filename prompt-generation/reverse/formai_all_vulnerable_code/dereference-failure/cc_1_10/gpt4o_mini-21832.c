//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define BUFFER_SIZE 256

void print_process_info(const char *pid) {
    char path[BUFFER_SIZE];
    snprintf(path, sizeof(path), "/proc/%s/status", pid);
    
    FILE *file = fopen(path, "r");
    if (!file) return;

    char line[BUFFER_SIZE];

    // Extract and print the PID and Command
    char cmd[BUFFER_SIZE];
    snprintf(path, sizeof(path), "/proc/%s/cmdline", pid);
    FILE *cmd_file = fopen(path, "r");
    if (cmd_file) {
        fgets(cmd, sizeof(cmd), cmd_file);
        fclose(cmd_file);
        
        // Replace null characters with a space in case of multi-argument commands
        for (int i = 0; cmd[i]; i++) {
            if (cmd[i] == '\0') cmd[i] = ' ';
        }
    } else {
        strcpy(cmd, "unknown");
    }

    // Print PID and command
    printf("PID: %s, Command: %s\n", pid, cmd);

    fclose(file);
}

void list_processes() {
    DIR *dir = opendir("/proc");
    if (!dir) {
        perror("opendir");
        return;
    }
    
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Check if entry is a directory and its name is numeric (process ID)
        if (entry->d_type == DT_DIR && atoi(entry->d_name) > 0) {
            print_process_info(entry->d_name);
        }
    }

    closedir(dir);
}

int main() {
    printf("Process Viewer\n");
    printf("---------------\n");

    list_processes();

    return 0;
}