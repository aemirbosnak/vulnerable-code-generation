//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define PROC_PATH "/proc"
#define MAX_PATH 256
#define MAX_CMDLINE 1024

// Function to check if a string represents a number
int is_number(const char *str) {
    while (*str) {
        if (!isdigit(*str)) return 0;
        str++;
    }
    return 1;
}

// Function to get the command line of a process
void get_command_line(const char *pid, char *cmdline, size_t size) {
    char path[MAX_PATH];
    snprintf(path, sizeof(path), "%s/%s/cmdline", PROC_PATH, pid);
    
    FILE *file = fopen(path, "r");
    if (file) {
        fread(cmdline, 1, size, file);
        fclose(file);
    }
}

// Function to get the process state
char get_process_state(const char *pid) {
    char path[MAX_PATH];
    snprintf(path, sizeof(path), "%s/%s/stat", PROC_PATH, pid);

    FILE *file = fopen(path, "r");
    if (file) {
        int dummy;
        char state;
        fscanf(file, "%d %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %c", &dummy, &state);
        fclose(file);
        return state;
    }
    return '?'; // Error reading state
}

// Function to print all the processes
void list_processes() {
    struct dirent *entry;
    DIR *dp = opendir(PROC_PATH);
    
    if (dp == NULL) {
        perror("opendir");
        return;
    }

    printf("%-10s %-20s %s\n", "PID", "State", "Command");
    printf("%-10s %-20s %s\n", "---", "-----", "-------");

    while ((entry = readdir(dp))) {
        if (is_number(entry->d_name)) {
            char cmdline[MAX_CMDLINE] = {0};
            char *pid = entry->d_name;
            char state = get_process_state(pid);
            get_command_line(pid, cmdline, sizeof(cmdline));
            printf("%-10s %-20c %s\n", pid, state, cmdline);
        }
    }
    closedir(dp);
}

int main() {
    printf("Process Viewer - A Linus Torvalds Style Process Watcher\n");
    printf("=====================================================\n");
    list_processes();
    return 0;
}