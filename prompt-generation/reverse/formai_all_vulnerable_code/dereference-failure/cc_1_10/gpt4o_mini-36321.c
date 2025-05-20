//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_PATH 1024
#define MAX_BUFFER 256

typedef struct {
    pid_t pid;
    char cmdline[MAX_BUFFER];
    char state;
} ProcessInfo;

// Function prototypes
void list_processes();
void get_process_info(pid_t pid, ProcessInfo *info);
void display_process(ProcessInfo *info);

int main() {
    list_processes();
    return 0;
}

void list_processes() {
    DIR *dir;
    struct dirent *entry;

    // Open the /proc directory
    if ((dir = opendir("/proc")) == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    printf("%-10s %-10s %-16s\n", "PID", "State", "Command");
    printf("-----------------------------------------\n");
    
    // Iterate through each entry in /proc
    while ((entry = readdir(dir)) != NULL) {
        // Check if the entry is a directory and if it is numeric (i.e., a process ID)
        if (entry->d_type == DT_DIR && atoi(entry->d_name) > 0) {
            ProcessInfo info;
            info.pid = atoi(entry->d_name);
            get_process_info(info.pid, &info);
            display_process(&info);
        }
    }

    closedir(dir);
}

void get_process_info(pid_t pid, ProcessInfo *info) {
    char path[MAX_PATH], buffer[MAX_BUFFER];
    FILE *file;

    // Construct the path to the cmdline and status files for the process
    snprintf(path, sizeof(path), "/proc/%d/status", pid);

    // Open the status file
    if ((file = fopen(path, "r")) == NULL) {
        perror("fopen");
        return;
    }

    // Read the state of the process
    while (fgets(buffer, sizeof(buffer), file)) {
        if (strncmp(buffer, "State:", 6) == 0) {
            info->state = buffer[7];
            break;
        }
    }

    fclose(file);

    // Get the command line
    snprintf(path, sizeof(path), "/proc/%d/cmdline", pid);
    if ((file = fopen(path, "r")) != NULL) {
        if (fgets(info->cmdline, sizeof(info->cmdline), file) != NULL) {
            // Replace null characters with spaces
            for (int i = 0; i < strlen(info->cmdline); i++) {
                if (info->cmdline[i] == '\0') {
                    info->cmdline[i] = ' ';
                }
            }
        }
        fclose(file);
    } else {
        strcpy(info->cmdline, "N/A");
    }
}

void display_process(ProcessInfo *info) {
    // Display the process information
    printf("%-10d %-10c %-16s\n", info->pid, info->state, info->cmdline);
}