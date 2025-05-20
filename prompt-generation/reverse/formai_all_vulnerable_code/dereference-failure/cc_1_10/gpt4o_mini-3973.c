//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define BUFFER_SIZE 256
#define MAX_PROCESSES 1024

typedef struct {
    pid_t pid;
    char user[BUFFER_SIZE];
    char command[BUFFER_SIZE];
} ProcessInfo;

void getProcessInfo(ProcessInfo *procInfo, int *count) {
    DIR *dir;
    struct dirent *entry;
    FILE *fp;
    char path[BUFFER_SIZE];
    char uid[BUFFER_SIZE];
    char stat[BUFFER_SIZE];
    char cmd[BUFFER_SIZE];
    int uid_num;
    *count = 0;

    // Open the /proc directory
    if ((dir = opendir("/proc")) == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        // Check if the entry is a number (which indicates a process ID)
        if (entry->d_type == DT_DIR) {
            pid_t pid = atoi(entry->d_name);
            if (pid > 0) {
                snprintf(path, sizeof(path), "/proc/%s/status", entry->d_name);
                fp = fopen(path, "r");
                if (fp) {
                    // Read user ID (UID)
                    while (fgets(stat, sizeof(stat), fp)) {
                        if (strncmp(stat, "Uid:", 4) == 0) {
                            sscanf(stat, "Uid:\t%d", &uid_num);
                        }
                        if (strncmp(stat, "Name:", 5) == 0) {
                            sscanf(stat, "Name:\t%s", procInfo[*count].command);
                        }
                    }
                    fclose(fp);
                    
                    // Get username from UID
                    snprintf(path, sizeof(path), "/etc/passwd");
                    FILE *passwd = fopen(path, "r");
                    if (passwd) {
                        while (fgets(stat, sizeof(stat), passwd)) {
                            if (atoi(strtok(stat, ":")) == uid_num) {
                                strncpy(procInfo[*count].user, strtok(NULL, ":") + 1, BUFFER_SIZE);
                                break;
                            }
                        }
                        fclose(passwd);
                    }
                    
                    procInfo[*count].pid = pid;
                    (*count)++;
                    if (*count >= MAX_PROCESSES) break; // Limit the number of processes
                }
            }
        }
    }

    closedir(dir);
}

void displayProcesses(ProcessInfo *procInfo, int count) {
    printf("\033[H\033[J"); // Clear the terminal
    printf("%-6s %-20s %-30s\n", "PID", "USER", "COMMAND");
    printf("%-6s %-20s %-30s\n", "----", "--------------------", "------------------------------");

    for (int i = 0; i < count; i++) {
        printf("%-6d %-20s %-30s\n", procInfo[i].pid, procInfo[i].user, procInfo[i].command);
    }
}

int main() {
    ProcessInfo procInfo[MAX_PROCESSES];
    int count;

    while (1) {
        getProcessInfo(procInfo, &count);
        displayProcesses(procInfo, count);
        sleep(1); // Refresh every second
    }

    return 0;
}