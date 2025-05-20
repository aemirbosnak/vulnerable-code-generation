//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 256
#define PROC_DIR "/proc"

void trim_newline(char *str) {
    str[strcspn(str, "\n")] = 0; // Remove newline character
}

void print_process_info(pid_t pid) {
    char path[MAX_LINE_LENGTH];
    sprintf(path, "%s/%d/status", PROC_DIR, pid);
    FILE *status_file = fopen(path, "r");
    if (!status_file) return;

    char line[MAX_LINE_LENGTH];
    char name[MAX_LINE_LENGTH] = "N/A"; // Default process name
    char state[MAX_LINE_LENGTH] = "N/A"; // Default state
    unsigned long vsize = 0; // Virtual memory size
    unsigned long rss = 0; // Resident set size

    while (fgets(line, sizeof(line), status_file)) {
        trim_newline(line);
        if (strncmp(line, "Name:", 5) == 0) {
            sscanf(line, "Name:\t%s", name);
        } else if (strncmp(line, "State:", 6) == 0) {
            sscanf(line, "State:\t%s", state);
        } else if (strncmp(line, "VmSize:", 7) == 0) {
            sscanf(line, "VmSize:\t%lu", &vsize);
        } else if (strncmp(line, "VmRSS:", 6) == 0) {
            sscanf(line, "VmRSS:\t%lu", &rss);
        }
    }

    fclose(status_file);
    
    printf("%-10d %-20s %-10s %-10lu %-10lu\n", pid, name, state, vsize, rss);
}

void list_processes() {
    DIR *proc_dir = opendir(PROC_DIR);
    if (!proc_dir) {
        perror("Failed to open /proc directory");
        exit(EXIT_FAILURE);
    }

    struct dirent *entry;
    printf("%-10s %-20s %-10s %-10s %-10s\n", "PID", "Process Name", "State", "VmSize", "VmRSS");
    printf("---------------------------------------------------------------\n");
    
    while ((entry = readdir(proc_dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            int pid = atoi(entry->d_name);
            if (pid > 0) { // It is a process directory
                print_process_info(pid);
            }
        }
    }

    closedir(proc_dir);
}

int main(void) {
    while (1) {
        printf("\033[H\033[J"); // Clear screen
        printf("Process Viewer\n");
        printf("=================\n");
        list_processes();
        printf("\nPress Ctrl+C to exit...\n");
        sleep(5); // Update every 5 seconds
    }

    return 0;
}