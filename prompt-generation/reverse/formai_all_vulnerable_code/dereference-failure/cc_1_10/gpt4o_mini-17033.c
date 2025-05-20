//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <ctype.h>

#define PROC_PATH "/proc"
#define CMDLINE_LENGTH 256

void list_processes();
void get_process_info(pid_t pid);
void print_process_info(pid_t pid, const char *cmdline, const char *state);
void clear_screen();

int main() {
    while (1) {
        clear_screen();
        printf("=== Linux Process Viewer ===\n");
        list_processes();
        printf("\nPress 'q' to quit or any other key to refresh...\n");
        
        if (getchar() == 'q') {
            break;
        }
        
        // Clear the input buffer for next iteration
        while (getchar() != '\n');
    }
    return 0;
}

void list_processes() {
    struct dirent *entry;
    DIR *dp = opendir(PROC_PATH);
    
    if (dp == NULL) {
        perror("opendir");
        return;
    }
    
    printf("%-10s %-20s %-10s\n", "PID", "COMMAND", "STATE");
    
    while ((entry = readdir(dp))) {
        if (isdigit(entry->d_name[0])) { // Checks if first character is a digit
            pid_t pid = atoi(entry->d_name);
            get_process_info(pid);
        }
    }
    
    closedir(dp);
}

void get_process_info(pid_t pid) {
    char filepath[CMDLINE_LENGTH];
    snprintf(filepath, sizeof(filepath), "/proc/%d/cmdline", pid);
    
    FILE *fp = fopen(filepath, "r");
    if (fp == NULL) {
        return;
    }
    
    char cmdline[CMDLINE_LENGTH] = {0};
    fread(cmdline, sizeof(char), CMDLINE_LENGTH, fp);
    fclose(fp);

    // Remove extra null characters in cmdline
    for (int i = 0; i < CMDLINE_LENGTH; i++) {
        if (cmdline[i] == '\0') {
            cmdline[i] = '\n'; // Ensure it doesn't truncate the command
            break;
        }
    }

    // Get process state
    snprintf(filepath, sizeof(filepath), "/proc/%d/stat", pid);
    fp = fopen(filepath, "r");
    if (fp == NULL) {
        return;
    }
    
    char state = '\0';
    fscanf(fp, "%*d %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %c", &state);
    fclose(fp);
    
    print_process_info(pid, cmdline, (state == 'R') ? "Running" : (state == 'S') ? "Sleeping" : "Other");
}

void print_process_info(pid_t pid, const char *cmdline, const char *state) {
    printf("%-10d %-20s %-10s\n", pid, cmdline, state);
}

void clear_screen() {
    // ANSI escape code to clear the screen
    printf("\033[H\033[J");
}